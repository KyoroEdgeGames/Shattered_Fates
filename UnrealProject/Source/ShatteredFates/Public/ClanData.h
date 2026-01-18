#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ClanData.generated.h"

USTRUCT(BlueprintType)
struct FClanData
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName Name;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName Leader;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName MedicineCat;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FName> Warriors;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName Territory;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TMap<FName, int32> Traits;
};

UCLASS(BlueprintType)
class SHATTEREDFATESPROJECT_API UClanDataAsset : public UDataAsset
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FClanData> Clans;
};
