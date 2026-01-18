using UnrealBuildTool;
using System.Collections.Generic;

public class ShatteredFatesEditorTarget : TargetRules
{
    public ShatteredFatesEditorTarget(TargetInfo Target) : base(Target)
    {
        Type = TargetType.Editor;
        DefaultBuildSettings = BuildSettingsVersion.V6;
        IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_7;
        bOverrideBuildEnvironment = true;
        ExtraModuleNames.Add("ShatteredFatesGame");
    }
}
