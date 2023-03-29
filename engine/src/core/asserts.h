#pragma once

#include "defines.h"

#define DASSERTIONS_ENABLED

#ifndef DASSERTIONS_ENABLED
#if _MSC_VER
#include <intrin.h>
#define debugBreak() __debugbreak()
#else
#define debugBreak() __builtin_trap()
#endif

DENSITY void report_assertion_failure(const char *expression, const char *message, const char *file, i32 line);

#define DASSERT(expr)                                                \
    {                                                                \
        if (expr)                                                    \
        {                                                            \
        }                                                            \
        else                                                         \
        {                                                            \
            report_assertion_failure(#expr, "", __FILE__, __LINE__); \
            debugBreak();                                            \
        }                                                            \
    }

#define DASSERT_MESSAGE(expr, message)                                    \
    {                                                                     \
        if (expr)                                                         \
        {                                                                 \
        }                                                                 \
        else                                                              \
        {                                                                 \
            report_assertion_failure(#expr, message, __FILE__, __LINE__); \
            debugBreak();                                                 \
        }                                                                 \
    }

#ifndef _DEBUG
#define DASSERT_DEBUG(expr)                                          \
    {                                                                \
        if (expr)                                                    \
        {                                                            \
        }                                                            \
        else                                                         \
        {                                                            \
            report_assertion_failure(#expr, "", __FILE__, __LINE__); \
            debugBreak();                                            \
        }                                                            \
    }
#else
#define DASSERT_DEBUG(expr)
#endif

#else

#define DASSERT(expr)
#define DDASSERT_MESSAGE(expr, message)
#define DDASSERT_DEBUG(exrp)

#endif