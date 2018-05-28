#ifndef SYSD_BUFFER_H
#define SYSD_BUFFER_H

#pragma once

#include <stddef.h>
#include <stdint.h>

struct buffer {
    uint8_t *payload;
    size_t size;
    size_t caret;
};

/**
 * initializes a buffer's internal variables
 */
int buffer_init(struct buffer *buffer, size_t size);

/**
 * releases resources of a buffer
 */
int buffer_free(struct buffer *buffer);

#endif // SYSD_BUFFER_H

