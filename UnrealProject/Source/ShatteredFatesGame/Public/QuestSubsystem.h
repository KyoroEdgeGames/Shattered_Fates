#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstanceSubsystem.h"
#include "QuestData.h"
#include "QuestSubsystem.generated.h"

UENUM(BlueprintType)
enum class EQuestStatus : uint8
{
    NotAccepted,
    Active,
    Completed,
    Failed
};

UCLASS()
class SHATTEREDFATESGAME_API UQuestSubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, Category="ShatteredFates|Quests")
    bool LoadFromJson(const FString& AbsolutePath);

    UFUNCTION(BlueprintCallable, Category="ShatteredFates|Quests")
    const TArray<FQuestData>& GetAllQuests() const { return Quests; }

    UFUNCTION(BlueprintCallable, Category="ShatteredFates|Quests")
    bool AcceptQuest(const FName& QuestId);

    UFUNCTION(BlueprintCallable, Category="ShatteredFates|Quests")
    bool CompleteQuest(const FName& QuestId);

    UFUNCTION(BlueprintCallable, Category="ShatteredFates|Quests")
    bool FailQuest(const FName& QuestId);

    UFUNCTION(BlueprintCallable, Category="ShatteredFates|Quests")
    EQuestStatus GetQuestStatus(const FName& QuestId) const;

    UFUNCTION(BlueprintCallable, Category="ShatteredFates|Quests")
    TArray<FName> GetQuestsByStatus(EQuestStatus Status) const;

private:
    const FQuestData* FindQuest(const FName& QuestId) const;

    UPROPERTY()
    TArray<FQuestData> Quests;

    UPROPERTY()
    TMap<FName, EQuestStatus> QuestStates;
};
