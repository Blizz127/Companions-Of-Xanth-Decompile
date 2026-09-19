#include "port_hal.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>
#include <sys/types.h>

#if defined(_WIN32) || defined(_MSC_VER)
  #include <windows.h>
  #include <direct.h>
  #define strcasecmp _stricmp
  #define strncasecmp _strnicmp
  #define mkdir_compat(path) _mkdir(path)
#else
  #include <dirent.h>
  #include <unistd.h>
  #define mkdir_compat(path) mkdir(path, 0755)
#endif

/* -------------------------------------------------------------------------
 * Internal State
 * ------------------------------------------------------------------------- */
static char g_cli_data_dir[512] = {0};
static char g_cli_save_dir[512] = {0};
static legend_ini_t g_ini_config;
static bool g_ini_loaded = false;

#define DOS_MAX_HANDLES 64
static FILE *g_dos_handles[DOS_MAX_HANDLES] = {0};

/* -------------------------------------------------------------------------
 * String & Path Utility Functions
 * ------------------------------------------------------------------------- */
static char *trim_whitespace(char *str) {
    if (!str) return NULL;
    while (isspace((unsigned char)*str)) str++;
    if (*str == '\0') return str;

    char *end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) {
        *end = '\0';
        end--;
    }
    return str;
}

static void normalize_separators(char *path) {
    if (!path) return;
    for (size_t i = 0; path[i]; i++) {
        if (path[i] == '\\') {
            path[i] = '/';
        }
    }
}

static void make_dir_recursive(const char *dir_path) {
    char tmp[512];
    snprintf(tmp, sizeof(tmp), "%s", dir_path);
    normalize_separators(tmp);

    size_t len = strlen(tmp);
    if (len == 0) return;
    if (tmp[len - 1] == '/') tmp[len - 1] = '\0';

    for (char *p = tmp + 1; *p; p++) {
        if (*p == '/') {
            *p = '\0';
            mkdir_compat(tmp);
            *p = '/';
        }
    }
    mkdir_compat(tmp);
}

/* -------------------------------------------------------------------------
 * Case-Insensitive Path Resolution with Traversal Defense
 * ------------------------------------------------------------------------- */
bool hal_fs_find_file(const char *base_dir, const char *rel_path, char *out_path, size_t max_len) {
    if (!base_dir || !rel_path || !out_path || max_len == 0) return false;

    char rel_norm[512];
    snprintf(rel_norm, sizeof(rel_norm), "%s", rel_path);
    normalize_separators(rel_norm);

    /* Strip drive letter e.g. "C:" */
    char *start = rel_norm;
    if (isalpha((unsigned char)start[0]) && start[1] == ':') {
        start += 2;
    }
    while (*start == '/') start++;

    char current_dir[512];
    snprintf(current_dir, sizeof(current_dir), "%s", base_dir);
    normalize_separators(current_dir);

    /* Remove trailing slash */
    size_t clen = strlen(current_dir);
    if (clen > 0 && current_dir[clen - 1] == '/') {
        current_dir[clen - 1] = '\0';
    }

    char base_canonical[512];
#if defined(_WIN32) || defined(_MSC_VER)
    if (_fullpath(base_canonical, current_dir, sizeof(base_canonical)) == NULL) {
        snprintf(base_canonical, sizeof(base_canonical), "%s", current_dir);
    }
#else
    if (realpath(current_dir, base_canonical) == NULL) {
        snprintf(base_canonical, sizeof(base_canonical), "%s", current_dir);
    }
#endif
    normalize_separators(base_canonical);

    /* Canonicalize current_dir to base_canonical to guarantee leading path delimiters */
    snprintf(current_dir, sizeof(current_dir), "%s", base_canonical);

    /* Tokenize rel_norm by '/' */
    char *token = strtok(start, "/");
    while (token != NULL) {
        if (strcmp(token, ".") == 0 || strlen(token) == 0) {
            token = strtok(NULL, "/");
            continue;
        }

        if (strcmp(token, "..") == 0) {
            /* Go up one directory, ensuring we do not escape base_dir */
            char *last_slash = strrchr(current_dir, '/');
            if (last_slash) {
                *last_slash = '\0';
            } else {
                return false; /* Cannot ascend past root or escape base_dir */
            }

            char check_canonical[512];
#if defined(_WIN32) || defined(_MSC_VER)
            if (_fullpath(check_canonical, current_dir, sizeof(check_canonical)) == NULL) {
                snprintf(check_canonical, sizeof(check_canonical), "%s", current_dir);
            }
#else
            if (realpath(current_dir, check_canonical) == NULL) {
                snprintf(check_canonical, sizeof(check_canonical), "%s", current_dir);
            }
#endif
            normalize_separators(check_canonical);

            /* Check if check_canonical is within base_canonical */
            size_t base_len = strlen(base_canonical);
            if (strncmp(check_canonical, base_canonical, base_len) != 0 ||
                (check_canonical[base_len] != '\0' && check_canonical[base_len] != '/')) {
                return false; /* Path traversal attack detected! */
            }

            token = strtok(NULL, "/");
            continue;
        }

        /* Scan directory entries case-insensitively */
        bool found = false;
        char matched_name[256] = {0};

#if defined(_WIN32) || defined(_MSC_VER)
        char search_pattern[512];
        snprintf(search_pattern, sizeof(search_pattern), "%s/*", current_dir);
        WIN32_FIND_DATAA fd;
        HANDLE hFind = FindFirstFileA(search_pattern, &fd);
        if (hFind != INVALID_HANDLE_VALUE) {
            do {
                if (strcasecmp(fd.cFileName, token) == 0) {
                    snprintf(matched_name, sizeof(matched_name), "%s", fd.cFileName);
                    found = true;
                    break;
                }
            } while (FindNextFileA(hFind, &fd));
            FindClose(hFind);
        }
#else
        DIR *dir = opendir(current_dir);
        if (!dir) return false;

        struct dirent *entry;
        while ((entry = readdir(dir)) != NULL) {
            if (strcasecmp(entry->d_name, token) == 0) {
                snprintf(matched_name, sizeof(matched_name), "%s", entry->d_name);
                found = true;
                break;
            }
        }
        closedir(dir);
#endif

        if (!found) {
            return false;
        }

        /* Append matched component */
        snprintf(current_dir + strlen(current_dir), sizeof(current_dir) - strlen(current_dir), "/%s", matched_name);
        token = strtok(NULL, "/");
    }

    snprintf(out_path, max_len, "%s", current_dir);
    return true;
}

/* -------------------------------------------------------------------------
 * LEGEND.INI Parser
 * ------------------------------------------------------------------------- */
bool hal_fs_parse_ini(const char *ini_path, legend_ini_t *config) {
    if (!ini_path || !config) return false;
    memset(config, 0, sizeof(*config));

    FILE *f = fopen(ini_path, "r");
    if (!f) return false;

    char line[512];
    while (fgets(line, sizeof(line), f)) {
        char *p = trim_whitespace(line);
        if (*p == '\0' || *p == ';' || *p == '#') {
            continue; /* Comment or blank line */
        }

        char *eq = strchr(p, '=');
        if (!eq) continue;

        *eq = '\0';
        char *key = trim_whitespace(p);
        char *val = trim_whitespace(eq + 1);

        /* Uppercase key */
        for (char *k = key; *k; k++) {
            *k = (char)toupper((unsigned char)*k);
        }

        if (strcmp(key, "MOUSE") == 0) {
            snprintf(config->mouse, sizeof(config->mouse), "%s", val);
        } else if (strcmp(key, "GAMEDATA") == 0) {
            snprintf(config->gamedata, sizeof(config->gamedata), "%s", val);
        } else if (strcmp(key, "SAVEDATA") == 0) {
            snprintf(config->savedata, sizeof(config->savedata), "%s", val);
        } else if (strcmp(key, "MUSIC") == 0) {
            snprintf(config->music, sizeof(config->music), "%s", val);
        } else if (strcmp(key, "SOUND") == 0) {
            snprintf(config->sound, sizeof(config->sound), "%s", val);
        }
    }

    fclose(f);
    return true;
}

/* -------------------------------------------------------------------------
 * Filesystem Initialization & Resolution
 * ------------------------------------------------------------------------- */
void hal_fs_init(const char *cli_data_path, const char *cli_save_path) {
    if (cli_data_path && *cli_data_path) {
        snprintf(g_cli_data_dir, sizeof(g_cli_data_dir), "%s", cli_data_path);
    }
    if (cli_save_path && *cli_save_path) {
        snprintf(g_cli_save_dir, sizeof(g_cli_save_dir), "%s", cli_save_path);
    }

    /* Try loading LEGEND.INI from common locations */
    const char *ini_locations[] = {
        "LEGEND.INI",
        "original/LEGEND.INI",
        "../original/LEGEND.INI",
        "gamedata/LEGEND.INI"
    };

    for (size_t i = 0; i < sizeof(ini_locations) / sizeof(ini_locations[0]); i++) {
        if (hal_fs_parse_ini(ini_locations[i], &g_ini_config)) {
            g_ini_loaded = true;
            break;
        }
    }
}

bool hal_fs_resolve_gamedata(const char *filename, char *out_path, size_t max_len) {
    if (!filename || !out_path || max_len == 0) return false;

    char exe_dir[512] = {0};
#if defined(_WIN32) || defined(_MSC_VER)
    GetModuleFileNameA(NULL, exe_dir, sizeof(exe_dir));
    normalize_separators(exe_dir);
    char *last_slash = strrchr(exe_dir, '/');
    if (last_slash) *last_slash = '\0';
#else
    ssize_t r = readlink("/proc/self/exe", exe_dir, sizeof(exe_dir) - 1);
    if (r > 0) {
        exe_dir[r] = '\0';
        char *last_slash = strrchr(exe_dir, '/');
        if (last_slash) *last_slash = '\0';
    }
#endif

    char exe_parent[512] = {0};
    char exe_cd[512] = {0};
    char exe_orig[512] = {0};
    char exe_parent_cd[512] = {0};
    char exe_parent_orig[512] = {0};

    if (exe_dir[0]) {
        snprintf(exe_cd, sizeof(exe_cd), "%s/game_cd/XANTH", exe_dir);
        snprintf(exe_orig, sizeof(exe_orig), "%s/original", exe_dir);
        snprintf(exe_parent, sizeof(exe_parent), "%s/..", exe_dir);
        snprintf(exe_parent_cd, sizeof(exe_parent_cd), "%s/../game_cd/XANTH", exe_dir);
        snprintf(exe_parent_orig, sizeof(exe_parent_orig), "%s/../original", exe_dir);
    }

    const char *candidates[32];
    int cand_count = 0;

    if (g_cli_data_dir[0]) {
        candidates[cand_count++] = g_cli_data_dir;
    }

    const char *env_data = getenv("XANTH_DATA");
    if (env_data && *env_data) {
        candidates[cand_count++] = env_data;
    }

    if (g_ini_loaded && g_ini_config.gamedata[0]) {
        candidates[cand_count++] = g_ini_config.gamedata;
    }

    /* Executable-relative candidate locations (for running from build/ or install directories) */
    if (exe_parent_cd[0])   candidates[cand_count++] = exe_parent_cd;
    if (exe_parent_orig[0]) candidates[cand_count++] = exe_parent_orig;
    if (exe_cd[0])          candidates[cand_count++] = exe_cd;
    if (exe_orig[0])        candidates[cand_count++] = exe_orig;
    if (exe_dir[0])         candidates[cand_count++] = exe_dir;

    /* Current working directory relative candidates */
    candidates[cand_count++] = "game_cd/XANTH";
    candidates[cand_count++] = "game_cd";
    candidates[cand_count++] = "original";
    candidates[cand_count++] = "./original";
    candidates[cand_count++] = "../game_cd/XANTH";
    candidates[cand_count++] = "../original";
    candidates[cand_count++] = "../../game_cd/XANTH";
    candidates[cand_count++] = "../../original";
    candidates[cand_count++] = "XANTH";
    candidates[cand_count++] = "../XANTH";
    candidates[cand_count++] = "gamedata";
    candidates[cand_count++] = ".";

    for (int i = 0; i < cand_count; i++) {
        if (hal_fs_find_file(candidates[i], filename, out_path, max_len)) {
            return true;
        }
    }

    /* Direct path fallback if file exists directly */
    FILE *f = fopen(filename, "rb");
    if (f) {
        fclose(f);
        snprintf(out_path, max_len, "%s", filename);
        return true;
    }

    return false;
}

bool hal_fs_resolve_savedata(const char *filename, char *out_path, size_t max_len) {
    if (!filename || !out_path || max_len == 0) return false;

    char save_dir[512] = {0};

    if (g_cli_save_dir[0]) {
        snprintf(save_dir, sizeof(save_dir), "%s", g_cli_save_dir);
    } else if (g_ini_loaded && g_ini_config.savedata[0]) {
        snprintf(save_dir, sizeof(save_dir), "%s", g_ini_config.savedata);
    } else {
        /* Standard user data directory */
#if defined(_WIN32) || defined(_MSC_VER)
        const char *appdata = getenv("APPDATA");
        if (appdata) {
            snprintf(save_dir, sizeof(save_dir), "%s/Legend/Xanth/saves", appdata);
        } else {
            snprintf(save_dir, sizeof(save_dir), "saves");
        }
#else
        const char *xdg = getenv("XDG_DATA_HOME");
        if (xdg && *xdg) {
            snprintf(save_dir, sizeof(save_dir), "%s/xanth/saves", xdg);
        } else {
            const char *home = getenv("HOME");
            if (home && *home) {
                snprintf(save_dir, sizeof(save_dir), "%s/.local/share/xanth/saves", home);
            } else {
                snprintf(save_dir, sizeof(save_dir), "saves");
            }
        }
#endif
    }

    make_dir_recursive(save_dir);

    /* Try finding existing file case-insensitively */
    if (hal_fs_find_file(save_dir, filename, out_path, max_len)) {
        return true;
    }

    /* Otherwise construct standard path */
    snprintf(out_path, max_len, "%s/%s", save_dir, filename);
    normalize_separators(out_path);
    return true;
}

bool hal_fs_get_save_path(int slot, char *out_path, size_t max_len) {
    if (slot < 0 || slot > 99 || !out_path || max_len == 0) return false;

    char save_name[32];
    snprintf(save_name, sizeof(save_name), "XANTH%02d.SAV", slot);
    return hal_fs_resolve_savedata(save_name, out_path, max_len);
}

/* -------------------------------------------------------------------------
 * DOS File I/O Compatibility Layer (INT 21h emulation)
 * ------------------------------------------------------------------------- */
int dos_open(const char *path, int mode) {
    if (!path) return -1;

    /* Find free slot in handle table (slots 3..63) */
    int slot = -1;
    for (int i = 3; i < DOS_MAX_HANDLES; i++) {
        if (g_dos_handles[i] == NULL) {
            slot = i;
            break;
        }
    }
    if (slot < 0) return -1;

    char resolved[512];
    if (!hal_fs_resolve_gamedata(path, resolved, sizeof(resolved))) {
        /* Fallback: try raw path */
        snprintf(resolved, sizeof(resolved), "%s", path);
    }

    const char *fmode = "rb";
    if (mode == 1) fmode = "wb";
    else if (mode == 2) fmode = "r+b";

    FILE *f = fopen(resolved, fmode);
    if (!f) return -1;

    g_dos_handles[slot] = f;
    return slot;
}

int dos_create(const char *path) {
    return dos_open(path, 1);
}

int dos_read(int fd, void far *buffer, unsigned int bytes) {
    if (fd < 3 || fd >= DOS_MAX_HANDLES || !g_dos_handles[fd] || !buffer) {
        return -1;
    }
    size_t read_bytes = fread(buffer, 1, bytes, g_dos_handles[fd]);
    return (int)read_bytes;
}

int dos_write(int fd, const void far *buffer, unsigned int bytes) {
    if (fd < 3 || fd >= DOS_MAX_HANDLES || !g_dos_handles[fd] || !buffer) {
        return -1;
    }
    size_t written = fwrite(buffer, 1, bytes, g_dos_handles[fd]);
    return (int)written;
}

long dos_lseek(int fd, unsigned int origin, unsigned long offset) {
    if (fd < 3 || fd >= DOS_MAX_HANDLES || !g_dos_handles[fd]) {
        return -1;
    }

    int whence = SEEK_SET;
    if (origin == 1) whence = SEEK_CUR;
    else if (origin == 2) whence = SEEK_END;

    if (fseek(g_dos_handles[fd], (long)offset, whence) != 0) {
        return -1;
    }
    return ftell(g_dos_handles[fd]);
}

int dos_close(int fd) {
    if (fd < 3 || fd >= DOS_MAX_HANDLES || !g_dos_handles[fd]) {
        return -1;
    }
    int res = fclose(g_dos_handles[fd]);
    g_dos_handles[fd] = NULL;
    return res == 0 ? 0 : -1;
}

long dos_tell(int fd) {
    if (fd < 3 || fd >= DOS_MAX_HANDLES || !g_dos_handles[fd]) {
        return -1;
    }
    return ftell(g_dos_handles[fd]);
}
