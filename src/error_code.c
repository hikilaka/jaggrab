#include <error_code.h>

char* sysd_error_str(int error) {
    switch (error) {
    default:
    case SYSD_OK:         return "no error";
    case SYSD_ENOMEM:     return "out of memory";
    case SYSD_EINVARG:    return "invalid argument";
    case SYSD_EUNDERFLOW: return "buffer underflow";
    case SYSD_EOVERFLOW:  return "buffer overflow";
    }
}

