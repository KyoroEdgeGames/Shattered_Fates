// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

// IWYU pragma: private, include "QuestSubsystem.h"

#ifdef SHATTEREDFATESGAME_QuestSubsystem_generated_h
#error "QuestSubsystem.generated.h already included, missing '#pragma once' in QuestSubsystem.h"
#endif
#define SHATTEREDFATESGAME_QuestSubsystem_generated_h

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FQuestData;

// ********** Begin Class UQuestSubsystem **********************************************************
#define FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesGame_Public_QuestSubsystem_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	DECLARE_FUNCTION(execGetAllQuests); \
	DECLARE_FUNCTION(execLoadFromJson);


struct Z_Construct_UClass_UQuestSubsystem_Statics;
SHATTEREDFATESGAME_API UClass* Z_Construct_UClass_UQuestSubsystem_NoRegister();

#define FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesGame_Public_QuestSubsystem_h_11_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUQuestSubsystem(); \
	friend struct ::Z_Construct_UClass_UQuestSubsystem_Statics; \
	static UClass* GetPrivateStaticClass(); \
	friend SHATTEREDFATESGAME_API UClass* ::Z_Construct_UClass_UQuestSubsystem_NoRegister(); \
public: \
	DECLARE_CLASS2(UQuestSubsystem, UGameInstanceSubsystem, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/ShatteredFatesGame"), Z_Construct_UClass_UQuestSubsystem_NoRegister) \
	DECLARE_SERIALIZER(UQuestSubsystem)


#define FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesGame_Public_QuestSubsystem_h_11_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UQuestSubsystem(); \
	/** Deleted move- and copy-constructors, should never be used */ \
	UQuestSubsystem(UQuestSubsystem&&) = delete; \
	UQuestSubsystem(const UQuestSubsystem&) = delete; \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UQuestSubsystem); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UQuestSubsystem); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UQuestSubsystem) \
	NO_API virtual ~UQuestSubsystem();


#define FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesGame_Public_QuestSubsystem_h_8_PROLOG
#define FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesGame_Public_QuestSubsystem_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesGame_Public_QuestSubsystem_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesGame_Public_QuestSubsystem_h_11_INCLASS_NO_PURE_DECLS \
	FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesGame_Public_QuestSubsystem_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


class UQuestSubsystem;

// ********** End Class UQuestSubsystem ************************************************************

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesGame_Public_QuestSubsystem_h

PRAGMA_ENABLE_DEPRECATION_WARNINGS
