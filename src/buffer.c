#include <buffer.h>

#include <assert.h>
#include <stdlib.h>

#include <error_code.h>

int buffer_init(struct buffer *buffer, size_t size) {
    if (buffer == NULL) {
        return SYSD_EINVARG;
    }

    buffer->payload = malloc(sizeof(uint8_t) * size);
    buffer->size = size;
    buffer->caret = 0;

    if (buffer->payload == NULL) {
        return SYSD_ENOMEM;
    }
    
    return SYSD_OK;
}

int buffer_free(struct buffer *buffer) {
    if (buffer == NULL) {
        return SYSD_EINVARG;
    }

    if (buffer->payload != NULL) {
        free(buffer->payload);
        buffer->payload = NULL;        
    }

    return SYSD_OK;
}

size_t buffer_readable(struct buffer *buffer) {
    if (buffer == NULL) {
        return 0;
    }
    assert(buffer->size >= buffer->caret);

    return buffer->size - buffer->caret;
}

static int ensure_writable(struct buffer *buffer, size_t size) {
    if (buffer->size < (buffer->caret + size)) {
        size_t new_size = buffer->size + size;
        
        // round up to next power of 2, taken from:
        // https://stackoverflow.com/a/466242
        new_size--;
        for (size_t i = 0; i < 5; i++) {
            new_size |= new_size >> (1 << i);
        }
        new_size++;

        if (new_size == 0) {
            return SYSD_OK;
        }

        void *ptr = realloc(buffer->payload, new_size);

        if (ptr == NULL) {
            return SYSD_ENOMEM;
        }

        buffer->payload = (uint8_t *) ptr;
        buffer->size = new_size;
    }

    return SYSD_OK;
}

#define write_data(buffer, bytes, value) \
    do { if (buffer == NULL) { return SYSD_EINVARG; }               \
         int error = ensure_writable(buffer, bytes);                \
         if (error != SYSD_OK) { return error; }                    \
         for (int8_t i = (bytes) - 1; i >= 0; i--) {                \
             buffer->payload[buffer->caret++] = (value >> (i * 8)); \
         }                                                          \
         return SYSD_OK;                                            \
    } while (0);

int buffer_write_byte(struct buffer *buffer, uint8_t value) {
    write_data(buffer, 1, value);
}

int buffer_write_short(struct buffer *buffer, uint16_t value) {
    write_data(buffer, 2, value);
}

int buffer_write_int(struct buffer *buffer, uint32_t value) {
    write_data(buffer, 4, value);
}

int buffer_write_long(struct buffer *buffer, uint64_t value) {
    write_data(buffer, 8, value);
}

