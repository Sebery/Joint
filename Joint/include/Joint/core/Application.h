#pragma once

#include <vector>
#include "Joint/core/Module.h"
#include "Joint/core/IEvents.h"

namespace Joint {

    class Application : public IEvents {
    public:
        static void RunEngine();
    public:
        ~Application();
    private:
        Application();
    private:
        void AddBaseModules();
        void OnStartUp() override;
        void OnUpdate() override;
        void OnShutDown() override;
    private:
        bool isRunning;
        std::vector<Module> modules;
    };

}