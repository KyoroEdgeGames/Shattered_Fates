// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "StorySubsystem.h"
#include "Engine/GameInstance.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeStorySubsystem() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
SHATTEREDFATESGAME_API UClass* Z_Construct_UClass_UStorySubsystem();
SHATTEREDFATESGAME_API UClass* Z_Construct_UClass_UStorySubsystem_NoRegister();
UPackage* Z_Construct_UPackage__Script_ShatteredFatesGame();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UStorySubsystem Function ResetStory **************************************
struct Z_Construct_UFunction_UStorySubsystem_ResetStory_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ShatteredFates|Story" },
		{ "ModuleRelativePath", "Public/StorySubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ResetStory constinit property declarations ****************************
// ********** End Function ResetStory constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UStorySubsystem_ResetStory_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UStorySubsystem, nullptr, "ResetStory", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UStorySubsystem_ResetStory_Statics::Function_MetaDataParams), Z_Construct_UFunction_UStorySubsystem_ResetStory_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_UStorySubsystem_ResetStory()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UStorySubsystem_ResetStory_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UStorySubsystem::execResetStory)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ResetStory();
	P_NATIVE_END;
}
// ********** End Class UStorySubsystem Function ResetStory ****************************************

// ********** Begin Class UStorySubsystem **********************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UStorySubsystem;
UClass* UStorySubsystem::GetPrivateStaticClass()
{
	using TClass = UStorySubsystem;
	if (!Z_Registration_Info_UClass_UStorySubsystem.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("StorySubsystem"),
			Z_Registration_Info_UClass_UStorySubsystem.InnerSingleton,
			StaticRegisterNativesUStorySubsystem,
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
	return Z_Registration_Info_UClass_UStorySubsystem.InnerSingleton;
}
UClass* Z_Construct_UClass_UStorySubsystem_NoRegister()
{
	return UStorySubsystem::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UStorySubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "StorySubsystem.h" },
		{ "ModuleRelativePath", "Public/StorySubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UStorySubsystem constinit property declarations **************************
// ********** End Class UStorySubsystem constinit property declarations ****************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("ResetStory"), .Pointer = &UStorySubsystem::execResetStory },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UStorySubsystem_ResetStory, "ResetStory" }, // 2015489076
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UStorySubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UStorySubsystem_Statics
UObject* (*const Z_Construct_UClass_UStorySubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_ShatteredFatesGame,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UStorySubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UStorySubsystem_Statics::ClassParams = {
	&UStorySubsystem::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	0,
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UStorySubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UStorySubsystem_Statics::Class_MetaDataParams)
};
void UStorySubsystem::StaticRegisterNativesUStorySubsystem()
{
	UClass* Class = UStorySubsystem::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UStorySubsystem_Statics::Funcs));
}
UClass* Z_Construct_UClass_UStorySubsystem()
{
	if (!Z_Registration_Info_UClass_UStorySubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UStorySubsystem.OuterSingleton, Z_Construct_UClass_UStorySubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UStorySubsystem.OuterSingleton;
}
UStorySubsystem::UStorySubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UStorySubsystem);
UStorySubsystem::~UStorySubsystem() {}
// ********** End Class UStorySubsystem ************************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesGame_Public_StorySubsystem_h__Script_ShatteredFatesGame_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UStorySubsystem, UStorySubsystem::StaticClass, TEXT("UStorySubsystem"), &Z_Registration_Info_UClass_UStorySubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UStorySubsystem), 749632131U) },
	};
}; // Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesGame_Public_StorySubsystem_h__Script_ShatteredFatesGame_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesGame_Public_StorySubsystem_h__Script_ShatteredFatesGame_3103727205{
	TEXT("/Script/ShatteredFatesGame"),
	Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesGame_Public_StorySubsystem_h__Script_ShatteredFatesGame_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesGame_Public_StorySubsystem_h__Script_ShatteredFatesGame_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
