#include "Joint/core/Application.h"
#include <iostream>
#include <memory>

// Modules
#include "Joint/testing/TestModule.h"
#include "Joint/internal/Window.h"

namespace Joint {

    void Application::RunEngine() {
        // Create the application
        static std::unique_ptr<Application> app{ new Application() };

        // Run the application only if it is not running
        if (!app->isRunning) {
            // Start the engine and modules
            app->isRunning = true;
            std::cout << "Application running!\n";
            app->OnStartUp();

            // Engine loop
            while (app->isRunning) {
                app->OnUpdate();
            }

            // Terminate the engine and modules
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
        modules.emplace_back(new TestModule());
        modules.emplace_back(new Window(400, 400, "Joint Engine"));
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