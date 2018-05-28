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

