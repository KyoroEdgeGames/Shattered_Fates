#include "ShatteredFates.h"
#include "Modules/ModuleManager.h"

class FShatteredFatesProjectModule : public IModuleInterface
{
public:
    virtual void StartupModule() override {}
    virtual void ShutdownModule() override {}
};

IMPLEMENT_MODULE(FShatteredFatesProjectModule, ShatteredFatesProject)
