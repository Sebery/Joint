#pragma once

#include "Joint/core/IEvents.h"

namespace Joint {

    // RAII class to manage modules
    class Module : public IEvents {
    public:
        explicit Module(IEvents* mdl);
        Module(Module&& mdl) noexcept;
        Module(const Module& mdl) = delete;
        ~Module();
    public:
        Module& operator=(Module&& mdl) noexcept;
        Module& operator=(const Module& mdl) = delete;
    public:
        void OnStartUp() override;
        void OnUpdate() override;
        void OnShutDown() override;
    private:
        IEvents* module;
    };

}
