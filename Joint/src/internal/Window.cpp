#include "Joint/internal/Window.h"
#include <iostream>

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
        }

        // Create window
        window = glfwCreateWindow(width, height, title, nullptr, nullptr);

        if (!window)
            std::cout << "Failed to create a window!\n"; // TODO: assertion

        glfwMakeContextCurrent(window);
    }

    Window::~Window() {
        glfwDestroyWindow(window);
    }

    void Window::OnStartUp() {
        std::cout << "Window created!\n";
    }

    void Window::OnUpdate() {
        std::cout << "Updating window!\n";
        glfwPollEvents();
        glfwSwapBuffers(window);
    }

    void Window::OnShutDown() {
        std::cout << "Window destroyed!\n";
    }

}