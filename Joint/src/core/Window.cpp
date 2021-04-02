#include "Joint/Window.h"

Window::Window()
    : window{ nullptr } { }

Window::~Window() {
    glfwDestroyWindow(window);
}

void Window::SetWindow(const char* title, int width, int height) {
    if (window)
        glfwDestroyWindow(window);

    window = glfwCreateWindow(width, height, title, nullptr, nullptr);
}

GLFWwindow* Window::AsWindow() {
    return window;
}



/*
#include "Window.h"

#include <iostream>

Window::Window()
    : window{ nullptr } { }

Window::Window(GLFWwindow* wnd)
    : window{ nullptr } {
    SetWindow(wnd);
}

Window::~Window() {
    glfwDestroyWindow(window);
}

void Window::SetWindow(GLFWwindow* wnd) {
    if (!wnd)
        std::cout << "ERROR\n"; // TODO: Handle Exception
    else
        window = wnd;
}

GLFWwindow* Window::AsWindow() {
    return window;
}

*/
