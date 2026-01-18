using UnrealBuildTool;

public class ShatteredFatesProject : ModuleRules
{
    public ShatteredFatesProject(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        DefaultBuildSettings = BuildSettingsVersion.V6;
        PublicDependencyModuleNames.AddRange(new string[] {
            "Core", "CoreUObject", "Engine"
        });
        PrivateDependencyModuleNames.AddRange(new string[] { });
    }
}
