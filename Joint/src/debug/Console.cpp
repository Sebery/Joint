#include "Joint/Console.h"

namespace Joint {

    Console& Console::System() {
        static Console system{ "SYSTEM" };
        return system;
    }

    Console::Console(const char* name)
        : name{ name } { }

    void Console::PrintHeader() const {
        std::cout << "[" << name << "] ";
    }

    void Console::PrintFooter() const {
        std::cout << "\n";
    }

    void Console::Log(const char *format, ...) const {
        PrintHeader();
        va_list args;
        va_start(args, format);
        vprintf(format, args);
        va_end(args);
        PrintFooter();
    }

}


