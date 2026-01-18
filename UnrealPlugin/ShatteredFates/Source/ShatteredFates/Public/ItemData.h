#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ItemData.generated.h"

USTRUCT(BlueprintType)
struct FItemData
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName Id;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FText Name;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName Type;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FText Description;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Value = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Attack = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 Durability = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TMap<FName, float> Effect;
};

UCLASS(BlueprintType)
class SHATTEREDFATES_API UItemDataAsset : public UDataAsset
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FItemData> Items;
};
