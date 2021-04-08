#include "Joint/core/Module.h"

namespace Joint {

    Module::Module(IEvents* mdl)
        : module{ mdl } {
    }

    Module::~Module() {
        delete module;
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