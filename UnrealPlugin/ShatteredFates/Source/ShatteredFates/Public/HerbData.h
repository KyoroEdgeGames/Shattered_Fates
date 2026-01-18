#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "HerbData.generated.h"

USTRUCT(BlueprintType)
struct FHerbData
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName Id;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FText Name;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FText Description;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName Rarity;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TMap<FName, float> Effects;
};

UCLASS(BlueprintType)
class SHATTEREDFATES_API UHerbDataAsset : public UDataAsset
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FHerbData> Herbs;
};
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "HerbData.generated.h"

USTRUCT(BlueprintType)
struct FHerbData
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName Id;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FText Name;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FText Description;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName Rarity;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TMap<FName, float> Effects;
};

UCLASS(BlueprintType)
class SHATTEREDFATES_API UHerbDataAsset : public UDataAsset
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FHerbData> Herbs;
};
