#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CharacterData.generated.h"

USTRUCT(BlueprintType)
struct FCharacterData
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName Name;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool bPlayable = false;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName Clan;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName AgeStage;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName StoryArc;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName AlignmentTendency;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TMap<FName, int32> Traits;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FName> Skills;
};

UCLASS(BlueprintType)
class SHATTEREDFATES_API UCharacterDataAsset : public UDataAsset
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FCharacterData> Characters;
};
