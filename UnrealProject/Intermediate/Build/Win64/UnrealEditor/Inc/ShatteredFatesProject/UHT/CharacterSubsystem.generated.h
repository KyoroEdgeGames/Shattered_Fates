// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "CharacterSubsystem.h"

#ifdef SHATTEREDFATESPROJECT_CharacterSubsystem_generated_h
#error "CharacterSubsystem.generated.h already included, missing '#pragma once' in CharacterSubsystem.h"
#endif
#define SHATTEREDFATESPROJECT_CharacterSubsystem_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UCharacterDataAsset;
struct FCharacterData;

// ********** Begin Class UCharacterSubsystem ******************************************************
#define FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesProject_Public_CharacterSubsystem_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execFindByClan); \
	DECLARE_FUNCTION(execFindByName); \
	DECLARE_FUNCTION(execGetPlayableCharacters); \
	DECLARE_FUNCTION(execGetAllCharacters); \
	DECLARE_FUNCTION(execSetDataAsset); \
	DECLARE_FUNCTION(execLoadFromJson);


struct Z_Construct_UClass_UCharacterSubsystem_Statics;
SHATTEREDFATESPROJECT_API UClass* Z_Construct_UClass_UCharacterSubsystem_NoRegister();

#define FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesProject_Public_CharacterSubsystem_h_11_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCharacterSubsystem(); \
	friend struct ::Z_Construct_UClass_UCharacterSubsystem_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend SHATTEREDFATESPROJECT_API UClass* ::Z_Construct_UClass_UCharacterSubsystem_NoRegister(); \
public: \
	DECLARE_CLASS2(UCharacterSubsystem, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ShatteredFatesProject"), Z_Construct_UClass_UCharacterSubsystem_NoRegister) \
	DECLARE_SERIALIZER(UCharacterSubsystem)


#define FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesProject_Public_CharacterSubsystem_h_11_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCharacterSubsystem(); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UCharacterSubsystem(UCharacterSubsystem&&) = delete; \
	UCharacterSubsystem(const UCharacterSubsystem&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCharacterSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCharacterSubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UCharacterSubsystem) \
	NO_API virtual ~UCharacterSubsystem();


#define FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesProject_Public_CharacterSubsystem_h_8_PROLOG
#define FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesProject_Public_CharacterSubsystem_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesProject_Public_CharacterSubsystem_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesProject_Public_CharacterSubsystem_h_11_INCLASS_NO_PURE_DECLS \
	FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesProject_Public_CharacterSubsystem_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UCharacterSubsystem;

// ********** End Class UCharacterSubsystem ********************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesProject_Public_CharacterSubsystem_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
