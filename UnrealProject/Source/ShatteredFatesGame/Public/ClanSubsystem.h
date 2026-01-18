#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstanceSubsystem.h"
#include "ClanData.h"
#include "ClanSubsystem.generated.h"

UCLASS()
class SHATTEREDFATESGAME_API UClanSubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, Category="ShatteredFates|Clans")
    void SetDataAsset(UClanDataAsset* InAsset);

    UFUNCTION(BlueprintCallable, Category="ShatteredFates|Clans")
    TArray<FClanData> GetAllClans() const;

private:
    UPROPERTY()
    UClanDataAsset* DataAsset = nullptr;
};
