#pragma once

#include "Joint/Application.h"

int main() {
    Joint::Console myCon{ "CLIENT" };
    myCon.Log("Hello World");
    myCon.Log("Logging, %d, %d, %d", 1, 2, 3);
    auto app{ Joint::Application::CreateApplication() };

    if (!app->Initialize())
        return -1;

    app->Run();

    return 0;
}
