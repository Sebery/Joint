#pragma once

#include <memory>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Joint/Window.h"

namespace Joint {

    class Application {
    public:
        // Only one application can be created
        static std::unique_ptr<Application> CreateApplication();
    public:
        Application(const Application& app) = delete;
        Application(Application&& app) = delete;
        Application& operator=(const Application& app) = delete;
        Application& operator=(Application&& app) = delete;
        ~Application();
    public:
        bool Initialize();
        void Run();
    private:
        // Create application using static method CreateApplication
        Application();
    private:
        void ProcessInput();
        void Terminate();
    private:
        Window mainWindow;
    };

}