#include "CharacterSubsystem.h"
#include "ShatteredFatesBlueprintLibrary.h"

bool UCharacterSubsystem::LoadFromJson(const FString& AbsolutePath)
{
    UCharacterDataAsset* Asset = UShatteredFatesBlueprintLibrary::LoadCharactersFromJsonFile(AbsolutePath);
    if (!Asset)
    {
        return false;
    }
    DataAsset = Asset;
    return true;
}

void UCharacterSubsystem::SetDataAsset(UCharacterDataAsset* InAsset)
{
    DataAsset = InAsset;
}

const TArray<FCharacterData>& UCharacterSubsystem::GetAllCharacters() const
{
    static const TArray<FCharacterData> Empty;
    return DataAsset ? DataAsset->Characters : Empty;
}

TArray<FCharacterData> UCharacterSubsystem::GetPlayableCharacters() const
{
    TArray<FCharacterData> Out;
    if (!DataAsset)
    {
        return Out;
    }
    for (const FCharacterData& C : DataAsset->Characters)
    {
        if (C.bPlayable)
        {
            Out.Add(C);
        }
    }
    return Out;
}

bool UCharacterSubsystem::FindByName(const FName& Name, FCharacterData& OutCharacter) const
{
    if (!DataAsset)
    {
        return false;
    }
    for (const FCharacterData& C : DataAsset->Characters)
    {
        if (C.Name == Name)
        {
            OutCharacter = C;
            return true;
        }
    }
    return false;
}

TArray<FCharacterData> UCharacterSubsystem::FindByClan(const FName& Clan) const
{
    TArray<FCharacterData> Out;
    if (!DataAsset)
    {
        return Out;
    }
    for (const FCharacterData& C : DataAsset->Characters)
    {
        if (C.Clan == Clan)
        {
            Out.Add(C);
        }
    }
    return Out;
}
