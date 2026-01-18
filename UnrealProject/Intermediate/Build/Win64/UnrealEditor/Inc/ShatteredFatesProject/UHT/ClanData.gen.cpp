// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ClanData.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeClanData() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UDataAsset();
SHATTEREDFATESPROJECT_API UClass* Z_Construct_UClass_UClanDataAsset();
SHATTEREDFATESPROJECT_API UClass* Z_Construct_UClass_UClanDataAsset_NoRegister();
SHATTEREDFATESPROJECT_API UScriptStruct* Z_Construct_UScriptStruct_FClanData();
UPackage* Z_Construct_UPackage__Script_ShatteredFatesProject();
// ********** End Cross Module References **********************************************************

// ********** Begin ScriptStruct FClanData *********************************************************
struct Z_Construct_UScriptStruct_FClanData_Statics
{
	static inline consteval int32 GetStructSize() { return sizeof(FClanData); }
	static inline consteval int16 GetStructAlignment() { return alignof(FClanData); }
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/ClanData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "Category", "ClanData" },
		{ "ModuleRelativePath", "Public/ClanData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Leader_MetaData[] = {
		{ "Category", "ClanData" },
		{ "ModuleRelativePath", "Public/ClanData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_MedicineCat_MetaData[] = {
		{ "Category", "ClanData" },
		{ "ModuleRelativePath", "Public/ClanData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Warriors_MetaData[] = {
		{ "Category", "ClanData" },
		{ "ModuleRelativePath", "Public/ClanData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Territory_MetaData[] = {
		{ "Category", "ClanData" },
		{ "ModuleRelativePath", "Public/ClanData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Traits_MetaData[] = {
		{ "Category", "ClanData" },
		{ "ModuleRelativePath", "Public/ClanData.h" },
	};
#endif // WITH_METADATA

// ********** Begin ScriptStruct FClanData constinit property declarations *************************
	static const UECodeGen_Private::FNamePropertyParams NewProp_Name;
	static const UECodeGen_Private::FNamePropertyParams NewProp_Leader;
	static const UECodeGen_Private::FNamePropertyParams NewProp_MedicineCat;
	static const UECodeGen_Private::FNamePropertyParams NewProp_Warriors_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Warriors;
	static const UECodeGen_Private::FNamePropertyParams NewProp_Territory;
	static const UECodeGen_Private::FIntPropertyParams NewProp_Traits_ValueProp;
	static const UECodeGen_Private::FNamePropertyParams NewProp_Traits_Key_KeyProp;
	static const UECodeGen_Private::FMapPropertyParams NewProp_Traits;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End ScriptStruct FClanData constinit property declarations ***************************
	static void* NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FClanData>();
	}
	static const UECodeGen_Private::FStructParams StructParams;
}; // struct Z_Construct_UScriptStruct_FClanData_Statics
static FStructRegistrationInfo Z_Registration_Info_UScriptStruct_FClanData;
class UScriptStruct* FClanData::StaticStruct()
{
	if (!Z_Registration_Info_UScriptStruct_FClanData.OuterSingleton)
	{
		Z_Registration_Info_UScriptStruct_FClanData.OuterSingleton = GetStaticStruct(Z_Construct_UScriptStruct_FClanData, (UObject*)Z_Construct_UPackage__Script_ShatteredFatesProject(), TEXT("ClanData"));
	}
	return Z_Registration_Info_UScriptStruct_FClanData.OuterSingleton;
	}

// ********** Begin ScriptStruct FClanData Property Definitions ************************************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FClanData_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FClanData, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FClanData_Statics::NewProp_Leader = { "Leader", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FClanData, Leader), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Leader_MetaData), NewProp_Leader_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FClanData_Statics::NewProp_MedicineCat = { "MedicineCat", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FClanData, MedicineCat), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_MedicineCat_MetaData), NewProp_MedicineCat_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FClanData_Statics::NewProp_Warriors_Inner = { "Warriors", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UScriptStruct_FClanData_Statics::NewProp_Warriors = { "Warriors", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FClanData, Warriors), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Warriors_MetaData), NewProp_Warriors_MetaData) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FClanData_Statics::NewProp_Territory = { "Territory", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FClanData, Territory), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Territory_MetaData), NewProp_Territory_MetaData) };
const UECodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FClanData_Statics::NewProp_Traits_ValueProp = { "Traits", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 1, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FNamePropertyParams Z_Construct_UScriptStruct_FClanData_Statics::NewProp_Traits_Key_KeyProp = { "Traits_Key", nullptr, (EPropertyFlags)0x0000000000000001, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FMapPropertyParams Z_Construct_UScriptStruct_FClanData_Statics::NewProp_Traits = { "Traits", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Map, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(FClanData, Traits), EMapPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Traits_MetaData), NewProp_Traits_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FClanData_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClanData_Statics::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClanData_Statics::NewProp_Leader,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClanData_Statics::NewProp_MedicineCat,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClanData_Statics::NewProp_Warriors_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClanData_Statics::NewProp_Warriors,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClanData_Statics::NewProp_Territory,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClanData_Statics::NewProp_Traits_ValueProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClanData_Statics::NewProp_Traits_Key_KeyProp,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FClanData_Statics::NewProp_Traits,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FClanData_Statics::PropPointers) < 2048);
// ********** End ScriptStruct FClanData Property Definitions **************************************
const UECodeGen_Private::FStructParams Z_Construct_UScriptStruct_FClanData_Statics::StructParams = {
	(UObject* (*)())Z_Construct_UPackage__Script_ShatteredFatesProject,
	nullptr,
	&NewStructOps,
	"ClanData",
	Z_Construct_UScriptStruct_FClanData_Statics::PropPointers,
	UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FClanData_Statics::PropPointers),
	sizeof(FClanData),
	alignof(FClanData),
	RF_Public|RF_Transient|RF_MarkAsNative,
	EStructFlags(0x00000001),
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FClanData_Statics::Struct_MetaDataParams), Z_Construct_UScriptStruct_FClanData_Statics::Struct_MetaDataParams)
};
UScriptStruct* Z_Construct_UScriptStruct_FClanData()
{
	if (!Z_Registration_Info_UScriptStruct_FClanData.InnerSingleton)
	{
		UECodeGen_Private::ConstructUScriptStruct(Z_Registration_Info_UScriptStruct_FClanData.InnerSingleton, Z_Construct_UScriptStruct_FClanData_Statics::StructParams);
	}
	return CastChecked<UScriptStruct>(Z_Registration_Info_UScriptStruct_FClanData.InnerSingleton);
}
// ********** End ScriptStruct FClanData ***********************************************************

// ********** Begin Class UClanDataAsset ***********************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UClanDataAsset;
UClass* UClanDataAsset::GetPrivateStaticClass()
{
	using TClass = UClanDataAsset;
	if (!Z_Registration_Info_UClass_UClanDataAsset.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("ClanDataAsset"),
			Z_Registration_Info_UClass_UClanDataAsset.InnerSingleton,
			StaticRegisterNativesUClanDataAsset,
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
	return Z_Registration_Info_UClass_UClanDataAsset.InnerSingleton;
}
UClass* Z_Construct_UClass_UClanDataAsset_NoRegister()
{
	return UClanDataAsset::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UClanDataAsset_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "IncludePath", "ClanData.h" },
		{ "ModuleRelativePath", "Public/ClanData.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Clans_MetaData[] = {
		{ "Category", "ClanDataAsset" },
		{ "ModuleRelativePath", "Public/ClanData.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UClanDataAsset constinit property declarations ***************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Clans_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Clans;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UClanDataAsset constinit property declarations *****************************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UClanDataAsset>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UClanDataAsset_Statics

// ********** Begin Class UClanDataAsset Property Definitions **************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UClanDataAsset_Statics::NewProp_Clans_Inner = { "Clans", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FClanData, METADATA_PARAMS(0, nullptr) }; // 2791863875
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UClanDataAsset_Statics::NewProp_Clans = { "Clans", nullptr, (EPropertyFlags)0x0010000000000005, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UClanDataAsset, Clans), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Clans_MetaData), NewProp_Clans_MetaData) }; // 2791863875
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UClanDataAsset_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UClanDataAsset_Statics::NewProp_Clans_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UClanDataAsset_Statics::NewProp_Clans,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UClanDataAsset_Statics::PropPointers) < 2048);
// ********** End Class UClanDataAsset Property Definitions ****************************************
UObject* (*const Z_Construct_UClass_UClanDataAsset_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UDataAsset,
	(UObject* (*)())Z_Construct_UPackage__Script_ShatteredFatesProject,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UClanDataAsset_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UClanDataAsset_Statics::ClassParams = {
	&UClanDataAsset::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	Z_Construct_UClass_UClanDataAsset_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	UE_ARRAY_COUNT(Z_Construct_UClass_UClanDataAsset_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UClanDataAsset_Statics::Class_MetaDataParams), Z_Construct_UClass_UClanDataAsset_Statics::Class_MetaDataParams)
};
void UClanDataAsset::StaticRegisterNativesUClanDataAsset()
{
}
UClass* Z_Construct_UClass_UClanDataAsset()
{
	if (!Z_Registration_Info_UClass_UClanDataAsset.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UClanDataAsset.OuterSingleton, Z_Construct_UClass_UClanDataAsset_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UClanDataAsset.OuterSingleton;
}
UClanDataAsset::UClanDataAsset(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UClanDataAsset);
UClanDataAsset::~UClanDataAsset() {}
// ********** End Class UClanDataAsset *************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesProject_Public_ClanData_h__Script_ShatteredFatesProject_Statics
{
	static constexpr FStructRegisterCompiledInInfo ScriptStructInfo[] = {
		{ FClanData::StaticStruct, Z_Construct_UScriptStruct_FClanData_Statics::NewStructOps, TEXT("ClanData"),&Z_Registration_Info_UScriptStruct_FClanData, CONSTRUCT_RELOAD_VERSION_INFO(FStructReloadVersionInfo, sizeof(FClanData), 2791863875U) },
	};
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UClanDataAsset, UClanDataAsset::StaticClass, TEXT("UClanDataAsset"), &Z_Registration_Info_UClass_UClanDataAsset, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UClanDataAsset), 1923022U) },
	};
}; // Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesProject_Public_ClanData_h__Script_ShatteredFatesProject_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesProject_Public_ClanData_h__Script_ShatteredFatesProject_3916212953{
	TEXT("/Script/ShatteredFatesProject"),
	Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesProject_Public_ClanData_h__Script_ShatteredFatesProject_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesProject_Public_ClanData_h__Script_ShatteredFatesProject_Statics::ClassInfo),
	Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesProject_Public_ClanData_h__Script_ShatteredFatesProject_Statics::ScriptStructInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesProject_Public_ClanData_h__Script_ShatteredFatesProject_Statics::ScriptStructInfo),
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
