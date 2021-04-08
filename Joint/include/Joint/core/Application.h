#pragma once

#include <vector>
#include "Joint/core/Module.h"
#include "Joint/core/IEvents.h"

namespace Joint {

    class Application : public IEvents {
    public:
        // Create and run the engine
        static void RunEngine();
    public:
        ~Application();
    private:
        Application();
    private:
        // Create and add the most important modules of the engine
        void AddBaseModules();
        // Main events
        void OnStartUp() override;
        void OnUpdate() override;
        void OnShutDown() override;
    private:
        bool isRunning;
        std::vector<Module> modules;
    };

}