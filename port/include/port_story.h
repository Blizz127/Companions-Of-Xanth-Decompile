#ifndef PORT_STORY_H
#define PORT_STORY_H

#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

#define STORY_MAX_SEGMENTS 128

typedef struct {
    int segment_count;
    int total_strings;
    int string_counts[STORY_MAX_SEGMENTS];
    char **strings[STORY_MAX_SEGMENTS];
    bool loaded;
} StoryTextDatabase;

extern StoryTextDatabase g_story_text_db;

/**
 * Load and decompress all 5,542 strings from XANTHSTR.DAT using Legend Huffman + shorthand dictionary.
 */
int story_text_load(const char *path);

/**
 * Get string by segment and string index.
 * Returns empty string "" if not found.
 */
const char *story_text_get(int segment, int string_idx);

/**
 * Free all memory allocated by the story text database.
 */
void story_text_free(void);

#ifdef __cplusplus
}
#endif

#endif /* PORT_STORY_H */
