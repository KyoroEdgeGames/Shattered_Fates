// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "DataTableRows.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeDataTableRows() {}

// ********** Begin Cross Module References ********************************************************
SHATTEREDFATESPROJECT_API UScriptStruct* Z_Construct_UScriptStruct_FCharacterRow();
SHATTEREDFATESPROJECT_API UScriptStruct* Z_Construct_UScriptStruct_FClanRow();
SHATTEREDFATESPROJECT_API UScriptStruct* Z_Construct_UScriptStruct_FHerbRow();
SHATTEREDFATESPROJECT_API UScriptStruct* Z_Construct_UScriptStruct_FItemRow();
SHATTEREDFATESPROJECT_API UScriptStruct* Z_Construct_UScriptStruct_FQuestRow();
SHATTEREDFATESPROJECT_API UScriptStruct* Z_Construct_UScriptStruct_FSkillRow();
UPackage* Z_Construct_UPackage__Script_ShatteredFatesProject();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FCharacterRow *****************************************************
struct Z_Construct_UScriptStruct_FCharacterRow_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FCharacterRow); }
	static inline consteval int16 GetStructAlignment() { return alignof(FCharacterRow); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/DataTableRows.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_name_MetaData[] = {
		{ "Category", "CharacterRow" },
		{ "ModuleRelativePath", "Public/DataTableRows.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_playable_MetaData[] = {
		{ "Category", "CharacterRow" },
		{ "ModuleRelativePath", "Public/DataTableRows.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_clan_MetaData[] = {
		{ "Category", "CharacterRow" },
		{ "ModuleRelativePath", "Public/DataTableRows.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_age_stage_MetaData[] = {
		{ "Category", "CharacterRow" },
		{ "ModuleRelativePath", "Public/DataTableRows.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_story_arc_MetaData[] = {
		{ "Category", "CharacterRow" },
		{ "ModuleRelativePath", "Public/DataTableRows.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_alignment_tendency_MetaData[] = {
		{ "Category", "CharacterRow" },
		{ "ModuleRelativePath", "Public/DataTableRows.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_skills_MetaData[] = {
		{ "Category", "CharacterRow" },
		{ "ModuleRelativePath", "Public/DataTableRows.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_traits_flat_MetaData[] = {
		{ "Category", "CharacterRow" },
		{ "ModuleRelativePath", "Public/DataTableRows.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FCharacterRow constinit property declarations *********************
	static const UECodeGen_Private::FNamePropertyParams NewProp_name;
	static void NewProp_playable_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_playable;
	static const UECodeGen_Private::FNamePropertyParams NewProp_clan;
	static const UECodeGen_Private::FNamePropertyParams NewProp_age_stage;
	static const UECodeGen_Private::FNamePropertyParams NewProp_story_arc;
	static const UECodeGen_Private::FNamePropertyParams NewProp_alignment_tendency;
	static const UECodeGen_Private::FStrPropertyParams NewProp_skills;
	static const UECodeGen_Private::FStrPropertyParams NewProp_traits_flat;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FCharacterRow constinit property declarations ***********************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FCharacterRow>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FCharacterRow_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FCharacterRow;
class UScriptStruct* FCharacterRow::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FCharacterRow.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FCharacterRow.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FCharacterRow, (UObject*)Z_Construct_UPackage__Script_ShatteredFatesProject(), TEXT("CharacterRow"));
	}
	return Z_Registration_Info_UScriptStruct_FCharacterRow.OuterSingleton;
	}

// ********** Begin ScriptStruct FCharacterRow Property Definitions ********************************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FCharacterRow_Statics::NewProp_name = { "name", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterRow, name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_name_MetaData), NewProp_name_MetaData) };
void Z_Construct_UScriptStruct_FCharacterRow_Statics::NewProp_playable_SetBit(void* Obj)
{
	((FCharacterRow*)Obj)->playable = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FCharacterRow_Statics::NewProp_playable = { "playable", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FCharacterRow), &Z_Construct_UScriptStruct_FCharacterRow_Statics::NewProp_playable_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_playable_MetaData), NewProp_playable_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FCharacterRow_Statics::NewProp_clan = { "clan", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterRow, clan), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_clan_MetaData), NewProp_clan_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FCharacterRow_Statics::NewProp_age_stage = { "age_stage", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterRow, age_stage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_age_stage_MetaData), NewProp_age_stage_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FCharacterRow_Statics::NewProp_story_arc = { "story_arc", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterRow, story_arc), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_story_arc_MetaData), NewProp_story_arc_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FCharacterRow_Statics::NewProp_alignment_tendency = { "alignment_tendency", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterRow, alignment_tendency), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_alignment_tendency_MetaData), NewProp_alignment_tendency_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FCharacterRow_Statics::NewProp_skills = { "skills", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterRow, skills), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_skills_MetaData), NewProp_skills_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FCharacterRow_Statics::NewProp_traits_flat = { "traits_flat", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterRow, traits_flat), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_traits_flat_MetaData), NewProp_traits_flat_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FCharacterRow_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterRow_Statics::NewProp_name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterRow_Statics::NewProp_playable,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterRow_Statics::NewProp_clan,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterRow_Statics::NewProp_age_stage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterRow_Statics::NewProp_story_arc,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterRow_Statics::NewProp_alignment_tendency,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterRow_Statics::NewProp_skills,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterRow_Statics::NewProp_traits_flat,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCharacterRow_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FCharacterRow Property Definitions **********************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FCharacterRow_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ShatteredFatesProject,
	nullptr,
	&NewStructOps,
	"CharacterRow",
	Z_Construct_UScriptStruct_FCharacterRow_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCharacterRow_Statics::PropPointers),
	sizeof(FCharacterRow),
	alignof(FCharacterRow),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCharacterRow_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FCharacterRow_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FCharacterRow()
{
	if (!Z_Registration_Info_UScriptStruct_FCharacterRow.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FCharacterRow.InnerSingleton, Z_Construct_UScriptStruct_FCharacterRow_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FCharacterRow.InnerSingleton);
}
// ********** End ScriptStruct FCharacterRow *******************************************************

// ********** Begin ScriptStruct FQuestRow *********************************************************
struct Z_Construct_UScriptStruct_FQuestRow_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FQuestRow); }
	static inline consteval int16 GetStructAlignment() { return alignof(FQuestRow); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/DataTableRows.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_id_MetaData[] = {
		{ "Category", "QuestRow" },
		{ "ModuleRelativePath", "Public/DataTableRows.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_name_MetaData[] = {
		{ "Category", "QuestRow" },
		{ "ModuleRelativePath", "Public/DataTableRows.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_description_MetaData[] = {
		{ "Category", "QuestRow" },
		{ "ModuleRelativePath", "Public/DataTableRows.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_required_age_MetaData[] = {
		{ "Category", "QuestRow" },
		{ "ModuleRelativePath", "Public/DataTableRows.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_alignment_MetaData[] = {
		{ "Category", "QuestRow" },
		{ "ModuleRelativePath", "Public/DataTableRows.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_story_arc_MetaData[] = {
		{ "Category", "QuestRow" },
		{ "ModuleRelativePath", "Public/DataTableRows.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_story_stage_MetaData[] = {
		{ "Category", "QuestRow" },
		{ "ModuleRelativePath", "Public/DataTableRows.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_rewards_xp_MetaData[] = {
		{ "Category", "QuestRow" },
		{ "ModuleRelativePath", "Public/DataTableRows.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_rewards_skill_unlock_MetaData[] = {
		{ "Category", "QuestRow" },
		{ "ModuleRelativePath", "Public/DataTableRows.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_rewards_alignment_shift_MetaData[] = {
		{ "Category", "QuestRow" },
		{ "ModuleRelativePath", "Public/DataTableRows.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_rewards_alignment_choice_MetaData[] = {
		{ "Category", "QuestRow" },
		{ "ModuleRelativePath", "Public/DataTableRows.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_rewards_reputation_gain_MetaData[] = {
		{ "Category", "QuestRow" },
		{ "ModuleRelativePath", "Public/DataTableRows.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_npc_involved_MetaData[] = {
		{ "Category", "QuestRow" },
		{ "ModuleRelativePath", "Public/DataTableRows.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FQuestRow constinit property declarations *************************
	static const UECodeGen_Private::FNamePropertyParams NewProp_id;
	static const UECodeGen_Private::FStrPropertyParams NewProp_name;
	static const UECodeGen_Private::FStrPropertyParams NewProp_description;
	static const UECodeGen_Private::FNamePropertyParams NewProp_required_age;
	static const UECodeGen_Private::FNamePropertyParams NewProp_alignment;
	static const UECodeGen_Private::FNamePropertyParams NewProp_story_arc;
	static const UECodeGen_Private::FIntPropertyParams NewProp_story_stage;
	static const UECodeGen_Private::FIntPropertyParams NewProp_rewards_xp;
	static const UECodeGen_Private::FNamePropertyParams NewProp_rewards_skill_unlock;
	static const UECodeGen_Private::FNamePropertyParams NewProp_rewards_alignment_shift;
	static const UECodeGen_Private::FStrPropertyParams NewProp_rewards_alignment_choice;
	static const UECodeGen_Private::FStrPropertyParams NewProp_rewards_reputation_gain;
	static const UECodeGen_Private::FStrPropertyParams NewProp_npc_involved;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FQuestRow constinit property declarations ***************************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FQuestRow>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FQuestRow_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FQuestRow;
class UScriptStruct* FQuestRow::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FQuestRow.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FQuestRow.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FQuestRow, (UObject*)Z_Construct_UPackage__Script_ShatteredFatesProject(), TEXT("QuestRow"));
	}
	return Z_Registration_Info_UScriptStruct_FQuestRow.OuterSingleton;
	}

// ********** Begin ScriptStruct FQuestRow Property Definitions ************************************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FQuestRow_Statics::NewProp_id = { "id", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FQuestRow, id), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_id_MetaData), NewProp_id_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FQuestRow_Statics::NewProp_name = { "name", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FQuestRow, name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_name_MetaData), NewProp_name_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FQuestRow_Statics::NewProp_description = { "description", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FQuestRow, description), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_description_MetaData), NewProp_description_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FQuestRow_Statics::NewProp_required_age = { "required_age", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FQuestRow, required_age), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_required_age_MetaData), NewProp_required_age_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FQuestRow_Statics::NewProp_alignment = { "alignment", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FQuestRow, alignment), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_alignment_MetaData), NewProp_alignment_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FQuestRow_Statics::NewProp_story_arc = { "story_arc", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FQuestRow, story_arc), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_story_arc_MetaData), NewProp_story_arc_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FQuestRow_Statics::NewProp_story_stage = { "story_stage", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FQuestRow, story_stage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_story_stage_MetaData), NewProp_story_stage_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FQuestRow_Statics::NewProp_rewards_xp = { "rewards_xp", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FQuestRow, rewards_xp), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_rewards_xp_MetaData), NewProp_rewards_xp_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FQuestRow_Statics::NewProp_rewards_skill_unlock = { "rewards_skill_unlock", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FQuestRow, rewards_skill_unlock), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_rewards_skill_unlock_MetaData), NewProp_rewards_skill_unlock_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FQuestRow_Statics::NewProp_rewards_alignment_shift = { "rewards_alignment_shift", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FQuestRow, rewards_alignment_shift), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_rewards_alignment_shift_MetaData), NewProp_rewards_alignment_shift_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FQuestRow_Statics::NewProp_rewards_alignment_choice = { "rewards_alignment_choice", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FQuestRow, rewards_alignment_choice), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_rewards_alignment_choice_MetaData), NewProp_rewards_alignment_choice_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FQuestRow_Statics::NewProp_rewards_reputation_gain = { "rewards_reputation_gain", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FQuestRow, rewards_reputation_gain), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_rewards_reputation_gain_MetaData), NewProp_rewards_reputation_gain_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FQuestRow_Statics::NewProp_npc_involved = { "npc_involved", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FQuestRow, npc_involved), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_npc_involved_MetaData), NewProp_npc_involved_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FQuestRow_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FQuestRow_Statics::NewProp_id,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FQuestRow_Statics::NewProp_name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FQuestRow_Statics::NewProp_description,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FQuestRow_Statics::NewProp_required_age,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FQuestRow_Statics::NewProp_alignment,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FQuestRow_Statics::NewProp_story_arc,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FQuestRow_Statics::NewProp_story_stage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FQuestRow_Statics::NewProp_rewards_xp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FQuestRow_Statics::NewProp_rewards_skill_unlock,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FQuestRow_Statics::NewProp_rewards_alignment_shift,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FQuestRow_Statics::NewProp_rewards_alignment_choice,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FQuestRow_Statics::NewProp_rewards_reputation_gain,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FQuestRow_Statics::NewProp_npc_involved,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FQuestRow_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FQuestRow Property Definitions **************************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FQuestRow_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ShatteredFatesProject,
	nullptr,
	&NewStructOps,
	"QuestRow",
	Z_Construct_UScriptStruct_FQuestRow_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FQuestRow_Statics::PropPointers),
	sizeof(FQuestRow),
	alignof(FQuestRow),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FQuestRow_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FQuestRow_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FQuestRow()
{
	if (!Z_Registration_Info_UScriptStruct_FQuestRow.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FQuestRow.InnerSingleton, Z_Construct_UScriptStruct_FQuestRow_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FQuestRow.InnerSingleton);
}
// ********** End ScriptStruct FQuestRow ***********************************************************

// ********** Begin ScriptStruct FClanRow **********************************************************
struct Z_Construct_UScriptStruct_FClanRow_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FClanRow); }
	static inline consteval int16 GetStructAlignment() { return alignof(FClanRow); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/DataTableRows.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_name_MetaData[] = {
		{ "Category", "ClanRow" },
		{ "ModuleRelativePath", "Public/DataTableRows.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_leader_MetaData[] = {
		{ "Category", "ClanRow" },
		{ "ModuleRelativePath", "Public/DataTableRows.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_medicine_cat_MetaData[] = {
		{ "Category", "ClanRow" },
		{ "ModuleRelativePath", "Public/DataTableRows.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_warriors_MetaData[] = {
		{ "Category", "ClanRow" },
		{ "ModuleRelativePath", "Public/DataTableRows.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_territory_MetaData[] = {
		{ "Category", "ClanRow" },
		{ "ModuleRelativePath", "Public/DataTableRows.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_traits_flat_MetaData[] = {
		{ "Category", "ClanRow" },
		{ "ModuleRelativePath", "Public/DataTableRows.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FClanRow constinit property declarations **************************
	static const UECodeGen_Private::FNamePropertyParams NewProp_name;
	static const UECodeGen_Private::FNamePropertyParams NewProp_leader;
	static const UECodeGen_Private::FNamePropertyParams NewProp_medicine_cat;
	static const UECodeGen_Private::FStrPropertyParams NewProp_warriors;
	static const UECodeGen_Private::FNamePropertyParams NewProp_territory;
	static const UECodeGen_Private::FStrPropertyParams NewProp_traits_flat;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FClanRow constinit property declarations ****************************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FClanRow>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FClanRow_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FClanRow;
class UScriptStruct* FClanRow::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FClanRow.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FClanRow.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FClanRow, (UObject*)Z_Construct_UPackage__Script_ShatteredFatesProject(), TEXT("ClanRow"));
	}
	return Z_Registration_Info_UScriptStruct_FClanRow.OuterSingleton;
	}

// ********** Begin ScriptStruct FClanRow Property Definitions *************************************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FClanRow_Statics::NewProp_name = { "name", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FClanRow, name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_name_MetaData), NewProp_name_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FClanRow_Statics::NewProp_leader = { "leader", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FClanRow, leader), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_leader_MetaData), NewProp_leader_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FClanRow_Statics::NewProp_medicine_cat = { "medicine_cat", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FClanRow, medicine_cat), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_medicine_cat_MetaData), NewProp_medicine_cat_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FClanRow_Statics::NewProp_warriors = { "warriors", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FClanRow, warriors), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_warriors_MetaData), NewProp_warriors_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FClanRow_Statics::NewProp_territory = { "territory", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FClanRow, territory), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_territory_MetaData), NewProp_territory_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FClanRow_Statics::NewProp_traits_flat = { "traits_flat", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FClanRow, traits_flat), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_traits_flat_MetaData), NewProp_traits_flat_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FClanRow_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClanRow_Statics::NewProp_name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClanRow_Statics::NewProp_leader,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClanRow_Statics::NewProp_medicine_cat,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClanRow_Statics::NewProp_warriors,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClanRow_Statics::NewProp_territory,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClanRow_Statics::NewProp_traits_flat,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FClanRow_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FClanRow Property Definitions ***************************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FClanRow_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ShatteredFatesProject,
	nullptr,
	&NewStructOps,
	"ClanRow",
	Z_Construct_UScriptStruct_FClanRow_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FClanRow_Statics::PropPointers),
	sizeof(FClanRow),
	alignof(FClanRow),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FClanRow_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FClanRow_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FClanRow()
{
	if (!Z_Registration_Info_UScriptStruct_FClanRow.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FClanRow.InnerSingleton, Z_Construct_UScriptStruct_FClanRow_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FClanRow.InnerSingleton);
}
// ********** End ScriptStruct FClanRow ************************************************************

// ********** Begin ScriptStruct FItemRow **********************************************************
struct Z_Construct_UScriptStruct_FItemRow_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FItemRow); }
	static inline consteval int16 GetStructAlignment() { return alignof(FItemRow); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/DataTableRows.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_id_MetaData[] = {
		{ "Category", "ItemRow" },
		{ "ModuleRelativePath", "Public/DataTableRows.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_name_MetaData[] = {
		{ "Category", "ItemRow" },
		{ "ModuleRelativePath", "Public/DataTableRows.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_type_MetaData[] = {
		{ "Category", "ItemRow" },
		{ "ModuleRelativePath", "Public/DataTableRows.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_description_MetaData[] = {
		{ "Category", "ItemRow" },
		{ "ModuleRelativePath", "Public/DataTableRows.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_value_MetaData[] = {
		{ "Category", "ItemRow" },
		{ "ModuleRelativePath", "Public/DataTableRows.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_attack_MetaData[] = {
		{ "Category", "ItemRow" },
		{ "ModuleRelativePath", "Public/DataTableRows.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_durability_MetaData[] = {
		{ "Category", "ItemRow" },
		{ "ModuleRelativePath", "Public/DataTableRows.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_effect_flat_MetaData[] = {
		{ "Category", "ItemRow" },
		{ "ModuleRelativePath", "Public/DataTableRows.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FItemRow constinit property declarations **************************
	static const UECodeGen_Private::FNamePropertyParams NewProp_id;
	static const UECodeGen_Private::FStrPropertyParams NewProp_name;
	static const UECodeGen_Private::FNamePropertyParams NewProp_type;
	static const UECodeGen_Private::FStrPropertyParams NewProp_description;
	static const UECodeGen_Private::FIntPropertyParams NewProp_value;
	static const UECodeGen_Private::FIntPropertyParams NewProp_attack;
	static const UECodeGen_Private::FIntPropertyParams NewProp_durability;
	static const UECodeGen_Private::FStrPropertyParams NewProp_effect_flat;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FItemRow constinit property declarations ****************************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FItemRow>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FItemRow_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FItemRow;
class UScriptStruct* FItemRow::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FItemRow.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FItemRow.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FItemRow, (UObject*)Z_Construct_UPackage__Script_ShatteredFatesProject(), TEXT("ItemRow"));
	}
	return Z_Registration_Info_UScriptStruct_FItemRow.OuterSingleton;
	}

// ********** Begin ScriptStruct FItemRow Property Definitions *************************************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FItemRow_Statics::NewProp_id = { "id", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FItemRow, id), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_id_MetaData), NewProp_id_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FItemRow_Statics::NewProp_name = { "name", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FItemRow, name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_name_MetaData), NewProp_name_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FItemRow_Statics::NewProp_type = { "type", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FItemRow, type), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_type_MetaData), NewProp_type_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FItemRow_Statics::NewProp_description = { "description", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FItemRow, description), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_description_MetaData), NewProp_description_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FItemRow_Statics::NewProp_value = { "value", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FItemRow, value), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_value_MetaData), NewProp_value_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FItemRow_Statics::NewProp_attack = { "attack", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FItemRow, attack), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_attack_MetaData), NewProp_attack_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FItemRow_Statics::NewProp_durability = { "durability", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FItemRow, durability), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_durability_MetaData), NewProp_durability_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FItemRow_Statics::NewProp_effect_flat = { "effect_flat", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FItemRow, effect_flat), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_effect_flat_MetaData), NewProp_effect_flat_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FItemRow_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FItemRow_Statics::NewProp_id,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FItemRow_Statics::NewProp_name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FItemRow_Statics::NewProp_type,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FItemRow_Statics::NewProp_description,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FItemRow_Statics::NewProp_value,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FItemRow_Statics::NewProp_attack,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FItemRow_Statics::NewProp_durability,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FItemRow_Statics::NewProp_effect_flat,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FItemRow_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FItemRow Property Definitions ***************************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FItemRow_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ShatteredFatesProject,
	nullptr,
	&NewStructOps,
	"ItemRow",
	Z_Construct_UScriptStruct_FItemRow_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FItemRow_Statics::PropPointers),
	sizeof(FItemRow),
	alignof(FItemRow),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FItemRow_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FItemRow_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FItemRow()
{
	if (!Z_Registration_Info_UScriptStruct_FItemRow.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FItemRow.InnerSingleton, Z_Construct_UScriptStruct_FItemRow_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FItemRow.InnerSingleton);
}
// ********** End ScriptStruct FItemRow ************************************************************

// ********** Begin ScriptStruct FHerbRow **********************************************************
struct Z_Construct_UScriptStruct_FHerbRow_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FHerbRow); }
	static inline consteval int16 GetStructAlignment() { return alignof(FHerbRow); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/DataTableRows.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_id_MetaData[] = {
		{ "Category", "HerbRow" },
		{ "ModuleRelativePath", "Public/DataTableRows.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_name_MetaData[] = {
		{ "Category", "HerbRow" },
		{ "ModuleRelativePath", "Public/DataTableRows.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_description_MetaData[] = {
		{ "Category", "HerbRow" },
		{ "ModuleRelativePath", "Public/DataTableRows.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_rarity_MetaData[] = {
		{ "Category", "HerbRow" },
		{ "ModuleRelativePath", "Public/DataTableRows.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_effects_flat_MetaData[] = {
		{ "Category", "HerbRow" },
		{ "ModuleRelativePath", "Public/DataTableRows.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FHerbRow constinit property declarations **************************
	static const UECodeGen_Private::FNamePropertyParams NewProp_id;
	static const UECodeGen_Private::FStrPropertyParams NewProp_name;
	static const UECodeGen_Private::FStrPropertyParams NewProp_description;
	static const UECodeGen_Private::FNamePropertyParams NewProp_rarity;
	static const UECodeGen_Private::FStrPropertyParams NewProp_effects_flat;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FHerbRow constinit property declarations ****************************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FHerbRow>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FHerbRow_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FHerbRow;
class UScriptStruct* FHerbRow::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FHerbRow.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FHerbRow.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FHerbRow, (UObject*)Z_Construct_UPackage__Script_ShatteredFatesProject(), TEXT("HerbRow"));
	}
	return Z_Registration_Info_UScriptStruct_FHerbRow.OuterSingleton;
	}

// ********** Begin ScriptStruct FHerbRow Property Definitions *************************************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FHerbRow_Statics::NewProp_id = { "id", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHerbRow, id), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_id_MetaData), NewProp_id_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FHerbRow_Statics::NewProp_name = { "name", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHerbRow, name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_name_MetaData), NewProp_name_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FHerbRow_Statics::NewProp_description = { "description", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHerbRow, description), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_description_MetaData), NewProp_description_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FHerbRow_Statics::NewProp_rarity = { "rarity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHerbRow, rarity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_rarity_MetaData), NewProp_rarity_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FHerbRow_Statics::NewProp_effects_flat = { "effects_flat", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHerbRow, effects_flat), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_effects_flat_MetaData), NewProp_effects_flat_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FHerbRow_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHerbRow_Statics::NewProp_id,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHerbRow_Statics::NewProp_name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHerbRow_Statics::NewProp_description,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHerbRow_Statics::NewProp_rarity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHerbRow_Statics::NewProp_effects_flat,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHerbRow_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FHerbRow Property Definitions ***************************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FHerbRow_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ShatteredFatesProject,
	nullptr,
	&NewStructOps,
	"HerbRow",
	Z_Construct_UScriptStruct_FHerbRow_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHerbRow_Statics::PropPointers),
	sizeof(FHerbRow),
	alignof(FHerbRow),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHerbRow_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FHerbRow_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FHerbRow()
{
	if (!Z_Registration_Info_UScriptStruct_FHerbRow.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FHerbRow.InnerSingleton, Z_Construct_UScriptStruct_FHerbRow_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FHerbRow.InnerSingleton);
}
// ********** End ScriptStruct FHerbRow ************************************************************

// ********** Begin ScriptStruct FSkillRow *********************************************************
struct Z_Construct_UScriptStruct_FSkillRow_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FSkillRow); }
	static inline consteval int16 GetStructAlignment() { return alignof(FSkillRow); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/DataTableRows.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_name_MetaData[] = {
		{ "Category", "SkillRow" },
		{ "ModuleRelativePath", "Public/DataTableRows.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_level_required_MetaData[] = {
		{ "Category", "SkillRow" },
		{ "ModuleRelativePath", "Public/DataTableRows.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_effect_MetaData[] = {
		{ "Category", "SkillRow" },
		{ "ModuleRelativePath", "Public/DataTableRows.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FSkillRow constinit property declarations *************************
	static const UECodeGen_Private::FNamePropertyParams NewProp_name;
	static const UECodeGen_Private::FIntPropertyParams NewProp_level_required;
	static const UECodeGen_Private::FStrPropertyParams NewProp_effect;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FSkillRow constinit property declarations ***************************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FSkillRow>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FSkillRow_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FSkillRow;
class UScriptStruct* FSkillRow::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FSkillRow.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FSkillRow.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FSkillRow, (UObject*)Z_Construct_UPackage__Script_ShatteredFatesProject(), TEXT("SkillRow"));
	}
	return Z_Registration_Info_UScriptStruct_FSkillRow.OuterSingleton;
	}

// ********** Begin ScriptStruct FSkillRow Property Definitions ************************************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FSkillRow_Statics::NewProp_name = { "name", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSkillRow, name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_name_MetaData), NewProp_name_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FSkillRow_Statics::NewProp_level_required = { "level_required", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSkillRow, level_required), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_level_required_MetaData), NewProp_level_required_MetaData) };
const UECodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FSkillRow_Statics::NewProp_effect = { "effect", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FSkillRow, effect), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_effect_MetaData), NewProp_effect_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FSkillRow_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSkillRow_Statics::NewProp_name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSkillRow_Statics::NewProp_level_required,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FSkillRow_Statics::NewProp_effect,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSkillRow_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FSkillRow Property Definitions **************************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FSkillRow_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ShatteredFatesProject,
	nullptr,
	&NewStructOps,
	"SkillRow",
	Z_Construct_UScriptStruct_FSkillRow_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSkillRow_Statics::PropPointers),
	sizeof(FSkillRow),
	alignof(FSkillRow),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FSkillRow_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FSkillRow_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FSkillRow()
{
	if (!Z_Registration_Info_UScriptStruct_FSkillRow.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FSkillRow.InnerSingleton, Z_Construct_UScriptStruct_FSkillRow_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FSkillRow.InnerSingleton);
}
// ********** End ScriptStruct FSkillRow ***********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesProject_Public_DataTableRows_h__Script_ShatteredFatesProject_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FCharacterRow::StaticStruct, Z_Construct_UScriptStruct_FCharacterRow_Statics::NewStructOps, TEXT("CharacterRow"),&Z_Registration_Info_UScriptStruct_FCharacterRow, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FCharacterRow), 2384244809U) },
		{ FQuestRow::StaticStruct, Z_Construct_UScriptStruct_FQuestRow_Statics::NewStructOps, TEXT("QuestRow"),&Z_Registration_Info_UScriptStruct_FQuestRow, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FQuestRow), 2997296871U) },
		{ FClanRow::StaticStruct, Z_Construct_UScriptStruct_FClanRow_Statics::NewStructOps, TEXT("ClanRow"),&Z_Registration_Info_UScriptStruct_FClanRow, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FClanRow), 2929141952U) },
		{ FItemRow::StaticStruct, Z_Construct_UScriptStruct_FItemRow_Statics::NewStructOps, TEXT("ItemRow"),&Z_Registration_Info_UScriptStruct_FItemRow, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FItemRow), 3923295884U) },
		{ FHerbRow::StaticStruct, Z_Construct_UScriptStruct_FHerbRow_Statics::NewStructOps, TEXT("HerbRow"),&Z_Registration_Info_UScriptStruct_FHerbRow, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FHerbRow), 1920288914U) },
		{ FSkillRow::StaticStruct, Z_Construct_UScriptStruct_FSkillRow_Statics::NewStructOps, TEXT("SkillRow"),&Z_Registration_Info_UScriptStruct_FSkillRow, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FSkillRow), 3707047080U) },
	};
}; // Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesProject_Public_DataTableRows_h__Script_ShatteredFatesProject_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesProject_Public_DataTableRows_h__Script_ShatteredFatesProject_961158567{
	TEXT("/Script/ShatteredFatesProject"),
	nullptr, 0,
	Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesProject_Public_DataTableRows_h__Script_ShatteredFatesProject_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesProject_Public_DataTableRows_h__Script_ShatteredFatesProject_Statics::ScriptStructInfo),
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
