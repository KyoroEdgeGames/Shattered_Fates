#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "WorldSubsystem.generated.h"

UCLASS()
class SHATTEREDFATESGAME_API UWorldSubsystemSF : public UWorldSubsystem
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, Category="ShatteredFates|World")
    void InitializeWorld();
};
