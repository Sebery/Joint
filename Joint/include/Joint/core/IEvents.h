#pragma once

namespace Joint {

    class IEvents {
    public:
        virtual ~IEvents() = default;
    public:
        virtual void OnStartUp() = 0;
        virtual void OnUpdate() = 0;
        virtual void OnShutDown() = 0;
    };

}
