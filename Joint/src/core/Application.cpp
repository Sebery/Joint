#include "Joint/Application.h"
#include "Joint/Console.h"

namespace Joint {

    std::unique_ptr<Application> Application::CreateApplication() {
        static bool created{ false };

        if (!created) {
            created = true;
            return std::unique_ptr<Application>(new Application);
        } else {
            JOINT_INFO_LOG("App already created");
            return std::unique_ptr<Application>(nullptr);
        }
    }

    Application::Application()
        : mainWindow{ }  { JOINT_INFO_LOG("App Created"); }

    Application::~Application() {
        JOINT_INFO_LOG("App Deleted");
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