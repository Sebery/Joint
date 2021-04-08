#include "Joint/core/Module.h"

namespace Joint {

    Module::Module(IEvents* mdl)
        : module{ mdl } {
    }

    Module::Module(Module&& mdl) noexcept
        : module{ mdl.module } {
        mdl.module = nullptr;
    }

    Module::~Module() {
        delete module;
    }

    Module& Module::operator=(Module&& mdl) noexcept {
        if (this != &mdl) {
            delete module;
            module = mdl.module;
            mdl.module = nullptr;
        }

        return *this;
    }

    void Module::OnStartUp() {
        module->OnStartUp();
    }

    void Module::OnUpdate() {
        module->OnUpdate();
    }

    void Module::OnShutDown() {
        module->OnShutDown();
    }

}