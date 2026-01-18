#pragma once

#include "CoreMinimal.h"
#include "DataTableRows.generated.h"

// CSV → DataTable row structs to match tools/unreal_export.py outputs

USTRUCT(BlueprintType)
struct FCharacterRow
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName name;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    bool playable = false;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName clan;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName age_stage;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName story_arc;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName alignment_tendency;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString skills; // semicolon separated
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString traits_flat; // key:value;key2:value2
};

USTRUCT(BlueprintType)
struct FQuestRow
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName id;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString name;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString description;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName required_age;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName alignment;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName story_arc;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 story_stage = 0;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 rewards_xp = 0;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName rewards_skill_unlock;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName rewards_alignment_shift;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString rewards_alignment_choice; // semicolon separated
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString rewards_reputation_gain; // key:value;key2:value2
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString npc_involved; // semicolon separated
};

USTRUCT(BlueprintType)
struct FClanRow
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName name;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName leader;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName medicine_cat;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString warriors; // semicolon separated
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName territory;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString traits_flat; // key:value;key2:value2
};

USTRUCT(BlueprintType)
struct FItemRow
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName id;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString name;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName type;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString description;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 value = 0;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 attack = 0;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 durability = 0;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString effect_flat; // key:value;key2:value2
};

USTRUCT(BlueprintType)
struct FHerbRow
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName id;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString name;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString description;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName rarity;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString effects_flat; // key:value;key2:value2
};

USTRUCT(BlueprintType)
struct FSkillRow
{
    GENERATED_BODY()

    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FName name;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    int32 level_required = 0;
    UPROPERTY(EditAnywhere, BlueprintReadWrite)
    FString effect;
};
