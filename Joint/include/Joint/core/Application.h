#pragma once

#include <vector>
#include "Joint/core/Module.h"
#include "Joint/events/IEvent.h"

namespace Joint {

    class Application : public IEvent {
    public:
        // Create and run the engine
        static void RunEngine();
        static bool IsRunning();
        static void IsRunning(bool run);
    public:
        ~Application();
    private:
        static bool isRunning;
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
        bool created;
        std::vector<Module> modules;
    };

}