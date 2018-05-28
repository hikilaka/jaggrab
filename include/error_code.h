#ifndef SYSD_ERROR_CODE_H
#define SYSD_ERROR_CODE_H

#pragma once

#include <log.h>

#define sysd_log_error(logger, error, message) \
    logger("[%d] %s: %s", (int)error, (char *)message, sysd_error_str(error))

#define sysd_check_error(error, message) \
    if (error != SYSD_OK) { sysd_log_error(log_error, error, message); }

#define sysd_check_fatal(error, message) \
    if (error != SYSD_OK) { sysd_log_error(log_fatal, error, message); \
                            exit(1); }

enum sysd_error_code {
    SYSD_OK = 0,
    SYSD_ENOMEM,     // no memory
    SYSD_EINVARG,    // invalid argument
    SYSD_EUNDERFLOW, // buffer underflow
    SYSD_EOVERFLOW,  // buffer overflow
};

char* sysd_error_str(int error);

#endif // SYSD_ERROR_CODE_H
