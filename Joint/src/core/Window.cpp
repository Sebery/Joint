#include "Joint/Window.h"

namespace Joint {

    Window::Window()
        : window{ nullptr } { }

    Window::Window(const char* title, int width, int height)
        : window{ glfwCreateWindow(width, height, title, nullptr, nullptr) } { }

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

}

/*Window::Window()
    : window{ nullptr } { }

void Window::SetWindow(const char* title, int width, int height) {
    if (window)
        glfwDestroyWindow(window);

    window = glfwCreateWindow(width, height, title, nullptr, nullptr);
}

GLFWwindow* Window::AsWindow() {
    return window;
}*/
