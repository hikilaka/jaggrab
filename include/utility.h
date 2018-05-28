#ifndef SYSD_UTILITY_H
#define SYSD_UTILITY_H

#pragma once

#include <log.h>
#include <stdlib.h>
#include <uv.h>

#define sysd_log_uverror(logger, error, message)    \
    logger("[%s(%d)] %s: %s", uv_err_name(error),   \
                              (int) error, message, \
                              uv_strerror(error))

/**
 * checks an error response code, and prints a message
 * if the result is negative
 */
#define sysd_check_net_error(error, message) \
    if (error < 0) { sysd_log_uverror(log_error, error, message); }

/**
 * checks an error response code, and prints a message
 * if the result is negatve AND calls sys_exit(EXIT_FAILURE)
 */
#define sysd_check_net_fatal(error, message) \
    if (error < 0) { sysd_log_uverror(log_fatal, error, message); exit(1); }

#endif // SYSD_UTILITY_H
