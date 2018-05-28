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

// TODO: should this return the amount of readable bytes
// or take a size_t pointer and return an error code??
size_t buffer_readable(struct buffer *buffer);

int buffer_write_byte(struct buffer *buffer, uint8_t value);

int buffer_write_short(struct buffer *buffer, uint16_t value);

int buffer_write_int(struct buffer *buffer, uint32_t value);

int buffer_write_long(struct buffer *buffer, uint64_t value);


#endif // SYSD_BUFFER_H

