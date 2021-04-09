#pragma once

#include "Joint/events/IEvent.h"

namespace Joint {

    class IWindowEvent : public IEvent {
    public:
        virtual ~IWindowEvent() = default;
        // Events not called automatically}
        virtual void OnInput() = 0;
    };

}