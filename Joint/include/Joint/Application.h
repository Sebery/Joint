#pragma once

#include <memory>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Joint/Window.h"


class Application {
public:
    // Only one application can be created
    static std::unique_ptr<Application> CreateApplication();
public:
    Application(const Application& app) = delete;
    Application& operator=(const Application& app) = delete;
    ~Application();
private:
    // Create application using static method CreateApplication
    Application();
public:
    // Initialize dependencies
    bool Initialize();
    // Run the engine
    void Run();
private:
    // Terminate application and free memory
    void Terminate();
private:
    Window mainWindow;
};