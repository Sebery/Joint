#pragma once

#include <GLFW/glfw3.h>

namespace Joint {

    class Window {
    public:
        Window();
        Window(const char* title, int width, int height);
        Window(Window&& wnd) noexcept;
        Window(const Window& wnd) = delete;
        ~Window();
    public:
        Window& operator=(Window&& wnd) noexcept;
        Window& operator=(const Window& wnd) = delete;
    public:
        bool SetWindow(const char* title, int width, int height);
        void MakeContextCurrent();
        int WindowShouldClose() const;
        void SwapBuffers();
    private:
        GLFWwindow* window;
    };

}

/*
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
};*/


