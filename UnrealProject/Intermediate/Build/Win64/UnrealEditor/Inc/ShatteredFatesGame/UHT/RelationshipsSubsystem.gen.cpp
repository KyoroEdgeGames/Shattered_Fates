// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "RelationshipsSubsystem.h"
#include "Engine/GameInstance.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeRelationshipsSubsystem() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
SHATTEREDFATESGAME_API UClass* Z_Construct_UClass_URelationshipsSubsystem();
SHATTEREDFATESGAME_API UClass* Z_Construct_UClass_URelationshipsSubsystem_NoRegister();
UPackage* Z_Construct_UPackage__Script_ShatteredFatesGame();
// ********** End Cross Module References **********************************************************

// ********** Begin Class URelationshipsSubsystem Function ResetRelationships **********************
struct Z_Construct_UFunction_URelationshipsSubsystem_ResetRelationships_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ShatteredFates|Relationships" },
		{ "ModuleRelativePath", "Public/RelationshipsSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function ResetRelationships constinit property declarations ********************
// ********** End Function ResetRelationships constinit property declarations **********************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_URelationshipsSubsystem_ResetRelationships_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_URelationshipsSubsystem, nullptr, "ResetRelationships", 	nullptr, 
	0, 
0,
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_URelationshipsSubsystem_ResetRelationships_Statics::Function_MetaDataParams), Z_Construct_UFunction_URelationshipsSubsystem_ResetRelationships_Statics::Function_MetaDataParams)},  };
UFunction* Z_Construct_UFunction_URelationshipsSubsystem_ResetRelationships()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_URelationshipsSubsystem_ResetRelationships_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(URelationshipsSubsystem::execResetRelationships)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->ResetRelationships();
	P_NATIVE_END;
}
// ********** End Class URelationshipsSubsystem Function ResetRelationships ************************

// ********** Begin Class URelationshipsSubsystem **************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_URelationshipsSubsystem;
UClass* URelationshipsSubsystem::GetPrivateStaticClass()
{
	using TClass = URelationshipsSubsystem;
	if (!Z_Registration_Info_UClass_URelationshipsSubsystem.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("RelationshipsSubsystem"),
			Z_Registration_Info_UClass_URelationshipsSubsystem.InnerSingleton,
			StaticRegisterNativesURelationshipsSubsystem,
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
	return Z_Registration_Info_UClass_URelationshipsSubsystem.InnerSingleton;
}
UClass* Z_Construct_UClass_URelationshipsSubsystem_NoRegister()
{
	return URelationshipsSubsystem::GetPrivateStaticClass();
}
struct Z_Construct_UClass_URelationshipsSubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "RelationshipsSubsystem.h" },
		{ "ModuleRelativePath", "Public/RelationshipsSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class URelationshipsSubsystem constinit property declarations ******************
// ********** End Class URelationshipsSubsystem constinit property declarations ********************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("ResetRelationships"), .Pointer = &URelationshipsSubsystem::execResetRelationships },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_URelationshipsSubsystem_ResetRelationships, "ResetRelationships" }, // 1446420991
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<URelationshipsSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_URelationshipsSubsystem_Statics
UObject* (*const Z_Construct_UClass_URelationshipsSubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_ShatteredFatesGame,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_URelationshipsSubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_URelationshipsSubsystem_Statics::ClassParams = {
	&URelationshipsSubsystem::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_URelationshipsSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_URelationshipsSubsystem_Statics::Class_MetaDataParams)
};
void URelationshipsSubsystem::StaticRegisterNativesURelationshipsSubsystem()
{
	UClass* Class = URelationshipsSubsystem::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_URelationshipsSubsystem_Statics::Funcs));
}
UClass* Z_Construct_UClass_URelationshipsSubsystem()
{
	if (!Z_Registration_Info_UClass_URelationshipsSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_URelationshipsSubsystem.OuterSingleton, Z_Construct_UClass_URelationshipsSubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_URelationshipsSubsystem.OuterSingleton;
}
URelationshipsSubsystem::URelationshipsSubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, URelationshipsSubsystem);
URelationshipsSubsystem::~URelationshipsSubsystem() {}
// ********** End Class URelationshipsSubsystem ****************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesGame_Public_RelationshipsSubsystem_h__Script_ShatteredFatesGame_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_URelationshipsSubsystem, URelationshipsSubsystem::StaticClass, TEXT("URelationshipsSubsystem"), &Z_Registration_Info_UClass_URelationshipsSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(URelationshipsSubsystem), 2230305466U) },
	};
}; // Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesGame_Public_RelationshipsSubsystem_h__Script_ShatteredFatesGame_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesGame_Public_RelationshipsSubsystem_h__Script_ShatteredFatesGame_3365551881{
	TEXT("/Script/ShatteredFatesGame"),
	Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesGame_Public_RelationshipsSubsystem_h__Script_ShatteredFatesGame_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesGame_Public_RelationshipsSubsystem_h__Script_ShatteredFatesGame_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
