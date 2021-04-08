#pragma once

#include <GLFW/glfw3.h>
#include "Joint/core/IEvents.h"

namespace Joint {

    // Module to create a window for the engine
    class Window : public IEvents {
    public:
        Window(int width, int height, const char* title);
        ~Window();
    public:
        void OnStartUp() override;
        void OnUpdate() override;
        void OnShutDown() override;
    private:
        GLFWwindow* window;
    };

}
