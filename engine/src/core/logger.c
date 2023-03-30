#include "logger.h"
#include "asserts.h"
#include "platform/platform.h"

#include <stdio.h>
#include <string.h>
#include <stdarg.h>

b8 init_logging()
{
    return TRUE;
}

void stop_logging()
{
}

void log_output(log_level level, const char *message, ...)
{
    const char *level_strings[6] = {"[FATAL]: ",
                                    "[ERROR]: ",
                                    "[WARN]: ",
                                    "[INFO]: ",
                                    "[DEBUG]: ",
                                    "[TRACE]: "};
    b8 isError = level < LOG_LEVEL_WARN;
    i32 max_char = 32000;

    char out_message[max_char];
    memset(out_message, 0, sizeof(out_message));

    __builtin_va_list arg_ptr;
    va_start(arg_ptr, message);
    vsnprintf(out_message, max_char, message, arg_ptr);
    va_end(arg_ptr);

    char out_message2[max_char];
    sprintf(out_message2, "%s%s\n", level_strings[level], out_message);

    if (isError)
    {
        platform_console_write_error(out_message2, level);
    }
    else
    {
        platform_console_write(out_message2, level);
    }
}

void report_assertion_failure(const char *expression, const char *message, const char *file, i32 line)
{
    log_output(LOG_LEVEL_FATAl, "Assertion Failure: %s, Message: %s, in file %s, line %d\n", expression, message, file, line);
}