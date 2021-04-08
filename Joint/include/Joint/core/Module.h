#pragma once

#include "Joint/core/IEvents.h"

namespace Joint {

    class Module : public IEvents {
    public:
        explicit Module(IEvents* mdl);
        Module(Module&& mdl) = delete;
        Module(const Module& mdl) = delete;
        ~Module();
    public:
        Module& operator=(Module&& mdl) = delete;
        Module& operator=(const Module& mdl) = delete;
    public:
        void OnStartUp() override;
        void OnUpdate() override;
        void OnShutDown() override;
    private:
        IEvents* module;
    };

}
