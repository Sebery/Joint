#include "Joint/core/Application.h"
#include <iostream>
#include <memory>

// Modules
#include "Joint/testing/TestModule.h"

namespace Joint {

    void Application::RunEngine() {
        static std::unique_ptr<Application> app{ new Application() };

        if (!app->isRunning) {
            app->isRunning = true;
            std::cout << "Application running!\n";
            app->OnStartUp();
            app->OnUpdate();
            app->OnShutDown();
        } else {
            std::cout << "Application already running!\n";
        }
    }

    Application::Application()
        : isRunning{ false } {
        std::cout << "Application created!\n";
    }

    Application::~Application() {
        std::cout << "Application destroyed!\n";
    }

    void Application::AddBaseModules() {
        modules.emplace_back(new TestModule);
    }

    void Application::OnStartUp() {
        AddBaseModules();
        for (auto& m : modules) {
            m.OnStartUp();
        }
    }

    void Application::OnUpdate() {
        for (auto& m : modules) {
            m.OnUpdate();
        }
    }

    void Application::OnShutDown() {
        for (auto& m : modules) {
            m.OnShutDown();
        }
    }

}