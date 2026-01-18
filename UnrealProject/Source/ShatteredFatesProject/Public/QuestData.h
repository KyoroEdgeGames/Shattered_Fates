#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "QuestData.generated.h"

USTRUCT(BlueprintType)
struct FQuestData
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName Id;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FText Name;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FText Description;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName RequiredAge;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName Alignment;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName StoryArc;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 StoryStage = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 XP = 0;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName SkillUnlock;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName AlignmentShift;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FName> AlignmentChoice;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TMap<FName, int32> ReputationGain;

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FName> NPCInvolved;
};

UCLASS(BlueprintType)
class SHATTEREDFATESPROJECT_API UQuestDataAsset : public UDataAsset
{
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    TArray<FQuestData> Quests;
};
