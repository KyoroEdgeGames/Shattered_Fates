// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ShatteredFatesGameInstance.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeShatteredFatesGameInstance() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UGameInstance();
SHATTEREDFATESGAME_API UClass* Z_Construct_UClass_UShatteredFatesGameInstance();
SHATTEREDFATESGAME_API UClass* Z_Construct_UClass_UShatteredFatesGameInstance_NoRegister();
UPackage* Z_Construct_UPackage__Script_ShatteredFatesGame();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UShatteredFatesGameInstance **********************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UShatteredFatesGameInstance;
UClass* UShatteredFatesGameInstance::GetPrivateStaticClass()
{
	using TClass = UShatteredFatesGameInstance;
	if (!Z_Registration_Info_UClass_UShatteredFatesGameInstance.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("ShatteredFatesGameInstance"),
			Z_Registration_Info_UClass_UShatteredFatesGameInstance.InnerSingleton,
			StaticRegisterNativesUShatteredFatesGameInstance,
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
	return Z_Registration_Info_UClass_UShatteredFatesGameInstance.InnerSingleton;
}
UClass* Z_Construct_UClass_UShatteredFatesGameInstance_NoRegister()
{
	return UShatteredFatesGameInstance::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UShatteredFatesGameInstance_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "ShatteredFatesGameInstance.h" },
		{ "ModuleRelativePath", "Public/ShatteredFatesGameInstance.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UShatteredFatesGameInstance constinit property declarations **************
// ********** End Class UShatteredFatesGameInstance constinit property declarations ****************
	static UObject* (*const DependentSingletons[])();
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UShatteredFatesGameInstance>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UShatteredFatesGameInstance_Statics
UObject* (*const Z_Construct_UClass_UShatteredFatesGameInstance_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameInstance,
	(UObject* (*)())Z_Construct_UPackage__Script_ShatteredFatesGame,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UShatteredFatesGameInstance_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UShatteredFatesGameInstance_Statics::ClassParams = {
	&UShatteredFatesGameInstance::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	nullptr,
	nullptr,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	0,
	0,
	0,
	0x009000A8u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UShatteredFatesGameInstance_Statics::Class_MetaDataParams), Z_Construct_UClass_UShatteredFatesGameInstance_Statics::Class_MetaDataParams)
};
void UShatteredFatesGameInstance::StaticRegisterNativesUShatteredFatesGameInstance()
{
}
UClass* Z_Construct_UClass_UShatteredFatesGameInstance()
{
	if (!Z_Registration_Info_UClass_UShatteredFatesGameInstance.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UShatteredFatesGameInstance.OuterSingleton, Z_Construct_UClass_UShatteredFatesGameInstance_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UShatteredFatesGameInstance.OuterSingleton;
}
UShatteredFatesGameInstance::UShatteredFatesGameInstance(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UShatteredFatesGameInstance);
UShatteredFatesGameInstance::~UShatteredFatesGameInstance() {}
// ********** End Class UShatteredFatesGameInstance ************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesGame_Public_ShatteredFatesGameInstance_h__Script_ShatteredFatesGame_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UShatteredFatesGameInstance, UShatteredFatesGameInstance::StaticClass, TEXT("UShatteredFatesGameInstance"), &Z_Registration_Info_UClass_UShatteredFatesGameInstance, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UShatteredFatesGameInstance), 1852950978U) },
	};
}; // Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesGame_Public_ShatteredFatesGameInstance_h__Script_ShatteredFatesGame_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesGame_Public_ShatteredFatesGameInstance_h__Script_ShatteredFatesGame_3185424326{
	TEXT("/Script/ShatteredFatesGame"),
	Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesGame_Public_ShatteredFatesGameInstance_h__Script_ShatteredFatesGame_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesGame_Public_ShatteredFatesGameInstance_h__Script_ShatteredFatesGame_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
