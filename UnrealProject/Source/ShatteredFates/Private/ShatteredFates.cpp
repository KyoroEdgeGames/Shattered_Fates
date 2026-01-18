#include "Modules/ModuleManager.h"

// Renamed game module stub to avoid collision with plugin module.
class FShatteredFatesProjectModule : public IModuleInterface
{
public:
	virtual void StartupModule() override {}
	virtual void ShutdownModule() override {}
};

IMPLEMENT_MODULE(FShatteredFatesProjectModule, ShatteredFatesProject)
