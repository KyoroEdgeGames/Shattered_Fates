using UnrealBuildTool;

// Legacy placeholder to avoid naming conflicts; not referenced by targets.
public class ShatteredFatesLegacy : ModuleRules
{
    public ShatteredFatesLegacy(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        DefaultBuildSettings = BuildSettingsVersion.V6;
        PublicDependencyModuleNames.AddRange(new string[] {
            "Core", "CoreUObject", "Engine"
        });
        PrivateDependencyModuleNames.AddRange(new string[] { });
    }
}
