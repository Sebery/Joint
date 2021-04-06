#include "Joint/Window.h"

namespace Joint {

    void Window::FramebufferSizeCB(GLFWwindow* wnd, int width, int height) {
        glViewport(0, 0, width, height);
    }

    Window::Window()
        : window{ nullptr } { }

    Window::Window(const char* title, int width, int height)
        : window{ glfwCreateWindow(width, height, title, nullptr, nullptr) } {
        if (window)
            SetCallbacks();
    }

    Window::Window(Window&& wnd) noexcept
        : window{ wnd.window } {
        wnd.window = nullptr;
    }

    Window::~Window() {
        if (window) {
            glfwDestroyWindow(window);
            window = nullptr;
        }
    }

    Window& Window::operator=(Window&& wnd) noexcept {
        if (this != &wnd) {
            if (window)
                glfwDestroyWindow(window);

            window = wnd.window;
            wnd.window = nullptr;
        }

        return *this;
    }

    bool Window::SetWindow(const char* title, int width, int height) {
        if (window)
            glfwDestroyWindow(window);

        window = glfwCreateWindow(width, height, title, nullptr, nullptr);

        if (!window)
            return false;

        SetCallbacks();

        return true;
    }

    void Window::MakeContextCurrent() {
        glfwMakeContextCurrent(window);
    }

    int Window::WindowShouldClose() const {
        return glfwWindowShouldClose(window);
    }

    void Window::SwapBuffers() {
        glfwSwapBuffers(window);
    }

    void Window::ProcessInput() {
        if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
            glfwSetWindowShouldClose(window, true);
    }

    void Window::SetCallbacks() {
        glfwSetFramebufferSizeCallback(window, FramebufferSizeCB);
    }

}