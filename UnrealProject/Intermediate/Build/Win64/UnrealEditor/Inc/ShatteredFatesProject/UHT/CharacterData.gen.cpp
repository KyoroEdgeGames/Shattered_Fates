// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CharacterData.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeCharacterData() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UDataAsset();
SHATTEREDFATESPROJECT_API UClass* Z_Construct_UClass_UCharacterDataAsset();
SHATTEREDFATESPROJECT_API UClass* Z_Construct_UClass_UCharacterDataAsset_NoRegister();
SHATTEREDFATESPROJECT_API UScriptStruct* Z_Construct_UScriptStruct_FCharacterData();
UPackage* Z_Construct_UPackage__Script_ShatteredFatesProject();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FCharacterData ****************************************************
struct Z_Construct_UScriptStruct_FCharacterData_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FCharacterData); }
	static inline consteval int16 GetStructAlignment() { return alignof(FCharacterData); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/CharacterData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "Category", "CharacterData" },
		{ "ModuleRelativePath", "Public/CharacterData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_bPlayable_MetaData[] = {
		{ "Category", "CharacterData" },
		{ "ModuleRelativePath", "Public/CharacterData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Clan_MetaData[] = {
		{ "Category", "CharacterData" },
		{ "ModuleRelativePath", "Public/CharacterData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AgeStage_MetaData[] = {
		{ "Category", "CharacterData" },
		{ "ModuleRelativePath", "Public/CharacterData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_StoryArc_MetaData[] = {
		{ "Category", "CharacterData" },
		{ "ModuleRelativePath", "Public/CharacterData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AlignmentTendency_MetaData[] = {
		{ "Category", "CharacterData" },
		{ "ModuleRelativePath", "Public/CharacterData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Traits_MetaData[] = {
		{ "Category", "CharacterData" },
		{ "ModuleRelativePath", "Public/CharacterData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Skills_MetaData[] = {
		{ "Category", "CharacterData" },
		{ "ModuleRelativePath", "Public/CharacterData.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FCharacterData constinit property declarations ********************
	static const UECodeGen_Private::FNamePropertyParams NewProp_Name;
	static void NewProp_bPlayable_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_bPlayable;
	static const UECodeGen_Private::FNamePropertyParams NewProp_Clan;
	static const UECodeGen_Private::FNamePropertyParams NewProp_AgeStage;
	static const UECodeGen_Private::FNamePropertyParams NewProp_StoryArc;
	static const UECodeGen_Private::FNamePropertyParams NewProp_AlignmentTendency;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Traits_ValueProp;
	static const UECodeGen_Private::FNamePropertyParams NewProp_Traits_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_Traits;
	static const UECodeGen_Private::FNamePropertyParams NewProp_Skills_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Skills;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FCharacterData constinit property declarations **********************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FCharacterData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FCharacterData_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FCharacterData;
class UScriptStruct* FCharacterData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FCharacterData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FCharacterData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FCharacterData, (UObject*)Z_Construct_UPackage__Script_ShatteredFatesProject(), TEXT("CharacterData"));
	}
	return Z_Registration_Info_UScriptStruct_FCharacterData.OuterSingleton;
	}

// ********** Begin ScriptStruct FCharacterData Property Definitions *******************************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterData, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
void Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_bPlayable_SetBit(void* Obj)
{
	((FCharacterData*)Obj)->bPlayable = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_bPlayable = { "bPlayable", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(FCharacterData), &Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_bPlayable_SetBit, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_bPlayable_MetaData), NewProp_bPlayable_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_Clan = { "Clan", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterData, Clan), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Clan_MetaData), NewProp_Clan_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_AgeStage = { "AgeStage", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterData, AgeStage), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AgeStage_MetaData), NewProp_AgeStage_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_StoryArc = { "StoryArc", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterData, StoryArc), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_StoryArc_MetaData), NewProp_StoryArc_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_AlignmentTendency = { "AlignmentTendency", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterData, AlignmentTendency), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AlignmentTendency_MetaData), NewProp_AlignmentTendency_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_Traits_ValueProp = { "Traits", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_Traits_Key_KeyProp = { "Traits_Key", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_Traits = { "Traits", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterData, Traits), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Traits_MetaData), NewProp_Traits_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_Skills_Inner = { "Skills", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_Skills = { "Skills", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FCharacterData, Skills), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Skills_MetaData), NewProp_Skills_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FCharacterData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_bPlayable,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_Clan,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_AgeStage,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_StoryArc,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_AlignmentTendency,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_Traits_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_Traits_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_Traits,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_Skills_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FCharacterData_Statics::NewProp_Skills,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCharacterData_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FCharacterData Property Definitions *********************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FCharacterData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ShatteredFatesProject,
	nullptr,
	&NewStructOps,
	"CharacterData",
	Z_Construct_UScriptStruct_FCharacterData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCharacterData_Statics::PropPointers),
	sizeof(FCharacterData),
	alignof(FCharacterData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FCharacterData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FCharacterData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FCharacterData()
{
	if (!Z_Registration_Info_UScriptStruct_FCharacterData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FCharacterData.InnerSingleton, Z_Construct_UScriptStruct_FCharacterData_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FCharacterData.InnerSingleton);
}
// ********** End ScriptStruct FCharacterData ******************************************************

// ********** Begin Class UCharacterDataAsset ******************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UCharacterDataAsset;
UClass* UCharacterDataAsset::GetPrivateStaticClass()
{
	using TClass = UCharacterDataAsset;
	if (!Z_Registration_Info_UClass_UCharacterDataAsset.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("CharacterDataAsset"),
			Z_Registration_Info_UClass_UCharacterDataAsset.InnerSingleton,
			StaticRegisterNativesUCharacterDataAsset,
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
	return Z_Registration_Info_UClass_UCharacterDataAsset.InnerSingleton;
}
UClass* Z_Construct_UClass_UCharacterDataAsset_NoRegister()
{
	return UCharacterDataAsset::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UCharacterDataAsset_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "CharacterData.h" },
		{ "ModuleRelativePath", "Public/CharacterData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Characters_MetaData[] = {
		{ "Category", "CharacterDataAsset" },
		{ "ModuleRelativePath", "Public/CharacterData.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UCharacterDataAsset constinit property declarations **********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Characters_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Characters;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UCharacterDataAsset constinit property declarations ************************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCharacterDataAsset>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UCharacterDataAsset_Statics

// ********** Begin Class UCharacterDataAsset Property Definitions *********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UCharacterDataAsset_Statics::NewProp_Characters_Inner = { "Characters", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FCharacterData, METADATA_PARAMS(0, nullptr) }; // 3716101072
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UCharacterDataAsset_Statics::NewProp_Characters = { "Characters", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCharacterDataAsset, Characters), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Characters_MetaData), NewProp_Characters_MetaData) }; // 3716101072
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCharacterDataAsset_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCharacterDataAsset_Statics::NewProp_Characters_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCharacterDataAsset_Statics::NewProp_Characters,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCharacterDataAsset_Statics::PropPointers) < 2048);
// ********** End Class UCharacterDataAsset Property Definitions ***********************************
UObject* (*const Z_Construct_UClass_UCharacterDataAsset_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDataAsset,
	(UObject* (*)())Z_Construct_UPackage__Script_ShatteredFatesProject,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCharacterDataAsset_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCharacterDataAsset_Statics::ClassParams = {
	&UCharacterDataAsset::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UCharacterDataAsset_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UCharacterDataAsset_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCharacterDataAsset_Statics::Class_MetaDataParams), Z_Construct_UClass_UCharacterDataAsset_Statics::Class_MetaDataParams)
};
void UCharacterDataAsset::StaticRegisterNativesUCharacterDataAsset()
{
}
UClass* Z_Construct_UClass_UCharacterDataAsset()
{
	if (!Z_Registration_Info_UClass_UCharacterDataAsset.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCharacterDataAsset.OuterSingleton, Z_Construct_UClass_UCharacterDataAsset_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCharacterDataAsset.OuterSingleton;
}
UCharacterDataAsset::UCharacterDataAsset(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UCharacterDataAsset);
UCharacterDataAsset::~UCharacterDataAsset() {}
// ********** End Class UCharacterDataAsset ********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesProject_Public_CharacterData_h__Script_ShatteredFatesProject_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FCharacterData::StaticStruct, Z_Construct_UScriptStruct_FCharacterData_Statics::NewStructOps, TEXT("CharacterData"),&Z_Registration_Info_UScriptStruct_FCharacterData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FCharacterData), 3716101072U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCharacterDataAsset, UCharacterDataAsset::StaticClass, TEXT("UCharacterDataAsset"), &Z_Registration_Info_UClass_UCharacterDataAsset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCharacterDataAsset), 1792913430U) },
	};
}; // Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesProject_Public_CharacterData_h__Script_ShatteredFatesProject_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesProject_Public_CharacterData_h__Script_ShatteredFatesProject_3500880135{
	TEXT("/Script/ShatteredFatesProject"),
	Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesProject_Public_CharacterData_h__Script_ShatteredFatesProject_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesProject_Public_CharacterData_h__Script_ShatteredFatesProject_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesProject_Public_CharacterData_h__Script_ShatteredFatesProject_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesProject_Public_CharacterData_h__Script_ShatteredFatesProject_Statics::ScriptStructInfo),
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
