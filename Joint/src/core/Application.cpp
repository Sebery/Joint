#include "Joint/Application.h"
#include <iostream>

namespace Joint {

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
        : mainWindow{ }  { std::cout << "App Created\n"; }

    Application::~Application() {
        std::cout << "App Deleted\n";
        Terminate();
    }

    bool Application::Initialize() {
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

        if (__APPLE__)
            glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

        if (!glfwInit())
            return false;

        if (!mainWindow.SetWindow("Joint", 400, 400))
            return false;

        mainWindow.MakeContextCurrent();

        if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
            return false;

        return true;
    }

    void Application::Run() {
        while (!mainWindow.WindowShouldClose()) {
            glClear(GL_COLOR_BUFFER_BIT);
            glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

            mainWindow.SwapBuffers();

            glfwPollEvents();
        }
    }

    void Application::Terminate() {
        glfwTerminate();
    }

}