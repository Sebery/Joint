#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Joint {

    class Window {
    private:
        // Callbacks
        static void FramebufferSizeCB(GLFWwindow* wnd, int width, int height);
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
        void ProcessInput();
    private:
        void SetCallbacks();
    private:
        GLFWwindow* window;
    };

}



