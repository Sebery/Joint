#pragma once

#include <iostream>
#include <cstdio>

// TODO: Add log level variable in cmake, add log type and color in output

// Select default log level
#ifndef JOINT_LOG_LEVEL
#   ifndef NDEBUG
#       define JOINT_LOG_LEVEL 4
#   else
#       define JOINT_LOG_LEVEL 0
#   endif
#endif

// Define Development Logs
#ifndef NDEBUG
#   define JOINT_ERROR_LOG(m) Joint::Console::System().Log(m)
#   define JOINT_WARN_LOG(m) Joint::Console::System().Log(m)
#   define JOINT_DEBUG_LOG(m) Joint::Console::System().Log(m)
#   define JOINT_INFO_LOG(m) Joint::Console::System().Log(m)
#else
#   define JOINT_DEBUG_LOG(m)
#   define JOINT_DEBUG_LOG(m)
#   define JOINT_DEBUG_LOG(m)
#   define JOINT_DEBUG_LOG(m)
#endif

namespace Joint {

    enum LOG_LEVEL {
        NONE = 0,
        ERROR,
        WARN,
        DEBUG,
        INFO
    };

    class Console {
    public:
        static Console& System();
    public:
        Console(const char* name);
        Console(Console&& cns) noexcept = delete;
        Console(const Console& cns) = delete;
        ~Console() = default;
    public:
        Console& operator=(Console&& cns) noexcept = delete;
        Console& operator=(const Console& cns) = delete;
    public:
        void Log(const char* format, ...) const;
    private:
        void PrintHeader() const;
        void PrintFooter() const;
    private:
        const char* name;
    };

}


