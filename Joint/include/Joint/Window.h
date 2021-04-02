#pragma once

#include <GLFW/glfw3.h>

class Window {
public:
    Window();
    Window(const Window& win) = delete;
    Window& operator=(const Window& win) = delete;
    ~Window();
public:
    void SetWindow(const char* title, int width, int height);
    GLFWwindow* AsWindow();
private:
    GLFWwindow* window;
};


/*
#pragma once

#include <GLFW/glfw3.h>

class Window {
public:
    Window();
    explicit Window(GLFWwindow* wnd);
    Window(const Window& wnd) = delete;
    ~Window();
public:
    Window& operator=(const Window& wnd) = delete;
public:
    void SetWindow(GLFWwindow* wnd);
    GLFWwindow* AsWindow();
private:
    GLFWwindow* window;
};*/
