// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "CharacterSubsystem.h"
#include "CharacterData.h"
#include "Engine/GameInstance.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeCharacterSubsystem() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UGameInstanceSubsystem();
SHATTEREDFATESPROJECT_API UClass* Z_Construct_UClass_UCharacterDataAsset_NoRegister();
SHATTEREDFATESPROJECT_API UClass* Z_Construct_UClass_UCharacterSubsystem();
SHATTEREDFATESPROJECT_API UClass* Z_Construct_UClass_UCharacterSubsystem_NoRegister();
SHATTEREDFATESPROJECT_API UScriptStruct* Z_Construct_UScriptStruct_FCharacterData();
UPackage* Z_Construct_UPackage__Script_ShatteredFatesProject();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UCharacterSubsystem Function FindByClan **********************************
struct Z_Construct_UFunction_UCharacterSubsystem_FindByClan_Statics
{
	struct CharacterSubsystem_eventFindByClan_Parms
	{
		FName Clan;
		TArray<FCharacterData> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ShatteredFates|Characters" },
		{ "ModuleRelativePath", "Public/CharacterSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Clan_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function FindByClan constinit property declarations ****************************
	static const UECodeGen_Private::FNamePropertyParams NewProp_Clan;
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function FindByClan constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function FindByClan Property Definitions ***************************************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UCharacterSubsystem_FindByClan_Statics::NewProp_Clan = { "Clan", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CharacterSubsystem_eventFindByClan_Parms, Clan), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Clan_MetaData), NewProp_Clan_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCharacterSubsystem_FindByClan_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FCharacterData, METADATA_PARAMS(0, nullptr) }; // 3716101072
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UCharacterSubsystem_FindByClan_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CharacterSubsystem_eventFindByClan_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 3716101072
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCharacterSubsystem_FindByClan_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCharacterSubsystem_FindByClan_Statics::NewProp_Clan,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCharacterSubsystem_FindByClan_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCharacterSubsystem_FindByClan_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCharacterSubsystem_FindByClan_Statics::PropPointers) < 2048);
// ********** End Function FindByClan Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCharacterSubsystem_FindByClan_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCharacterSubsystem, nullptr, "FindByClan", 	Z_Construct_UFunction_UCharacterSubsystem_FindByClan_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCharacterSubsystem_FindByClan_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCharacterSubsystem_FindByClan_Statics::CharacterSubsystem_eventFindByClan_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCharacterSubsystem_FindByClan_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCharacterSubsystem_FindByClan_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCharacterSubsystem_FindByClan_Statics::CharacterSubsystem_eventFindByClan_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCharacterSubsystem_FindByClan()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCharacterSubsystem_FindByClan_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCharacterSubsystem::execFindByClan)
{
	P_GET_PROPERTY_REF(FNameProperty,Z_Param_Out_Clan);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FCharacterData>*)Z_Param__Result=P_THIS->FindByClan(Z_Param_Out_Clan);
	P_NATIVE_END;
}
// ********** End Class UCharacterSubsystem Function FindByClan ************************************

// ********** Begin Class UCharacterSubsystem Function FindByName **********************************
struct Z_Construct_UFunction_UCharacterSubsystem_FindByName_Statics
{
	struct CharacterSubsystem_eventFindByName_Parms
	{
		FName Name;
		FCharacterData OutCharacter;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ShatteredFates|Characters" },
		{ "ModuleRelativePath", "Public/CharacterSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function FindByName constinit property declarations ****************************
	static const UECodeGen_Private::FNamePropertyParams NewProp_Name;
	static const UECodeGen_Private::FStructPropertyParams NewProp_OutCharacter;
	static void NewProp_ReturnValue_SetBit(void* Obj);
	static const UECodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function FindByName constinit property declarations ******************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function FindByName Property Definitions ***************************************
const UECodeGen_Private::FNamePropertyParams Z_Construct_UFunction_UCharacterSubsystem_FindByName_Statics::NewProp_Name = { "Name", nullptr, (EPropertyFlags)0x0010000008000182, UECodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CharacterSubsystem_eventFindByName_Parms, Name), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_Name_MetaData), NewProp_Name_MetaData) };
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCharacterSubsystem_FindByName_Statics::NewProp_OutCharacter = { "OutCharacter", nullptr, (EPropertyFlags)0x0010000000000180, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CharacterSubsystem_eventFindByName_Parms, OutCharacter), Z_Construct_UScriptStruct_FCharacterData, METADATA_PARAMS(0, nullptr) }; // 3716101072
void Z_Construct_UFunction_UCharacterSubsystem_FindByName_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((CharacterSubsystem_eventFindByName_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCharacterSubsystem_FindByName_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CharacterSubsystem_eventFindByName_Parms), &Z_Construct_UFunction_UCharacterSubsystem_FindByName_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCharacterSubsystem_FindByName_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCharacterSubsystem_FindByName_Statics::NewProp_Name,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCharacterSubsystem_FindByName_Statics::NewProp_OutCharacter,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCharacterSubsystem_FindByName_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCharacterSubsystem_FindByName_Statics::PropPointers) < 2048);
// ********** End Function FindByName Property Definitions *****************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCharacterSubsystem_FindByName_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCharacterSubsystem, nullptr, "FindByName", 	Z_Construct_UFunction_UCharacterSubsystem_FindByName_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCharacterSubsystem_FindByName_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCharacterSubsystem_FindByName_Statics::CharacterSubsystem_eventFindByName_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54420401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCharacterSubsystem_FindByName_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCharacterSubsystem_FindByName_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCharacterSubsystem_FindByName_Statics::CharacterSubsystem_eventFindByName_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCharacterSubsystem_FindByName()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCharacterSubsystem_FindByName_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCharacterSubsystem::execFindByName)
{
	P_GET_PROPERTY_REF(FNameProperty,Z_Param_Out_Name);
	P_GET_STRUCT_REF(FCharacterData,Z_Param_Out_OutCharacter);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->FindByName(Z_Param_Out_Name,Z_Param_Out_OutCharacter);
	P_NATIVE_END;
}
// ********** End Class UCharacterSubsystem Function FindByName ************************************

// ********** Begin Class UCharacterSubsystem Function GetAllCharacters ****************************
struct Z_Construct_UFunction_UCharacterSubsystem_GetAllCharacters_Statics
{
	struct CharacterSubsystem_eventGetAllCharacters_Parms
	{
		TArray<FCharacterData> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ShatteredFates|Characters" },
		{ "ModuleRelativePath", "Public/CharacterSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_ReturnValue_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetAllCharacters constinit property declarations **********************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetAllCharacters constinit property declarations ************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetAllCharacters Property Definitions *********************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCharacterSubsystem_GetAllCharacters_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FCharacterData, METADATA_PARAMS(0, nullptr) }; // 3716101072
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UCharacterSubsystem_GetAllCharacters_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000008000582, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CharacterSubsystem_eventGetAllCharacters_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_ReturnValue_MetaData), NewProp_ReturnValue_MetaData) }; // 3716101072
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCharacterSubsystem_GetAllCharacters_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCharacterSubsystem_GetAllCharacters_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCharacterSubsystem_GetAllCharacters_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCharacterSubsystem_GetAllCharacters_Statics::PropPointers) < 2048);
// ********** End Function GetAllCharacters Property Definitions ***********************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCharacterSubsystem_GetAllCharacters_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCharacterSubsystem, nullptr, "GetAllCharacters", 	Z_Construct_UFunction_UCharacterSubsystem_GetAllCharacters_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCharacterSubsystem_GetAllCharacters_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCharacterSubsystem_GetAllCharacters_Statics::CharacterSubsystem_eventGetAllCharacters_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCharacterSubsystem_GetAllCharacters_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCharacterSubsystem_GetAllCharacters_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCharacterSubsystem_GetAllCharacters_Statics::CharacterSubsystem_eventGetAllCharacters_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCharacterSubsystem_GetAllCharacters()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCharacterSubsystem_GetAllCharacters_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCharacterSubsystem::execGetAllCharacters)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FCharacterData>*)Z_Param__Result=P_THIS->GetAllCharacters();
	P_NATIVE_END;
}
// ********** End Class UCharacterSubsystem Function GetAllCharacters ******************************

// ********** Begin Class UCharacterSubsystem Function GetPlayableCharacters ***********************
struct Z_Construct_UFunction_UCharacterSubsystem_GetPlayableCharacters_Statics
{
	struct CharacterSubsystem_eventGetPlayableCharacters_Parms
	{
		TArray<FCharacterData> ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ShatteredFates|Characters" },
		{ "ModuleRelativePath", "Public/CharacterSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function GetPlayableCharacters constinit property declarations *****************
	static const UECodeGen_Private::FStructPropertyParams NewProp_ReturnValue_Inner;
	static const UECodeGen_Private::FArrayPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function GetPlayableCharacters constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function GetPlayableCharacters Property Definitions ****************************
const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_UCharacterSubsystem_GetPlayableCharacters_Statics::NewProp_ReturnValue_Inner = { "ReturnValue", nullptr, (EPropertyFlags)0x0000000000000000, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UScriptStruct_FCharacterData, METADATA_PARAMS(0, nullptr) }; // 3716101072
const UECodeGen_Private::FArrayPropertyParams Z_Construct_UFunction_UCharacterSubsystem_GetPlayableCharacters_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CharacterSubsystem_eventGetPlayableCharacters_Parms, ReturnValue), EArrayPropertyFlags::None, METADATA_PARAMS(0, nullptr) }; // 3716101072
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCharacterSubsystem_GetPlayableCharacters_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCharacterSubsystem_GetPlayableCharacters_Statics::NewProp_ReturnValue_Inner,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCharacterSubsystem_GetPlayableCharacters_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCharacterSubsystem_GetPlayableCharacters_Statics::PropPointers) < 2048);
// ********** End Function GetPlayableCharacters Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCharacterSubsystem_GetPlayableCharacters_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCharacterSubsystem, nullptr, "GetPlayableCharacters", 	Z_Construct_UFunction_UCharacterSubsystem_GetPlayableCharacters_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCharacterSubsystem_GetPlayableCharacters_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCharacterSubsystem_GetPlayableCharacters_Statics::CharacterSubsystem_eventGetPlayableCharacters_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x54020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCharacterSubsystem_GetPlayableCharacters_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCharacterSubsystem_GetPlayableCharacters_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCharacterSubsystem_GetPlayableCharacters_Statics::CharacterSubsystem_eventGetPlayableCharacters_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCharacterSubsystem_GetPlayableCharacters()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCharacterSubsystem_GetPlayableCharacters_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCharacterSubsystem::execGetPlayableCharacters)
{
	P_FINISH;
	P_NATIVE_BEGIN;
	*(TArray<FCharacterData>*)Z_Param__Result=P_THIS->GetPlayableCharacters();
	P_NATIVE_END;
}
// ********** End Class UCharacterSubsystem Function GetPlayableCharacters *************************

// ********** Begin Class UCharacterSubsystem Function LoadFromJson ********************************
struct Z_Construct_UFunction_UCharacterSubsystem_LoadFromJson_Statics
{
	struct CharacterSubsystem_eventLoadFromJson_Parms
	{
		FString AbsolutePath;
		bool ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ShatteredFates|Characters" },
		{ "ModuleRelativePath", "Public/CharacterSubsystem.h" },
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
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UCharacterSubsystem_LoadFromJson_Statics::NewProp_AbsolutePath = { "AbsolutePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CharacterSubsystem_eventLoadFromJson_Parms, AbsolutePath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AbsolutePath_MetaData), NewProp_AbsolutePath_MetaData) };
void Z_Construct_UFunction_UCharacterSubsystem_LoadFromJson_Statics::NewProp_ReturnValue_SetBit(void* Obj)
{
	((CharacterSubsystem_eventLoadFromJson_Parms*)Obj)->ReturnValue = 1;
}
const UECodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_UCharacterSubsystem_LoadFromJson_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Bool | UECodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, sizeof(bool), sizeof(CharacterSubsystem_eventLoadFromJson_Parms), &Z_Construct_UFunction_UCharacterSubsystem_LoadFromJson_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCharacterSubsystem_LoadFromJson_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCharacterSubsystem_LoadFromJson_Statics::NewProp_AbsolutePath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCharacterSubsystem_LoadFromJson_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCharacterSubsystem_LoadFromJson_Statics::PropPointers) < 2048);
// ********** End Function LoadFromJson Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCharacterSubsystem_LoadFromJson_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCharacterSubsystem, nullptr, "LoadFromJson", 	Z_Construct_UFunction_UCharacterSubsystem_LoadFromJson_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCharacterSubsystem_LoadFromJson_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCharacterSubsystem_LoadFromJson_Statics::CharacterSubsystem_eventLoadFromJson_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCharacterSubsystem_LoadFromJson_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCharacterSubsystem_LoadFromJson_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCharacterSubsystem_LoadFromJson_Statics::CharacterSubsystem_eventLoadFromJson_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCharacterSubsystem_LoadFromJson()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCharacterSubsystem_LoadFromJson_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCharacterSubsystem::execLoadFromJson)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_AbsolutePath);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(bool*)Z_Param__Result=P_THIS->LoadFromJson(Z_Param_AbsolutePath);
	P_NATIVE_END;
}
// ********** End Class UCharacterSubsystem Function LoadFromJson **********************************

// ********** Begin Class UCharacterSubsystem Function SetDataAsset ********************************
struct Z_Construct_UFunction_UCharacterSubsystem_SetDataAsset_Statics
{
	struct CharacterSubsystem_eventSetDataAsset_Parms
	{
		UCharacterDataAsset* InAsset;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ShatteredFates|Characters" },
		{ "ModuleRelativePath", "Public/CharacterSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Function SetDataAsset constinit property declarations **************************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_InAsset;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function SetDataAsset constinit property declarations ****************************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function SetDataAsset Property Definitions *************************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UCharacterSubsystem_SetDataAsset_Statics::NewProp_InAsset = { "InAsset", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(CharacterSubsystem_eventSetDataAsset_Parms, InAsset), Z_Construct_UClass_UCharacterDataAsset_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UCharacterSubsystem_SetDataAsset_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UCharacterSubsystem_SetDataAsset_Statics::NewProp_InAsset,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UCharacterSubsystem_SetDataAsset_Statics::PropPointers) < 2048);
// ********** End Function SetDataAsset Property Definitions ***************************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UCharacterSubsystem_SetDataAsset_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UCharacterSubsystem, nullptr, "SetDataAsset", 	Z_Construct_UFunction_UCharacterSubsystem_SetDataAsset_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UCharacterSubsystem_SetDataAsset_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UCharacterSubsystem_SetDataAsset_Statics::CharacterSubsystem_eventSetDataAsset_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UCharacterSubsystem_SetDataAsset_Statics::Function_MetaDataParams), Z_Construct_UFunction_UCharacterSubsystem_SetDataAsset_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UCharacterSubsystem_SetDataAsset_Statics::CharacterSubsystem_eventSetDataAsset_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UCharacterSubsystem_SetDataAsset()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UCharacterSubsystem_SetDataAsset_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UCharacterSubsystem::execSetDataAsset)
{
	P_GET_OBJECT(UCharacterDataAsset,Z_Param_InAsset);
	P_FINISH;
	P_NATIVE_BEGIN;
	P_THIS->SetDataAsset(Z_Param_InAsset);
	P_NATIVE_END;
}
// ********** End Class UCharacterSubsystem Function SetDataAsset **********************************

// ********** Begin Class UCharacterSubsystem ******************************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UCharacterSubsystem;
UClass* UCharacterSubsystem::GetPrivateStaticClass()
{
	using TClass = UCharacterSubsystem;
	if (!Z_Registration_Info_UClass_UCharacterSubsystem.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("CharacterSubsystem"),
			Z_Registration_Info_UClass_UCharacterSubsystem.InnerSingleton,
			StaticRegisterNativesUCharacterSubsystem,
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
	return Z_Registration_Info_UClass_UCharacterSubsystem.InnerSingleton;
}
UClass* Z_Construct_UClass_UCharacterSubsystem_NoRegister()
{
	return UCharacterSubsystem::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UCharacterSubsystem_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "CharacterSubsystem.h" },
		{ "ModuleRelativePath", "Public/CharacterSubsystem.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_DataAsset_MetaData[] = {
		{ "ModuleRelativePath", "Public/CharacterSubsystem.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UCharacterSubsystem constinit property declarations **********************
	static const UECodeGen_Private::FObjectPropertyParams NewProp_DataAsset;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Class UCharacterSubsystem constinit property declarations ************************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("FindByClan"), .Pointer = &UCharacterSubsystem::execFindByClan },
		{ .NameUTF8 = UTF8TEXT("FindByName"), .Pointer = &UCharacterSubsystem::execFindByName },
		{ .NameUTF8 = UTF8TEXT("GetAllCharacters"), .Pointer = &UCharacterSubsystem::execGetAllCharacters },
		{ .NameUTF8 = UTF8TEXT("GetPlayableCharacters"), .Pointer = &UCharacterSubsystem::execGetPlayableCharacters },
		{ .NameUTF8 = UTF8TEXT("LoadFromJson"), .Pointer = &UCharacterSubsystem::execLoadFromJson },
		{ .NameUTF8 = UTF8TEXT("SetDataAsset"), .Pointer = &UCharacterSubsystem::execSetDataAsset },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UCharacterSubsystem_FindByClan, "FindByClan" }, // 1147271533
		{ &Z_Construct_UFunction_UCharacterSubsystem_FindByName, "FindByName" }, // 664421792
		{ &Z_Construct_UFunction_UCharacterSubsystem_GetAllCharacters, "GetAllCharacters" }, // 2930878927
		{ &Z_Construct_UFunction_UCharacterSubsystem_GetPlayableCharacters, "GetPlayableCharacters" }, // 2325785352
		{ &Z_Construct_UFunction_UCharacterSubsystem_LoadFromJson, "LoadFromJson" }, // 463933307
		{ &Z_Construct_UFunction_UCharacterSubsystem_SetDataAsset, "SetDataAsset" }, // 976256929
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UCharacterSubsystem>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UCharacterSubsystem_Statics

// ********** Begin Class UCharacterSubsystem Property Definitions *********************************
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_UCharacterSubsystem_Statics::NewProp_DataAsset = { "DataAsset", nullptr, (EPropertyFlags)0x0040000000000000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(UCharacterSubsystem, DataAsset), Z_Construct_UClass_UCharacterDataAsset_NoRegister, METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_DataAsset_MetaData), NewProp_DataAsset_MetaData) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UCharacterSubsystem_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UCharacterSubsystem_Statics::NewProp_DataAsset,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCharacterSubsystem_Statics::PropPointers) < 2048);
// ********** End Class UCharacterSubsystem Property Definitions ***********************************
UObject* (*const Z_Construct_UClass_UCharacterSubsystem_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UGameInstanceSubsystem,
	(UObject* (*)())Z_Construct_UPackage__Script_ShatteredFatesProject,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UCharacterSubsystem_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UCharacterSubsystem_Statics::ClassParams = {
	&UCharacterSubsystem::StaticClass,
	nullptr,
	&StaticCppClassTypeInfo,
	DependentSingletons,
	FuncInfo,
	Z_Construct_UClass_UCharacterSubsystem_Statics::PropPointers,
	nullptr,
	UE_ARRAY_COUNT(DependentSingletons),
	UE_ARRAY_COUNT(FuncInfo),
	UE_ARRAY_COUNT(Z_Construct_UClass_UCharacterSubsystem_Statics::PropPointers),
	0,
	0x001000A0u,
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UCharacterSubsystem_Statics::Class_MetaDataParams), Z_Construct_UClass_UCharacterSubsystem_Statics::Class_MetaDataParams)
};
void UCharacterSubsystem::StaticRegisterNativesUCharacterSubsystem()
{
	UClass* Class = UCharacterSubsystem::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UCharacterSubsystem_Statics::Funcs));
}
UClass* Z_Construct_UClass_UCharacterSubsystem()
{
	if (!Z_Registration_Info_UClass_UCharacterSubsystem.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UCharacterSubsystem.OuterSingleton, Z_Construct_UClass_UCharacterSubsystem_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UCharacterSubsystem.OuterSingleton;
}
UCharacterSubsystem::UCharacterSubsystem() {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UCharacterSubsystem);
UCharacterSubsystem::~UCharacterSubsystem() {}
// ********** End Class UCharacterSubsystem ********************************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesProject_Public_CharacterSubsystem_h__Script_ShatteredFatesProject_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UCharacterSubsystem, UCharacterSubsystem::StaticClass, TEXT("UCharacterSubsystem"), &Z_Registration_Info_UClass_UCharacterSubsystem, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UCharacterSubsystem), 1987139771U) },
	};
}; // Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesProject_Public_CharacterSubsystem_h__Script_ShatteredFatesProject_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesProject_Public_CharacterSubsystem_h__Script_ShatteredFatesProject_106698916{
	TEXT("/Script/ShatteredFatesProject"),
	Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesProject_Public_CharacterSubsystem_h__Script_ShatteredFatesProject_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesProject_Public_CharacterSubsystem_h__Script_ShatteredFatesProject_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
