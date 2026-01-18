// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SkillsSubsystem.h"
#include "Engine/GameInstance.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeSkillsSubsystem() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
SHATTEREDFATESGAME_API UClass* Z_Construct_UClass_USkillsSubsystem();
SHATTEREDFATESGAME_API UClass* Z_Construct_UClass_USkillsSubsystem_NoRegister();
UPackage* Z_Construct_UPackage__Script_ShatteredFatesGame();
// ********** End Cross Module References **********************************************************

// ********** Begin Class USkillsSubsystem Function ResetSkills ************************************
struct Z_Construct_UFunction_USkillsSubsystem_ResetSkills_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ShatteredFates|Skills" },
		{ "ModuleRelativePath", "Public/SkillsSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ResetSkills constinit property declarations ***************************
// ********** End Function ResetSkills constinit property declarations *****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_USkillsSubsystem_ResetSkills_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_USkillsSubsystem, nullptr, "ResetSkills", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_USkillsSubsystem_ResetSkills_Statics::Function_MetaDataParams), Z_Construct_UFunction_USkillsSubsystem_ResetSkills_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_USkillsSubsystem_ResetSkills()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_USkillsSubsystem_ResetSkills_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(USkillsSubsystem::execResetSkills)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ResetSkills();
	P_NATIVE_END;
}
// ********** End Class USkillsSubsystem Function ResetSkills **************************************

// ********** Begin Class USkillsSubsystem *********************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_USkillsSubsystem;
UClass* USkillsSubsystem::GetPrivateStaticClass()
{
	using TClass = USkillsSubsystem;
	if (!Z_Registration_Info_UClass_USkillsSubsystem.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("SkillsSubsystem"),
			Z_Registration_Info_UClass_USkillsSubsystem.InnerSingleton,
			StaticRegisterNativesUSkillsSubsystem,
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
	return Z_Registration_Info_UClass_USkillsSubsystem.InnerSingleton;
}
UClass* Z_Construct_UClass_USkillsSubsystem_NoRegister()
{
	return USkillsSubsystem::GetPrivateStaticClass();
}
struct Z_Construct_UClass_USkillsSubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "SkillsSubsystem.h" },
		{ "ModuleRelativePath", "Public/SkillsSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class USkillsSubsystem constinit property declarations *************************
// ********** End Class USkillsSubsystem constinit property declarations ***************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("ResetSkills"), .Pointer = &USkillsSubsystem::execResetSkills },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_USkillsSubsystem_ResetSkills, "ResetSkills" }, // 2050969713
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<USkillsSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_USkillsSubsystem_Statics
UObject* (*const Z_Construct_UClass_USkillsSubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_ShatteredFatesGame,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_USkillsSubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_USkillsSubsystem_Statics::ClassParams = {
	&USkillsSubsystem::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_USkillsSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_USkillsSubsystem_Statics::Class_MetaDataParams)
};
void USkillsSubsystem::StaticRegisterNativesUSkillsSubsystem()
{
	UClass* Class = USkillsSubsystem::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_USkillsSubsystem_Statics::Funcs));
}
UClass* Z_Construct_UClass_USkillsSubsystem()
{
	if (!Z_Registration_Info_UClass_USkillsSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_USkillsSubsystem.OuterSingleton, Z_Construct_UClass_USkillsSubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_USkillsSubsystem.OuterSingleton;
}
USkillsSubsystem::USkillsSubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, USkillsSubsystem);
USkillsSubsystem::~USkillsSubsystem() {}
// ********** End Class USkillsSubsystem ***********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesGame_Public_SkillsSubsystem_h__Script_ShatteredFatesGame_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_USkillsSubsystem, USkillsSubsystem::StaticClass, TEXT("USkillsSubsystem"), &Z_Registration_Info_UClass_USkillsSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(USkillsSubsystem), 113775109U) },
	};
}; // Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesGame_Public_SkillsSubsystem_h__Script_ShatteredFatesGame_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesGame_Public_SkillsSubsystem_h__Script_ShatteredFatesGame_2880830086{
	TEXT("/Script/ShatteredFatesGame"),
	Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesGame_Public_SkillsSubsystem_h__Script_ShatteredFatesGame_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesGame_Public_SkillsSubsystem_h__Script_ShatteredFatesGame_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
