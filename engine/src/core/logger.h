#pragma once

#include "defines.h"

#define LOG_WARN_ENABLED 1
#define LOG_INFO_ENABLED 1
#define LOG_DEBUG_ENABLED 1
#define LOG_TRACE_ENABLED 1

#if DRELEASE == 1
#define LOG_DEBUG_ENABLED 0
#define LOG_TRACE_ENABLED 0
#endif

typedef enum log_level
{
    LOG_LEVEL_FATAl = 0,
    LOG_LEVEL_ERROR = 1,
    LOG_LEVEL_WARN = 2,
    LOG_LEVEL_INFO = 3,
    LOG_LEVEL_DEBUG = 4,
    LOG_LEVEL_TRACE = 5
} log_level;

DENSITY b8 initialize_logging();
void stop_logging();

DENSITY void log_output(log_level level, const char *message, ...);

#define D_FATAL(message, ...) log_output(LOG_LEVEL_FATAl, message, ##__VA_ARGS__);

#ifndef D_ERROR
#define D_ERROR(message, ...) log_output(LOG_LEVEL_ERROR, message, ##__VA_ARGS__);
#endif

#if LOG_WARN_ENABLED == 1
#define D_WARN(message, ...) log_output(LOG_LEVEL_WARN, message, ##__VA_ARGS__);
#else
#define D_WARN(message, ...)
#endif

#if LOG_INFO_ENABLED == 1
#define D_INFO(message, ...) log_output(LOG_LEVEL_INFO, message, ##__VA_ARGS__);
#else
#define D_INFO(message, ...)
#endif

#if LOG_DEBUG_ENABLED == 1
#define D_DEBUG(message, ...) log_output(LOG_LEVEL_DEBUG, message, ##__VA_ARGS__);
#else
#define D_DEBUG(message, ...)
#endif

#if LOG_TRACE_ENABLED == 1
#define D_TRACE(message, ...) log_output(LOG_LEVEL_TRACE, message, ##__VA_ARGS__);
#else
#define D_TRACE(message, ...)
#endif