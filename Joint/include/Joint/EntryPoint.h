#pragma once

#include "Joint/Application.h"

int main() {
    auto app{ Joint::Application::CreateApplication() };

    if (!app->Initialize())
        return -1;

    app->Run();

    return 0;
}
