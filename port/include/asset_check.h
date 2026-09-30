#ifndef XANTH_ASSET_CHECK_H
#define XANTH_ASSET_CHECK_H

#include <stdbool.h>
#include <stddef.h>

/* Validate a user-supplied copy of the pinned local XANBUD asset set. */
bool xanth_check_assets(const char *exe_path, const char *data_dir,
                        char *error, size_t error_size);
bool xanth_sha256_buffer(const void *data, size_t size, char hex[65]);
bool xanth_sha256_file(const char *path, char hex[65]);

#endif
