/*
 * vm.c — machine setup and DOS/BIOS services.
 *
 * Two principles hold this together:
 *
 *  1. Services are reached ARCHITECTURALLY. Every IVT entry points into a
 *     trampoline page of `HLT; IRET` slots. The CPU core knows nothing about
 *     interrupt numbers; it just vectors through the IVT like hardware. That
 *     is what makes the guest's own AH=35h/25h vector hooking and its INT 08h
 *     handler chaining work without any special cases.
 *
 *  2. Unimplemented services are FATAL AND LOUD by default. The point is that
 *     the trap report tells us exactly what to write next, so the DOS kernel
 *     only ever grows to fit what this game actually calls.
 */
#include "vm.h"
#include "asset_check.h"
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#ifdef _WIN32
#  include <direct.h>
#  define vm_mkdir(path) _mkdir(path)
#else
#  include <dirent.h>
#  include <sys/stat.h>
#  define vm_mkdir(path) mkdir(path,0755)
#endif

static vm *g_vm;   /* the HLT callback has no user pointer to ride on */

/*
 * Audio sink, injected by the front end.
 *
 * The VM must keep linking without SDL so the CPU conformance suite can run
 * in asset-free CI, so it cannot call into the HAL directly. main_vm.c points
 * this at hal_audio_write_opl(); the headless tools leave it silent.
 */
static void audio_opl_write_noop(uint16_t reg, uint8_t val) { (void)reg; (void)val; }
void (*vm_audio_opl_write)(uint16_t reg, uint8_t val) = audio_opl_write_noop;

static void audio_dma_write_noop(const uint8_t *samples, uint32_t count, uint32_t sample_rate) {
    (void)samples; (void)count; (void)sample_rate;
}
void (*vm_audio_dma_write)(const uint8_t *samples, uint32_t count, uint32_t sample_rate) = audio_dma_write_noop;
static uint8_t audio_mpu_read_stub(void) { return 0xFF; }
static void audio_mpu_write_stub(uint8_t value) { (void)value; }
uint8_t (*vm_audio_mpu_read_data)(void) = audio_mpu_read_stub;
uint8_t (*vm_audio_mpu_read_status)(void) = audio_mpu_read_stub;
void (*vm_audio_mpu_write_data)(uint8_t data) = audio_mpu_write_stub;
void (*vm_audio_mpu_write_cmd)(uint8_t cmd) = audio_mpu_write_stub;

/* ------------------------------------------------------------------ */
/* Small helpers                                                       */
/* ------------------------------------------------------------------ */
static void set_cf(cpu86 *c, int on) {
    if (on) c->flags |= F_CF; else c->flags &= (uint16_t)~F_CF;
}

static void dos_ok(cpu86 *c)                { set_cf(c, 0); }
static void dos_err(cpu86 *c, uint16_t e)   { set_cf(c, 1); c->r[CPU_AX] = e; }

/* ------------------------------------------------------------------ */
/* Path translation: DOS name -> host path                              */
/* ------------------------------------------------------------------ */
static void dos_read_cstr(uint16_t seg, uint16_t off, char *out, size_t max) {
    size_t i = 0;
    while (i + 1 < max) {
        uint8_t ch = seg_r8(seg, (uint16_t)(off + i));
        if (!ch) break;
        out[i++] = (char)ch;
    }
    out[i] = '\0';
}

/* Case-insensitive lookup of `name` inside `dir`. */
static bool find_in_dir(const char *dir, const char *name, char *out, size_t max) {
#ifdef _WIN32
    snprintf(out, max, "%s/%s", dir, name);
    { FILE *f = fopen(out, "rb"); if (f) { fclose(f); return true; } }
    return false;
#else
    DIR *d = opendir(dir);
    struct dirent *e;
    if (!d) return false;
    while ((e = readdir(d)) != NULL) {
#ifdef __GNUC__
        if (strcasecmp(e->d_name, name) == 0) {
#else
        if (strcmp(e->d_name, name) == 0) {
#endif
            if ((size_t)snprintf(out, max, "%s/%s", dir, e->d_name) >= max) {
                closedir(d);
                return false;   /* path too long for the caller's buffer */
            }
            closedir(d);
            return true;
        }
    }
    closedir(d);
    return false;
#endif
}

/*
 * Optional replacement lookup. A replacement is stored as mods/<sha256>,
 * where the key is the hash of the pinned original asset. With --mods unset,
 * this path is never consulted and retail file resolution is unchanged.
 */
static bool find_hash_replacement(const vm *v, const char *original_path,
                                  char *out, size_t max) {
    char digest[65], candidate[1024];
    FILE *f;
    int n;
    if (!v->cfg.mods_dir[0] || !xanth_sha256_file(original_path,digest)) return false;
    n=snprintf(candidate,sizeof(candidate),"%s/%s",v->cfg.mods_dir,digest);
    if (n<0 || (size_t)n>=sizeof(candidate)) return false;
    f=fopen(candidate,"rb");
    if (!f) return false;
    fclose(f);
    n=snprintf(out,max,"%s",candidate);
    return n>=0 && (size_t)n<max;
}

/*
 * Map a DOS path to a host path. Drive letters and directories in the guest's
 * path are discarded: the game is configured (via the LEGEND.INI we author)
 * to look in one place, and everything it opens is a bare 8.3 name.
 */
static bool resolve_path(vm *v, const char *dos_path, char *out, size_t max,
                         bool for_create) {
    const char *base = dos_path;
    const char *p;
    char name[128];

    for (p = dos_path; *p; p++) {
        if (*p == '\\' || *p == '/' || *p == ':') base = p + 1;
    }
    snprintf(name, sizeof(name), "%s", base);
    if (!name[0]) return false;

    /* Saves live in the save dir; everything else in the data dir.
     * Note .DAT is shipped game data (OBJECT.DAT, XANTHSTR.DAT), NOT a save,
     * so only .SAV routes here. */
    {
        size_t n = strlen(name);
        bool is_save = (n > 4 && strcasecmp(name + n - 4, ".SAV") == 0);

        if (is_save) {
            if ((size_t)snprintf(out, max, "%s/%s", v->cfg.save_dir, name) >= max)
                return false;
            return true;
        }
    }

    if (find_in_dir(v->cfg.data_dir, name, out, max)) {
        char original[1024], replacement[1024];
        snprintf(original,sizeof(original),"%s",out);
        if (find_hash_replacement(v,original,replacement,sizeof(replacement))) {
            if (snprintf(out,max,"%s",replacement)<0 || strlen(replacement)>=max)
                return false;
        }
        return true;
    }

    /* Config and anything else we generate lives in the save dir, so the
     * user's asset directory is never written to and can stay read-only. */
    if (find_in_dir(v->cfg.save_dir, name, out, max)) return true;

    if (for_create) {
        if ((size_t)snprintf(out, max, "%s/%s", v->cfg.save_dir, name) >= max)
            return false;
        return true;
    }
    return false;
}

/*
 * Write LEGEND.INI if it is not already there.
 *
 * The retail INSTALL.EXE produced this file and we do not ship it, so the
 * port authors it. That is a lever rather than a chore: the game reads its
 * hardware configuration from here, so we get to choose which devices the
 * shim has to emulate. Tokens are the ones XANTH.EXE actually parses --
 * quiet / real / noreal / adlib / mt32 / blaster -- and the format strings
 * are MOUSE=%s, GAMEDATA=%s, SAVEDATA=%s, MUSIC=%s %c %s, SOUND=%s %c %s.
 *
 * Sound starts as `quiet` deliberately: audio devices arrive at M7/M9, and
 * until then a silent configuration is the difference between reaching the
 * title screen and blocking on a device that does not exist yet.
 */
static bool ensure_save_directory(const char *path);

static bool ensure_legend_ini(vm *v) {
    char path[600];
    FILE *f;

    if (!ensure_save_directory(v->cfg.save_dir)) {
        fprintf(stderr,"[vm] invalid or too-long save directory: %s\n",v->cfg.save_dir);
        return !v->cfg.use_general_midi;
    }
    snprintf(path, sizeof(path), "%s/LEGEND.INI", v->cfg.save_dir);
    f = fopen(path, "rb");
    if (f) {
        if (!v->cfg.use_general_midi) { fclose(f); return true; }

        /* The user explicitly selected the soundfont backend. Keep every
         * other saved device setting, but route retail music through the
         * game's MT-32 MPU-401 path so MIDI events reach that backend. */
        char original[8192], updated[8192];
        size_t n=fread(original,1,sizeof(original),f);
        bool too_large=!feof(f);
        fclose(f);
        if (too_large) {
            fprintf(stderr,"[vm] LEGEND.INI is too large to enable General MIDI\n");
            return false;
        }
        size_t in=0,out=0;
        bool replaced=false;
        while (in<n) {
            size_t end=in;
            while (end<n && original[end]!='\n') ++end;
            size_t line_len=end-in;
            size_t text_len=line_len;
            if (text_len && original[in+text_len-1]=='\r') --text_len;
            size_t key=in;
            while (key<in+text_len && (original[key]==' ' || original[key]=='\t')) ++key;
            bool is_music=(in+text_len-key>=6 &&
                toupper((unsigned char)original[key+0])=='M' &&
                toupper((unsigned char)original[key+1])=='U' &&
                toupper((unsigned char)original[key+2])=='S' &&
                toupper((unsigned char)original[key+3])=='I' &&
                toupper((unsigned char)original[key+4])=='C' && original[key+5]=='=');
            const char *replacement="MUSIC=mt32 0 330\r\n";
            if (is_music) {
                if (!replaced) {
                    size_t rlen=strlen(replacement);
                    if (out+rlen>=sizeof(updated)) return false;
                    memcpy(updated+out,replacement,rlen); out+=rlen;
                    replaced=true;
                }
            } else {
                size_t raw_len=end-in+(end<n ? 1u : 0u);
                if (out+raw_len>=sizeof(updated)) return false;
                memcpy(updated+out,original+in,raw_len); out+=raw_len;
            }
            in=end+(end<n ? 1u : 0u);
        }
        if (!replaced) {
            static const char replacement[]="MUSIC=mt32 0 330\r\n";
            if (out && updated[out-1]!='\n') {
                if (out+2>=sizeof(updated)) return false;
                updated[out++]='\r'; updated[out++]='\n';
            }
            if (out+sizeof(replacement)>sizeof(updated)) return false;
            memcpy(updated+out,replacement,sizeof(replacement)-1);
            out+=sizeof(replacement)-1;
        }
        f=fopen(path,"wb");
        if (!f) {
            fprintf(stderr,"[vm] cannot configure MUSIC=mt32 in %s\n",path);
            return false;
        }
        bool write_ok=fwrite(updated,1,out,f)==out;
        if (fclose(f)!=0) write_ok=false;
        if (!write_ok) {
            fprintf(stderr,"[vm] cannot configure MUSIC=mt32 in %s\n",path);
            return false;
        }
        fprintf(stderr,"[vm] soundfont selected; LEGEND.INI uses MUSIC=mt32\n");
        return true;
    }

    f = fopen(path, "wb");
    if (!f) {
        fprintf(stderr, "[vm] warning: cannot write %s\n", path);
        return !v->cfg.use_general_midi;
    }
    if (v->cfg.use_general_midi)
        fprintf(f,
                "MOUSE=mouse\r\n"
                "GAMEDATA=C:\\XANTH\\\r\n"
                "SAVEDATA=C:\\XANTH\\\r\n"
                "MUSIC=mt32 0 330\r\n"
                "SOUND=blaster 7 220\r\n");
    else
        fprintf(f,
                "MOUSE=mouse\r\n"
                "GAMEDATA=C:\\XANTH\\\r\n"
                "SAVEDATA=C:\\XANTH\\\r\n"
                "MUSIC=adlib 0 388\r\n"
                "SOUND=blaster 7 220\r\n");
    if (ferror(f) || fclose(f)!=0) {
        fprintf(stderr,"[vm] failed writing %s\n",path);
        return !v->cfg.use_general_midi;
    }
    fprintf(stderr, "[vm] authored %s\n", path);
    return true;
}

/* ------------------------------------------------------------------ */
/* DOS 8.3 wildcard matching                                            */
/*                                                                      */
/* These are DOS semantics, not glob: '*' matches the remainder of the  */
/* NAME FIELD only (so "*.SAV" means "????????.SAV"), and '?' matches   */
/* one character or the end of the field. Getting this subtly wrong is  */
/* easy, so it is a pure function with its own test.                    */
/* ------------------------------------------------------------------ */
/* Returns false if `in` is not representable as 8.3.
 *
 * Real DOS would silently truncate, but our host filesystem can hold names
 * DOS never could, and silently truncating means a stray "XANTH01.SAVE" gets
 * picked up by the game's "*.SAV" save-slot glob. Non-8.3 names simply do not
 * participate. */
static bool split_83(const char *in, char *name, char *ext) {
    int i = 0, j = 0;
    memset(name, ' ', 8); name[8] = 0;
    memset(ext, ' ', 3);  ext[3] = 0;

    for (; in[i] && in[i] != '.'; i++, j++) {
        if (j >= 8) return false;
        name[j] = (char)toupper((unsigned char)in[i]);
    }
    if (in[i] == '.') {
        i++;
        for (j = 0; in[i]; i++, j++) {
            if (j >= 3) return false;
            ext[j] = (char)toupper((unsigned char)in[i]);
        }
    }
    return true;
}

static bool match_field(const char *pat, const char *val, int len) {
    for (int i = 0; i < len; i++) {
        if (pat[i] == '*') return true;          /* matches the rest of the field */
        if (pat[i] == '?') continue;             /* matches any one character     */
        if (pat[i] != val[i]) return false;
    }
    return true;
}

bool dos_match_83(const char *pattern, const char *filename) {
    char pn[9], pe[4], fn[9], fe[4];
    if (!split_83(pattern, pn, pe)) return false;
    if (!split_83(filename, fn, fe)) return false;
    return match_field(pn, fn, 8) && match_field(pe, fe, 3);
}

/* Snapshot a directory listing matching `pattern`, sorted.
 * Sorting matters: the save-slot list is user-visible, and an unsorted
 * host readdir order would make replay non-deterministic. */
static int cmp_names(const void *a, const void *b) {
    return strcmp(*(const char *const *)a, *(const char *const *)b);
}

static void find_close(vm *v) {
    for (int i = 0; i < v->find.count; i++) free(v->find.names[i]);
    free(v->find.names);
    v->find.names = NULL;
    v->find.count = 0;
    v->find.index = 0;
}

static void find_snapshot(vm *v, const char *dir, const char *pattern) {
    find_close(v);
#ifndef _WIN32
    {
        DIR *d = opendir(dir);
        struct dirent *e;
        int cap = 16;
        if (!d) return;
        v->find.names = (char **)malloc(sizeof(char *) * cap);
        if (!v->find.names) { closedir(d); return; }
        while ((e = readdir(d)) != NULL) {
            if (e->d_name[0] == '.') continue;
            if (!dos_match_83(pattern, e->d_name)) continue;
            if (v->find.count == cap) {
                char **bigger = (char **)realloc(v->find.names, sizeof(char *) * cap * 2);
                if (!bigger) break;
                v->find.names = bigger;
                cap *= 2;
            }
            v->find.names[v->find.count] = strdup(e->d_name);
            if (!v->find.names[v->find.count]) break;
            v->find.count++;
        }
        closedir(d);
        if (v->find.count > 1)
            qsort(v->find.names, (size_t)v->find.count, sizeof(char *), cmp_names);
    }
#else
    (void)dir; (void)pattern;
#endif
    snprintf(v->find.dir, sizeof(v->find.dir), "%s", dir);
}

/* Fill the DTA with the entry at find.index, and advance it. */
static bool find_fill_dta(vm *v) {
    cpu86 *c = &v->cpu;
    char host[600];
    long size = 0;
    FILE *f;
    const char *nm;
    uint16_t seg = v->dta_seg, off = v->dta_off;

    if (v->find.index >= v->find.count) return false;
    nm = v->find.names[v->find.index++];

    snprintf(host, sizeof(host), "%s/%s", v->find.dir, nm);
    f = fopen(host, "rb");
    if (f) { fseek(f, 0, SEEK_END); size = ftell(f); fclose(f); }

    seg_w8 (seg, (uint16_t)(off + 0x15), 0x20);          /* attribute: archive */
    seg_w16(seg, (uint16_t)(off + 0x16), 0);             /* time  */
    seg_w16(seg, (uint16_t)(off + 0x18), 0x1891);        /* date: 1992-04-17 */
    seg_w16(seg, (uint16_t)(off + 0x1A), (uint16_t)(size & 0xFFFF));
    seg_w16(seg, (uint16_t)(off + 0x1C), (uint16_t)((uint32_t)size >> 16));
    for (int i = 0; i < 13; i++) {
        char ch = nm[i] ? (char)toupper((unsigned char)nm[i]) : 0;
        seg_w8(seg, (uint16_t)(off + 0x1E + i), (uint8_t)ch);
        if (!nm[i]) break;
    }
    (void)c;
    return true;
}

/* Record a distinct opened filename for the end-of-run report. */
static void note_opened(vm *v, const char *dos_path) {
    const char *base = dos_path, *p;
    for (p = dos_path; *p; p++)
        if (*p == '\\' || *p == '/' || *p == ':') base = p + 1;
    for (int i = 0; i < v->opened_count; i++)
        if (strcasecmp(v->opened[i], base) == 0) return;
    if (v->opened_count >= VM_MAX_OPENED) return;
    {
        /* 8.3 plus NUL fits in 16; anything longer is simply clipped, since
         * this list is diagnostic output rather than a lookup key. */
        char *dst = v->opened[v->opened_count];
        size_t n = sizeof(v->opened[0]) - 1;
        strncpy(dst, base, n);
        dst[n] = '\0';
    }
    v->opened_count++;
}

/* ------------------------------------------------------------------ */
/* File handle table                                                    */
/* ------------------------------------------------------------------ */
static int alloc_handle(vm *v) {
    for (int i = 5; i < VM_MAX_FILES; i++) {
        if (!v->files[i].used) return i;
    }
    return -1;
}

static void init_std_handles(vm *v) {
    for (int i = 0; i < 5; i++) {
        v->files[i].used = true;
        v->files[i].is_device = true;
        v->files[i].device_id = i;
        v->files[i].fp = NULL;
    }
}

/* ------------------------------------------------------------------ */
/* Clock                                                                */
/*                                                                      */
/* Derived from the virtual timer, never from the host clock. That is   */
/* what lets a replay be bit-reproducible while still letting time pass */
/* -- and time MUST pass: the game polls DOS for the time and spins in  */
/* the C runtime's long-division and localtime helpers until it changes.*/
/* A clock pinned to a constant looks deterministic and hangs the game. */
/* ------------------------------------------------------------------ */
#define VM_EPOCH_Y 1994
#define VM_EPOCH_M 4
#define VM_EPOCH_D 17
#define VM_EPOCH_HOUR 12

/*
 * Milliseconds of guest time elapsed, taken from the virtual cycle counter.
 *
 * Deliberately NOT derived from the timer-tick count: the game's audio setup
 * reprograms the PIT divisor, so a tick stops being 54.925 ms and any clock
 * built on tick counting silently starts running at the wrong rate. The cycle
 * counter is the one authority for time and is divisor-independent.
 */
static uint64_t vm_elapsed_ms(const vm *v) {
    uint64_t cps = v->cycles_per_second ? v->cycles_per_second : 1;
    return (v->cpu.cycles * 1000ull) / cps;
}

/* Days-from-civil, after Howard Hinnant's algorithm. */
static long days_from_civil(int y, unsigned m, unsigned d) {
    y -= m <= 2;
    const int era = (y >= 0 ? y : y - 399) / 400;
    const unsigned yoe = (unsigned)(y - era * 400);
    const unsigned doy = (153u * (m + (m > 2 ? -3 : 9)) + 2u) / 5u + d - 1u;
    const unsigned doe = yoe * 365u + yoe / 4u - yoe / 100u + doy;
    return (long)era * 146097L + (long)doe - 719468L;
}

static void civil_from_days(long z, int *y, unsigned *m, unsigned *d) {
    z += 719468L;
    const long era = (z >= 0 ? z : z - 146096L) / 146097L;
    const unsigned long doe = (unsigned long)(z - era * 146097L);
    const unsigned long yoe =
        (doe - doe / 1460ul + doe / 36524ul - doe / 146096ul) / 365ul;
    const long yy = (long)yoe + era * 400L;
    const unsigned long doy = doe - (365ul * yoe + yoe / 4ul - yoe / 100ul);
    const unsigned long mp = (5ul * doy + 2ul) / 153ul;
    *d = (unsigned)(doy - (153ul * mp + 2ul) / 5ul + 1ul);
    *m = (unsigned)(mp + (mp < 10 ? 3 : -9));
    *y = (int)(yy + (*m <= 2));
}

void vm_clock_time(const vm *v, int *hh, int *mm, int *ss, int *cs) {
    uint64_t ms = vm_elapsed_ms(v) + (uint64_t)VM_EPOCH_HOUR * 3600000ull;
    uint64_t sec = ms / 1000ull;
    *hh = (int)((sec / 3600ull) % 24ull);
    *mm = (int)((sec / 60ull) % 60ull);
    *ss = (int)(sec % 60ull);
    *cs = (int)((ms % 1000ull) / 10ull);
}

void vm_clock_date(const vm *v, int *year, int *month, int *day, int *dow) {
    uint64_t ms = vm_elapsed_ms(v) + (uint64_t)VM_EPOCH_HOUR * 3600000ull;
    long extra_days = (long)(ms / 86400000ull);
    long z = days_from_civil(VM_EPOCH_Y, VM_EPOCH_M, VM_EPOCH_D) + extra_days;
    int y; unsigned m, d;
    civil_from_days(z, &y, &m, &d);
    *year = y; *month = (int)m; *day = (int)d;
    /* 1970-01-01 (day 0) was a Thursday; DOS wants 0 = Sunday. */
    *dow = (int)(((z % 7) + 11) % 7);
}

/* ------------------------------------------------------------------ */
/* Host input injection                                                */
/* ------------------------------------------------------------------ */
static int keyq_count(const vm *v) {
    return (v->keyq_head - v->keyq_tail + VM_KEY_QUEUE) % VM_KEY_QUEUE;
}

static void bda_sync_keyboard(vm *v) {
    /* Some code peeks the BIOS keyboard buffer head/tail at 0040:001A-001D
     * instead of calling INT 16h, so keep them consistent with the queue. */
    uint16_t head = 0x1E;
    uint16_t tail = (uint16_t)(0x1E + (uint16_t)keyq_count(v) * 2);
    if (tail > 0x3C) tail = 0x3C;
    seg_w16(VM_SEG_BDA, 0x1A, head);
    seg_w16(VM_SEG_BDA, 0x1C, tail);
}

void vm_post_key(vm *v, uint8_t scancode, uint8_t ascii) {
    v->waiting_for_input = false;
    int next = (v->keyq_head + 1) % VM_KEY_QUEUE;
    if (next == v->keyq_tail) return;          /* full: drop, like the BIOS */
    v->keyq[v->keyq_head].scan = scancode;
    v->keyq[v->keyq_head].ascii = ascii;
    v->keyq_head = next;
    v->idle_polls = 0;
    bda_sync_keyboard(v);
}

static bool keyq_pop(vm *v, uint16_t *out) {
    if (v->keyq_head == v->keyq_tail) return false;
    if (out) *out = (uint16_t)((v->keyq[v->keyq_tail].scan << 8)
                             |  v->keyq[v->keyq_tail].ascii);
    v->keyq_tail = (v->keyq_tail + 1) % VM_KEY_QUEUE;
    bda_sync_keyboard(v);
    return true;
}

static bool keyq_peek(const vm *v, uint16_t *out) {
    if (v->keyq_head == v->keyq_tail) return false;
    if (out) *out = (uint16_t)((v->keyq[v->keyq_tail].scan << 8)
                             |  v->keyq[v->keyq_tail].ascii);
    return true;
}

static int clampi(int x, int lo, int hi) {
    return x < lo ? lo : (x > hi ? hi : x);
}

/* INT 33h event condition bits. */
#define M33_MOVE        0x0001
#define M33_LDOWN       0x0002
#define M33_LUP         0x0004
#define M33_RDOWN       0x0008
#define M33_RUP         0x0010
#define M33_MDOWN       0x0020
#define M33_MUP         0x0040

static void m33_raise(vm *v, uint16_t cond) {
    if (v->m33_handler_seg || v->m33_handler_off)
        v->m33_pending |= (uint16_t)(cond & v->m33_mask);
}

void vm_post_mouse_move(vm *v, int x, int y) {
    v->waiting_for_input = false;
    int nx = clampi(x, v->mouse_min_x, v->mouse_max_x);
    int ny = clampi(y, v->mouse_min_y, v->mouse_max_y);
    v->mickey_dx += (nx - v->mouse_x) * 8;
    v->mickey_dy += (ny - v->mouse_y) * 8;
    if (nx != v->mouse_x || ny != v->mouse_y) {
        v->mouse_x = nx;
        v->mouse_y = ny;
        m33_raise(v, M33_MOVE);
    }
    v->idle_polls = 0;
}

void vm_post_mouse_button(vm *v, int button, bool pressed) {
    v->waiting_for_input = false;
    if (button < 0 || button > 2) return;
    if (pressed) {
        v->mouse_buttons |= (1 << button);
        v->press_count[button]++;
        v->press_x[button] = v->mouse_x;
        v->press_y[button] = v->mouse_y;
        m33_raise(v, (uint16_t)(M33_LDOWN << (button * 2)));
    } else {
        v->mouse_buttons &= ~(1 << button);
        v->release_count[button]++;
        v->release_x[button] = v->mouse_x;
        v->release_y[button] = v->mouse_y;
        m33_raise(v, (uint16_t)(M33_LUP << (button * 2)));
    }
    v->idle_polls = 0;
}

/*
 * Make a blocking service actually block.
 *
 * We are inside the trampoline's HLT callback, so SS:SP holds the interrupted
 * IP, CS and FLAGS. Rewinding the saved IP by two -- the length of `INT nn` --
 * makes the interrupt re-execute when the guest resumes. Combined with ending
 * the slice, that turns "wait for a keystroke" into a real wait the host can
 * satisfy, rather than a fabricated keystroke that sends the game spinning
 * through hundreds of thousands of phantom inputs.
 */
static void dos_block_retry(vm *v) {
    cpu86 *c = &v->cpu;
    uint16_t ip = seg_r16(c->s[CPU_SS], c->r[CPU_SP]);
    seg_w16(c->s[CPU_SS], c->r[CPU_SP], (uint16_t)(ip - 2));
    c->yield_request = 1;
    v->waiting_for_input = true;
    v->idle_polls++;
}

/* ------------------------------------------------------------------ */
/* Overlay provenance                                                   */
/* ------------------------------------------------------------------ */
#define OVL_PAYLOAD_START 496u   /* directory + FFFF terminator + padding */

void vm_note_overlay_load(vm *v, uint32_t file_off, uint32_t len,
                          uint16_t seg, uint16_t off) {
    uint32_t payload_off = (file_off >= OVL_PAYLOAD_START)
                         ? file_off - OVL_PAYLOAD_START : 0;
    uint32_t lin = cpu_lin(seg, off);
    uint32_t para0, paras;

    if (v->ovl_load_count < VM_OVL_LOADS) {
        v->ovl_loads[v->ovl_load_count].file_off = file_off;
        v->ovl_loads[v->ovl_load_count].length   = len;
        v->ovl_loads[v->ovl_load_count].seg      = seg;
        v->ovl_loads[v->ovl_load_count].off      = off;
        v->ovl_loads[v->ovl_load_count].at_insn  = v->insn_count;
        v->ovl_load_count++;
    }
    if (!v->ovl_base_seg || seg < v->ovl_base_seg) v->ovl_base_seg = seg;

    /* Keyed by ABSOLUTE paragraph across the whole 1 MB. Basing the map on
     * the lowest destination segment looked tidier but was wrong: the lowest
     * destination is RTLink's relocation scratch buffer inside the root
     * image, which put the real slots out of range. */
    if (!v->ovl_provenance) return;
    para0 = lin >> 4;
    paras = (len + 15) >> 4;
    for (uint32_t i = 0; i < paras; i++) {
        uint32_t idx = para0 + i;
        if (idx >= VM_OVL_PARAS) break;
        v->ovl_provenance[idx] = (int32_t)(payload_off + i * 16u);
    }
}

int32_t vm_overlay_payload_at(const vm *v, uint16_t seg, uint16_t off) {
    uint32_t lin = cpu_lin(seg, off);
    uint32_t para = lin >> 4;
    int32_t base;
    if (!v->ovl_provenance || para >= VM_OVL_PARAS) return -1;
    base = v->ovl_provenance[para];
    if (base < 0) return -1;
    return base + (int32_t)(lin & 0xF);
}

/* ------------------------------------------------------------------ */
/* Trap reporting                                                      */
/* ------------------------------------------------------------------ */
static void trap_unimplemented(vm *v, const char *what, uint8_t intno, uint16_t ah) {
    cpu86 *c = &v->cpu;
    v->last_unimpl_int = intno;
    v->last_unimpl_ah = ah;
    v->dos_unimpl[intno] = true;

    fprintf(stderr,
        "\n================ UNIMPLEMENTED HOST SERVICE ================\n"
        "  %s\n"
        "  called from %04X:%04X  (instruction %llu)\n",
        what, c->s[CPU_CS], c->ip, (unsigned long long)v->insn_count);
    vm_dump_state(v, stderr);
    fprintf(stderr,
        "  To implement: add this case in port/src/emu/vm.c\n"
        "  Or re-run with --permissive to return an error and continue.\n"
        "============================================================\n\n");

    if (v->cfg.permissive) {
        dos_err(c, DOSERR_INVALID_FUNCTION);
    } else {
        c->fault = CPU_FAULT_UNIMPL_INT;
    }
}

void vm_dump_state(const vm *v, FILE *out) {
    const cpu86 *c = &v->cpu;
    fprintf(out,
        "  AX=%04X BX=%04X CX=%04X DX=%04X  SI=%04X DI=%04X BP=%04X SP=%04X\n"
        "  DS=%04X ES=%04X SS=%04X CS=%04X  IP=%04X FL=%04X [%c%c%c%c%c%c%c%c%c]\n",
        c->r[CPU_AX], c->r[CPU_BX], c->r[CPU_CX], c->r[CPU_DX],
        c->r[CPU_SI], c->r[CPU_DI], c->r[CPU_BP], c->r[CPU_SP],
        c->s[CPU_DS], c->s[CPU_ES], c->s[CPU_SS], c->s[CPU_CS],
        c->ip, c->flags,
        (c->flags & F_OF) ? 'O' : '-', (c->flags & F_DF) ? 'D' : '-',
        (c->flags & F_IF) ? 'I' : '-', (c->flags & F_TF) ? 'T' : '-',
        (c->flags & F_SF) ? 'S' : '-', (c->flags & F_ZF) ? 'Z' : '-',
        (c->flags & F_AF) ? 'A' : '-', (c->flags & F_PF) ? 'P' : '-',
        (c->flags & F_CF) ? 'C' : '-');

    /* A few bytes at CS:IP help identify the instruction that trapped. */
    fprintf(out, "  code:");
    for (int i = -4; i < 8; i++) {
        uint16_t off = (uint16_t)(c->ip + i);
        fprintf(out, "%s%02X", (i == 0) ? " >" : " ", seg_r8(c->s[CPU_CS], off));
    }
    fprintf(out, "\n");
}

/* ------------------------------------------------------------------ */
/* INT 21h — DOS                                                        */
/* ------------------------------------------------------------------ */
static void svc_int21(vm *v) {
    cpu86 *c = &v->cpu;
    uint8_t ah = cpu_get_r8(c, CPU_AH);

    v->dos_counts[ah]++;
    if (v->cfg.trace_dos) {
        fprintf(stderr, "[dos] AH=%02X AL=%02X BX=%04X CX=%04X DX=%04X DS=%04X\n",
                ah, cpu_get_r8(c, CPU_AL), c->r[CPU_BX], c->r[CPU_CX],
                c->r[CPU_DX], c->s[CPU_DS]);
    }

    switch (ah) {

    case 0x02:  /* display character */
        fputc(cpu_get_r8(c, CPU_DL), stderr);
        dos_ok(c);
        break;

    case 0x09: { /* display '$'-terminated string */
        uint16_t off = c->r[CPU_DX];
        for (int i = 0; i < 1024; i++) {
            uint8_t ch = seg_r8(c->s[CPU_DS], (uint16_t)(off + i));
            if (ch == '$') break;
            fputc(ch, stderr);
        }
        dos_ok(c);
        break;
    }

    case 0x01:  /* console input with echo */
    case 0x07:  /* direct console input, no echo */
    case 0x08: { /* console input without echo */
        uint16_t key;
        /*
         * Extended keys (arrows, function keys) have no ASCII value and are
         * delivered by DOS as TWO reads: a zero byte, then the scan code.
         * Collapsing that into one read loses every cursor key, which is how
         * a keyboard-driven adventure ends up looking unresponsive.
         */
        if (v->pending_ext) {
            cpu_set_r8(c, CPU_AL, v->pending_ext);
            v->pending_ext = 0;
            dos_ok(c);
            break;
        }
        if (v->cfg.trace_int) {
            static int n;
            if (n++ < 1) {
                fprintf(stderr, "[dos] AH=%02X console read from %04X:%04X\n",
                        ah, c->last_int_cs, c->last_int_ip);
                /*
                 * Walk the stack for VERIFIED far-call return addresses: a
                 * slot only counts if the five bytes before it actually are
                 * a `call far` (9A) opcode. Pattern-matching on the segment
                 * alone produces false positives that send you chasing
                 * addresses that were never call sites.
                 */
                for (int j = 0; j < 200; j += 2) {
                    uint16_t off = seg_r16(c->s[CPU_SS], (uint16_t)(c->r[CPU_SP] + j));
                    uint16_t sg  = seg_r16(c->s[CPU_SS], (uint16_t)(c->r[CPU_SP] + j + 2));
                    uint32_t lin = cpu_lin(sg, off);
                    if (lin < 16 || lin >= DOS_MEM_SIZE) continue;
                    if (seg_r8(sg, (uint16_t)(off - 5)) == 0x9A) {
                        uint16_t toff = seg_r16(sg, (uint16_t)(off - 4));
                        uint16_t tseg = seg_r16(sg, (uint16_t)(off - 2));
                        int32_t prov = vm_overlay_payload_at(v, sg, off);
                        if (prov >= 0)
                            fprintf(stderr, "    frame %04X:%04X  (called %04X:%04X)"
                                            "  [ovl-payload %d]\n",
                                    sg, off, tseg, toff, prov);
                        else
                            fprintf(stderr, "    frame %04X:%04X  (called %04X:%04X)"
                                            "  [exe-code %ld]\n",
                                    sg, off, tseg, toff,
                                    (long)cpu_lin(sg, off)
                                        - (long)((uint32_t)v->img.load_seg * 16));
                    }
                }
            }
        }
        if (keyq_pop(v, &key)) {
            uint8_t ascii = (uint8_t)(key & 0xFF);
            if (ascii == 0) v->pending_ext = (uint8_t)(key >> 8);
            cpu_set_r8(c, CPU_AL, ascii);
            dos_ok(c);
        } else if (v->cfg.nonblocking_conin) {
            /* Experiment: report "no character" instead of blocking, so the
             * caller's loop keeps running and can poll the mouse. */
            cpu_set_r8(c, CPU_AL, 0);
            dos_ok(c);
            v->idle_polls++;
        } else {
            dos_block_retry(v);   /* a genuine block, see the comment there */
        }
        break;
    }

    case 0x0B:  /* check console input status */
        cpu_set_r8(c, CPU_AL,
                   (v->pending_ext || keyq_peek(v, NULL)) ? 0xFF : 0x00);
        dos_ok(c);
        break;

    case 0x19:  /* get current drive: C: */
        cpu_set_r8(c, CPU_AL, 2);
        dos_ok(c);
        break;

    case 0x1A:  /* set DTA */
        v->dta_seg = c->s[CPU_DS];
        v->dta_off = c->r[CPU_DX];
        dos_ok(c);
        break;

    case 0x2F:  /* get DTA */
        c->s[CPU_ES] = v->dta_seg;
        c->r[CPU_BX] = v->dta_off;
        dos_ok(c);
        break;

    case 0x25: { /* set interrupt vector */
        uint8_t vec = cpu_get_r8(c, CPU_AL);
        seg_w16(0, (uint16_t)(vec * 4), c->r[CPU_DX]);
        seg_w16(0, (uint16_t)(vec * 4 + 2), c->s[CPU_DS]);
        if (v->cfg.trace_dos)
            fprintf(stderr, "[dos] guest hooked INT %02Xh -> %04X:%04X\n",
                    vec, c->s[CPU_DS], c->r[CPU_DX]);
        dos_ok(c);
        break;
    }

    case 0x35: { /* get interrupt vector */
        uint8_t vec = cpu_get_r8(c, CPU_AL);
        c->r[CPU_BX] = seg_r16(0, (uint16_t)(vec * 4));
        c->s[CPU_ES] = seg_r16(0, (uint16_t)(vec * 4 + 2));
        dos_ok(c);
        break;
    }

    case 0x30:  /* get DOS version: report 6.22 */
        cpu_set_r8(c, CPU_AL, 6);
        cpu_set_r8(c, CPU_AH, 22);
        cpu_set_r8(c, CPU_BH, 0xFF);
        c->r[CPU_CX] = 0;
        cpu_set_r8(c, CPU_BL, 0);
        dos_ok(c);
        break;

    case 0x2A: { /* get date */
        int y, mo, d, dow;
        vm_clock_date(v, &y, &mo, &d, &dow);
        c->r[CPU_CX] = (uint16_t)y;
        cpu_set_r8(c, CPU_DH, (uint8_t)mo);
        cpu_set_r8(c, CPU_DL, (uint8_t)d);
        cpu_set_r8(c, CPU_AL, (uint8_t)dow);
        dos_ok(c);
        break;
    }

    case 0x2C: { /* get time */
        int hh, mm, ss, cs;
        vm_clock_time(v, &hh, &mm, &ss, &cs);
        cpu_set_r8(c, CPU_CH, (uint8_t)hh);
        cpu_set_r8(c, CPU_CL, (uint8_t)mm);
        cpu_set_r8(c, CPU_DH, (uint8_t)ss);
        cpu_set_r8(c, CPU_DL, (uint8_t)cs);
        dos_ok(c);
        break;
    }

    case 0x2B:  /* set date — accepted and ignored; our clock is fixed so
                 * that replay stays deterministic */
        cpu_set_r8(c, CPU_AL, 0);
        dos_ok(c);
        break;

    case 0x2D:  /* set time — likewise */
        cpu_set_r8(c, CPU_AL, 0);
        dos_ok(c);
        break;

    case 0x45: { /* dup handle */
        uint16_t h = c->r[CPU_BX];
        int nh;
        if (h >= VM_MAX_FILES || !v->files[h].used) { dos_err(c, DOSERR_INVALID_HANDLE); break; }
        nh = alloc_handle(v);
        if (nh < 0) { dos_err(c, DOSERR_TOO_MANY_OPEN); break; }
        v->files[nh] = v->files[h];
        c->r[CPU_AX] = (uint16_t)nh;
        dos_ok(c);
        break;
    }

    case 0x46: { /* force duplicate handle */
        uint16_t h = c->r[CPU_BX], nh = c->r[CPU_CX];
        if (h >= VM_MAX_FILES || nh >= VM_MAX_FILES || !v->files[h].used) {
            dos_err(c, DOSERR_INVALID_HANDLE); break;
        }
        v->files[nh] = v->files[h];
        dos_ok(c);
        break;
    }

    case 0x56: { /* rename */
        char from[256], to[256], hf[512], ht[512];
        dos_read_cstr(c->s[CPU_DS], c->r[CPU_DX], from, sizeof(from));
        dos_read_cstr(c->s[CPU_ES], c->r[CPU_DI], to, sizeof(to));
        if (resolve_path(v, from, hf, sizeof(hf), false) &&
            resolve_path(v, to, ht, sizeof(ht), true)) {
            if (rename(hf, ht) == 0) { dos_ok(c); break; }
        }
        dos_err(c, DOSERR_FILE_NOT_FOUND);
        break;
    }

    case 0x39: case 0x3A: case 0x3B:  /* mkdir / rmdir / chdir */
        dos_ok(c);
        break;

    case 0x4E: { /* find first */
        char dos_path[256];
        const char *base, *p2;
        dos_read_cstr(c->s[CPU_DS], c->r[CPU_DX], dos_path, sizeof(dos_path));
        base = dos_path;
        for (p2 = dos_path; *p2; p2++)
            if (*p2 == '\\' || *p2 == '/' || *p2 == ':') base = p2 + 1;

        /* Saves are what the game globs for (%s\%s*.SAV), so search the
         * save directory; anything else searches the asset directory. */
        {
            size_t n = strlen(base);
            const char *dir = (n > 4 && strcasecmp(base + n - 4, ".SAV") == 0)
                            ? v->cfg.save_dir : v->cfg.data_dir;
            find_snapshot(v, dir, base);
        }
        if (v->cfg.trace_dos)
            fprintf(stderr, "[dos] findfirst '%s' -> %d match(es)\n",
                    dos_path, v->find.count);
        if (find_fill_dta(v)) dos_ok(c);
        else                  dos_err(c, 0x0012);   /* no more files */
        break;
    }

    case 0x4F:  /* find next */
        if (find_fill_dta(v)) dos_ok(c);
        else                  dos_err(c, 0x0012);
        break;

    case 0x33:  /* get/set ctrl-break */
        cpu_set_r8(c, CPU_DL, 0);
        dos_ok(c);
        break;

    case 0x47:  /* get current directory into DS:SI, without drive or leading \ */
        seg_w8(c->s[CPU_DS], c->r[CPU_SI], 0);   /* we are at the root */
        c->r[CPU_AX] = 0x0100;
        dos_ok(c);
        break;

    case 0x0E:  /* select drive; report one drive present */
        cpu_set_r8(c, CPU_AL, 1);
        dos_ok(c);
        break;

    case 0x36:  /* get free disk space: 32 MB of headroom for saves */
        c->r[CPU_AX] = 4;        /* sectors per cluster */
        c->r[CPU_BX] = 16384;    /* free clusters       */
        c->r[CPU_CX] = 512;      /* bytes per sector    */
        c->r[CPU_DX] = 16384;    /* total clusters      */
        dos_ok(c);
        break;

    case 0x43:  /* get/set file attributes */
        if (cpu_get_r8(c, CPU_AL) == 0) c->r[CPU_CX] = 0x20;  /* archive */
        dos_ok(c);
        break;

    case 0x4D:  /* get child return code */
        c->r[CPU_AX] = 0;
        dos_ok(c);
        break;

    case 0x62:  /* get PSP */
        c->r[CPU_BX] = v->psp_seg;
        dos_ok(c);
        break;

    case 0x3C: { /* create file */
        char dos_path[256], host[512];
        int h;
        dos_read_cstr(c->s[CPU_DS], c->r[CPU_DX], dos_path, sizeof(dos_path));
        h = alloc_handle(v);
        if (h < 0) { dos_err(c, DOSERR_TOO_MANY_OPEN); break; }
        if (!resolve_path(v, dos_path, host, sizeof(host), true)) {
            dos_err(c, DOSERR_PATH_NOT_FOUND); break;
        }
        v->files[h].fp = fopen(host, "w+b");
        if (!v->files[h].fp) { dos_err(c, DOSERR_ACCESS_DENIED); break; }
        v->files[h].used = true;
        v->files[h].is_device = false;
        snprintf(v->files[h].host_path, sizeof(v->files[h].host_path), "%s", host);
        c->r[CPU_AX] = (uint16_t)h;
        dos_ok(c);
        break;
    }

    case 0x3D: { /* open file */
        char dos_path[256], host[512];
        uint8_t mode = cpu_get_r8(c, CPU_AL) & 3;
        int h;
        dos_read_cstr(c->s[CPU_DS], c->r[CPU_DX], dos_path, sizeof(dos_path));
        h = alloc_handle(v);
        if (h < 0) { dos_err(c, DOSERR_TOO_MANY_OPEN); break; }
        /*
         * A write-open of a file that does not exist is created in the save
         * directory rather than failed.
         *
         * Strict DOS would fail this, but on a real installation the game's
         * own runtime files (RESTART.DAT, which holds the initial-state
         * snapshot the RESTART command restores) already exist in a writable
         * install directory. We ship a read-only asset tree instead, so
         * without this the very first write-open fails -- and the game does
         * not check CF, so it takes the DOS error code in AX as a file handle
         * and writes 512-byte blocks to handle 2. Creating on demand
         * reproduces the installed-game environment the code was written for.
         */
        if (!resolve_path(v, dos_path, host, sizeof(host), mode != 0)) {
            if (v->cfg.trace_dos)
                fprintf(stderr, "[dos] open '%s' -> NOT FOUND\n", dos_path);
            dos_err(c, DOSERR_FILE_NOT_FOUND);
            break;
        }
        v->files[h].fp = fopen(host, (mode == 0) ? "rb" : "r+b");
        if (!v->files[h].fp && mode != 0) v->files[h].fp = fopen(host, "w+b");
        if (!v->files[h].fp && mode != 0) v->files[h].fp = fopen(host, "rb");
        if (!v->files[h].fp) { dos_err(c, DOSERR_FILE_NOT_FOUND); break; }
        v->files[h].used = true;
        v->files[h].is_device = false;
        snprintf(v->files[h].host_path, sizeof(v->files[h].host_path), "%s", host);
        note_opened(v, dos_path);
        {   /* Remember the overlay handle so its reads can be attributed. */
            const char *b = dos_path, *q;
            for (q = dos_path; *q; q++)
                if (*q == '\\' || *q == '/' || *q == ':') b = q + 1;
            if (strcasecmp(b, "XANTH.OVL") == 0) v->ovl_handle = h;
        }
        if (v->cfg.trace_dos)
            fprintf(stderr, "[dos] open '%s' -> handle %d (%s)\n", dos_path, h, host);
        c->r[CPU_AX] = (uint16_t)h;
        dos_ok(c);
        break;
    }

    case 0x3E: { /* close */
        uint16_t h = c->r[CPU_BX];
        if (h >= VM_MAX_FILES || !v->files[h].used) { dos_err(c, DOSERR_INVALID_HANDLE); break; }
        if (!v->files[h].is_device) {
            if (v->files[h].fp) fclose(v->files[h].fp);
            v->files[h].fp = NULL;
            v->files[h].used = false;
        }
        dos_ok(c);
        break;
    }

    case 0x3F: { /* read */
        uint16_t h = c->r[CPU_BX], n = c->r[CPU_CX];
        uint16_t off = c->r[CPU_DX], seg = c->s[CPU_DS];
        size_t got = 0;
        if (h >= VM_MAX_FILES || !v->files[h].used) { dos_err(c, DOSERR_INVALID_HANDLE); break; }
        if (v->files[h].is_device) { c->r[CPU_AX] = 0; dos_ok(c); break; }
        {
            /* Read via a bounce buffer, then copy byte-wise so that a read
             * straddling the 64 KB segment boundary wraps like real hardware. */
            uint8_t *tmp = (uint8_t *)malloc(n ? n : 1);
            if (!tmp) { dos_err(c, DOSERR_INSUFFICIENT_MEM); break; }
            got = fread(tmp, 1, n, v->files[h].fp);
            for (size_t i = 0; i < got; i++)
                seg_w8(seg, (uint16_t)(off + i), tmp[i]);
            free(tmp);
        }
        /* Overlay provenance: note which payload offset landed where. */
        if ((int)h == v->ovl_handle && got > 0) {
            long pos = ftell(v->files[h].fp);
            uint32_t start = (uint32_t)(pos - (long)got);
            vm_note_overlay_load(v, start, (uint32_t)got, seg, off);
        }

        c->r[CPU_AX] = (uint16_t)got;
        dos_ok(c);
        break;
    }

    case 0x40: { /* write */
        uint16_t h = c->r[CPU_BX], n = c->r[CPU_CX];
        uint16_t off = c->r[CPU_DX], seg = c->s[CPU_DS];
        if (h >= VM_MAX_FILES || !v->files[h].used) { dos_err(c, DOSERR_INVALID_HANDLE); break; }
        if (v->files[h].is_device) {
            if (v->cfg.trace_dos)
                fprintf(stderr, "[dos] write %u bytes to DEVICE handle %u\n", n, h);
            else
                for (uint16_t i = 0; i < n; i++)
                    fputc(seg_r8(seg, (uint16_t)(off + i)), stderr);
            c->r[CPU_AX] = n;
            dos_ok(c);
            break;
        }
        {
            uint8_t *tmp = (uint8_t *)malloc(n ? n : 1);
            size_t put;
            if (!tmp) { dos_err(c, DOSERR_INSUFFICIENT_MEM); break; }
            for (uint16_t i = 0; i < n; i++) tmp[i] = seg_r8(seg, (uint16_t)(off + i));
            put = fwrite(tmp, 1, n, v->files[h].fp);
            free(tmp);
            c->r[CPU_AX] = (uint16_t)put;
        }
        dos_ok(c);
        break;
    }

    case 0x42: { /* lseek */
        uint16_t h = c->r[CPU_BX];
        uint8_t whence = cpu_get_r8(c, CPU_AL);
        long offset = (long)(((uint32_t)c->r[CPU_CX] << 16) | c->r[CPU_DX]);
        long pos;
        if (h >= VM_MAX_FILES || !v->files[h].used || v->files[h].is_device) {
            dos_err(c, DOSERR_INVALID_HANDLE); break;
        }
        fseek(v->files[h].fp, offset,
              (whence == 1) ? SEEK_CUR : (whence == 2) ? SEEK_END : SEEK_SET);
        pos = ftell(v->files[h].fp);
        c->r[CPU_AX] = (uint16_t)(pos & 0xFFFF);
        c->r[CPU_DX] = (uint16_t)((uint32_t)pos >> 16);
        dos_ok(c);
        break;
    }

    case 0x41: { /* delete */
        char dos_path[256], host[512];
        dos_read_cstr(c->s[CPU_DS], c->r[CPU_DX], dos_path, sizeof(dos_path));
        if (resolve_path(v, dos_path, host, sizeof(host), false)) remove(host);
        dos_ok(c);
        break;
    }

    case 0x44:  /* IOCTL get device info */
        if (cpu_get_r8(c, CPU_AL) == 0) {
            uint16_t h = c->r[CPU_BX];
            if (h < VM_MAX_FILES && v->files[h].used && v->files[h].is_device)
                c->r[CPU_DX] = 0x80D3;   /* character device, console */
            else
                c->r[CPU_DX] = 0x0002;   /* block device, drive C: */
            dos_ok(c);
        } else {
            trap_unimplemented(v, "INT 21h IOCTL subfunction", 0x21, ah);
        }
        break;

    case 0x48: { /* allocate memory */
        uint16_t largest = 0, err = 0;
        uint16_t seg = mcb_alloc(&v->arena, c->r[CPU_BX], v->psp_seg, &largest, &err);
        if (!seg) {
            c->r[CPU_BX] = largest;     /* both CRT and RTLink branch on this */
            dos_err(c, err);
        } else {
            c->r[CPU_AX] = seg;
            dos_ok(c);
        }
        break;
    }

    case 0x49: { /* free memory */
        uint16_t e = mcb_free(&v->arena, c->s[CPU_ES]);
        if (e) dos_err(c, e); else dos_ok(c);
        break;
    }

    case 0x4A: { /* resize memory block */
        uint16_t largest = 0;
        uint16_t e = mcb_resize(&v->arena, c->s[CPU_ES], c->r[CPU_BX], &largest);
        if (e) { c->r[CPU_BX] = largest; dos_err(c, e); }
        else   dos_ok(c);
        break;
    }

    case 0x4C:  /* terminate */
        v->exited = true;
        v->exit_code = cpu_get_r8(c, CPU_AL);
        c->fault = CPU_FAULT_EXITED;
        break;

    case 0x68:  /* commit file (fflush) */
    case 0x0D: { /* disk reset */
        uint16_t h = c->r[CPU_BX];
        if (ah == 0x68 && h < VM_MAX_FILES && v->files[h].used && v->files[h].fp)
            fflush(v->files[h].fp);
        dos_ok(c);
        break;
    }

    default:
        trap_unimplemented(v, "INT 21h function", 0x21, ah);
        break;
    }
}

/* ------------------------------------------------------------------ */
/* Other interrupts                                                     */
/* ------------------------------------------------------------------ */
static void svc_int10(vm *v) {
    cpu86 *c = &v->cpu;
    uint8_t ah = cpu_get_r8(c, CPU_AH);
    switch (ah) {
    case 0x00:  /* set video mode */
        fprintf(stderr, "[bios] INT 10h set mode %02X\n", cpu_get_r8(c, CPU_AL));
        seg_w8(VM_SEG_BDA, 0x49, cpu_get_r8(c, CPU_AL));
        break;
    case 0x0F:  /* get video mode */
        cpu_set_r8(c, CPU_AL, seg_r8(VM_SEG_BDA, 0x49));
        cpu_set_r8(c, CPU_AH, 40);
        cpu_set_r8(c, CPU_BH, 0);
        break;
    case 0x01:  /* set cursor shape */
        break;

    case 0x02:  /* set cursor position */
        seg_w8(VM_SEG_BDA, (uint16_t)(0x50 + (cpu_get_r8(c, CPU_BH) & 7) * 2),
               cpu_get_r8(c, CPU_DL));
        seg_w8(VM_SEG_BDA, (uint16_t)(0x51 + (cpu_get_r8(c, CPU_BH) & 7) * 2),
               cpu_get_r8(c, CPU_DH));
        break;

    case 0x03: {  /* get cursor position and shape */
        uint8_t page = (uint8_t)(cpu_get_r8(c, CPU_BH) & 7);
        cpu_set_r8(c, CPU_DL, seg_r8(VM_SEG_BDA, (uint16_t)(0x50 + page * 2)));
        cpu_set_r8(c, CPU_DH, seg_r8(VM_SEG_BDA, (uint16_t)(0x51 + page * 2)));
        c->r[CPU_CX] = 0x0607;   /* a conventional underline cursor */
        break;
    }

    case 0x05:  /* set active display page */
        seg_w8(VM_SEG_BDA, 0x62, cpu_get_r8(c, CPU_AL));
        break;

    case 0x06: case 0x07:  /* scroll window up / down */
    case 0x09: case 0x0A:  /* write character (+attribute) at cursor */
    case 0x0E:             /* teletype output */
        break;

    case 0x08:  /* read character and attribute at cursor */
        c->r[CPU_AX] = 0x0720;   /* space, normal attribute */
        break;

    case 0x0B:  /* set colour palette / border */
    case 0x10:  /* palette register services (we watch the DAC ports) */
    case 0x12:  /* video subsystem configuration */
        break;

    case 0x1A:  /* get/set display combination code: VGA + colour monitor */
        cpu_set_r8(c, CPU_AL, 0x1A);
        cpu_set_r8(c, CPU_BL, 0x08);
        cpu_set_r8(c, CPU_BH, 0x00);
        break;
    default:
        trap_unimplemented(v, "INT 10h function", 0x10, ah);
        break;
    }
}

static void svc_int16(vm *v) {
    cpu86 *c = &v->cpu;
    uint8_t ah = cpu_get_r8(c, CPU_AH);
    uint16_t key;

    switch (ah) {
    case 0x00: case 0x10:  /* read keystroke, blocking */
        if (keyq_pop(v, &key)) {
            c->r[CPU_AX] = key;
        } else {
            /* Nothing queued. Rewind so the INT re-executes, and end the
             * slice so the host can deliver input -- this is a real block,
             * not a fabricated keystroke. */
            dos_block_retry(v);
        }
        break;

    case 0x01: case 0x11:  /* peek: ZF=1 means no key available */
        if (keyq_peek(v, &key)) {
            c->r[CPU_AX] = key;
            c->flags &= (uint16_t)~F_ZF;
        } else {
            c->flags |= F_ZF;
            v->idle_polls++;
        }
        break;

    case 0x02: case 0x12:  /* shift flag status */
        cpu_set_r8(c, CPU_AL, 0);
        cpu_set_r8(c, CPU_AH, 0);
        break;

    case 0x03: case 0x05:  /* set repeat rate / push keystroke */
        break;

    default:
        trap_unimplemented(v, "INT 16h function", 0x16, ah);
        break;
    }
}

static void svc_int33(vm *v) {
    cpu86 *c = &v->cpu;
    uint16_t ax = c->r[CPU_AX];

    if (v->cfg.trace_dos)
        fprintf(stderr, "[mouse] AX=%04X from %04X:%04X buttons=%d\n",
                ax, c->last_int_cs, c->last_int_ip, v->mouse_buttons);

    /*
     * Coordinates. The driver reports a virtual 640x200 space in mode 13h,
     * so the horizontal value is doubled; the game halves it again. Getting
     * this backwards puts every click at half or double the intended x.
     */
    switch (ax) {
    case 0x0000:  /* reset and detect */
        v->mouse_visible = false;
        v->mouse_min_x = 0; v->mouse_max_x = 319;
        v->mouse_min_y = 0; v->mouse_max_y = 199;
        v->mouse_x = 160; v->mouse_y = 100;
        v->mouse_buttons = 0;
        memset(v->press_count, 0, sizeof(v->press_count));
        memset(v->release_count, 0, sizeof(v->release_count));
        c->r[CPU_AX] = 0xFFFF;   /* driver installed */
        c->r[CPU_BX] = 2;        /* two buttons      */
        break;

    case 0x0001: v->mouse_visible = true;  break;
    case 0x0002: v->mouse_visible = false; break;

    case 0x0003:  /* get position and button state */
        c->r[CPU_BX] = (uint16_t)v->mouse_buttons;
        c->r[CPU_CX] = (uint16_t)(v->mouse_x * 2);
        c->r[CPU_DX] = (uint16_t)v->mouse_y;
        v->idle_polls++;
        break;

    case 0x0004:  /* set position */
        v->mouse_x = clampi((int)c->r[CPU_CX] / 2, v->mouse_min_x, v->mouse_max_x);
        v->mouse_y = clampi((int)c->r[CPU_DX],     v->mouse_min_y, v->mouse_max_y);
        break;

    case 0x0005: { /* button press information since the last call */
        int b = c->r[CPU_BX] & 3;
        if (b > 2) b = 0;
        c->r[CPU_AX] = (uint16_t)v->mouse_buttons;
        c->r[CPU_BX] = (uint16_t)v->press_count[b];
        c->r[CPU_CX] = (uint16_t)(v->press_x[b] * 2);
        c->r[CPU_DX] = (uint16_t)v->press_y[b];
        v->press_count[b] = 0;
        break;
    }

    case 0x0006: { /* button release information since the last call */
        int b = c->r[CPU_BX] & 3;
        if (b > 2) b = 0;
        c->r[CPU_AX] = (uint16_t)v->mouse_buttons;
        c->r[CPU_BX] = (uint16_t)v->release_count[b];
        c->r[CPU_CX] = (uint16_t)(v->release_x[b] * 2);
        c->r[CPU_DX] = (uint16_t)v->release_y[b];
        v->release_count[b] = 0;
        break;
    }

    case 0x0007:  /* set horizontal range (virtual coordinates) */
        v->mouse_min_x = clampi((int)c->r[CPU_CX] / 2, 0, 319);
        v->mouse_max_x = clampi((int)c->r[CPU_DX] / 2, 0, 319);
        if (v->mouse_min_x > v->mouse_max_x) {
            int t = v->mouse_min_x; v->mouse_min_x = v->mouse_max_x; v->mouse_max_x = t;
        }
        v->mouse_x = clampi(v->mouse_x, v->mouse_min_x, v->mouse_max_x);
        break;

    case 0x0008:  /* set vertical range */
        v->mouse_min_y = clampi((int)c->r[CPU_CX], 0, 199);
        v->mouse_max_y = clampi((int)c->r[CPU_DX], 0, 199);
        if (v->mouse_min_y > v->mouse_max_y) {
            int t = v->mouse_min_y; v->mouse_min_y = v->mouse_max_y; v->mouse_max_y = t;
        }
        v->mouse_y = clampi(v->mouse_y, v->mouse_min_y, v->mouse_max_y);
        break;

    case 0x000C:  /* install event handler: mask in CX, handler in ES:DX */
        v->m33_mask        = c->r[CPU_CX];
        v->m33_handler_seg = c->s[CPU_ES];
        v->m33_handler_off = c->r[CPU_DX];
        break;

    case 0x0009:  /* define graphics cursor shape — the game draws its own */
    case 0x000A:  /* define text cursor */
    case 0x000D: case 0x000E:   /* light pen on/off */
    case 0x0010:  /* set exclusion area */
    case 0x0012: case 0x0013:
    case 0x001C: case 0x001D: case 0x001E:
        break;

    case 0x000B:  /* read motion counters, in mickeys, and clear them */
        c->r[CPU_CX] = (uint16_t)(int16_t)v->mickey_dx;
        c->r[CPU_DX] = (uint16_t)(int16_t)v->mickey_dy;
        v->mickey_dx = 0;
        v->mickey_dy = 0;
        break;

    case 0x000F:  /* set mickeys per 8 pixels */
        break;

    case 0x0014: { /* swap event handlers: install new, return the old */
        uint16_t old_mask = v->m33_mask;
        uint16_t old_seg  = v->m33_handler_seg;
        uint16_t old_off  = v->m33_handler_off;
        v->m33_mask        = c->r[CPU_CX];
        v->m33_handler_seg = c->s[CPU_ES];
        v->m33_handler_off = c->r[CPU_DX];
        c->r[CPU_CX] = old_mask;
        c->s[CPU_ES] = old_seg;
        c->r[CPU_DX] = old_off;
        if (v->cfg.trace_dos)
            fprintf(stderr, "[mouse] handler installed at %04X:%04X mask %04X\n",
                    v->m33_handler_seg, v->m33_handler_off, v->m33_mask);
        break;
    }

    case 0x0020:  /* disable driver */
        c->r[CPU_AX] = 0x001F;
        break;
    case 0x0021:  /* software reset */
        c->r[CPU_AX] = 0xFFFF;
        c->r[CPU_BX] = 2;
        break;

    default:
        trap_unimplemented(v, "INT 33h function", 0x33, ax);
        break;
    }
}

/* ------------------------------------------------------------------ */
/* INT 33h event callbacks                                             */
/*                                                                     */
/* The game installs a handler with AX=0014h and never polls for mouse */
/* movement, so nothing happens on screen until the driver calls it.   */
/*                                                                     */
/* A real mouse driver invokes the handler from its hardware interrupt */
/* with a FAR CALL, having saved the interrupted program's registers.  */
/* We do exactly that: save state, set the documented callback         */
/* registers, push a return address pointing at a dedicated trampoline */
/* slot, and jump. When the handler executes its RETF it lands on that */
/* slot's HLT, and the host restores the interrupted state. No nested  */
/* interpreter, and the guest cannot tell the difference.              */
/* ------------------------------------------------------------------ */
static void m33_dispatch(vm *v) {
    cpu86 *c = &v->cpu;
    uint16_t cond = v->m33_pending;

    if (!cond || v->m33_in_callback) return;
    if (!v->m33_handler_seg && !v->m33_handler_off) return;

    v->m33_pending = 0;
    v->m33_in_callback = true;

    memcpy(v->m33_saved.r, c->r, sizeof(c->r));
    memcpy(v->m33_saved.s, c->s, sizeof(c->s));
    v->m33_saved.ip    = c->ip;
    v->m33_saved.flags = c->flags;

    /* Return address for the handler's RETF. */
    cpu86_push16(c, VM_SEG_TRAMP);
    cpu86_push16(c, VM_TRAMP_MOUSE_RET);

    c->r[CPU_AX] = cond;
    c->r[CPU_BX] = (uint16_t)v->mouse_buttons;
    c->r[CPU_CX] = (uint16_t)(v->mouse_x * 2);   /* virtual 640-wide space */
    c->r[CPU_DX] = (uint16_t)v->mouse_y;
    c->r[CPU_SI] = (uint16_t)(int16_t)v->mickey_dx;
    c->r[CPU_DI] = (uint16_t)(int16_t)v->mickey_dy;

    c->s[CPU_CS] = v->m33_handler_seg;
    c->ip        = v->m33_handler_off;
    v->m33_calls++;
    if (v->cfg.trace_dos)
        fprintf(stderr, "[mouse] callback cond=%04X buttons=%04X at %d,%d\n",
                cond, (unsigned)v->mouse_buttons, v->mouse_x, v->mouse_y);
}

static void m33_return(vm *v) {
    cpu86 *c = &v->cpu;
    memcpy(c->r, v->m33_saved.r, sizeof(c->r));
    memcpy(c->s, v->m33_saved.s, sizeof(c->s));
    c->ip    = v->m33_saved.ip;
    c->flags = v->m33_saved.flags;
    v->m33_in_callback = false;
}

/* ------------------------------------------------------------------ */
/* Trampoline dispatch                                                 */
/* ------------------------------------------------------------------ */
static bool on_hlt(cpu86 *c, uint32_t lin) {
    vm *v = g_vm;
    uint32_t base = (uint32_t)VM_SEG_TRAMP * 16u;
    uint32_t vec;

    if (!v) return false;

    if (lin == base + VM_TRAMP_MOUSE_RET) {
        m33_return(v);
        return true;    /* CS:IP restored; do not fall through to the IRET */
    }

    if (lin < base || lin >= base + VM_TRAMP_SLOTS * 16u) {
        return false;   /* a genuine HLT in guest code */
    }
    vec = (lin - base) / 16u;
    v->int_counts[vec & 0xFF]++;

    if (v->cfg.trace_int) {
        fprintf(stderr, "[int] %02X  AX=%04X BX=%04X CX=%04X DX=%04X @%04X:%04X\n",
                (unsigned)vec, c->r[CPU_AX], c->r[CPU_BX], c->r[CPU_CX],
                c->r[CPU_DX], c->s[CPU_CS], c->ip);
    }

    /*
     * Capture the flags the service will modify.
     *
     * The trampoline ends in IRET, which restores FLAGS from the stack -- so
     * anything a service writes to the live flags register is discarded the
     * instant it returns. DOS and BIOS services report status in CF and ZF,
     * so this silently threw away every error code and every "no key
     * available" answer. The retail keyboard check is
     * `call peek; jz no_key; call getkey`, and with ZF lost it took whatever
     * the interrupted code happened to leave there -- so it called the
     * blocking getkey with an empty queue and hung.
     *
     * Real handlers modify the FLAGS image on the stack, and so must we.
     */
    {
        uint16_t saved = seg_r16(c->s[CPU_SS], (uint16_t)(c->r[CPU_SP] + 4));
        v->svc_flags_slot_valid = true;
        v->svc_saved_flags = saved;
    }

    switch (vec) {
    case 0x21: svc_int21(v); break;
    case 0x10: svc_int10(v); break;
    case 0x16: svc_int16(v); break;
    case 0x33: svc_int33(v); break;

    case 0x20:  /* terminate program */
        v->exited = true;
        v->exit_code = 0;
        c->fault = CPU_FAULT_EXITED;
        break;

    case 0x08:  /* timer tick: bump the BDA counter and chain to INT 1Ch */
        {
            uint32_t t = ((uint32_t)seg_r16(VM_SEG_BDA, 0x6E) << 16)
                       |  seg_r16(VM_SEG_BDA, 0x6C);
            t++;
            seg_w16(VM_SEG_BDA, 0x6C, (uint16_t)(t & 0xFFFF));
            seg_w16(VM_SEG_BDA, 0x6E, (uint16_t)(t >> 16));
        }
        break;

    case 0x1C:  /* user timer tick: nothing by default */
    case 0x23:  /* ctrl-break */
    case 0x28:  /* DOS idle */
        break;

    case 0x24:  /* critical error: fail the call */
        cpu_set_r8(c, CPU_AL, 3);
        break;

    case 0x67:
        /*
         * EMS. Deliberately NOT provided in Stage 1: the picture allocator
         * has a conventional-memory fallback that every EMS-less 1993 machine
         * exercised, and our memory map is more generous than a typical DOS 6
         * box. If "[retail bytes removed]" ever appears, this
         * is the switch to flip.
         */
        cpu_set_r8(c, CPU_AH, 0x84);   /* EMM not installed */
        break;

    default:
        {
            char buf[64];
            snprintf(buf, sizeof(buf), "INT %02Xh (no handler installed)", (unsigned)vec);
            trap_unimplemented(v, buf, (uint8_t)vec, cpu_get_r8(c, CPU_AH));
        }
        break;
    }

    /*
     * Write the status flags back into the stack image the IRET will restore.
     * Only the arithmetic/status bits: IF, TF and DF belong to the
     * interrupted code, and clobbering IF here would disable interrupts on
     * return.
     */
    if (v->svc_flags_slot_valid) {
        const uint16_t status = F_CF | F_PF | F_AF | F_ZF | F_SF | F_OF;
        uint16_t merged = (uint16_t)((v->svc_saved_flags & ~status)
                                   | (c->flags & status));
        seg_w16(c->s[CPU_SS], (uint16_t)(c->r[CPU_SP] + 4), merged);
        v->svc_flags_slot_valid = false;
    }
    return true;
}

/* ------------------------------------------------------------------ */
/* 8253 programmable interval timer, channel 0                          */
/*                                                                      */
/* The counter is derived from the virtual clock rather than counted    */
/* down step by step: it is read far less often than it would tick, and */
/* deriving it keeps it exact and deterministic.                        */
/* ------------------------------------------------------------------ */
#define PIT_HZ 1193182ull

static uint32_t pit0_divisor(const vm *v) {
    return v->pit0.divisor ? v->pit0.divisor : 65536u;
}

static uint16_t pit0_counter(const vm *v) {
    uint32_t div = pit0_divisor(v);
    uint64_t ticks = (v->cpu.cycles * PIT_HZ) / (v->cycles_per_second
                                                 ? v->cycles_per_second : 1);
    return (uint16_t)(div - (uint32_t)(ticks % div));
}

/* Recompute the interrupt period after the guest reprograms the divisor. */
static void pit0_reprogram(vm *v) {
    uint64_t period = ((uint64_t)pit0_divisor(v) * v->cycles_per_second) / PIT_HZ;
    if (period < 1000) period = 1000;   /* refuse an absurd interrupt storm */
    v->pit_period_cycles = period;
    v->next_tick_cycles  = v->cpu.cycles + period;
}

/*
 * RealSound (the "real" device) plays a loaded .RS buffer from a timer ISR
 * by writing each sample byte to PIT channel 2 (port 0x42). The byte is a
 * pulse width, not an unsigned DAC code — retail payloads such as PHONE.RS
 * sit in 0..61. One port write is one sample: a phone ring produces as many
 * writes as the file has payload bytes. The ISR's repeat count is patched
 * per effect and is 1 for that ring, so the writes are not decimated.
 */
static uint8_t rs_pwm_to_pcm(uint8_t sample) {
    int pcm;
    if (sample > 96) return sample;          /* already a full-range code */
    pcm = 128 + ((int)sample - 31) * 4;
    if (pcm < 0) pcm = 0;
    if (pcm > 255) pcm = 255;
    return (uint8_t)pcm;
}

static void rs_flush(vm *v) {
    uint32_t div, rate;
    if (!v->rs_batch_n) return;
    if (!vm_audio_dma_write) { v->rs_batch_n = 0; return; }
    div = pit0_divisor(v);
    rate = (uint32_t)(PIT_HZ / (div ? div : 1u));
    if (rate < 200 || rate > 80000) rate = 16572;   /* divisor 0x48 */
    vm_audio_dma_write(v->rs_batch, v->rs_batch_n, rate);
    v->rs_batch_n = 0;
}

/* ------------------------------------------------------------------ */
/* Sound Blaster DSP                                                    */
/* ------------------------------------------------------------------ */
static void sb_out_push(vm *v, uint8_t val) {
    int next = (v->sb.out_head + 1) % 16;
    if (next == v->sb.out_tail) return;
    v->sb.out_queue[v->sb.out_head] = val;
    v->sb.out_head = next;
}

static bool sb_out_empty(const vm *v) {
    return v->sb.out_head == v->sb.out_tail;
}

static uint8_t sb_out_pop(vm *v) {
    uint8_t val;
    if (sb_out_empty(v)) return 0xFF;
    val = v->sb.out_queue[v->sb.out_tail];
    v->sb.out_tail = (v->sb.out_tail + 1) % 16;
    return val;
}

static void sb_reset_write(vm *v, uint8_t val) {
    if (val & 1) {
        v->sb.reset_state = 1;               /* held in reset */
    } else if (v->sb.reset_state == 1) {
        /* Released: the DSP announces itself with 0xAA. */
        v->sb.reset_state = 0;
        v->sb.out_head = v->sb.out_tail = 0;
        v->sb.cmd_args_needed = 0;
        v->sb.dma_active = false;
        v->sb.auto_init = false;
        v->sb.block_size = 0;
        sb_out_push(v, 0xAA);
    }
}

static bool sb_trace_enabled(void) {
    static int cached = -1;
    if (cached < 0) {
        const char *e = getenv("XANTH_SB_TRACE");
        cached = (e && *e && *e != '0') ? 1 : 0;
    }
    return cached == 1;
}

static void sb_dma_stream(vm *v, uint32_t phys_addr, uint32_t dma_len) {
    uint32_t cur_addr = phys_addr & 0xFFFFu;
    uint32_t page = (phys_addr >> 16) & 0x0Fu;
    uint32_t first_len = dma_len;
    uint32_t rate = v->sb.sample_rate ? v->sb.sample_rate : 11025;
    uint8_t *wrapped;

    if (!vm_audio_dma_write || dma_len == 0) return;
    if (first_len > 0x10000u - cur_addr) first_len = 0x10000u - cur_addr;
    if (phys_addr + first_len > 0x100000u) return;
    if (first_len == dma_len) {
        vm_audio_dma_write(g_dos_mem + phys_addr, dma_len, rate);
        return;
    }

    /* The 8237 channel address is 16-bit; the page register does not carry
     * when that address wraps. Present both guest spans as one sample block. */
    wrapped = (uint8_t *)malloc(dma_len);
    if (!wrapped) return;
    memcpy(wrapped, g_dos_mem + phys_addr, first_len);
    memcpy(wrapped + first_len, g_dos_mem + (page << 16), dma_len - first_len);
    vm_audio_dma_write(wrapped, dma_len, rate);
    free(wrapped);
}

static void sb_dma_transfer(vm *v, uint32_t dma_len) {
    uint32_t cur_addr = v->dma.cur_addr[1];
    uint32_t page = (uint32_t)(v->dma.page[1] & 0x0F);
    uint32_t phys_addr = (page << 16) | cur_addr;
    v->sb.dma_base_phys = phys_addr;
    sb_dma_stream(v, phys_addr, dma_len);
    v->sb.dma_transferred_bytes += dma_len;
    if (!v->sb.auto_init) {
        v->dma.cur_addr[1] = (uint16_t)(v->dma.cur_addr[1] + dma_len);
    }
    v->dma.cur_count[1] = 0xFFFF;
    uint64_t rate = v->sb.sample_rate ? v->sb.sample_rate : 11025;
    uint64_t cps = v->cycles_per_second ? v->cycles_per_second : 10000000ULL;
    uint64_t dma_cycles = (uint64_t)dma_len * cps / rate;
    if (dma_cycles == 0) dma_cycles = 1;
    v->sb.dma_active = true;
    v->sb.dma_end_cycles = v->cpu.cycles + dma_cycles;
}

static void sb_execute_cmd(vm *v) {
    if (sb_trace_enabled()) {
        fprintf(stderr, "[sb] cmd %02X args %02X %02X (rate %u)\n",
                v->sb.last_cmd, v->sb.cmd_args[0], v->sb.cmd_args[1],
                v->sb.sample_rate);
    }
    switch (v->sb.last_cmd) {
    case 0xE0: /* DSP identify: invert argument */
        sb_out_push(v, (uint8_t)(~v->sb.cmd_args[0]));
        break;
    case 0x10: { /* Direct DAC output: single 8-bit sample */
        uint8_t sample = v->sb.cmd_args[0];
        uint32_t rate = v->sb.sample_rate ? v->sb.sample_rate : 11025;
        if (vm_audio_dma_write) {
            vm_audio_dma_write(&sample, 1, rate);
        }
        v->sb.dma_transferred_bytes += 1;
        break;
    }
    case 0x40: { /* Set time constant */
        v->sb.time_constant = v->sb.cmd_args[0];
        uint32_t div = 256 - (uint32_t)v->sb.cmd_args[0];
        v->sb.sample_rate = div ? (1000000 / div) : 11025;
        break;
    }
    case 0x14: case 0x24: case 0x91: { /* 8-bit DMA single-cycle output */
        uint16_t len_raw = (uint16_t)(v->sb.cmd_args[0] | ((uint16_t)v->sb.cmd_args[1] << 8));
        uint32_t dma_len = (uint32_t)len_raw + 1;
        v->sb.auto_init = false;
        sb_dma_transfer(v, dma_len);
        break;
    }
    case 0x48: { /* Set auto-init block size */
        uint16_t len_raw = (uint16_t)(v->sb.cmd_args[0] | ((uint16_t)v->sb.cmd_args[1] << 8));
        v->sb.block_size = (uint32_t)len_raw + 1;
        break;
    }
    case 0x1C: case 0x2C: case 0x90: { /* auto-init DMA start */
        if (v->sb.block_size) {
            v->sb.auto_init = true;
            sb_dma_transfer(v, v->sb.block_size);
        }
        break;
    }
    default:
        break;
    }
}

static void sb_command(vm *v, uint8_t val) {
    if (v->sb.cmd_args_needed > 0) {
        if (v->sb.cmd_args_got < 4) v->sb.cmd_args[v->sb.cmd_args_got] = val;
        v->sb.cmd_args_got++;
        if (v->sb.cmd_args_got >= v->sb.cmd_args_needed) {
            v->sb.cmd_args_needed = 0;
            sb_execute_cmd(v);
        }
        return;
    }

    v->sb.last_cmd = val;
    v->sb.cmd_args_got = 0;

    switch (val) {
    case 0xD1: v->sb.speaker_on = true;  break;
    case 0xD3: v->sb.speaker_on = false; break;
    case 0xE1:               /* get DSP version: report 2.01 */
        sb_out_push(v, 2);
        sb_out_push(v, 1);
        break;
    case 0xE0: v->sb.cmd_args_needed = 1; break;   /* DSP identify */
    case 0x40: v->sb.cmd_args_needed = 1; break;   /* set time constant */
    case 0x14: case 0x24: case 0x91:
        v->sb.cmd_args_needed = 2; break;          /* single-cycle DMA length */
    case 0x48:
        v->sb.cmd_args_needed = 2; break;          /* set block size */
    case 0x1C: case 0x2C: case 0x90:
        sb_execute_cmd(v); break;                  /* auto-init DMA start */
    case 0xD0:
        v->sb.dma_active = false;                  /* pause DMA */
        break;
    case 0xD9: case 0xDA:
        v->sb.dma_active = false;                  /* halt DMA / exit auto-init */
        v->sb.auto_init = false;
        break;
    case 0xD4:
        v->sb.dma_active = true;                   /* continue DMA */
        break;
    case 0x10:
        v->sb.cmd_args_needed = 1; break;          /* direct DAC: 1 sample byte follows */
    default:
        if (sb_trace_enabled()) {
            fprintf(stderr, "[sb] unhandled cmd %02X\n", val);
        }
        break;
    }
}

/* ------------------------------------------------------------------ */
/* Port I/O                                                            */
/* ------------------------------------------------------------------ */
static uint8_t vm_in8(cpu86 *c, uint16_t port) {
    vm *v = g_vm;
    (void)c;
    if (!v) return 0xFF;

    switch (port) {
    case 0x00: case 0x02: case 0x04: case 0x06: {
        /* DMA channels 0..3 current address */
        uint8_t ch = (uint8_t)(port >> 1);
        uint8_t res;
        if (!v->dma.flip_flop) {
            res = (uint8_t)(v->dma.cur_addr[ch] & 0xFF);
            v->dma.flip_flop = 1;
        } else {
            res = (uint8_t)(v->dma.cur_addr[ch] >> 8);
            v->dma.flip_flop = 0;
        }
        return res;
    }
    case 0x01: case 0x03: case 0x05: case 0x07: {
        /* DMA channels 0..3 current word count */
        uint8_t ch = (uint8_t)((port - 1) >> 1);
        uint8_t res;
        if (!v->dma.flip_flop) {
            res = (uint8_t)(v->dma.cur_count[ch] & 0xFF);
            v->dma.flip_flop = 1;
        } else {
            res = (uint8_t)(v->dma.cur_count[ch] >> 8);
            v->dma.flip_flop = 0;
        }
        return res;
    }
    case 0x08: return 0x00; /* DMA status register */
    case 0x0A: return v->dma.mask;
    case 0x0C:
        v->dma.flip_flop = 0;
        return 0x00;
    case 0x87: return v->dma.page[0];
    case 0x83: return v->dma.page[1]; /* Ch 1 page */
    case 0x81: return v->dma.page[2];
    case 0x82: return v->dma.page[3];

    case 0x20: return v->pic.isr;
    case 0x21: return v->pic.imr;
    case 0x61: return v->speaker_port;

    case 0x3DA: {
        /* Synthesise a retrace bit that CHANGES OVER TIME. */
        static uint32_t tick;
        tick++;
        return (uint8_t)((tick & 7) < 2 ? 0x09 : 0x00);
    }

    case 0x40: {  /* PIT channel 0 counter read */
        uint16_t value = v->pit0.latched ? v->pit0.latch : pit0_counter(v);
        if (v->pit0.access == 1) {          /* low byte only */
            v->pit0.latched = false;
            return (uint8_t)(value & 0xFF);
        }
        if (v->pit0.access == 2) {          /* high byte only */
            v->pit0.latched = false;
            return (uint8_t)(value >> 8);
        }
        if (!v->pit0.read_hi) {             /* lo then hi */
            v->pit0.read_hi = 1;
            return (uint8_t)(value & 0xFF);
        }
        v->pit0.read_hi = 0;
        v->pit0.latched = false;
        return (uint8_t)(value >> 8);
    }

    case 0x22A:   /* DSP read data */
        v->sb.accesses++;
        return sb_out_pop(v);

    case 0x22C:   /* DSP write-buffer status: bit 7 clear means "ready" */
        v->sb.accesses++;
        return 0x00;

    case 0x22E:   /* DSP read-buffer status & 8-bit IRQ acknowledge */
        v->sb.accesses++;
        v->sb.irq_pending = false;
        v->pic.irr &= (uint8_t)~(1 << v->sb.irq);
        return (uint8_t)(sb_out_empty(v) ? 0x00 : 0x80);

    case 0x22F:   /* DSP 16-bit IRQ acknowledge */
        v->sb.accesses++;
        v->sb.irq_pending = false;
        v->pic.irr &= (uint8_t)~(1 << v->sb.irq);
        return 0x00;

    case 0x330:
        return v->cfg.use_general_midi ? vm_audio_mpu_read_data() : 0xFF;
    case 0x331:
        return v->cfg.use_general_midi ? vm_audio_mpu_read_status() : 0xFF;

    case 0x388:
        return v->opl_status;

    case 0x389: return 0x00;
    default: return 0xFF;
    }
}

static uint16_t vm_in16(cpu86 *c, uint16_t port) {
    return (uint16_t)(vm_in8(c, port) | ((uint16_t)vm_in8(c, (uint16_t)(port + 1)) << 8));
}

static void vm_out8(cpu86 *c, uint16_t port, uint8_t val) {
    vm *v = g_vm;
    (void)c;
    if (!v) return;

    switch (port) {
    case 0x00: case 0x02: case 0x04: case 0x06: {
        /* DMA channels 0..3 base/current address */
        uint8_t ch = (uint8_t)(port >> 1);
        if (!v->dma.flip_flop) {
            v->dma.base_addr[ch] = (uint16_t)((v->dma.base_addr[ch] & 0xFF00) | val);
            v->dma.cur_addr[ch] = v->dma.base_addr[ch];
            v->dma.flip_flop = 1;
        } else {
            v->dma.base_addr[ch] = (uint16_t)((v->dma.base_addr[ch] & 0x00FF) | ((uint16_t)val << 8));
            v->dma.cur_addr[ch] = v->dma.base_addr[ch];
            v->dma.flip_flop = 0;
        }
        break;
    }
    case 0x01: case 0x03: case 0x05: case 0x07: {
        /* DMA channels 0..3 base/current word count */
        uint8_t ch = (uint8_t)((port - 1) >> 1);
        if (!v->dma.flip_flop) {
            v->dma.base_count[ch] = (uint16_t)((v->dma.base_count[ch] & 0xFF00) | val);
            v->dma.cur_count[ch] = v->dma.base_count[ch];
            v->dma.flip_flop = 1;
        } else {
            v->dma.base_count[ch] = (uint16_t)((v->dma.base_count[ch] & 0x00FF) | ((uint16_t)val << 8));
            v->dma.cur_count[ch] = v->dma.base_count[ch];
            v->dma.flip_flop = 0;
        }
        break;
    }
    case 0x0A: {
        /* DMA single channel mask register */
        uint8_t ch = val & 3;
        if (val & 4) {
            v->dma.mask |= (uint8_t)(1 << ch);
        } else {
            v->dma.mask &= (uint8_t)~(1 << ch);
        }
        break;
    }
    case 0x0B: {
        /* DMA mode register */
        uint8_t ch = val & 3;
        v->dma.mode[ch] = val;
        break;
    }
    case 0x0C:
        /* DMA clear byte pointer flip-flop */
        v->dma.flip_flop = 0;
        break;
    case 0x0F:
        /* DMA master mask register */
        v->dma.mask = (uint8_t)(val & 0x0F);
        break;
    case 0x87: v->dma.page[0] = val; break;
    case 0x83: v->dma.page[1] = val; break; /* Ch 1 page register */
    case 0x81: v->dma.page[2] = val; break;
    case 0x82: v->dma.page[3] = val; break;

    case 0x20:
        /* 8259 PIC command register */
        v->pic.last_cmd = val;
        if (val == 0x20) {
            /* Non-specific EOI: clear active IRQ from ISR */
            v->pic.isr &= (uint8_t)~(1 << v->sb.irq);
        }
        break;
    case 0x21:
        /* 8259 PIC Interrupt Mask Register */
        v->pic.imr = val;
        break;

    case 0x42:    /* PIT channel 2 reload: one RealSound sample. */
        if ((v->speaker_port & 3) == 3) {
            v->rs_pwm_writes++;
            v->rs_batch[v->rs_batch_n++] = rs_pwm_to_pcm(val);
            v->rs_samples++;
            if (v->rs_batch_n >= sizeof(v->rs_batch)) rs_flush(v);
        }
        break;

    case 0x61: {  /* PC speaker gate. RealSound enables timer-2 output with
                   * bits 0 and 1; the sample stream itself is port 0x42. */
        uint8_t prev = v->speaker_port;
        v->speaker_port = val;
        v->speaker_writes++;
        if ((prev & 3) == 3 && (val & 3) != 3) rs_flush(v);
        break;
    }

    case 0x226:   /* DSP reset */
        v->sb.accesses++;
        sb_reset_write(v, val);
        break;

    case 0x22C:   /* DSP command / data */
        v->sb.accesses++;
        sb_command(v, val);
        break;

    case 0x330:
        if (v->cfg.use_general_midi) vm_audio_mpu_write_data(val);
        break;
    case 0x331:
        if (v->cfg.use_general_midi) vm_audio_mpu_write_cmd(val);
        break;

    case 0x43: {  /* PIT mode / command */
        uint8_t channel = (uint8_t)(val >> 6);
        uint8_t access  = (uint8_t)((val >> 4) & 3);
        if (channel != 0) break;            /* only channel 0 matters here */
        if (access == 0) {
            /* Latch the current count for a stable two-byte read. */
            v->pit0.latch   = pit0_counter(v);
            v->pit0.latched = true;
            v->pit0.read_hi = 0;
        } else {
            v->pit0.access   = access;
            v->pit0.mode     = (uint8_t)((val >> 1) & 7);
            v->pit0.write_hi = 0;
            v->pit0.read_hi  = 0;
            v->pit0.latched  = false;
        }
        break;
    }

    case 0x40:    /* PIT channel 0 divisor */
        if (v->pit0.access == 1) {
            v->pit0.divisor = (uint16_t)((v->pit0.divisor & 0xFF00) | val);
            pit0_reprogram(v);
        } else if (v->pit0.access == 2) {
            v->pit0.divisor = (uint16_t)((v->pit0.divisor & 0x00FF) | (val << 8));
            pit0_reprogram(v);
        } else if (!v->pit0.write_hi) {
            v->pit0.divisor = (uint16_t)((v->pit0.divisor & 0xFF00) | val);
            v->pit0.write_hi = 1;
        } else {
            v->pit0.divisor = (uint16_t)((v->pit0.divisor & 0x00FF) | (val << 8));
            v->pit0.write_hi = 0;
            pit0_reprogram(v);
        }
        break;

    case 0x388:   /* AdLib / OPL2 register index */
        v->opl_index = val;
        break;

    case 0x389:   /* AdLib / OPL2 data */
        v->opl_writes++;
        if (v->opl_index == 0x04) {
            /* Timer control. Bit 7 resets the status flags; bits 0/1 start
             * timers 1/2; bits 5/6 mask them. */
            v->opl_timer_ctl = val;
            if (val & 0x80) {
                v->opl_status = 0x00;
            } else {
                uint8_t st = 0;
                if ((val & 0x01) && !(val & 0x40)) st |= 0x40;  /* timer 1 */
                if ((val & 0x02) && !(val & 0x20)) st |= 0x20;  /* timer 2 */
                if (st) st |= 0x80;                              /* IRQ flag */
                v->opl_status = st;
            }
        }
        vm_audio_opl_write(v->opl_index, val);
        break;

    case 0x3C8:   /* DAC write index */
        v->dac_index = val;
        v->dac_component = 0;
        break;
    case 0x3C7:   /* DAC read index */
        v->dac_index = val;
        v->dac_component = 0;
        break;
    case 0x3C9:   /* DAC data: three 6-bit components per entry */
        v->dac[v->dac_index * 3 + v->dac_component] = (uint8_t)(val & 0x3F);
        v->dac_writes++;
        if (++v->dac_component == 3) {
            v->dac_component = 0;
            v->dac_index++;          /* wraps at 256 naturally */
        }
        break;
    default:
        break;
    }
}

static void vm_out16(cpu86 *c, uint16_t port, uint16_t val) {
    vm_out8(c, port, (uint8_t)(val & 0xFF));
    vm_out8(c, (uint16_t)(port + 1), (uint8_t)(val >> 8));
}

/* ------------------------------------------------------------------ */
/* Setup                                                               */
/* ------------------------------------------------------------------ */
static void build_trampoline(void) {
    for (int i = 0; i < VM_TRAMP_SLOTS; i++) {
        uint16_t off = (uint16_t)(i * 16);
        seg_w8(VM_SEG_TRAMP, off,                 0xF4);  /* HLT  */
        seg_w8(VM_SEG_TRAMP, (uint16_t)(off + 1), 0xCF);  /* IRET */
        /* Point the matching IVT entry at this slot. */
        seg_w16(0, (uint16_t)(i * 4),     off);
        seg_w16(0, (uint16_t)(i * 4 + 2), VM_SEG_TRAMP);
    }

    /*
     * INT 08h is special: the real BIOS handler chains to INT 1Ch, and this
     * game installs its own INT 1Ch handler and drives all of its timing from
     * it. Rather than calling the guest's handler from C -- which would mean
     * re-entering the interpreter from inside a callback -- the stub simply
     * CONTAINS an `int 1Ch` instruction. The guest handler then runs as
     * ordinary interpreted code and its `iret` returns here naturally.
     *
     * This is the payoff from making the VM architectural: chaining needs no
     * special mechanism, just the right three bytes.
     */
    /* Return landing pad for INT 33h event callbacks. */
    seg_w8(VM_SEG_TRAMP, VM_TRAMP_MOUSE_RET, 0xF4);       /* HLT */

    {
        uint16_t off = 8 * 16;
        seg_w8(VM_SEG_TRAMP, off,                 0xF4);  /* HLT      */
        seg_w8(VM_SEG_TRAMP, (uint16_t)(off + 1), 0xCD);  /* INT 1Ch  */
        seg_w8(VM_SEG_TRAMP, (uint16_t)(off + 2), 0x1C);
        seg_w8(VM_SEG_TRAMP, (uint16_t)(off + 3), 0xCF);  /* IRET     */
    }
}

static void build_bda(void) {
    seg_w16(VM_SEG_BDA, 0x10, 0x0021);  /* equipment: VGA, one drive  */
    seg_w16(VM_SEG_BDA, 0x13, 640);     /* KB of conventional memory  */
    seg_w8 (VM_SEG_BDA, 0x49, 0x03);    /* current video mode         */
    seg_w16(VM_SEG_BDA, 0x4A, 80);      /* columns                    */
    seg_w16(VM_SEG_BDA, 0x63, 0x03D4);  /* CRTC base (so +6 == 0x3DA) */
    seg_w16(VM_SEG_BDA, 0x1A, 0x001E);  /* keyboard buffer head       */
    seg_w16(VM_SEG_BDA, 0x1C, 0x001E);  /* keyboard buffer tail       */
    seg_w16(VM_SEG_BDA, 0x80, 0x001E);  /* buffer start               */
    seg_w16(VM_SEG_BDA, 0x82, 0x003E);  /* buffer end                 */
}

static uint16_t build_environment(uint16_t seg, const char *exe_dos_path) {
    /* "PATH=C:\" NUL "COMSPEC=..." NUL NUL 0100 "C:\XANTH\XANTH.EXE" NUL */
    /* BLASTER is how a DOS machine advertises its Sound Blaster: base
     * address, IRQ, DMA channel, card type. Software that configures itself
     * from the environment rather than probing will not find a card without
     * it. Matches the ports the VM emulates. */
    static const char *vars[] = {
        "PATH=C:\\",
        "COMSPEC=C:\\COMMAND.COM",
        "TEMP=C:\\",
        "BLASTER=A220 I7 D1 T3",
    };
    uint16_t off = 0;
    for (size_t i = 0; i < sizeof(vars) / sizeof(vars[0]); i++) {
        for (const char *p = vars[i]; *p; p++) seg_w8(seg, off++, (uint8_t)*p);
        seg_w8(seg, off++, 0);
    }
    seg_w8(seg, off++, 0);              /* end of the variable block */
    seg_w16(seg, off, 1); off += 2;     /* one following string      */
    for (const char *p = exe_dos_path; *p; p++) seg_w8(seg, off++, (uint8_t)*p);
    seg_w8(seg, off++, 0);
    return off;
}

static bool ensure_save_directory(const char *path) {
    char tmp[512];
    size_t n;
    if (!path || !*path) return false;
    n=(size_t)snprintf(tmp,sizeof(tmp),"%s",path);
    if (n>=sizeof(tmp)) return false;
    for (char *p=tmp+1;*p;++p) {
        if (*p=='/' || *p=='\\') {
            char sep=*p;
            if (p==tmp+2 && tmp[1]==':') continue; /* Windows drive root */
            *p='\0';
            if (*tmp) (void)vm_mkdir(tmp);
            *p=sep;
        }
    }
    (void)vm_mkdir(tmp);
    return true;
}

static void build_psp(vm *v, uint16_t psp, uint16_t env, uint16_t top_seg) {
    for (int i = 0; i < 256; i++) seg_w8(psp, (uint16_t)i, 0);

    seg_w8 (psp, 0x00, 0xCD); seg_w8(psp, 0x01, 0x20);   /* INT 20h       */
    seg_w16(psp, 0x02, top_seg);                          /* top of memory */

    /* Far call to the DOS entry thunk. */
    seg_w8 (psp, 0x05, 0x9A);
    seg_w16(psp, 0x06, 0x0050);
    seg_w16(psp, 0x08, VM_SEG_TRAMP);

    seg_w16(psp, 0x0A, 0x0000); seg_w16(psp, 0x0C, VM_SEG_TRAMP); /* INT 22h */
    seg_w16(psp, 0x0E, 0x0000); seg_w16(psp, 0x10, VM_SEG_TRAMP); /* INT 23h */
    seg_w16(psp, 0x12, 0x0000); seg_w16(psp, 0x14, VM_SEG_TRAMP); /* INT 24h */
    seg_w16(psp, 0x16, psp);                                       /* parent  */

    /* Job file table: 0-2 -> CON, 3 -> AUX, 4 -> PRN, rest closed. */
    seg_w8(psp, 0x18, 1); seg_w8(psp, 0x19, 1); seg_w8(psp, 0x1A, 1);
    seg_w8(psp, 0x1B, 0); seg_w8(psp, 0x1C, 2);
    for (int i = 5; i < 20; i++) seg_w8(psp, (uint16_t)(0x18 + i), 0xFF);

    seg_w16(psp, 0x2C, env);            /* environment segment */
    seg_w16(psp, 0x32, 20);             /* JFT size            */
    seg_w16(psp, 0x34, 0x0018);
    seg_w16(psp, 0x36, psp);

    seg_w8 (psp, 0x50, 0xCD); seg_w8(psp, 0x51, 0x21); seg_w8(psp, 0x52, 0xCB);

    seg_w8 (psp, 0x80, 0);              /* empty command tail */
    seg_w8 (psp, 0x81, 0x0D);

    v->dta_seg = psp;
    v->dta_off = 0x80;
}

bool vm_init(vm *v, const vm_config *cfg, char *err, size_t errlen) {
    uint16_t env_seg, psp_seg, load_seg, image_paras, want_paras;
    uint16_t largest = 0, merr = 0;
    uint16_t block;

    memset(v, 0, sizeof(*v));
    v->cfg = *cfg;
    g_vm = v;

    v->sb.base = 0x220;
    v->sb.sample_rate = 11025;
    v->sb.irq = 7;
    v->sb.time_constant = (uint16_t)(256 - (1000000 / 11025));
    v->dma.mask = 0x0F;

    memset(g_dos_mem, 0, DOS_MEM_SIZE);

    cpu86_reset(&v->cpu);
    v->cpu.vm = v;

    cpu86_port_in8   = vm_in8;
    cpu86_port_in16  = vm_in16;
    cpu86_port_out8  = vm_out8;
    cpu86_port_out16 = vm_out16;
    cpu86_on_hlt     = on_hlt;

    v->prof = (uint32_t *)calloc(0x10000, sizeof(uint32_t));
    v->ovl_handle = -1;
    v->ovl_provenance = (int32_t *)malloc(VM_OVL_PARAS * sizeof(int32_t));
    if (v->ovl_provenance)
        for (int i = 0; i < VM_OVL_PARAS; i++) v->ovl_provenance[i] = -1;

    build_trampoline();
    build_bda();
    init_std_handles(v);
    if (!ensure_legend_ini(v)) {
        snprintf(err,errlen,"cannot configure LEGEND.INI for the selected General MIDI backend");
        return false;
    }

    mcb_init(&v->arena, VM_SEG_ARENA, VM_SEG_ARENA_END);

    /* Environment block. */
    block = mcb_alloc(&v->arena, 0x20, MCB_OWNER_DOS, &largest, &merr);
    if (!block) { snprintf(err, errlen, "cannot allocate environment block"); return false; }
    env_seg = block;
    build_environment(env_seg, "C:\\XANTH\\XANTH.EXE");

    /*
     * Program block. maxalloc is 0xFFFF, so a real DOS hands over every
     * remaining paragraph and the CRT shrinks it afterwards with AH=4Ah.
     * Reproduce that: ask for the largest free block.
     */
    {
        /* Size the image first so we can sanity-check the request. */
        mz_header_t h;
        FILE *f = fopen(cfg->exe_path, "rb");
        uint8_t head[64];
        size_t got;
        if (!f) { snprintf(err, errlen, "cannot open '%s'", cfg->exe_path); return false; }
        got = fread(head, 1, sizeof(head), f);
        fclose(f);
        if (got < 0x1C || !mz_parse_header(head, got, &h)) {
            snprintf(err, errlen, "'%s' is not an MZ image", cfg->exe_path);
            return false;
        }
        image_paras = (uint16_t)((h.image_size + 15) / 16);
        want_paras  = mcb_largest_free(&v->arena);
        if (want_paras < image_paras + h.minalloc + 0x10) {
            snprintf(err, errlen,
                     "not enough conventional memory: have %u paragraphs, "
                     "need at least %u", want_paras, image_paras + h.minalloc + 0x10);
            return false;
        }
    }

    block = mcb_alloc(&v->arena, want_paras, 0, &largest, &merr);
    if (!block) { snprintf(err, errlen, "cannot allocate the program block"); return false; }

    psp_seg  = block;
    load_seg = (uint16_t)(psp_seg + 0x10);
    v->psp_seg = psp_seg;
    v->env_seg = env_seg;

    /* The block is owned by its own PSP, as DOS arranges it. */
    seg_w16((uint16_t)(psp_seg - 1), 1, psp_seg);

    build_psp(v, psp_seg, env_seg, VM_SEG_ARENA_END);

    if (!mz_load_file(cfg->exe_path, load_seg, &v->img, err, errlen)) return false;

    v->cpu.s[CPU_CS] = v->img.entry_cs;
    v->cpu.ip        = v->img.entry_ip;
    v->cpu.s[CPU_SS] = v->img.entry_ss;
    v->cpu.r[CPU_SP] = v->img.entry_sp;
    v->cpu.s[CPU_DS] = psp_seg;
    v->cpu.s[CPU_ES] = psp_seg;
    v->cpu.r[CPU_AX] = 0;
    v->cpu.flags     = F_ALWAYS_SET | F_IF;

    /* 18.2 Hz against a nominal 4 MHz virtual clock, matching the PIT's
     * default divisor. The coarse cost model charges 4 cycles/instruction. */
    v->stub_key = ' ';
    v->mouse_min_x = 0; v->mouse_max_x = 319;
    v->mouse_min_y = 0; v->mouse_max_y = 199;
    v->mouse_x = 160;   v->mouse_y = 100;
    v->cycles_per_second  = 4000000;
    v->sb.base            = 0x220;
    v->pit0.divisor       = 0;       /* 65536: the default 18.2 Hz */
    v->pit0.access        = 3;
    v->pit_period_cycles  = (65536ull * v->cycles_per_second) / PIT_HZ;
    v->next_tick_cycles   = v->pit_period_cycles;

    fprintf(stderr,
        "[vm] loaded %s: image %u bytes at %04X, PSP %04X, env %04X\n"
        "[vm] entry %04X:%04X  stack %04X:%04X  program block %u paragraphs\n"
        "[vm] overlay region (load_seg + 30CBh) = %04X\n",
        cfg->exe_path, v->img.hdr.image_size, load_seg, psp_seg, env_seg,
        v->img.entry_cs, v->img.entry_ip, v->img.entry_ss, v->img.entry_sp,
        want_paras, (unsigned)(load_seg + 0x30CB));

    return true;
}

void vm_shutdown(vm *v) {
    free(v->prof);
    v->prof = NULL;
    free(v->ovl_provenance);
    v->ovl_provenance = NULL;
    find_close(v);
    for (int i = 0; i < VM_MAX_FILES; i++) {
        if (v->files[i].used && v->files[i].fp) fclose(v->files[i].fp);
    }
    if (g_vm == v) g_vm = NULL;
}

bool vm_run(vm *v, uint64_t max_insns) {
    cpu86 *c = &v->cpu;

    for (uint64_t i = 0; i < max_insns; i++) {
        if (c->fault || c->halted || v->exited) return false;

        /*
         * A blocking service asked us to stop: the guest cannot make progress
         * until the host supplies input. Ending the slice here rather than
         * re-running the same INT is what stops a wait from burning the whole
         * instruction budget -- the first version of this spun 26 million
         * times waiting at the title screen.
         *
         * The virtual clock is still advanced to the next tick so that timed
         * animations behind the prompt keep running while we wait.
         */
        if (c->yield_request) {
            c->yield_request = 0;
            v->waits++;
            /*
             * Advance the virtual clock to the next timer tick before handing
             * control back. A real DOS read blocks inside INT 21h while the
             * timer keeps firing, so animations behind a prompt keep running;
             * if the clock stood still here the logo fade would never play.
             * Advancing a whole tick per block is also what keeps a wait
             * cheap -- an earlier version that neither advanced nor returned
             * spun 26 million times at the title screen.
             */
            if (c->cycles < v->next_tick_cycles) c->cycles = v->next_tick_cycles;
            return true;
        }

        /*
         * Timer. The guest hooks INT 1Ch and paces everything from it, so
         * without this the game spins forever waiting for time to pass.
         *
         * An interrupt may only be injected at an instruction boundary with
         * IF set and not in the shadow of a segment load -- the 8086 rule
         * that makes `mov ss,ax; mov sp,bx` atomic. If the guest has
         * interrupts masked we hold the tick pending rather than dropping it,
         * so a long CLI region does not lose time.
         */
        if (c->cycles >= v->next_tick_cycles) {
            v->next_tick_cycles += v->pit_period_cycles;
            v->tick_pending = true;
        }

        /* Sound Blaster DMA completion timer check */
        if (v->sb.dma_active && c->cycles >= v->sb.dma_end_cycles) {
            v->sb.irq_pending = true;
            v->pic.irr |= (uint8_t)(1 << v->sb.irq);
            if (v->sb.auto_init && v->sb.block_size) {
                /* Auto-init loops the same buffer: re-stream the block
                 * and re-arm, so a per-block IRQ paces the guest. */
                uint32_t len = v->sb.block_size;
                uint32_t base = v->sb.dma_base_phys;
                sb_dma_stream(v, base, len);
                v->sb.dma_transferred_bytes += len;
                uint64_t rate = v->sb.sample_rate ? v->sb.sample_rate : 11025;
                uint64_t cps = v->cycles_per_second ? v->cycles_per_second : 10000000ULL;
                uint64_t dma_cycles = (uint64_t)len * cps / rate;
                if (dma_cycles == 0) dma_cycles = 1;
                v->sb.dma_end_cycles = c->cycles + dma_cycles;
            } else {
                v->sb.dma_active = false;
            }
        }

        /* Deliver a mouse event at an instruction boundary, for the same
         * reason interrupts are only injected here: mid-instruction or in
         * the shadow of a segment load is not a safe place to divert. */
        if (v->m33_pending && !c->inhibit_irq) m33_dispatch(v);

        if (v->tick_pending && (c->flags & F_IF) && !c->inhibit_irq) {
            v->tick_pending = false;
            v->timer_ticks++;
            cpu86_interrupt(c, 0x08);
        }

        /* Deliver pending Sound Blaster virtual IRQ */
        if (v->sb.irq_pending &&
            !(v->pic.imr & (1 << v->sb.irq)) &&
            !(v->pic.isr & (1 << v->sb.irq)) &&
            (c->flags & F_IF) && !c->inhibit_irq) {
            v->pic.irr &= (uint8_t)~(1 << v->sb.irq);
            v->pic.isr |= (uint8_t)(1 << v->sb.irq);
            cpu86_interrupt(c, (uint8_t)(0x08 + v->sb.irq));
        }

        if (v->cfg.trace_cpu) {
            fprintf(stderr, "%04X:%04X ", c->s[CPU_CS], c->ip);
            vm_dump_state(v, stderr);
        }

        /* Sample the profile cheaply: one in 1024 instructions is plenty to
         * localise a spin, and costs a predictable branch. */
        if (v->prof && (v->insn_count & 1023u) == 0) {
            v->prof[(cpu_lin(c->s[CPU_CS], c->ip) >> 4) & 0xFFFFu]++;
            v->prof_samples++;
        }

        c->step_budget_remaining = max_insns - i;
        cpu86_step(c);
        {
            uint64_t guest_insns = c->step_guest_insns ? c->step_guest_insns : 1u;
            v->insn_count += guest_insns;
            i += guest_insns - 1u;
        }
    }
    return !(c->fault || c->halted || v->exited);
}

/*
 * Checkpoint hash: the 64,000-byte Mode 13h buffer plus the 768-byte DAC.
 *
 * Hashes only, never pixels -- a golden file of screenshots would be shipping
 * copyrighted artwork. Including the palette matters: the framebuffer alone
 * is identical whether the scene is faded in or still black.
 */
uint64_t vm_frame_hash(const vm *v) {
    uint64_t h = 1469598103934665603ULL;
    for (uint32_t i = 0; i < 64000; i++) {
        h ^= g_dos_mem[0xA0000u + i];
        h *= 1099511628211ULL;
    }
    for (int i = 0; i < 256 * 3; i++) {
        h ^= v->dac[i];
        h *= 1099511628211ULL;
    }
    return h;
}

bool vm_save_bmp(const vm *v, const char *path) {
    FILE *f = fopen(path, "wb");
    const int w = 320, h = 200;
    const uint32_t pixel_bytes = (uint32_t)w * h * 3;
    const uint32_t offset = 54;
    uint32_t i;
    uint8_t hdr[54];

    if (!f) return false;
    memset(hdr, 0, sizeof(hdr));
    hdr[0] = 'B'; hdr[1] = 'M';
    write_le32(hdr + 2, offset + pixel_bytes);
    write_le32(hdr + 10, offset);
    write_le32(hdr + 14, 40);
    write_le32(hdr + 18, (uint32_t)w);
    write_le32(hdr + 22, (uint32_t)h);
    write_le16(hdr + 26, 1);
    write_le16(hdr + 28, 24);
    write_le32(hdr + 34, pixel_bytes);
    fwrite(hdr, 1, sizeof(hdr), f);

    /* BMP rows run bottom-up. The DAC holds 6-bit components, so widen them
     * the way a VGA DAC does: (c << 2) | (c >> 4). */
    for (int y = h - 1; y >= 0; y--) {
        for (int x = 0; x < w; x++) {
            uint8_t idx = g_dos_mem[0xA0000u + (uint32_t)y * w + x];
            uint8_t r6 = v->dac[idx * 3 + 0];
            uint8_t g6 = v->dac[idx * 3 + 1];
            uint8_t b6 = v->dac[idx * 3 + 2];
            uint8_t rgb[3];
            rgb[0] = (uint8_t)((b6 << 2) | (b6 >> 4));
            rgb[1] = (uint8_t)((g6 << 2) | (g6 >> 4));
            rgb[2] = (uint8_t)((r6 << 2) | (r6 >> 4));
            fwrite(rgb, 1, 3, f);
        }
    }
    (void)i;
    fclose(f);
    return true;
}

void vm_report(const vm *v, FILE *out) {
    fprintf(out, "\n--- vm report ---\n");
    fprintf(out, "instructions executed : %llu\n", (unsigned long long)v->insn_count);
    fprintf(out, "exited                : %s (code %d)\n",
            v->exited ? "yes" : "no", v->exit_code);
    fprintf(out, "fault                 : %s\n", cpu86_fault_name(v->cpu.fault));
    if (v->cpu.fault == CPU_FAULT_BAD_OPCODE)
        fprintf(out, "  at linear %05X\n", v->cpu.fault_addr);

    fprintf(out, "interrupts used       :");
    for (int i = 0; i < 256; i++)
        if (v->int_counts[i]) fprintf(out, " %02X(%u)", i, v->int_counts[i]);
    fprintf(out, "\n");

    fprintf(out, "INT 21h functions     :");
    for (int i = 0; i < 256; i++)
        if (v->dos_counts[i]) fprintf(out, " %02X(%u)", i, v->dos_counts[i]);
    fprintf(out, "\n");

    /* Is the guest actually drawing? Mode 13h lives at A000:0000, which is
     * already aliased into g_dos_mem, so this needs no plumbing. */
    {
        uint32_t nonzero = 0;
        uint8_t seen[256] = {0};
        uint32_t colours = 0;
        for (uint32_t i = 0; i < 64000; i++) {
            uint8_t px = g_dos_mem[0xA0000u + i];
            if (px) nonzero++;
            if (!seen[px]) { seen[px] = 1; colours++; }
        }
        fprintf(out, "framebuffer           : %u/64000 non-black (%.1f%%), %u distinct colours\n",
                nonzero, 100.0 * nonzero / 64000.0, colours);
    }

    fprintf(out, "files opened          :");
    for (int i = 0; i < v->opened_count; i++) fprintf(out, " %s", v->opened[i]);
    fprintf(out, "\n");
    fprintf(out, "DAC writes            : %u\n", v->dac_writes);
    fprintf(out, "OPL register writes   : %u\n", v->opl_writes);
    fprintf(out, "SB DSP port accesses  : %u\n", v->sb.accesses);
    fprintf(out, "DMA bytes transferred : %llu\n", (unsigned long long)v->sb.dma_transferred_bytes);
    fprintf(out, "PC speaker writes     : %u\n", v->speaker_writes);
    if (g_vm == v) rs_flush((vm *)v);
    fprintf(out, "RealSound PWM writes  : %llu\n", (unsigned long long)v->rs_pwm_writes);
    fprintf(out, "RealSound samples     : %llu\n", (unsigned long long)v->rs_samples);
    fprintf(out, "INT 33h callbacks     : %u (mask %04X, handler %04X:%04X)\n",
            v->m33_calls, v->m33_mask, v->m33_handler_seg, v->m33_handler_off);
    fprintf(out, "input waits           : %llu\n", (unsigned long long)v->waits);
    fprintf(out, "timer ticks delivered : %llu\n",
            (unsigned long long)v->timer_ticks);
    if (v->prof && v->prof_samples) {
        /* Top paragraphs by sample count: where the guest actually is. */
        int top[10]; uint32_t topv[10];
        memset(top, -1, sizeof(top));
        memset(topv, 0, sizeof(topv));
        for (int i = 0; i < 0x10000; i++) {
            uint32_t n = v->prof[i];
            if (!n) continue;
            for (int k = 0; k < 10; k++) {
                if (n > topv[k]) {
                    for (int j = 9; j > k; j--) { topv[j] = topv[j-1]; top[j] = top[j-1]; }
                    topv[k] = n; top[k] = i;
                    break;
                }
            }
        }
        fprintf(out, "hottest code (%llu samples):\n",
                (unsigned long long)v->prof_samples);
        for (int k = 0; k < 10 && top[k] >= 0; k++) {
            fprintf(out, "    linear %05X  %6.2f%%  (%u)\n",
                    (unsigned)top[k] << 4,
                    100.0 * topv[k] / (double)v->prof_samples, topv[k]);
        }
    }

    if (v->ovl_load_count) {
        fprintf(out, "overlay loads         : %d (base segment %04X)\n",
                v->ovl_load_count, v->ovl_base_seg);
        for (int i = 0; i < v->ovl_load_count; i++)
            fprintf(out, "    payload %6u  len %5u -> %04X:%04X  @insn %llu\n",
                    (unsigned)(v->ovl_loads[i].file_off >= OVL_PAYLOAD_START
                               ? v->ovl_loads[i].file_off - OVL_PAYLOAD_START : 0),
                    v->ovl_loads[i].length, v->ovl_loads[i].seg,
                    v->ovl_loads[i].off,
                    (unsigned long long)v->ovl_loads[i].at_insn);
    }

    fprintf(out, "MCB chain valid       : %s\n",
            mcb_validate(&v->arena) ? "yes" : "NO - guest corrupted it");
    fprintf(out, "largest free block    : %u paragraphs (%u KB)\n",
            mcb_largest_free(&v->arena), mcb_largest_free(&v->arena) / 64);
}
