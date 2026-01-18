// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "QuestSubsystem.h"
#include "Engine/GameInstance.h"
#include "QuestData.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeQuestSubsystem() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
SHATTEREDFATESGAME_API UClass* Z_Construct_UClass_UQuestSubsystem();
SHATTEREDFATESGAME_API UClass* Z_Construct_UClass_UQuestSubsystem_NoRegister();
SHATTEREDFATESPROJECT_API UScriptStruct* Z_Construct_UScriptStruct_FQuestData();
UPackage* Z_Construct_UPackage__Script_ShatteredFatesGame();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UQuestSubsystem Function GetAllQuests ************************************
struct Z_Construct_UFunction_UQuestSubsystem_GetAllQuests_Statics
{
	struct QuestSubsystem_eventGetAllQuests_Parms
	{
		TArray<FQuestData> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ShatteredFates|Quests" },
		{ "ModuleRelativePath", "Public/QuestSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetAllQuests constinit property declarations **************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetAllQuests constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetAllQuests Property Definitions *************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UQuestSubsystem_GetAllQuests_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FQuestData, METADATA_PARAMS(0, nullptr) }; // 2067824791
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UQuestSubsystem_GetAllQuests_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000008000582, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(QuestSubsystem_eventGetAllQuests_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) }; // 2067824791
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UQuestSubsystem_GetAllQuests_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UQuestSubsystem_GetAllQuests_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UQuestSubsystem_GetAllQuests_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UQuestSubsystem_GetAllQuests_Statics::PropPointers) < 2048);
// ********** End Function GetAllQuests Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UQuestSubsystem_GetAllQuests_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UQuestSubsystem, nullptr, "GetAllQuests", 	Z_Construct_UFunction_UQuestSubsystem_GetAllQuests_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UQuestSubsystem_GetAllQuests_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UQuestSubsystem_GetAllQuests_Statics::QuestSubsystem_eventGetAllQuests_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UQuestSubsystem_GetAllQuests_Statics::Function_MetaDataParams), Z_Construct_UFunction_UQuestSubsystem_GetAllQuests_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UQuestSubsystem_GetAllQuests_Statics::QuestSubsystem_eventGetAllQuests_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UQuestSubsystem_GetAllQuests()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UQuestSubsystem_GetAllQuests_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UQuestSubsystem::execGetAllQuests)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FQuestData>*)Z_Param__Result=P_THIS->GetAllQuests();
	P_NATIVE_END;
}
// ********** End Class UQuestSubsystem Function GetAllQuests **************************************

// ********** Begin Class UQuestSubsystem Function LoadFromJson ************************************
struct Z_Construct_UFunction_UQuestSubsystem_LoadFromJson_Statics
{
	struct QuestSubsystem_eventLoadFromJson_Parms
	{
		FString AbsolutePath;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ShatteredFates|Quests" },
		{ "ModuleRelativePath", "Public/QuestSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AbsolutePath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function LoadFromJson constinit property declarations **************************
	static const UECodeGen_Private::FStrPropertyParams NewProp_AbsolutePath;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function LoadFromJson constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function LoadFromJson Property Definitions *************************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UQuestSubsystem_LoadFromJson_Statics::NewProp_AbsolutePath = { "AbsolutePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(QuestSubsystem_eventLoadFromJson_Parms, AbsolutePath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AbsolutePath_MetaData), NewProp_AbsolutePath_MetaData) };
void Z_Construct_UFunction_UQuestSubsystem_LoadFromJson_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((QuestSubsystem_eventLoadFromJson_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UQuestSubsystem_LoadFromJson_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(QuestSubsystem_eventLoadFromJson_Parms), &Z_Construct_UFunction_UQuestSubsystem_LoadFromJson_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UQuestSubsystem_LoadFromJson_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UQuestSubsystem_LoadFromJson_Statics::NewProp_AbsolutePath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UQuestSubsystem_LoadFromJson_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UQuestSubsystem_LoadFromJson_Statics::PropPointers) < 2048);
// ********** End Function LoadFromJson Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UQuestSubsystem_LoadFromJson_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UQuestSubsystem, nullptr, "LoadFromJson", 	Z_Construct_UFunction_UQuestSubsystem_LoadFromJson_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UQuestSubsystem_LoadFromJson_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UQuestSubsystem_LoadFromJson_Statics::QuestSubsystem_eventLoadFromJson_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UQuestSubsystem_LoadFromJson_Statics::Function_MetaDataParams), Z_Construct_UFunction_UQuestSubsystem_LoadFromJson_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UQuestSubsystem_LoadFromJson_Statics::QuestSubsystem_eventLoadFromJson_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UQuestSubsystem_LoadFromJson()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UQuestSubsystem_LoadFromJson_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UQuestSubsystem::execLoadFromJson)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_AbsolutePath);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->LoadFromJson(Z_Param_AbsolutePath);
	P_NATIVE_END;
}
// ********** End Class UQuestSubsystem Function LoadFromJson **************************************

// ********** Begin Class UQuestSubsystem **********************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UQuestSubsystem;
UClass* UQuestSubsystem::GetPrivateStaticClass()
{
	using TClass = UQuestSubsystem;
	if (!Z_Registration_Info_UClass_UQuestSubsystem.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("QuestSubsystem"),
			Z_Registration_Info_UClass_UQuestSubsystem.InnerSingleton,
			StaticRegisterNativesUQuestSubsystem,
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
	return Z_Registration_Info_UClass_UQuestSubsystem.InnerSingleton;
}
UClass* Z_Construct_UClass_UQuestSubsystem_NoRegister()
{
	return UQuestSubsystem::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UQuestSubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "QuestSubsystem.h" },
		{ "ModuleRelativePath", "Public/QuestSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Quests_MetaData[] = {
		{ "ModuleRelativePath", "Public/QuestSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UQuestSubsystem constinit property declarations **************************
	static const UECodeGen_Private::FStructPropertyParams NewProp_Quests_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_Quests;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UQuestSubsystem constinit property declarations ****************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("GetAllQuests"), .Pointer = &UQuestSubsystem::execGetAllQuests },
		{ .NameUTF8 = UTF8TEXT("LoadFromJson"), .Pointer = &UQuestSubsystem::execLoadFromJson },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UQuestSubsystem_GetAllQuests, "GetAllQuests" }, // 2752651283
		{ &Z_Construct_UFunction_UQuestSubsystem_LoadFromJson, "LoadFromJson" }, // 2970539961
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UQuestSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UQuestSubsystem_Statics

// ********** Begin Class UQuestSubsystem Property Definitions *************************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UClass_UQuestSubsystem_Statics::NewProp_Quests_Inner = { "Quests", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FQuestData, METADATA_PARAMS(0, nullptr) }; // 2067824791
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_UQuestSubsystem_Statics::NewProp_Quests = { "Quests", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UQuestSubsystem, Quests), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Quests_MetaData), NewProp_Quests_MetaData) }; // 2067824791
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UQuestSubsystem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuestSubsystem_Statics::NewProp_Quests_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UQuestSubsystem_Statics::NewProp_Quests,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UQuestSubsystem_Statics::PropPointers) < 2048);
// ********** End Class UQuestSubsystem Property Definitions ***************************************
UObject* (*const Z_Construct_UClass_UQuestSubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_ShatteredFatesGame,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UQuestSubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UQuestSubsystem_Statics::ClassParams = {
	&UQuestSubsystem::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UQuestSubsystem_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UQuestSubsystem_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UQuestSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UQuestSubsystem_Statics::Class_MetaDataParams)
};
void UQuestSubsystem::StaticRegisterNativesUQuestSubsystem()
{
	UClass* Class = UQuestSubsystem::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UQuestSubsystem_Statics::Funcs));
}
UClass* Z_Construct_UClass_UQuestSubsystem()
{
	if (!Z_Registration_Info_UClass_UQuestSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UQuestSubsystem.OuterSingleton, Z_Construct_UClass_UQuestSubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UQuestSubsystem.OuterSingleton;
}
UQuestSubsystem::UQuestSubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UQuestSubsystem);
UQuestSubsystem::~UQuestSubsystem() {}
// ********** End Class UQuestSubsystem ************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesGame_Public_QuestSubsystem_h__Script_ShatteredFatesGame_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UQuestSubsystem, UQuestSubsystem::StaticClass, TEXT("UQuestSubsystem"), &Z_Registration_Info_UClass_UQuestSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UQuestSubsystem), 932586729U) },
	};
}; // Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesGame_Public_QuestSubsystem_h__Script_ShatteredFatesGame_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesGame_Public_QuestSubsystem_h__Script_ShatteredFatesGame_28220326{
	TEXT("/Script/ShatteredFatesGame"),
	Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesGame_Public_QuestSubsystem_h__Script_ShatteredFatesGame_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesGame_Public_QuestSubsystem_h__Script_ShatteredFatesGame_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
