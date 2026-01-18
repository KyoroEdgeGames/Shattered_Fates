using UnrealBuildTool;

public class ShatteredFatesGame : ModuleRules
{
    public ShatteredFatesGame(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        DefaultBuildSettings = BuildSettingsVersion.V5;
        PublicDependencyModuleNames.AddRange(new string[] {
            "Core", "CoreUObject", "Engine", "ShatteredFatesProject", "NavigationSystem", "AIModule"
        });
        PrivateDependencyModuleNames.AddRange(new string[] { });
    }
}
