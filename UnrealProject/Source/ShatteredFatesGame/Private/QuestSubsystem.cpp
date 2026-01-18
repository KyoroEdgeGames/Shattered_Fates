#include "QuestSubsystem.h"
#include "ShatteredFatesBlueprintLibrary.h"

bool UQuestSubsystem::LoadFromJson(const FString& AbsolutePath)
{
    UQuestDataAsset* Asset = UShatteredFatesBlueprintLibrary::LoadQuestsFromJsonFile(AbsolutePath);
    Quests.Reset();
    if (!Asset) { return false; }
    Quests = Asset->Quests;
    return true;
}
