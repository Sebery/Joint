#pragma once

#include "Joint/Application.h"

int main() {
    auto app{ Application::CreateApplication() };

    if (!app->Initialize())
        return -1;

    app->Run();

    return 0;
}
