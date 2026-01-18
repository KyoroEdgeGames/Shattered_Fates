#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstanceSubsystem.h"
#include "CharacterData.h"
#include "CharacterSubsystem.generated.h"

/**
 * Character data manager for runtime queries and simple filters.
 * Loads from JSON via the existing blueprint library or accepts a data asset reference.
 */
UCLASS()
class SHATTEREDFATES_API UCharacterSubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable, Category="ShatteredFates|Characters")
    bool LoadFromJson(const FString& AbsolutePath);

    UFUNCTION(BlueprintCallable, Category="ShatteredFates|Characters")
    void SetDataAsset(UCharacterDataAsset* InAsset);

    UFUNCTION(BlueprintCallable, Category="ShatteredFates|Characters")
    const TArray<FCharacterData>& GetAllCharacters() const;

    UFUNCTION(BlueprintCallable, Category="ShatteredFates|Characters")
    TArray<FCharacterData> GetPlayableCharacters() const;

    UFUNCTION(BlueprintCallable, Category="ShatteredFates|Characters")
    bool FindByName(const FName& Name, FCharacterData& OutCharacter) const;

    UFUNCTION(BlueprintCallable, Category="ShatteredFates|Characters")
    TArray<FCharacterData> FindByClan(const FName& Clan) const;

private:
    UPROPERTY()
    UCharacterDataAsset* DataAsset = nullptr;
};
