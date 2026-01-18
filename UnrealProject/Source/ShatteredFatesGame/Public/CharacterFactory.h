#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "CharacterFactory.generated.h"

UCLASS()
class SHATTEREDFATESGAME_API UCharacterFactory : public UObject
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, Category="ShatteredFates|Characters")
    AActor* SpawnCharacter(UObject* WorldContextObject, TSubclassOf<AActor> CharacterClass, const FVector& Location);
};
