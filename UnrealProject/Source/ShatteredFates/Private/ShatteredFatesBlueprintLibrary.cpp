#include "ShatteredFatesBlueprintLibrary.h"
#include "Misc/FileHelper.h"
#include "Misc/Paths.h"
#include "Serialization/JsonSerializer.h"
#include "Dom/JsonObject.h"
#include "Engine/DataTable.h"
#include "UObject/StructOnScope.h"

static bool SF_LoadJsonObjectFromFile(const FString& Path, TSharedPtr<FJsonObject>& OutObj)
{
    FString Content;
    if (!FFileHelper::LoadFileToString(Content, *Path))
    {
        return false;
    }
    TSharedRef<TJsonReader<>> Reader = TJsonReaderFactory<>::Create(Content);
    TSharedPtr<FJsonObject> RootObj;
    if (!FJsonSerializer::Deserialize(Reader, RootObj) || !RootObj.IsValid())
    {
        return false;
    }
    OutObj = RootObj;
    return true;
}

template <typename TAsset>
static TAsset* SF_NewAsset()
{
    return NewObject<TAsset>(GetTransientPackage(), TAsset::StaticClass());
}

UCharacterDataAsset* UShatteredFatesBlueprintLibrary::LoadCharactersFromJsonFile(const FString& AbsolutePath)
{
    TSharedPtr<FJsonObject> Root;
    if (!SF_LoadJsonObjectFromFile(AbsolutePath, Root))
    {
        return nullptr;
    }
    const TArray<TSharedPtr<FJsonValue>>* Rows = nullptr;
    Root->TryGetArrayField(TEXT("rows"), Rows);
    UCharacterDataAsset* Asset = SF_NewAsset<UCharacterDataAsset>();
    if (!Rows)
    {
        return Asset;
    }
    for (const TSharedPtr<FJsonValue>& V : *Rows)
    {
        const TSharedPtr<FJsonObject>* RowObjPtr;
        if (!V->TryGetObject(RowObjPtr)) { continue; }
        const TSharedPtr<FJsonObject>& RowObj = *RowObjPtr;
        FCharacterData Row;
        FString NameStr;
        if (RowObj->TryGetStringField(TEXT("name"), NameStr)) { Row.Name = FName(NameStr); }
        bool Playable = false; RowObj->TryGetBoolField(TEXT("playable"), Playable); Row.bPlayable = Playable;
        FString ClanStr; if (RowObj->TryGetStringField(TEXT("clan"), ClanStr)) { Row.Clan = FName(ClanStr); }
        FString AgeStageStr; if (RowObj->TryGetStringField(TEXT("age_stage"), AgeStageStr)) { Row.AgeStage = FName(AgeStageStr); }
        FString StoryArcStr; if (RowObj->TryGetStringField(TEXT("story_arc"), StoryArcStr)) { Row.StoryArc = FName(StoryArcStr); }
        FString AlignStr; if (RowObj->TryGetStringField(TEXT("alignment_tendency"), AlignStr)) { Row.AlignmentTendency = FName(AlignStr); }
        const TSharedPtr<FJsonObject>* TraitsObjPtr; if (RowObj->TryGetObjectField(TEXT("traits"), TraitsObjPtr))
        {
            for (const auto& P : (*TraitsObjPtr)->Values)
            {
                int32 Val = 0;
                if (P.Value->TryGetNumber(Val)) { Row.Traits.Add(FName(P.Key), Val); }
            }
        }
        const TArray<TSharedPtr<FJsonValue>>* SkillsArr = nullptr; if (RowObj->TryGetArrayField(TEXT("skills"), SkillsArr))
        {
            for (const TSharedPtr<FJsonValue>& SV : *SkillsArr)
            {
                FString S; if (SV->TryGetString(S)) { Row.Skills.Add(FName(S)); }
            }
        }
        Asset->Characters.Add(Row);
    }
    return Asset;
}

UQuestDataAsset* UShatteredFatesBlueprintLibrary::LoadQuestsFromJsonFile(const FString& AbsolutePath)
{
    TSharedPtr<FJsonObject> Root;
    if (!SF_LoadJsonObjectFromFile(AbsolutePath, Root)) { return nullptr; }
    const TArray<TSharedPtr<FJsonValue>>* Rows = nullptr; Root->TryGetArrayField(TEXT("rows"), Rows);
    UQuestDataAsset* Asset = SF_NewAsset<UQuestDataAsset>();
    if (!Rows) { return Asset; }
    for (const TSharedPtr<FJsonValue>& V : *Rows)
    {
        const TSharedPtr<FJsonObject>* RowObjPtr; if (!V->TryGetObject(RowObjPtr)) { continue; }
        const TSharedPtr<FJsonObject>& RowObj = *RowObjPtr;
        FQuestData Row;
        FString IdStr; if (RowObj->TryGetStringField(TEXT("id"), IdStr)) { Row.Id = FName(IdStr); }
        FString NameStr; if (RowObj->TryGetStringField(TEXT("name"), NameStr)) { Row.Name = FText::FromString(NameStr); }
        FString DescStr; if (RowObj->TryGetStringField(TEXT("description"), DescStr)) { Row.Description = FText::FromString(DescStr); }
        FString RequiredAge; if (RowObj->TryGetStringField(TEXT("required_age"), RequiredAge)) { Row.RequiredAge = FName(RequiredAge); }
        FString Alignment; if (RowObj->TryGetStringField(TEXT("alignment"), Alignment)) { Row.Alignment = FName(Alignment); }
        FString StoryArc; if (RowObj->TryGetStringField(TEXT("story_arc"), StoryArc)) { Row.StoryArc = FName(StoryArc); }
        int32 StoryStage = 0; RowObj->TryGetNumberField(TEXT("story_stage"), StoryStage); Row.StoryStage = StoryStage;
        const TSharedPtr<FJsonObject>* RewardsObjPtr; if (RowObj->TryGetObjectField(TEXT("rewards"), RewardsObjPtr))
        {
            int32 XP = 0; (*RewardsObjPtr)->TryGetNumberField(TEXT("xp"), XP); Row.XP = XP;
            FString SkillUnlock; if ((*RewardsObjPtr)->TryGetStringField(TEXT("skill_unlock"), SkillUnlock)) { Row.SkillUnlock = FName(SkillUnlock); }
            FString AlignmentShift; if ((*RewardsObjPtr)->TryGetStringField(TEXT("alignment_shift"), AlignmentShift)) { Row.AlignmentShift = FName(AlignmentShift); }
            const TArray<TSharedPtr<FJsonValue>>* AlignChoice = nullptr; if ((*RewardsObjPtr)->TryGetArrayField(TEXT("alignment_choice"), AlignChoice))
            {
                for (const TSharedPtr<FJsonValue>& ACV : *AlignChoice)
                {
                    FString S; if (ACV->TryGetString(S)) { Row.AlignmentChoice.Add(FName(S)); }
                }
            }
            const TSharedPtr<FJsonObject>* RepObjPtr; if ((*RewardsObjPtr)->TryGetObjectField(TEXT("reputation_gain"), RepObjPtr))
            {
                for (const auto& P : (*RepObjPtr)->Values)
                {
                    int32 Val = 0; if (P.Value->TryGetNumber(Val)) { Row.ReputationGain.Add(FName(P.Key), Val); }
                }
            }
        }
        const TArray<TSharedPtr<FJsonValue>>* NPCArr = nullptr; if (RowObj->TryGetArrayField(TEXT("npc_involved"), NPCArr))
        {
            for (const TSharedPtr<FJsonValue>& NV : *NPCArr)
            {
                FString S; if (NV->TryGetString(S)) { Row.NPCInvolved.Add(FName(S)); }
            }
        }
        Asset->Quests.Add(Row);
    }
    return Asset;
}

UClanDataAsset* UShatteredFatesBlueprintLibrary::LoadClansFromJsonFile(const FString& AbsolutePath)
{
    TSharedPtr<FJsonObject> Root; if (!SF_LoadJsonObjectFromFile(AbsolutePath, Root)) { return nullptr; }
    UClanDataAsset* Asset = SF_NewAsset<UClanDataAsset>();
    const TSharedPtr<FJsonObject>* RowsObjPtr; if (Root->TryGetObjectField(TEXT("rows"), RowsObjPtr))
    {
        for (const auto& P : (*RowsObjPtr)->Values)
        {
            const TSharedPtr<FJsonObject>* CObjPtr; if (!P.Value->TryGetObject(CObjPtr)) { continue; }
            FClanData Row; Row.Name = FName(P.Key);
            FString Leader; (*CObjPtr)->TryGetStringField(TEXT("leader"), Leader); Row.Leader = FName(Leader);
            FString Med; (*CObjPtr)->TryGetStringField(TEXT("medicine_cat"), Med); Row.MedicineCat = FName(Med);
            FString Territory; (*CObjPtr)->TryGetStringField(TEXT("territory"), Territory); Row.Territory = FName(Territory);
            const TArray<TSharedPtr<FJsonValue>>* Wars = nullptr; (*CObjPtr)->TryGetArrayField(TEXT("warriors"), Wars);
            if (Wars)
            {
                for (const TSharedPtr<FJsonValue>& WV : *Wars)
                {
                    FString S; if (WV->TryGetString(S)) { Row.Warriors.Add(FName(S)); }
                }
            }
            const TSharedPtr<FJsonObject>* TraitsObjPtr; if ((*CObjPtr)->TryGetObjectField(TEXT("traits"), TraitsObjPtr))
            {
                for (const auto& TP : (*TraitsObjPtr)->Values)
                {
                    int32 Val = 0; if (TP.Value->TryGetNumber(Val)) { Row.Traits.Add(FName(TP.Key), Val); }
                }
            }
            Asset->Clans.Add(Row);
        }
    }
    else
    {
        for (const auto& P : Root->Values)
        {
            const TSharedPtr<FJsonObject>* CObjPtr; if (!P.Value->TryGetObject(CObjPtr)) { continue; }
            FClanData Row; Row.Name = FName(P.Key);
            FString Leader; (*CObjPtr)->TryGetStringField(TEXT("leader"), Leader); Row.Leader = FName(Leader);
            FString Med; (*CObjPtr)->TryGetStringField(TEXT("medicine_cat"), Med); Row.MedicineCat = FName(Med);
            FString Territory; (*CObjPtr)->TryGetStringField(TEXT("territory"), Territory); Row.Territory = FName(Territory);
            const TArray<TSharedPtr<FJsonValue>>* Wars = nullptr; (*CObjPtr)->TryGetArrayField(TEXT("warriors"), Wars);
            if (Wars)
            {
                for (const TSharedPtr<FJsonValue>& WV : *Wars)
                {
                    FString S; if (WV->TryGetString(S)) { Row.Warriors.Add(FName(S)); }
                }
            }
            const TSharedPtr<FJsonObject>* TraitsObjPtr; if ((*CObjPtr)->TryGetObjectField(TEXT("traits"), TraitsObjPtr))
            {
                for (const auto& TP : (*TraitsObjPtr)->Values)
                {
                    int32 Val = 0; if (TP.Value->TryGetNumber(Val)) { Row.Traits.Add(FName(TP.Key), Val); }
                }
            }
            Asset->Clans.Add(Row);
        }
    }
    return Asset;
}

UItemDataAsset* UShatteredFatesBlueprintLibrary::LoadItemsFromJsonFile(const FString& AbsolutePath)
{
    TSharedPtr<FJsonObject> Root; if (!SF_LoadJsonObjectFromFile(AbsolutePath, Root)) { return nullptr; }
    const TArray<TSharedPtr<FJsonValue>>* Rows = nullptr; Root->TryGetArrayField(TEXT("rows"), Rows);
    UItemDataAsset* Asset = SF_NewAsset<UItemDataAsset>(); if (!Rows) { return Asset; }
    for (const TSharedPtr<FJsonValue>& V : *Rows)
    {
        const TSharedPtr<FJsonObject>* ObjPtr; if (!V->TryGetObject(ObjPtr)) { continue; }
        FItemData Row;
        FString Id; (*ObjPtr)->TryGetStringField(TEXT("id"), Id); Row.Id = FName(Id);
        FString Name; (*ObjPtr)->TryGetStringField(TEXT("name"), Name); Row.Name = FText::FromString(Name);
        FString Type; (*ObjPtr)->TryGetStringField(TEXT("type"), Type); Row.Type = FName(Type);
        FString Desc; (*ObjPtr)->TryGetStringField(TEXT("description"), Desc); Row.Description = FText::FromString(Desc);
        int32 Val=0; (*ObjPtr)->TryGetNumberField(TEXT("value"), Val); Row.Value = Val;
        int32 Atk=0; (*ObjPtr)->TryGetNumberField(TEXT("attack"), Atk); Row.Attack = Atk;
        int32 Dur=0; (*ObjPtr)->TryGetNumberField(TEXT("durability"), Dur); Row.Durability = Dur;
        const TSharedPtr<FJsonObject>* EffObj; if ((*ObjPtr)->TryGetObjectField(TEXT("effect"), EffObj))
        {
            for (const auto& P : (*EffObj)->Values)
            {
                double D=0.0; if (P.Value->TryGetNumber(D)) { Row.Effect.Add(FName(P.Key), (float)D); }
            }
        }
        Asset->Items.Add(Row);
    }
    return Asset;
}

UHerbDataAsset* UShatteredFatesBlueprintLibrary::LoadHerbsFromJsonFile(const FString& AbsolutePath)
{
    TSharedPtr<FJsonObject> Root; if (!SF_LoadJsonObjectFromFile(AbsolutePath, Root)) { return nullptr; }
    const TArray<TSharedPtr<FJsonValue>>* Rows = nullptr; Root->TryGetArrayField(TEXT("rows"), Rows);
    UHerbDataAsset* Asset = SF_NewAsset<UHerbDataAsset>(); if (!Rows) { return Asset; }
    for (const TSharedPtr<FJsonValue>& V : *Rows)
    {
        const TSharedPtr<FJsonObject>* ObjPtr; if (!V->TryGetObject(ObjPtr)) { continue; }
        FHerbData Row;
        FString Id; (*ObjPtr)->TryGetStringField(TEXT("id"), Id); Row.Id = FName(Id);
        FString Name; (*ObjPtr)->TryGetStringField(TEXT("name"), Name); Row.Name = FText::FromString(Name);
        FString Desc; (*ObjPtr)->TryGetStringField(TEXT("description"), Desc); Row.Description = FText::FromString(Desc);
        FString Rarity; (*ObjPtr)->TryGetStringField(TEXT("rarity"), Rarity); Row.Rarity = FName(Rarity);
        const TSharedPtr<FJsonObject>* EffObj; if ((*ObjPtr)->TryGetObjectField(TEXT("effects"), EffObj))
        {
            for (const auto& P : (*EffObj)->Values)
            {
                double D=0.0; if (P.Value->TryGetNumber(D)) { Row.Effects.Add(FName(P.Key), (float)D); }
            }
        }
        Asset->Herbs.Add(Row);
    }
    return Asset;
}

template <typename TRow>
static UDataTable* SF_CreateDataTableFromCsv(const FString& AbsolutePath)
{
    FString Content;
    if (!FFileHelper::LoadFileToString(Content, *AbsolutePath))
    {
        return nullptr;
    }
    UDataTable* Table = NewObject<UDataTable>(GetTransientPackage(), UDataTable::StaticClass());
    Table->RowStruct = TBaseStructure<TRow>::Get();
    const bool bOk = Table->CreateTableFromCSVString(Content);
    if (!bOk)
    {
        return nullptr;
    }
    return Table;
}

UDataTable* UShatteredFatesBlueprintLibrary::LoadCharactersDataTableFromCsvFile(const FString& AbsolutePath)
{
    return SF_CreateDataTableFromCsv<FCharacterRow>(AbsolutePath);
}

UDataTable* UShatteredFatesBlueprintLibrary::LoadQuestsDataTableFromCsvFile(const FString& AbsolutePath)
{
    return SF_CreateDataTableFromCsv<FQuestRow>(AbsolutePath);
}

UDataTable* UShatteredFatesBlueprintLibrary::LoadClansDataTableFromCsvFile(const FString& AbsolutePath)
{
    return SF_CreateDataTableFromCsv<FClanRow>(AbsolutePath);
}

UDataTable* UShatteredFatesBlueprintLibrary::LoadItemsDataTableFromCsvFile(const FString& AbsolutePath)
{
    return SF_CreateDataTableFromCsv<FItemRow>(AbsolutePath);
}

UDataTable* UShatteredFatesBlueprintLibrary::LoadHerbsDataTableFromCsvFile(const FString& AbsolutePath)
{
    return SF_CreateDataTableFromCsv<FHerbRow>(AbsolutePath);
}

UDataTable* UShatteredFatesBlueprintLibrary::LoadSkillsDataTableFromCsvFile(const FString& AbsolutePath)
{
    return SF_CreateDataTableFromCsv<FSkillRow>(AbsolutePath);
}
