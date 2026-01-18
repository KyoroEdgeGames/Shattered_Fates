#include "ShatteredFates.h"
#include "Modules/ModuleManager.h"

class FShatteredFatesModule : public IModuleInterface
{
public:
    virtual void StartupModule() override {}
    virtual void ShutdownModule() override {}
};

IMPLEMENT_MODULE(FShatteredFatesModule, ShatteredFates)
