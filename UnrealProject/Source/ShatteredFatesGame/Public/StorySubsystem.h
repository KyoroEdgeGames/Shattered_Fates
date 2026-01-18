#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstanceSubsystem.h"
#include "StorySubsystem.generated.h"

UCLASS()
class SHATTEREDFATESGAME_API UStorySubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, Category="ShatteredFates|Story")
    void ResetStory() {}
};
