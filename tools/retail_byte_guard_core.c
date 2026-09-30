/*
 * retail_byte_guard_core.c — exact retail byte-run finder (driver:
 * tools/retail_byte_guard.py).
 *
 * Reads two newline-separated path lists: the user's retail reference files
 * and the files to check.  Every run of at least --min identical bytes
 * shared by a target file and a reference file is printed as
 *
 *   target_index <TAB> target_offset <TAB> length <TAB> ref_index <TAB> ref_offset <TAB> trivial
 *
 * where trivial is 1 when the run is a 1..4-byte repeating fill (zeros,
 * spaces, 0xFF...) with at most one stray byte.
 *
 * Completeness: reference files are indexed by 16-byte windows at every
 * 16-byte-aligned offset of each file, and targets are probed at every
 * offset.  Any shared run of 31 or more bytes contains a whole indexed
 * window, so no run of length >= 32 can be missed.  Hash collisions are
 * resolved by comparing bytes; nothing is sampled.  Only windows that are
 * pure 1..4-byte fills cap their candidate list, since such runs are
 * classed trivial anyway.
 */
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIN 16
#define MAX_CANDIDATES_FILL 64      /* windows that are 1..4-byte repeats */
#define MAX_CANDIDATES      100000

typedef struct { uint64_t hash; uint32_t pos; uint32_t file; } entry;
typedef struct { char *path; uint8_t *data; size_t size; size_t base; } blob;

static uint64_t load64(const uint8_t *p) { uint64_t v; memcpy(&v, p, 8); return v; }

static uint64_t win_hash(const uint8_t *p) {
    uint64_t a = load64(p) * 0x9E3779B97F4A7C15ull;
    uint64_t b = load64(p + 8) * 0xC2B2AE3D27D4EB4Full;
    uint64_t h = a ^ ((b << 31) | (b >> 33));
    return h ^ (h >> 29);
}

static int cmp_entry(const void *x, const void *y) {
    const entry *a = x, *b = y;
    if (a->hash != b->hash) return a->hash < b->hash ? -1 : 1;
    if (a->file != b->file) return a->file < b->file ? -1 : 1;
    return a->pos < b->pos ? -1 : (a->pos > b->pos);
}

static uint8_t *read_file(const char *path, size_t *size) {
    FILE *f = fopen(path, "rb");
    uint8_t *buf;
    long n;
    if (!f) return NULL;
    if (fseek(f, 0, SEEK_END) != 0 || (n = ftell(f)) < 0 || fseek(f, 0, SEEK_SET) != 0) {
        fclose(f);
        return NULL;
    }
    buf = malloc((size_t)n + 1);
    if (buf && fread(buf, 1, (size_t)n, f) != (size_t)n) { free(buf); buf = NULL; }
    fclose(f);
    *size = (size_t)n;
    return buf;
}

static blob *read_list(const char *list, size_t *count) {
    FILE *f = fopen(list, "r");
    char line[4096];
    blob *v = NULL;
    size_t n = 0, cap = 0;
    if (!f) { fprintf(stderr, "cannot open list %s\n", list); exit(2); }
    while (fgets(line, sizeof(line), f)) {
        line[strcspn(line, "\r\n")] = '\0';
        if (!line[0]) continue;
        if (n == cap) {
            cap = cap ? cap * 2 : 64;
            v = realloc(v, cap * sizeof(*v));
            if (!v) { fprintf(stderr, "out of memory\n"); exit(2); }
        }
        v[n].path = strdup(line);
        v[n].data = read_file(line, &v[n].size);
        if (!v[n].data) { fprintf(stderr, "cannot read %s\n", line); exit(2); }
        n++;
    }
    fclose(f);
    *count = n;
    return v;
}

/* A 1..4-byte repeating fill, allowing one stray byte (which breaks the
 * repeat in at most two places), e.g. a zero block after a single flag. */
static int periodic(const uint8_t *p, size_t n) {
    for (size_t period = 1; period <= 4; ++period) {
        int breaks = 0;
        for (size_t k = period; k < n && breaks <= 2; ++k) breaks += p[k] != p[k - period];
        if (breaks <= 2) return 1;
    }
    return 0;
}

int main(int argc, char **argv) {
    const char *ref_list = NULL, *target_list = NULL;
    size_t min_run = 32, nref, ntarget, nentries = 0, cap = 0;
    blob *refs, *targets;
    entry *idx = NULL;

    for (int i = 1; i < argc; ++i) {
        if (!strcmp(argv[i], "--refs") && i + 1 < argc) ref_list = argv[++i];
        else if (!strcmp(argv[i], "--targets") && i + 1 < argc) target_list = argv[++i];
        else if (!strcmp(argv[i], "--min") && i + 1 < argc) min_run = strtoul(argv[++i], NULL, 10);
        else { fprintf(stderr, "usage: %s --refs LIST --targets LIST [--min N]\n", argv[0]); return 2; }
    }
    if (!ref_list || !target_list || min_run < 2 * WIN - 1) {
        fprintf(stderr, "need --refs, --targets and --min >= %d\n", 2 * WIN - 1);
        return 2;
    }
    refs = read_list(ref_list, &nref);
    targets = read_list(target_list, &ntarget);

    for (size_t r = 0; r < nref; ++r) {
        for (size_t pos = 0; pos + WIN <= refs[r].size; pos += WIN) {
            if (nentries == cap) {
                cap = cap ? cap * 2 : (1u << 20);
                idx = realloc(idx, cap * sizeof(*idx));
                if (!idx) { fprintf(stderr, "out of memory\n"); return 2; }
            }
            idx[nentries].hash = win_hash(refs[r].data + pos);
            idx[nentries].pos = (uint32_t)pos;
            idx[nentries].file = (uint32_t)r;
            nentries++;
        }
    }
    qsort(idx, nentries, sizeof(*idx), cmp_entry);
    fprintf(stderr, "[core] indexed %zu windows from %zu reference files\n", nentries, nref);

    for (size_t t = 0; t < ntarget; ++t) {
        const uint8_t *td = targets[t].data;
        size_t tn = targets[t].size, i = 0;
        while (i + WIN <= tn) {
            uint64_t h = win_hash(td + i);
            size_t lo = 0, hi = nentries, best_len = 0, best_ts = 0, best_rpos = 0, best_ref = 0;
            size_t limit = periodic(td + i, WIN) ? MAX_CANDIDATES_FILL : MAX_CANDIDATES;
            while (lo < hi) {
                size_t mid = lo + (hi - lo) / 2;
                if (idx[mid].hash < h) lo = mid + 1; else hi = mid;
            }
            for (size_t k = lo, seen = 0; k < nentries && idx[k].hash == h && seen < limit; ++k, ++seen) {
                const blob *rb = &refs[idx[k].file];
                size_t rp = idx[k].pos, back = 0, fwd = WIN;
                if (memcmp(td + i, rb->data + rp, WIN) != 0) continue;
                while (back < i && back < rp && td[i - back - 1] == rb->data[rp - back - 1]) ++back;
                while (i + fwd < tn && rp + fwd < rb->size && td[i + fwd] == rb->data[rp + fwd]) ++fwd;
                if (back + fwd > best_len) {
                    best_len = back + fwd;
                    best_ts = i - back;
                    best_rpos = rp - back;
                    best_ref = idx[k].file;
                }
            }
            if (best_len >= min_run) {
                printf("%zu\t%zu\t%zu\t%zu\t%zu\t%d\n", t, best_ts, best_len, best_ref, best_rpos,
                       periodic(td + best_ts, best_len));
                i = best_ts + best_len;   /* resume after this run */
            } else {
                ++i;
            }
        }
    }
    return 0;
}
