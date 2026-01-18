#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstanceSubsystem.h"
#include "SkillsSubsystem.generated.h"

UCLASS()
class SHATTEREDFATESGAME_API USkillsSubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, Category="ShatteredFates|Skills")
    void ResetSkills();

    UFUNCTION(BlueprintCallable, Category="ShatteredFates|Skills")
    bool UnlockSkill(const FName& Character, const FName& Skill);

    UFUNCTION(BlueprintCallable, Category="ShatteredFates|Skills")
    bool HasSkill(const FName& Character, const FName& Skill) const;

    UFUNCTION(BlueprintCallable, Category="ShatteredFates|Skills")
    TArray<FName> GetSkills(const FName& Character) const;

private:
    UPROPERTY()
    TMap<FName, TSet<FName>> CharacterSkills;
};
