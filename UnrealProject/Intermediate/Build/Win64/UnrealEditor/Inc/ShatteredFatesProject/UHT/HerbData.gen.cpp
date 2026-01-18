// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "HerbData.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeHerbData() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UDataAsset();
SHATTEREDFATESPROJECT_API UClass* Z_Construct_UClass_UHerbDataAsset();
SHATTEREDFATESPROJECT_API UClass* Z_Construct_UClass_UHerbDataAsset_NoRegister();
SHATTEREDFATESPROJECT_API UScriptStruct* Z_Construct_UScriptStruct_FHerbData();
UPackage* Z_Construct_UPackage__Script_ShatteredFatesProject();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FHerbData *********************************************************
struct Z_Construct_UScriptStruct_FHerbData_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FHerbData); }
	static inline consteval int16 GetStructAlignment() { return alignof(FHerbData); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/HerbData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Id_MetaData[] = {
		{ "Category", "HerbData" },
		{ "ModuleRelativePath", "Public/HerbData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "Category", "HerbData" },
		{ "ModuleRelativePath", "Public/HerbData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Description_MetaData[] = {
		{ "Category", "HerbData" },
		{ "ModuleRelativePath", "Public/HerbData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Rarity_MetaData[] = {
		{ "Category", "HerbData" },
		{ "ModuleRelativePath", "Public/HerbData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Effects_MetaData[] = {
		{ "Category", "HerbData" },
		{ "ModuleRelativePath", "Public/HerbData.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FHerbData constinit property declarations *************************
	static const UECodeGen_Private::FNamePropertyParams NewProp_Id;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Name;
	static const UECodeGen_Private::FTextPropertyParams NewProp_Description;
	static const UECodeGen_Private::FNamePropertyParams NewProp_Rarity;
	static const UECodeGen_Private::FFloatPropertyParams NewProp_Effects_ValueProp;
	static const UECodeGen_Private::FNamePropertyParams NewProp_Effects_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_Effects;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FHerbData constinit property declarations ***************************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FHerbData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FHerbData_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FHerbData;
class UScriptStruct* FHerbData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FHerbData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FHerbData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FHerbData, (UObject*)Z_Construct_UPackage__Script_ShatteredFatesProject(), TEXT("HerbData"));
	}
	return Z_Registration_Info_UScriptStruct_FHerbData.OuterSingleton;
	}

// ********** Begin ScriptStruct FHerbData Property Definitions ************************************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FHerbData_Statics::NewProp_Id = { "Id", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHerbData, Id), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Id_MetaData), NewProp_Id_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UScriptStruct_FHerbData_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHerbData, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FTextPropertyParams Z_Construct_UScriptStruct_FHerbData_Statics::NewProp_Description = { "Description", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Text, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHerbData, Description), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Description_MetaData), NewProp_Description_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FHerbData_Statics::NewProp_Rarity = { "Rarity", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHerbData, Rarity), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Rarity_MetaData), NewProp_Rarity_MetaData) };
const UECodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FHerbData_Statics::NewProp_Effects_ValueProp = { "Effects", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FHerbData_Statics::NewProp_Effects_Key_KeyProp = { "Effects_Key", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UScriptStruct_FHerbData_Statics::NewProp_Effects = { "Effects", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FHerbData, Effects), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Effects_MetaData), NewProp_Effects_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FHerbData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHerbData_Statics::NewProp_Id,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHerbData_Statics::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHerbData_Statics::NewProp_Description,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHerbData_Statics::NewProp_Rarity,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHerbData_Statics::NewProp_Effects_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHerbData_Statics::NewProp_Effects_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FHerbData_Statics::NewProp_Effects,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHerbData_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FHerbData Property Definitions **************************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FHerbData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ShatteredFatesProject,
	nullptr,
	&NewStructOps,
	"HerbData",
	Z_Construct_UScriptStruct_FHerbData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHerbData_Statics::PropPointers),
	sizeof(FHerbData),
	alignof(FHerbData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FHerbData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FHerbData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FHerbData()
{
	if (!Z_Registration_Info_UScriptStruct_FHerbData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FHerbData.InnerSingleton, Z_Construct_UScriptStruct_FHerbData_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FHerbData.InnerSingleton);
}
// ********** End ScriptStruct FHerbData ***********************************************************

// ********** Begin Class UHerbDataAsset ***********************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UHerbDataAsset;
UClass* UHerbDataAsset::GetPrivateStaticClass()
{
	using TClass = UHerbDataAsset;
	if (!Z_Registration_Info_UClass_UHerbDataAsset.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("HerbDataAsset"),
			Z_Registration_Info_UClass_UHerbDataAsset.InnerSingleton,
			StaticRegisterNativesUHerbDataAsset,
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
	return Z_Registration_Info_UClass_UHerbDataAsset.InnerSingleton;
}
UClass* Z_Construct_UClass_UHerbDataAsset_NoRegister()
{
	return UHerbDataAsset::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UHerbDataAsset_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "HerbData.h" },
		{ "ModuleRelativePath", "Public/HerbData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Herbs_MetaData[] = {
		{ "Category", "HerbDataAsset" },
		{ "ModuleRelativePath", "Public/HerbData.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UHerbDataAsset constinit property declarations ***************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Herbs_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Herbs;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UHerbDataAsset constinit property declarations *****************************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UHerbDataAsset>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UHerbDataAsset_Statics

// ********** Begin Class UHerbDataAsset Property Definitions **************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UHerbDataAsset_Statics::NewProp_Herbs_Inner = { "Herbs", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FHerbData, METADATA_PARAMS(0, nullptr) }; // 2968797728
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UHerbDataAsset_Statics::NewProp_Herbs = { "Herbs", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UHerbDataAsset, Herbs), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Herbs_MetaData), NewProp_Herbs_MetaData) }; // 2968797728
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UHerbDataAsset_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHerbDataAsset_Statics::NewProp_Herbs_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UHerbDataAsset_Statics::NewProp_Herbs,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UHerbDataAsset_Statics::PropPointers) < 2048);
// ********** End Class UHerbDataAsset Property Definitions ****************************************
UObject* (*const Z_Construct_UClass_UHerbDataAsset_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDataAsset,
	(UObject* (*)())Z_Construct_UPackage__Script_ShatteredFatesProject,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UHerbDataAsset_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UHerbDataAsset_Statics::ClassParams = {
	&UHerbDataAsset::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UHerbDataAsset_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UHerbDataAsset_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UHerbDataAsset_Statics::Class_MetaDataParams), Z_Construct_UClass_UHerbDataAsset_Statics::Class_MetaDataParams)
};
void UHerbDataAsset::StaticRegisterNativesUHerbDataAsset()
{
}
UClass* Z_Construct_UClass_UHerbDataAsset()
{
	if (!Z_Registration_Info_UClass_UHerbDataAsset.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UHerbDataAsset.OuterSingleton, Z_Construct_UClass_UHerbDataAsset_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UHerbDataAsset.OuterSingleton;
}
UHerbDataAsset::UHerbDataAsset(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UHerbDataAsset);
UHerbDataAsset::~UHerbDataAsset() {}
// ********** End Class UHerbDataAsset *************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesProject_Public_HerbData_h__Script_ShatteredFatesProject_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FHerbData::StaticStruct, Z_Construct_UScriptStruct_FHerbData_Statics::NewStructOps, TEXT("HerbData"),&Z_Registration_Info_UScriptStruct_FHerbData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FHerbData), 2968797728U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UHerbDataAsset, UHerbDataAsset::StaticClass, TEXT("UHerbDataAsset"), &Z_Registration_Info_UClass_UHerbDataAsset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UHerbDataAsset), 2709856059U) },
	};
}; // Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesProject_Public_HerbData_h__Script_ShatteredFatesProject_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesProject_Public_HerbData_h__Script_ShatteredFatesProject_4201816105{
	TEXT("/Script/ShatteredFatesProject"),
	Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesProject_Public_HerbData_h__Script_ShatteredFatesProject_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesProject_Public_HerbData_h__Script_ShatteredFatesProject_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesProject_Public_HerbData_h__Script_ShatteredFatesProject_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesProject_Public_HerbData_h__Script_ShatteredFatesProject_Statics::ScriptStructInfo),
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
