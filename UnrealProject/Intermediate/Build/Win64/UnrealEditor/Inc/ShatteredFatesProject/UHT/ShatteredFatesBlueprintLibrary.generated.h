// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "ShatteredFatesBlueprintLibrary.h"

#ifdef SHATTEREDFATESPROJECT_ShatteredFatesBlueprintLibrary_generated_h
#error "ShatteredFatesBlueprintLibrary.generated.h already included, missing '#pragma once' in ShatteredFatesBlueprintLibrary.h"
#endif
#define SHATTEREDFATESPROJECT_ShatteredFatesBlueprintLibrary_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UCharacterDataAsset;
class UClanDataAsset;
class UDataTable;
class UHerbDataAsset;
class UItemDataAsset;
class UQuestDataAsset;

// ********** Begin Class UShatteredFatesBlueprintLibrary ******************************************
#define FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesProject_Public_ShatteredFatesBlueprintLibrary_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execLoadSkillsDataTableFromCsvFile); \
	DECLARE_FUNCTION(execLoadHerbsDataTableFromCsvFile); \
	DECLARE_FUNCTION(execLoadItemsDataTableFromCsvFile); \
	DECLARE_FUNCTION(execLoadClansDataTableFromCsvFile); \
	DECLARE_FUNCTION(execLoadQuestsDataTableFromCsvFile); \
	DECLARE_FUNCTION(execLoadCharactersDataTableFromCsvFile); \
	DECLARE_FUNCTION(execLoadHerbsFromJsonFile); \
	DECLARE_FUNCTION(execLoadItemsFromJsonFile); \
	DECLARE_FUNCTION(execLoadClansFromJsonFile); \
	DECLARE_FUNCTION(execLoadQuestsFromJsonFile); \
	DECLARE_FUNCTION(execLoadCharactersFromJsonFile);


struct Z_Construct_UClass_UShatteredFatesBlueprintLibrary_Statics;
SHATTEREDFATESPROJECT_API UClass* Z_Construct_UClass_UShatteredFatesBlueprintLibrary_NoRegister();

#define FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesProject_Public_ShatteredFatesBlueprintLibrary_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUShatteredFatesBlueprintLibrary(); \
	friend struct ::Z_Construct_UClass_UShatteredFatesBlueprintLibrary_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend SHATTEREDFATESPROJECT_API UClass* ::Z_Construct_UClass_UShatteredFatesBlueprintLibrary_NoRegister(); \
public: \
	DECLARE_CLASS2(UShatteredFatesBlueprintLibrary, UBlueprintFunctionLibrary, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ShatteredFatesProject"), Z_Construct_UClass_UShatteredFatesBlueprintLibrary_NoRegister) \
	DECLARE_SERIALIZER(UShatteredFatesBlueprintLibrary)


#define FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesProject_Public_ShatteredFatesBlueprintLibrary_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UShatteredFatesBlueprintLibrary(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UShatteredFatesBlueprintLibrary(UShatteredFatesBlueprintLibrary&&) = delete; \
	UShatteredFatesBlueprintLibrary(const UShatteredFatesBlueprintLibrary&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UShatteredFatesBlueprintLibrary); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UShatteredFatesBlueprintLibrary); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UShatteredFatesBlueprintLibrary) \
	NO_API virtual ~UShatteredFatesBlueprintLibrary();


#define FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesProject_Public_ShatteredFatesBlueprintLibrary_h_13_PROLOG
#define FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesProject_Public_ShatteredFatesBlueprintLibrary_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesProject_Public_ShatteredFatesBlueprintLibrary_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesProject_Public_ShatteredFatesBlueprintLibrary_h_16_INCLASS_NO_PURE_DECLS \
	FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesProject_Public_ShatteredFatesBlueprintLibrary_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UShatteredFatesBlueprintLibrary;

// ********** End Class UShatteredFatesBlueprintLibrary ********************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesProject_Public_ShatteredFatesBlueprintLibrary_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
