#include "Joint/Application.h"
#include <iostream>

bool Application::Initialize() {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    if (__APPLE__)
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    if (!glfwInit())
        return false;

    mainWindow.SetWindow("Joint", 400, 400);
    if (!mainWindow.AsWindow())
        return false;

    glfwMakeContextCurrent(mainWindow.AsWindow());

    if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress)) {
        std::cout << "Failed to initialize OpenGL context" << std::endl;
        return false;
    }

    return true;
}

void Application::Run() {
    while (!glfwWindowShouldClose(mainWindow.AsWindow())) {
        glClear(GL_COLOR_BUFFER_BIT);
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

        glfwSwapBuffers(mainWindow.AsWindow());

        glfwPollEvents();
    }
}

void Application::Terminate() {
    glfwTerminate();
}

std::unique_ptr<Application> Application::CreateApplication() {
    static bool created{ false };

    if (!created) {
        created = true;
        return std::unique_ptr<Application>(new Application);
    } else {
        std::cout << "App Already Created\n";
        return std::unique_ptr<Application>(nullptr);
    }
}

Application::Application()
    : mainWindow() {
    std::cout << "App Created\n";
}

Application::~Application() {
    std::cout << "App Deleted\n";
    Terminate();
}
