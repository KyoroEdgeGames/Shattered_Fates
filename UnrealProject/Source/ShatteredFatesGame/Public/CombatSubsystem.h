#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstanceSubsystem.h"
#include "CombatSubsystem.generated.h"

UCLASS()
class SHATTEREDFATESGAME_API UCombatSubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, Category="ShatteredFates|Combat")
    void StartBattle();
};
