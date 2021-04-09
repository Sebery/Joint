#pragma once

namespace Joint {

    class IEvent {
    public:
        virtual ~IEvent() = default;
    public:
        // Events called automatically
        virtual void OnStartUp() = 0;
        virtual void OnUpdate() = 0;
        virtual void OnShutDown() = 0;
    };

}
