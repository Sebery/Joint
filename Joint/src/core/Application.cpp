#include "Joint/core/Application.h"
#include <iostream>
#include <memory>

// Modules
#include "Joint/testing/TestModule.h"
#include "Joint/modules/Window.h"

namespace Joint {

    bool Application::isRunning{ false };

    bool Application::IsRunning() {
        return isRunning;
    }

    void Application::IsRunning(bool run) {
        isRunning = run;
    }

    void Application::RunEngine() {
        // Create the application
        static std::unique_ptr<Application> app{ new Application() };

        // Run the application only if it is not running
        if (!app->created) {
            // Start the engine and modules
            isRunning = true;
            app->created = true;
            std::cout << "Application running!\n";
            app->OnStartUp();

            // Engine loop
            while (isRunning) {
                app->OnUpdate();
            }

            // Terminate the engine and modules
            app->OnShutDown();
        } else {
            std::cout << "Application already running!\n";
        }
    }

    Application::Application()
        : created{ false } {
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
        glClearColor(0.5f, 1.0f, 0.5f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);
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