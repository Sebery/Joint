#include "Joint/modules/Window.h"
#include <iostream>
#include "Joint/core/Application.h"

namespace Joint {

    Window::Window(int width, int height, const char* title)
        : window{nullptr } {
        static bool glfwInitialized{ false };

        // Initialize GLFW
        if (!glfwInitialized) {
            glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
            glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
            glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

            if (__APPLE__)
                glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

            if (!glfwInit())
                std::cout << "Failed to initialize glfw!\n"; // TODO: assertion

            glfwInitialized = true;
        }

        // Create window
        window = glfwCreateWindow(width, height, title, nullptr, nullptr);

        if (!window)
            std::cout << "Failed to create a window!\n"; // TODO: assertion

        glfwMakeContextCurrent(window);

        if (!gladLoadGLLoader((GLADloadproc) glfwGetProcAddress))
            std::cout << "Failed to initialize glad!\n"; // TODO: assertion
    }

    Window::~Window() {
        glfwDestroyWindow(window);
        glfwTerminate(); // TODO: Call this in the last module of the engine
    }

    void Window::OnStartUp() {
        std::cout << "Window created!\n";
    }

    void Window::OnUpdate() {
        OnInput();
        std::cout << "Updating window!\n";
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    void Window::OnShutDown() {
        std::cout << "Window destroyed!\n";
    }

    void Window::OnInput() {
        if (glfwWindowShouldClose(window)) {
            Application::IsRunning(false);
        }

        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            glfwSetWindowShouldClose(window, true);
            Application::IsRunning(false);
        }
    }

}