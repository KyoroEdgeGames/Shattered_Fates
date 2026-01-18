#include "ShatteredFatesGameInstance.h"
#include "Engine/Engine.h"
#include "Misc/Paths.h"
#include "HAL/PlatformFilemanager.h"
#include "ShatteredFatesBlueprintLibrary.h"
#include "CharacterSubsystem.h"

DEFINE_LOG_CATEGORY_STATIC(LogShatteredFatesGameInstance, Log, All);

void UShatteredFatesGameInstance::Init()
{
    Super::Init();
    LoadCharactersAtStartup();
}

bool UShatteredFatesGameInstance::LoadCharactersAtStartup()
{
    const FString AbsPath = GetCharactersJsonAbsolutePath();
    if (AbsPath.IsEmpty())
    {
        UE_LOG(LogShatteredFatesGameInstance, Warning, TEXT("Character JSON path empty"));
        return false;
    }

    IPlatformFile& PF = FPlatformFileManager::Get().GetPlatformFile();
    if (!PF.FileExists(*AbsPath))
    {
        UE_LOG(LogShatteredFatesGameInstance, Warning, TEXT("Character JSON not found: %s"), *AbsPath);
        return false;
    }

    UCharacterSubsystem* CharSys = GetSubsystem<UCharacterSubsystem>();
    if (!CharSys)
    {
        UE_LOG(LogShatteredFatesGameInstance, Error, TEXT("CharacterSubsystem missing"));
        return false;
    }

    const bool bOk = CharSys->LoadFromJson(AbsPath);
    UE_LOG(LogShatteredFatesGameInstance, Log, TEXT("LoadFromJson(%s) => %s"), *AbsPath, bOk ? TEXT("OK") : TEXT("FAIL"));
    return bOk;
}

FString UShatteredFatesGameInstance::GetCharactersJsonAbsolutePath() const
{
    // ProjectDir points to UnrealProject/, exported JSON is at repo root: export_unreal/json/Characters.json
    const FString Rel = FPaths::Combine(FPaths::ProjectDir(), TEXT(".."), TEXT("export_unreal/json/Characters.json"));
    return FPaths::ConvertRelativePathToFull(Rel);
}
