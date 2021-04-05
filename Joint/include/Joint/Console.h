#pragma once

#include <iostream>

// TODO: Add log level variable in cmake

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
        template<typename ...Args>
        void Log(const char* format, Args&& ...args) const {
            PrintHeader();
            printf(format, std::forward<Args>(args)...);
            PrintFooter();
        }

        template<typename ...Args>
        void Log(LOG_LEVEL logLevel, const char* format, Args&& ...args) const {
            if (logLevel <= JOINT_LOG_LEVEL) {
                PrintHeader();
                printf(format, std::forward<Args>(args)...);
                PrintFooter();
            }
        }
    private:
        void PrintHeader() const;
        void PrintFooter() const;
    private:
        const char* name;
    };

}


