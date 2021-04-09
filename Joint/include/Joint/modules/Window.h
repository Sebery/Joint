#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Joint/events/IWindowEvent.h"

namespace Joint {

    // Module to create a window for the engine,
    // You can create only one window with this module,
    // but you can easily create your own module to
    // allow the application more windows
    class Window : public IWindowEvent {
    public:
        Window(int width, int height, const char* title);
        ~Window();
    public:
        void OnStartUp() override;
        void OnUpdate() override;
        void OnShutDown() override;
        void OnInput() override;
    private:
        GLFWwindow* window;
    };

}
