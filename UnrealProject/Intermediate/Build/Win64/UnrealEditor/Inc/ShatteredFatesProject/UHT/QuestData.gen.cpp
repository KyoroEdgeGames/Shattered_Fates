// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "QuestData.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeQuestData() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UDataAsset();
SHATTEREDFATESPROJECT_API UClass* Z_Construct_UClass_UQuestDataAsset();
SHATTEREDFATESPROJECT_API UClass* Z_Construct_UClass_UQuestDataAsset_NoRegister();
SHATTEREDFATESPROJECT_API UScriptStruct* Z_Construct_UScriptStruct_FQuestData();
UPackage* Z_Construct_UPackage__Script_ShatteredFatesProject();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FQuestData ********************************************************
struct Z_Construct_UScriptStruct_FQuestData_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FQuestData); }
	static inline consteval int16 GetStructAlignment() { return alignof(FQuestData); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/QuestData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Id_MetaData[] = {
		{ "Category", "QuestData" },
		{ "ModuleRelativePath", "Public/QuestData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "Category", "QuestData" },
		{ "ModuleRelativePath", "Public/QuestData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Description_MetaData[] = {
		{ "Category", "QuestData" },
		{ "ModuleRelativePath", "Public/QuestData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_RequiredAge_MetaData[] = {
		{ "Category", "QuestData" },
		{ "ModuleRelativePath", "Public/QuestData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Alignment_MetaData[] = {
		{ "Category", "QuestData" },
		{ "ModuleRelativePath", "Public/QuestData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StoryArc_MetaData[] = {
		{ "Category", "QuestData" },
		{ "ModuleRelativePath", "Public/QuestData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StoryStage_MetaData[] = {
		{ "Category", "QuestData" },
		{ "ModuleRelativePath", "Public/QuestData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_XP_MetaData[] = {
		{ "Category", "QuestData" },
		{ "ModuleRelativePath", "Public/QuestData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_SkillUnlock_MetaData[] = {
		{ "Category", "QuestData" },
		{ "ModuleRelativePath", "Public/QuestData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AlignmentShift_MetaData[] = {
		{ "Category", "QuestData" },
		{ "ModuleRelativePath", "Public/QuestData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AlignmentChoice_MetaData[] = {
		{ "Category", "QuestData" },
		{ "ModuleRelativePath", "Public/QuestData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReputationGain_MetaData[] = {
		{ "Category", "QuestData" },
		{ "ModuleRelativePath", "Public/QuestData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_NPCInvolved_MetaData[] = {
		{ "Category", "QuestData" },
		{ "ModuleRelativePath", "Public/QuestData.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FQuestData constinit property declarations ************************
	static const UECodeGen_Private::FNamePropertyParams NewProp_Id;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Name;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Description;
	static const UECodeGen_Private::FNamePropertyParams NewProp_RequiredAge;
	static const UECodeGen_Private::FNamePropertyParams NewProp_Alignment;
	static const UECodeGen_Private::FNamePropertyParams NewProp_StoryArc;
	static const UECodeGen_Private::FIntPropertyParams NewProp_StoryStage;
	static const UECodeGen_Private::FIntPropertyParams NewProp_XP;
	static const UECodeGen_Private::FNamePropertyParams NewProp_SkillUnlock;
	static const UECodeGen_Private::FNamePropertyParams NewProp_AlignmentShift;
	static const UECodeGen_Private::FNamePropertyParams NewProp_AlignmentChoice_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_AlignmentChoice;
	static const UECodeGen_Private::FIntPropertyParams NewProp_ReputationGain_ValueProp;
	static const UECodeGen_Private::FNamePropertyParams NewProp_ReputationGain_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_ReputationGain;
	static const UECodeGen_Private::FNamePropertyParams NewProp_NPCInvolved_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_NPCInvolved;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FQuestData constinit property declarations **************************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FQuestData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FQuestData_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FQuestData;
class UScriptStruct* FQuestData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FQuestData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FQuestData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FQuestData, (UObject*)Z_Construct_UPackage__Script_ShatteredFatesProject(), TEXT("QuestData"));
	}
	return Z_Registration_Info_UScriptStruct_FQuestData.OuterSingleton;
	}

// ********** Begin ScriptStruct FQuestData Property Definitions ***********************************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FQuestData_Statics::NewProp_Id = { "Id", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FQuestData, Id), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Id_MetaData), NewProp_Id_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UScriptStruct_FQuestData_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FQuestData, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UScriptStruct_FQuestData_Statics::NewProp_Description = { "Description", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FQuestData, Description), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Description_MetaData), NewProp_Description_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FQuestData_Statics::NewProp_RequiredAge = { "RequiredAge", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FQuestData, RequiredAge), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_RequiredAge_MetaData), NewProp_RequiredAge_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FQuestData_Statics::NewProp_Alignment = { "Alignment", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FQuestData, Alignment), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Alignment_MetaData), NewProp_Alignment_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FQuestData_Statics::NewProp_StoryArc = { "StoryArc", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FQuestData, StoryArc), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StoryArc_MetaData), NewProp_StoryArc_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FQuestData_Statics::NewProp_StoryStage = { "StoryStage", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FQuestData, StoryStage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StoryStage_MetaData), NewProp_StoryStage_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FQuestData_Statics::NewProp_XP = { "XP", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FQuestData, XP), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_XP_MetaData), NewProp_XP_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FQuestData_Statics::NewProp_SkillUnlock = { "SkillUnlock", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FQuestData, SkillUnlock), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_SkillUnlock_MetaData), NewProp_SkillUnlock_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FQuestData_Statics::NewProp_AlignmentShift = { "AlignmentShift", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FQuestData, AlignmentShift), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AlignmentShift_MetaData), NewProp_AlignmentShift_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FQuestData_Statics::NewProp_AlignmentChoice_Inner = { "AlignmentChoice", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FQuestData_Statics::NewProp_AlignmentChoice = { "AlignmentChoice", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FQuestData, AlignmentChoice), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AlignmentChoice_MetaData), NewProp_AlignmentChoice_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FQuestData_Statics::NewProp_ReputationGain_ValueProp = { "ReputationGain", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FQuestData_Statics::NewProp_ReputationGain_Key_KeyProp = { "ReputationGain_Key", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UScriptStruct_FQuestData_Statics::NewProp_ReputationGain = { "ReputationGain", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FQuestData, ReputationGain), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReputationGain_MetaData), NewProp_ReputationGain_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FQuestData_Statics::NewProp_NPCInvolved_Inner = { "NPCInvolved", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FQuestData_Statics::NewProp_NPCInvolved = { "NPCInvolved", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FQuestData, NPCInvolved), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_NPCInvolved_MetaData), NewProp_NPCInvolved_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FQuestData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FQuestData_Statics::NewProp_Id,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FQuestData_Statics::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FQuestData_Statics::NewProp_Description,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FQuestData_Statics::NewProp_RequiredAge,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FQuestData_Statics::NewProp_Alignment,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FQuestData_Statics::NewProp_StoryArc,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FQuestData_Statics::NewProp_StoryStage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FQuestData_Statics::NewProp_XP,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FQuestData_Statics::NewProp_SkillUnlock,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FQuestData_Statics::NewProp_AlignmentShift,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FQuestData_Statics::NewProp_AlignmentChoice_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FQuestData_Statics::NewProp_AlignmentChoice,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FQuestData_Statics::NewProp_ReputationGain_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FQuestData_Statics::NewProp_ReputationGain_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FQuestData_Statics::NewProp_ReputationGain,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FQuestData_Statics::NewProp_NPCInvolved_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FQuestData_Statics::NewProp_NPCInvolved,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FQuestData_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FQuestData Property Definitions *************************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FQuestData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ShatteredFatesProject,
	nullptr,
	&NewStructOps,
	"QuestData",
	Z_Construct_UScriptStruct_FQuestData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FQuestData_Statics::PropPointers),
	sizeof(FQuestData),
	alignof(FQuestData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FQuestData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FQuestData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FQuestData()
{
	if (!Z_Registration_Info_UScriptStruct_FQuestData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FQuestData.InnerSingleton, Z_Construct_UScriptStruct_FQuestData_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FQuestData.InnerSingleton);
}
// ********** End ScriptStruct FQuestData **********************************************************

// ********** Begin Class UQuestDataAsset **********************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UQuestDataAsset;
UClass* UQuestDataAsset::GetPrivateStaticClass()
{
	using TClass = UQuestDataAsset;
	if (!Z_Registration_Info_UClass_UQuestDataAsset.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("QuestDataAsset"),
			Z_Registration_Info_UClass_UQuestDataAsset.InnerSingleton,
			StaticRegisterNativesUQuestDataAsset,
			sizeof(TClass),
			alignof(TClass),
			TClass::StaticClassFlags,
			TClass::StaticClassCastFlags(),
			TClass::StaticConfigName(),
			(UClass::ClassConstructorType)InternalConstructor<TClass>,
			(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<TClass>,
			UOBJECT_CPPCLASS_STATICFUNCTIONS_FORCLASS(TClass),
			&TClass::Super::StaticClass,
			&TClass::WithinClass::StaticClass
		);
	}
	return Z_Registration_Info_UClass_UQuestDataAsset.InnerSingleton;
}
UClass* Z_Construct_UClass_UQuestDataAsset_NoRegister()
{
	return UQuestDataAsset::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UQuestDataAsset_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "QuestData.h" },
		{ "ModuleRelativePath", "Public/QuestData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Quests_MetaData[] = {
		{ "Category", "QuestDataAsset" },
		{ "ModuleRelativePath", "Public/QuestData.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UQuestDataAsset constinit property declarations **************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Quests_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Quests;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UQuestDataAsset constinit property declarations ****************************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UQuestDataAsset>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UQuestDataAsset_Statics

// ********** Begin Class UQuestDataAsset Property Definitions *************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UQuestDataAsset_Statics::NewProp_Quests_Inner = { "Quests", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FQuestData, METADATA_PARAMS(0, nullptr) }; // 2067824791
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UQuestDataAsset_Statics::NewProp_Quests = { "Quests", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UQuestDataAsset, Quests), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Quests_MetaData), NewProp_Quests_MetaData) }; // 2067824791
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UQuestDataAsset_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuestDataAsset_Statics::NewProp_Quests_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuestDataAsset_Statics::NewProp_Quests,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UQuestDataAsset_Statics::PropPointers) < 2048);
// ********** End Class UQuestDataAsset Property Definitions ***************************************
UObject* (*const Z_Construct_UClass_UQuestDataAsset_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDataAsset,
	(UObject* (*)())Z_Construct_UPackage__Script_ShatteredFatesProject,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UQuestDataAsset_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UQuestDataAsset_Statics::ClassParams = {
	&UQuestDataAsset::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UQuestDataAsset_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UQuestDataAsset_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UQuestDataAsset_Statics::Class_MetaDataParams), Z_Construct_UClass_UQuestDataAsset_Statics::Class_MetaDataParams)
};
void UQuestDataAsset::StaticRegisterNativesUQuestDataAsset()
{
}
UClass* Z_Construct_UClass_UQuestDataAsset()
{
	if (!Z_Registration_Info_UClass_UQuestDataAsset.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UQuestDataAsset.OuterSingleton, Z_Construct_UClass_UQuestDataAsset_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UQuestDataAsset.OuterSingleton;
}
UQuestDataAsset::UQuestDataAsset(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UQuestDataAsset);
UQuestDataAsset::~UQuestDataAsset() {}
// ********** End Class UQuestDataAsset ************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesProject_Public_QuestData_h__Script_ShatteredFatesProject_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FQuestData::StaticStruct, Z_Construct_UScriptStruct_FQuestData_Statics::NewStructOps, TEXT("QuestData"),&Z_Registration_Info_UScriptStruct_FQuestData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FQuestData), 2067824791U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UQuestDataAsset, UQuestDataAsset::StaticClass, TEXT("UQuestDataAsset"), &Z_Registration_Info_UClass_UQuestDataAsset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UQuestDataAsset), 945155656U) },
	};
}; // Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesProject_Public_QuestData_h__Script_ShatteredFatesProject_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesProject_Public_QuestData_h__Script_ShatteredFatesProject_2548283557{
	TEXT("/Script/ShatteredFatesProject"),
	Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesProject_Public_QuestData_h__Script_ShatteredFatesProject_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesProject_Public_QuestData_h__Script_ShatteredFatesProject_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesProject_Public_QuestData_h__Script_ShatteredFatesProject_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesProject_Public_QuestData_h__Script_ShatteredFatesProject_Statics::ScriptStructInfo),
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
