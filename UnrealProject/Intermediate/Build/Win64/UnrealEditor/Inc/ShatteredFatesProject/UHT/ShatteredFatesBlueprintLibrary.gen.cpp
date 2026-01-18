// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "ShatteredFatesBlueprintLibrary.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
static_assert(!UE_WITH_CONSTINIT_UOBJECT, "This generated code can only be compiled with !UE_WITH_CONSTINIT_OBJECT");
void EmptyLinkFunctionForGeneratedCodeShatteredFatesBlueprintLibrary() {}

// ********** Begin Cross Module References ********************************************************
ENGINE_API UClass* Z_Construct_UClass_UBlueprintFunctionLibrary();
ENGINE_API UClass* Z_Construct_UClass_UDataTable_NoRegister();
SHATTEREDFATESPROJECT_API UClass* Z_Construct_UClass_UCharacterDataAsset_NoRegister();
SHATTEREDFATESPROJECT_API UClass* Z_Construct_UClass_UClanDataAsset_NoRegister();
SHATTEREDFATESPROJECT_API UClass* Z_Construct_UClass_UHerbDataAsset_NoRegister();
SHATTEREDFATESPROJECT_API UClass* Z_Construct_UClass_UItemDataAsset_NoRegister();
SHATTEREDFATESPROJECT_API UClass* Z_Construct_UClass_UQuestDataAsset_NoRegister();
SHATTEREDFATESPROJECT_API UClass* Z_Construct_UClass_UShatteredFatesBlueprintLibrary();
SHATTEREDFATESPROJECT_API UClass* Z_Construct_UClass_UShatteredFatesBlueprintLibrary_NoRegister();
UPackage* Z_Construct_UPackage__Script_ShatteredFatesProject();
// ********** End Cross Module References **********************************************************

// ********** Begin Class UShatteredFatesBlueprintLibrary Function LoadCharactersDataTableFromCsvFile 
struct Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadCharactersDataTableFromCsvFile_Statics
{
	struct ShatteredFatesBlueprintLibrary_eventLoadCharactersDataTableFromCsvFile_Parms
	{
		FString AbsolutePath;
		UDataTable* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ShatteredFates|Import" },
		{ "ModuleRelativePath", "Public/ShatteredFatesBlueprintLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AbsolutePath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function LoadCharactersDataTableFromCsvFile constinit property declarations ****
	static const UECodeGen_Private::FStrPropertyParams NewProp_AbsolutePath;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function LoadCharactersDataTableFromCsvFile constinit property declarations ******
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function LoadCharactersDataTableFromCsvFile Property Definitions ***************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadCharactersDataTableFromCsvFile_Statics::NewProp_AbsolutePath = { "AbsolutePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShatteredFatesBlueprintLibrary_eventLoadCharactersDataTableFromCsvFile_Parms, AbsolutePath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AbsolutePath_MetaData), NewProp_AbsolutePath_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadCharactersDataTableFromCsvFile_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShatteredFatesBlueprintLibrary_eventLoadCharactersDataTableFromCsvFile_Parms, ReturnValue), Z_Construct_UClass_UDataTable_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadCharactersDataTableFromCsvFile_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadCharactersDataTableFromCsvFile_Statics::NewProp_AbsolutePath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadCharactersDataTableFromCsvFile_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadCharactersDataTableFromCsvFile_Statics::PropPointers) < 2048);
// ********** End Function LoadCharactersDataTableFromCsvFile Property Definitions *****************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadCharactersDataTableFromCsvFile_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UShatteredFatesBlueprintLibrary, nullptr, "LoadCharactersDataTableFromCsvFile", 	Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadCharactersDataTableFromCsvFile_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadCharactersDataTableFromCsvFile_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadCharactersDataTableFromCsvFile_Statics::ShatteredFatesBlueprintLibrary_eventLoadCharactersDataTableFromCsvFile_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadCharactersDataTableFromCsvFile_Statics::Function_MetaDataParams), Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadCharactersDataTableFromCsvFile_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadCharactersDataTableFromCsvFile_Statics::ShatteredFatesBlueprintLibrary_eventLoadCharactersDataTableFromCsvFile_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadCharactersDataTableFromCsvFile()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadCharactersDataTableFromCsvFile_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UShatteredFatesBlueprintLibrary::execLoadCharactersDataTableFromCsvFile)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_AbsolutePath);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UDataTable**)Z_Param__Result=UShatteredFatesBlueprintLibrary::LoadCharactersDataTableFromCsvFile(Z_Param_AbsolutePath);
	P_NATIVE_END;
}
// ********** End Class UShatteredFatesBlueprintLibrary Function LoadCharactersDataTableFromCsvFile 

// ********** Begin Class UShatteredFatesBlueprintLibrary Function LoadCharactersFromJsonFile ******
struct Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadCharactersFromJsonFile_Statics
{
	struct ShatteredFatesBlueprintLibrary_eventLoadCharactersFromJsonFile_Parms
	{
		FString AbsolutePath;
		UCharacterDataAsset* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ShatteredFates|Import" },
		{ "ModuleRelativePath", "Public/ShatteredFatesBlueprintLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AbsolutePath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function LoadCharactersFromJsonFile constinit property declarations ************
	static const UECodeGen_Private::FStrPropertyParams NewProp_AbsolutePath;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function LoadCharactersFromJsonFile constinit property declarations **************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function LoadCharactersFromJsonFile Property Definitions ***********************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadCharactersFromJsonFile_Statics::NewProp_AbsolutePath = { "AbsolutePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShatteredFatesBlueprintLibrary_eventLoadCharactersFromJsonFile_Parms, AbsolutePath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AbsolutePath_MetaData), NewProp_AbsolutePath_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadCharactersFromJsonFile_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShatteredFatesBlueprintLibrary_eventLoadCharactersFromJsonFile_Parms, ReturnValue), Z_Construct_UClass_UCharacterDataAsset_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadCharactersFromJsonFile_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadCharactersFromJsonFile_Statics::NewProp_AbsolutePath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadCharactersFromJsonFile_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadCharactersFromJsonFile_Statics::PropPointers) < 2048);
// ********** End Function LoadCharactersFromJsonFile Property Definitions *************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadCharactersFromJsonFile_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UShatteredFatesBlueprintLibrary, nullptr, "LoadCharactersFromJsonFile", 	Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadCharactersFromJsonFile_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadCharactersFromJsonFile_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadCharactersFromJsonFile_Statics::ShatteredFatesBlueprintLibrary_eventLoadCharactersFromJsonFile_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadCharactersFromJsonFile_Statics::Function_MetaDataParams), Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadCharactersFromJsonFile_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadCharactersFromJsonFile_Statics::ShatteredFatesBlueprintLibrary_eventLoadCharactersFromJsonFile_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadCharactersFromJsonFile()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadCharactersFromJsonFile_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UShatteredFatesBlueprintLibrary::execLoadCharactersFromJsonFile)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_AbsolutePath);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UCharacterDataAsset**)Z_Param__Result=UShatteredFatesBlueprintLibrary::LoadCharactersFromJsonFile(Z_Param_AbsolutePath);
	P_NATIVE_END;
}
// ********** End Class UShatteredFatesBlueprintLibrary Function LoadCharactersFromJsonFile ********

// ********** Begin Class UShatteredFatesBlueprintLibrary Function LoadClansDataTableFromCsvFile ***
struct Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadClansDataTableFromCsvFile_Statics
{
	struct ShatteredFatesBlueprintLibrary_eventLoadClansDataTableFromCsvFile_Parms
	{
		FString AbsolutePath;
		UDataTable* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ShatteredFates|Import" },
		{ "ModuleRelativePath", "Public/ShatteredFatesBlueprintLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AbsolutePath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function LoadClansDataTableFromCsvFile constinit property declarations *********
	static const UECodeGen_Private::FStrPropertyParams NewProp_AbsolutePath;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function LoadClansDataTableFromCsvFile constinit property declarations ***********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function LoadClansDataTableFromCsvFile Property Definitions ********************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadClansDataTableFromCsvFile_Statics::NewProp_AbsolutePath = { "AbsolutePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShatteredFatesBlueprintLibrary_eventLoadClansDataTableFromCsvFile_Parms, AbsolutePath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AbsolutePath_MetaData), NewProp_AbsolutePath_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadClansDataTableFromCsvFile_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShatteredFatesBlueprintLibrary_eventLoadClansDataTableFromCsvFile_Parms, ReturnValue), Z_Construct_UClass_UDataTable_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadClansDataTableFromCsvFile_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadClansDataTableFromCsvFile_Statics::NewProp_AbsolutePath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadClansDataTableFromCsvFile_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadClansDataTableFromCsvFile_Statics::PropPointers) < 2048);
// ********** End Function LoadClansDataTableFromCsvFile Property Definitions **********************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadClansDataTableFromCsvFile_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UShatteredFatesBlueprintLibrary, nullptr, "LoadClansDataTableFromCsvFile", 	Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadClansDataTableFromCsvFile_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadClansDataTableFromCsvFile_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadClansDataTableFromCsvFile_Statics::ShatteredFatesBlueprintLibrary_eventLoadClansDataTableFromCsvFile_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadClansDataTableFromCsvFile_Statics::Function_MetaDataParams), Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadClansDataTableFromCsvFile_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadClansDataTableFromCsvFile_Statics::ShatteredFatesBlueprintLibrary_eventLoadClansDataTableFromCsvFile_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadClansDataTableFromCsvFile()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadClansDataTableFromCsvFile_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UShatteredFatesBlueprintLibrary::execLoadClansDataTableFromCsvFile)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_AbsolutePath);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UDataTable**)Z_Param__Result=UShatteredFatesBlueprintLibrary::LoadClansDataTableFromCsvFile(Z_Param_AbsolutePath);
	P_NATIVE_END;
}
// ********** End Class UShatteredFatesBlueprintLibrary Function LoadClansDataTableFromCsvFile *****

// ********** Begin Class UShatteredFatesBlueprintLibrary Function LoadClansFromJsonFile ***********
struct Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadClansFromJsonFile_Statics
{
	struct ShatteredFatesBlueprintLibrary_eventLoadClansFromJsonFile_Parms
	{
		FString AbsolutePath;
		UClanDataAsset* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ShatteredFates|Import" },
		{ "ModuleRelativePath", "Public/ShatteredFatesBlueprintLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AbsolutePath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function LoadClansFromJsonFile constinit property declarations *****************
	static const UECodeGen_Private::FStrPropertyParams NewProp_AbsolutePath;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function LoadClansFromJsonFile constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function LoadClansFromJsonFile Property Definitions ****************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadClansFromJsonFile_Statics::NewProp_AbsolutePath = { "AbsolutePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShatteredFatesBlueprintLibrary_eventLoadClansFromJsonFile_Parms, AbsolutePath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AbsolutePath_MetaData), NewProp_AbsolutePath_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadClansFromJsonFile_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShatteredFatesBlueprintLibrary_eventLoadClansFromJsonFile_Parms, ReturnValue), Z_Construct_UClass_UClanDataAsset_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadClansFromJsonFile_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadClansFromJsonFile_Statics::NewProp_AbsolutePath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadClansFromJsonFile_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadClansFromJsonFile_Statics::PropPointers) < 2048);
// ********** End Function LoadClansFromJsonFile Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadClansFromJsonFile_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UShatteredFatesBlueprintLibrary, nullptr, "LoadClansFromJsonFile", 	Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadClansFromJsonFile_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadClansFromJsonFile_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadClansFromJsonFile_Statics::ShatteredFatesBlueprintLibrary_eventLoadClansFromJsonFile_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadClansFromJsonFile_Statics::Function_MetaDataParams), Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadClansFromJsonFile_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadClansFromJsonFile_Statics::ShatteredFatesBlueprintLibrary_eventLoadClansFromJsonFile_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadClansFromJsonFile()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadClansFromJsonFile_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UShatteredFatesBlueprintLibrary::execLoadClansFromJsonFile)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_AbsolutePath);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UClanDataAsset**)Z_Param__Result=UShatteredFatesBlueprintLibrary::LoadClansFromJsonFile(Z_Param_AbsolutePath);
	P_NATIVE_END;
}
// ********** End Class UShatteredFatesBlueprintLibrary Function LoadClansFromJsonFile *************

// ********** Begin Class UShatteredFatesBlueprintLibrary Function LoadHerbsDataTableFromCsvFile ***
struct Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadHerbsDataTableFromCsvFile_Statics
{
	struct ShatteredFatesBlueprintLibrary_eventLoadHerbsDataTableFromCsvFile_Parms
	{
		FString AbsolutePath;
		UDataTable* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ShatteredFates|Import" },
		{ "ModuleRelativePath", "Public/ShatteredFatesBlueprintLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AbsolutePath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function LoadHerbsDataTableFromCsvFile constinit property declarations *********
	static const UECodeGen_Private::FStrPropertyParams NewProp_AbsolutePath;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function LoadHerbsDataTableFromCsvFile constinit property declarations ***********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function LoadHerbsDataTableFromCsvFile Property Definitions ********************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadHerbsDataTableFromCsvFile_Statics::NewProp_AbsolutePath = { "AbsolutePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShatteredFatesBlueprintLibrary_eventLoadHerbsDataTableFromCsvFile_Parms, AbsolutePath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AbsolutePath_MetaData), NewProp_AbsolutePath_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadHerbsDataTableFromCsvFile_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShatteredFatesBlueprintLibrary_eventLoadHerbsDataTableFromCsvFile_Parms, ReturnValue), Z_Construct_UClass_UDataTable_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadHerbsDataTableFromCsvFile_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadHerbsDataTableFromCsvFile_Statics::NewProp_AbsolutePath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadHerbsDataTableFromCsvFile_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadHerbsDataTableFromCsvFile_Statics::PropPointers) < 2048);
// ********** End Function LoadHerbsDataTableFromCsvFile Property Definitions **********************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadHerbsDataTableFromCsvFile_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UShatteredFatesBlueprintLibrary, nullptr, "LoadHerbsDataTableFromCsvFile", 	Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadHerbsDataTableFromCsvFile_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadHerbsDataTableFromCsvFile_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadHerbsDataTableFromCsvFile_Statics::ShatteredFatesBlueprintLibrary_eventLoadHerbsDataTableFromCsvFile_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadHerbsDataTableFromCsvFile_Statics::Function_MetaDataParams), Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadHerbsDataTableFromCsvFile_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadHerbsDataTableFromCsvFile_Statics::ShatteredFatesBlueprintLibrary_eventLoadHerbsDataTableFromCsvFile_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadHerbsDataTableFromCsvFile()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadHerbsDataTableFromCsvFile_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UShatteredFatesBlueprintLibrary::execLoadHerbsDataTableFromCsvFile)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_AbsolutePath);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UDataTable**)Z_Param__Result=UShatteredFatesBlueprintLibrary::LoadHerbsDataTableFromCsvFile(Z_Param_AbsolutePath);
	P_NATIVE_END;
}
// ********** End Class UShatteredFatesBlueprintLibrary Function LoadHerbsDataTableFromCsvFile *****

// ********** Begin Class UShatteredFatesBlueprintLibrary Function LoadHerbsFromJsonFile ***********
struct Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadHerbsFromJsonFile_Statics
{
	struct ShatteredFatesBlueprintLibrary_eventLoadHerbsFromJsonFile_Parms
	{
		FString AbsolutePath;
		UHerbDataAsset* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ShatteredFates|Import" },
		{ "ModuleRelativePath", "Public/ShatteredFatesBlueprintLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AbsolutePath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function LoadHerbsFromJsonFile constinit property declarations *****************
	static const UECodeGen_Private::FStrPropertyParams NewProp_AbsolutePath;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function LoadHerbsFromJsonFile constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function LoadHerbsFromJsonFile Property Definitions ****************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadHerbsFromJsonFile_Statics::NewProp_AbsolutePath = { "AbsolutePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShatteredFatesBlueprintLibrary_eventLoadHerbsFromJsonFile_Parms, AbsolutePath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AbsolutePath_MetaData), NewProp_AbsolutePath_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadHerbsFromJsonFile_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShatteredFatesBlueprintLibrary_eventLoadHerbsFromJsonFile_Parms, ReturnValue), Z_Construct_UClass_UHerbDataAsset_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadHerbsFromJsonFile_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadHerbsFromJsonFile_Statics::NewProp_AbsolutePath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadHerbsFromJsonFile_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadHerbsFromJsonFile_Statics::PropPointers) < 2048);
// ********** End Function LoadHerbsFromJsonFile Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadHerbsFromJsonFile_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UShatteredFatesBlueprintLibrary, nullptr, "LoadHerbsFromJsonFile", 	Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadHerbsFromJsonFile_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadHerbsFromJsonFile_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadHerbsFromJsonFile_Statics::ShatteredFatesBlueprintLibrary_eventLoadHerbsFromJsonFile_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadHerbsFromJsonFile_Statics::Function_MetaDataParams), Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadHerbsFromJsonFile_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadHerbsFromJsonFile_Statics::ShatteredFatesBlueprintLibrary_eventLoadHerbsFromJsonFile_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadHerbsFromJsonFile()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadHerbsFromJsonFile_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UShatteredFatesBlueprintLibrary::execLoadHerbsFromJsonFile)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_AbsolutePath);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UHerbDataAsset**)Z_Param__Result=UShatteredFatesBlueprintLibrary::LoadHerbsFromJsonFile(Z_Param_AbsolutePath);
	P_NATIVE_END;
}
// ********** End Class UShatteredFatesBlueprintLibrary Function LoadHerbsFromJsonFile *************

// ********** Begin Class UShatteredFatesBlueprintLibrary Function LoadItemsDataTableFromCsvFile ***
struct Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadItemsDataTableFromCsvFile_Statics
{
	struct ShatteredFatesBlueprintLibrary_eventLoadItemsDataTableFromCsvFile_Parms
	{
		FString AbsolutePath;
		UDataTable* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ShatteredFates|Import" },
		{ "ModuleRelativePath", "Public/ShatteredFatesBlueprintLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AbsolutePath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function LoadItemsDataTableFromCsvFile constinit property declarations *********
	static const UECodeGen_Private::FStrPropertyParams NewProp_AbsolutePath;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function LoadItemsDataTableFromCsvFile constinit property declarations ***********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function LoadItemsDataTableFromCsvFile Property Definitions ********************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadItemsDataTableFromCsvFile_Statics::NewProp_AbsolutePath = { "AbsolutePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShatteredFatesBlueprintLibrary_eventLoadItemsDataTableFromCsvFile_Parms, AbsolutePath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AbsolutePath_MetaData), NewProp_AbsolutePath_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadItemsDataTableFromCsvFile_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShatteredFatesBlueprintLibrary_eventLoadItemsDataTableFromCsvFile_Parms, ReturnValue), Z_Construct_UClass_UDataTable_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadItemsDataTableFromCsvFile_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadItemsDataTableFromCsvFile_Statics::NewProp_AbsolutePath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadItemsDataTableFromCsvFile_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadItemsDataTableFromCsvFile_Statics::PropPointers) < 2048);
// ********** End Function LoadItemsDataTableFromCsvFile Property Definitions **********************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadItemsDataTableFromCsvFile_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UShatteredFatesBlueprintLibrary, nullptr, "LoadItemsDataTableFromCsvFile", 	Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadItemsDataTableFromCsvFile_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadItemsDataTableFromCsvFile_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadItemsDataTableFromCsvFile_Statics::ShatteredFatesBlueprintLibrary_eventLoadItemsDataTableFromCsvFile_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadItemsDataTableFromCsvFile_Statics::Function_MetaDataParams), Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadItemsDataTableFromCsvFile_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadItemsDataTableFromCsvFile_Statics::ShatteredFatesBlueprintLibrary_eventLoadItemsDataTableFromCsvFile_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadItemsDataTableFromCsvFile()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadItemsDataTableFromCsvFile_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UShatteredFatesBlueprintLibrary::execLoadItemsDataTableFromCsvFile)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_AbsolutePath);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UDataTable**)Z_Param__Result=UShatteredFatesBlueprintLibrary::LoadItemsDataTableFromCsvFile(Z_Param_AbsolutePath);
	P_NATIVE_END;
}
// ********** End Class UShatteredFatesBlueprintLibrary Function LoadItemsDataTableFromCsvFile *****

// ********** Begin Class UShatteredFatesBlueprintLibrary Function LoadItemsFromJsonFile ***********
struct Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadItemsFromJsonFile_Statics
{
	struct ShatteredFatesBlueprintLibrary_eventLoadItemsFromJsonFile_Parms
	{
		FString AbsolutePath;
		UItemDataAsset* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ShatteredFates|Import" },
		{ "ModuleRelativePath", "Public/ShatteredFatesBlueprintLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AbsolutePath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function LoadItemsFromJsonFile constinit property declarations *****************
	static const UECodeGen_Private::FStrPropertyParams NewProp_AbsolutePath;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function LoadItemsFromJsonFile constinit property declarations *******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function LoadItemsFromJsonFile Property Definitions ****************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadItemsFromJsonFile_Statics::NewProp_AbsolutePath = { "AbsolutePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShatteredFatesBlueprintLibrary_eventLoadItemsFromJsonFile_Parms, AbsolutePath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AbsolutePath_MetaData), NewProp_AbsolutePath_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadItemsFromJsonFile_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShatteredFatesBlueprintLibrary_eventLoadItemsFromJsonFile_Parms, ReturnValue), Z_Construct_UClass_UItemDataAsset_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadItemsFromJsonFile_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadItemsFromJsonFile_Statics::NewProp_AbsolutePath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadItemsFromJsonFile_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadItemsFromJsonFile_Statics::PropPointers) < 2048);
// ********** End Function LoadItemsFromJsonFile Property Definitions ******************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadItemsFromJsonFile_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UShatteredFatesBlueprintLibrary, nullptr, "LoadItemsFromJsonFile", 	Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadItemsFromJsonFile_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadItemsFromJsonFile_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadItemsFromJsonFile_Statics::ShatteredFatesBlueprintLibrary_eventLoadItemsFromJsonFile_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadItemsFromJsonFile_Statics::Function_MetaDataParams), Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadItemsFromJsonFile_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadItemsFromJsonFile_Statics::ShatteredFatesBlueprintLibrary_eventLoadItemsFromJsonFile_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadItemsFromJsonFile()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadItemsFromJsonFile_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UShatteredFatesBlueprintLibrary::execLoadItemsFromJsonFile)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_AbsolutePath);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UItemDataAsset**)Z_Param__Result=UShatteredFatesBlueprintLibrary::LoadItemsFromJsonFile(Z_Param_AbsolutePath);
	P_NATIVE_END;
}
// ********** End Class UShatteredFatesBlueprintLibrary Function LoadItemsFromJsonFile *************

// ********** Begin Class UShatteredFatesBlueprintLibrary Function LoadQuestsDataTableFromCsvFile **
struct Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadQuestsDataTableFromCsvFile_Statics
{
	struct ShatteredFatesBlueprintLibrary_eventLoadQuestsDataTableFromCsvFile_Parms
	{
		FString AbsolutePath;
		UDataTable* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ShatteredFates|Import" },
		{ "ModuleRelativePath", "Public/ShatteredFatesBlueprintLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AbsolutePath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function LoadQuestsDataTableFromCsvFile constinit property declarations ********
	static const UECodeGen_Private::FStrPropertyParams NewProp_AbsolutePath;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function LoadQuestsDataTableFromCsvFile constinit property declarations **********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function LoadQuestsDataTableFromCsvFile Property Definitions *******************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadQuestsDataTableFromCsvFile_Statics::NewProp_AbsolutePath = { "AbsolutePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShatteredFatesBlueprintLibrary_eventLoadQuestsDataTableFromCsvFile_Parms, AbsolutePath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AbsolutePath_MetaData), NewProp_AbsolutePath_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadQuestsDataTableFromCsvFile_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShatteredFatesBlueprintLibrary_eventLoadQuestsDataTableFromCsvFile_Parms, ReturnValue), Z_Construct_UClass_UDataTable_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadQuestsDataTableFromCsvFile_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadQuestsDataTableFromCsvFile_Statics::NewProp_AbsolutePath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadQuestsDataTableFromCsvFile_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadQuestsDataTableFromCsvFile_Statics::PropPointers) < 2048);
// ********** End Function LoadQuestsDataTableFromCsvFile Property Definitions *********************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadQuestsDataTableFromCsvFile_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UShatteredFatesBlueprintLibrary, nullptr, "LoadQuestsDataTableFromCsvFile", 	Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadQuestsDataTableFromCsvFile_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadQuestsDataTableFromCsvFile_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadQuestsDataTableFromCsvFile_Statics::ShatteredFatesBlueprintLibrary_eventLoadQuestsDataTableFromCsvFile_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadQuestsDataTableFromCsvFile_Statics::Function_MetaDataParams), Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadQuestsDataTableFromCsvFile_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadQuestsDataTableFromCsvFile_Statics::ShatteredFatesBlueprintLibrary_eventLoadQuestsDataTableFromCsvFile_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadQuestsDataTableFromCsvFile()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadQuestsDataTableFromCsvFile_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UShatteredFatesBlueprintLibrary::execLoadQuestsDataTableFromCsvFile)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_AbsolutePath);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UDataTable**)Z_Param__Result=UShatteredFatesBlueprintLibrary::LoadQuestsDataTableFromCsvFile(Z_Param_AbsolutePath);
	P_NATIVE_END;
}
// ********** End Class UShatteredFatesBlueprintLibrary Function LoadQuestsDataTableFromCsvFile ****

// ********** Begin Class UShatteredFatesBlueprintLibrary Function LoadQuestsFromJsonFile **********
struct Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadQuestsFromJsonFile_Statics
{
	struct ShatteredFatesBlueprintLibrary_eventLoadQuestsFromJsonFile_Parms
	{
		FString AbsolutePath;
		UQuestDataAsset* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ShatteredFates|Import" },
		{ "ModuleRelativePath", "Public/ShatteredFatesBlueprintLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AbsolutePath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function LoadQuestsFromJsonFile constinit property declarations ****************
	static const UECodeGen_Private::FStrPropertyParams NewProp_AbsolutePath;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function LoadQuestsFromJsonFile constinit property declarations ******************
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function LoadQuestsFromJsonFile Property Definitions ***************************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadQuestsFromJsonFile_Statics::NewProp_AbsolutePath = { "AbsolutePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShatteredFatesBlueprintLibrary_eventLoadQuestsFromJsonFile_Parms, AbsolutePath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AbsolutePath_MetaData), NewProp_AbsolutePath_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadQuestsFromJsonFile_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShatteredFatesBlueprintLibrary_eventLoadQuestsFromJsonFile_Parms, ReturnValue), Z_Construct_UClass_UQuestDataAsset_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadQuestsFromJsonFile_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadQuestsFromJsonFile_Statics::NewProp_AbsolutePath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadQuestsFromJsonFile_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadQuestsFromJsonFile_Statics::PropPointers) < 2048);
// ********** End Function LoadQuestsFromJsonFile Property Definitions *****************************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadQuestsFromJsonFile_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UShatteredFatesBlueprintLibrary, nullptr, "LoadQuestsFromJsonFile", 	Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadQuestsFromJsonFile_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadQuestsFromJsonFile_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadQuestsFromJsonFile_Statics::ShatteredFatesBlueprintLibrary_eventLoadQuestsFromJsonFile_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadQuestsFromJsonFile_Statics::Function_MetaDataParams), Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadQuestsFromJsonFile_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadQuestsFromJsonFile_Statics::ShatteredFatesBlueprintLibrary_eventLoadQuestsFromJsonFile_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadQuestsFromJsonFile()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadQuestsFromJsonFile_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UShatteredFatesBlueprintLibrary::execLoadQuestsFromJsonFile)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_AbsolutePath);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UQuestDataAsset**)Z_Param__Result=UShatteredFatesBlueprintLibrary::LoadQuestsFromJsonFile(Z_Param_AbsolutePath);
	P_NATIVE_END;
}
// ********** End Class UShatteredFatesBlueprintLibrary Function LoadQuestsFromJsonFile ************

// ********** Begin Class UShatteredFatesBlueprintLibrary Function LoadSkillsDataTableFromCsvFile **
struct Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadSkillsDataTableFromCsvFile_Statics
{
	struct ShatteredFatesBlueprintLibrary_eventLoadSkillsDataTableFromCsvFile_Parms
	{
		FString AbsolutePath;
		UDataTable* ReturnValue;
	};
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
		{ "Category", "ShatteredFates|Import" },
		{ "ModuleRelativePath", "Public/ShatteredFatesBlueprintLibrary.h" },
	};
	static constexpr UECodeGen_Private::FMetaDataPairParam NewProp_AbsolutePath_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif // WITH_METADATA

// ********** Begin Function LoadSkillsDataTableFromCsvFile constinit property declarations ********
	static const UECodeGen_Private::FStrPropertyParams NewProp_AbsolutePath;
	static const UECodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
	static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
// ********** End Function LoadSkillsDataTableFromCsvFile constinit property declarations **********
	static const UECodeGen_Private::FFunctionParams FuncParams;
};

// ********** Begin Function LoadSkillsDataTableFromCsvFile Property Definitions *******************
const UECodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadSkillsDataTableFromCsvFile_Statics::NewProp_AbsolutePath = { "AbsolutePath", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShatteredFatesBlueprintLibrary_eventLoadSkillsDataTableFromCsvFile_Parms, AbsolutePath), METADATA_PARAMS(UE_ARRAY_COUNT(NewProp_AbsolutePath_MetaData), NewProp_AbsolutePath_MetaData) };
const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadSkillsDataTableFromCsvFile_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ShatteredFatesBlueprintLibrary_eventLoadSkillsDataTableFromCsvFile_Parms, ReturnValue), Z_Construct_UClass_UDataTable_NoRegister, METADATA_PARAMS(0, nullptr) };
const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadSkillsDataTableFromCsvFile_Statics::PropPointers[] = {
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadSkillsDataTableFromCsvFile_Statics::NewProp_AbsolutePath,
	(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadSkillsDataTableFromCsvFile_Statics::NewProp_ReturnValue,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadSkillsDataTableFromCsvFile_Statics::PropPointers) < 2048);
// ********** End Function LoadSkillsDataTableFromCsvFile Property Definitions *********************
const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadSkillsDataTableFromCsvFile_Statics::FuncParams = { { (UObject*(*)())Z_Construct_UClass_UShatteredFatesBlueprintLibrary, nullptr, "LoadSkillsDataTableFromCsvFile", 	Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadSkillsDataTableFromCsvFile_Statics::PropPointers, 
	UE_ARRAY_COUNT(Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadSkillsDataTableFromCsvFile_Statics::PropPointers), 
sizeof(Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadSkillsDataTableFromCsvFile_Statics::ShatteredFatesBlueprintLibrary_eventLoadSkillsDataTableFromCsvFile_Parms),
RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04022401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadSkillsDataTableFromCsvFile_Statics::Function_MetaDataParams), Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadSkillsDataTableFromCsvFile_Statics::Function_MetaDataParams)},  };
static_assert(sizeof(Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadSkillsDataTableFromCsvFile_Statics::ShatteredFatesBlueprintLibrary_eventLoadSkillsDataTableFromCsvFile_Parms) < MAX_uint16);
UFunction* Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadSkillsDataTableFromCsvFile()
{
	static UFunction* ReturnFunction = nullptr;
	if (!ReturnFunction)
	{
		UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadSkillsDataTableFromCsvFile_Statics::FuncParams);
	}
	return ReturnFunction;
}
DEFINE_FUNCTION(UShatteredFatesBlueprintLibrary::execLoadSkillsDataTableFromCsvFile)
{
	P_GET_PROPERTY(FStrProperty,Z_Param_AbsolutePath);
	P_FINISH;
	P_NATIVE_BEGIN;
	*(UDataTable**)Z_Param__Result=UShatteredFatesBlueprintLibrary::LoadSkillsDataTableFromCsvFile(Z_Param_AbsolutePath);
	P_NATIVE_END;
}
// ********** End Class UShatteredFatesBlueprintLibrary Function LoadSkillsDataTableFromCsvFile ****

// ********** Begin Class UShatteredFatesBlueprintLibrary ******************************************
FClassRegistrationInfo Z_Registration_Info_UClass_UShatteredFatesBlueprintLibrary;
UClass* UShatteredFatesBlueprintLibrary::GetPrivateStaticClass()
{
	using TClass = UShatteredFatesBlueprintLibrary;
	if (!Z_Registration_Info_UClass_UShatteredFatesBlueprintLibrary.InnerSingleton)
	{
		GetPrivateStaticClassBody(
			TClass::StaticPackage(),
			TEXT("ShatteredFatesBlueprintLibrary"),
			Z_Registration_Info_UClass_UShatteredFatesBlueprintLibrary.InnerSingleton,
			StaticRegisterNativesUShatteredFatesBlueprintLibrary,
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
	return Z_Registration_Info_UClass_UShatteredFatesBlueprintLibrary.InnerSingleton;
}
UClass* Z_Construct_UClass_UShatteredFatesBlueprintLibrary_NoRegister()
{
	return UShatteredFatesBlueprintLibrary::GetPrivateStaticClass();
}
struct Z_Construct_UClass_UShatteredFatesBlueprintLibrary_Statics
{
#if WITH_METADATA
	static constexpr UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
		{ "IncludePath", "ShatteredFatesBlueprintLibrary.h" },
		{ "ModuleRelativePath", "Public/ShatteredFatesBlueprintLibrary.h" },
	};
#endif // WITH_METADATA

// ********** Begin Class UShatteredFatesBlueprintLibrary constinit property declarations **********
// ********** End Class UShatteredFatesBlueprintLibrary constinit property declarations ************
	static constexpr UE::CodeGen::FClassNativeFunction Funcs[] = {
		{ .NameUTF8 = UTF8TEXT("LoadCharactersDataTableFromCsvFile"), .Pointer = &UShatteredFatesBlueprintLibrary::execLoadCharactersDataTableFromCsvFile },
		{ .NameUTF8 = UTF8TEXT("LoadCharactersFromJsonFile"), .Pointer = &UShatteredFatesBlueprintLibrary::execLoadCharactersFromJsonFile },
		{ .NameUTF8 = UTF8TEXT("LoadClansDataTableFromCsvFile"), .Pointer = &UShatteredFatesBlueprintLibrary::execLoadClansDataTableFromCsvFile },
		{ .NameUTF8 = UTF8TEXT("LoadClansFromJsonFile"), .Pointer = &UShatteredFatesBlueprintLibrary::execLoadClansFromJsonFile },
		{ .NameUTF8 = UTF8TEXT("LoadHerbsDataTableFromCsvFile"), .Pointer = &UShatteredFatesBlueprintLibrary::execLoadHerbsDataTableFromCsvFile },
		{ .NameUTF8 = UTF8TEXT("LoadHerbsFromJsonFile"), .Pointer = &UShatteredFatesBlueprintLibrary::execLoadHerbsFromJsonFile },
		{ .NameUTF8 = UTF8TEXT("LoadItemsDataTableFromCsvFile"), .Pointer = &UShatteredFatesBlueprintLibrary::execLoadItemsDataTableFromCsvFile },
		{ .NameUTF8 = UTF8TEXT("LoadItemsFromJsonFile"), .Pointer = &UShatteredFatesBlueprintLibrary::execLoadItemsFromJsonFile },
		{ .NameUTF8 = UTF8TEXT("LoadQuestsDataTableFromCsvFile"), .Pointer = &UShatteredFatesBlueprintLibrary::execLoadQuestsDataTableFromCsvFile },
		{ .NameUTF8 = UTF8TEXT("LoadQuestsFromJsonFile"), .Pointer = &UShatteredFatesBlueprintLibrary::execLoadQuestsFromJsonFile },
		{ .NameUTF8 = UTF8TEXT("LoadSkillsDataTableFromCsvFile"), .Pointer = &UShatteredFatesBlueprintLibrary::execLoadSkillsDataTableFromCsvFile },
	};
	static UObject* (*const DependentSingletons[])();
	static constexpr FClassFunctionLinkInfo FuncInfo[] = {
		{ &Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadCharactersDataTableFromCsvFile, "LoadCharactersDataTableFromCsvFile" }, // 4047522518
		{ &Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadCharactersFromJsonFile, "LoadCharactersFromJsonFile" }, // 410200698
		{ &Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadClansDataTableFromCsvFile, "LoadClansDataTableFromCsvFile" }, // 1921132698
		{ &Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadClansFromJsonFile, "LoadClansFromJsonFile" }, // 2551779728
		{ &Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadHerbsDataTableFromCsvFile, "LoadHerbsDataTableFromCsvFile" }, // 2515738855
		{ &Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadHerbsFromJsonFile, "LoadHerbsFromJsonFile" }, // 1880168341
		{ &Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadItemsDataTableFromCsvFile, "LoadItemsDataTableFromCsvFile" }, // 748368451
		{ &Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadItemsFromJsonFile, "LoadItemsFromJsonFile" }, // 3290507956
		{ &Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadQuestsDataTableFromCsvFile, "LoadQuestsDataTableFromCsvFile" }, // 2357970766
		{ &Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadQuestsFromJsonFile, "LoadQuestsFromJsonFile" }, // 369081848
		{ &Z_Construct_UFunction_UShatteredFatesBlueprintLibrary_LoadSkillsDataTableFromCsvFile, "LoadSkillsDataTableFromCsvFile" }, // 1515823210
	};
	static_assert(UE_ARRAY_COUNT(FuncInfo) < 2048);
	static constexpr FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UShatteredFatesBlueprintLibrary>::IsAbstract,
	};
	static const UECodeGen_Private::FClassParams ClassParams;
}; // struct Z_Construct_UClass_UShatteredFatesBlueprintLibrary_Statics
UObject* (*const Z_Construct_UClass_UShatteredFatesBlueprintLibrary_Statics::DependentSingletons[])() = {
	(UObject* (*)())Z_Construct_UClass_UBlueprintFunctionLibrary,
	(UObject* (*)())Z_Construct_UPackage__Script_ShatteredFatesProject,
};
static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_UShatteredFatesBlueprintLibrary_Statics::DependentSingletons) < 16);
const UECodeGen_Private::FClassParams Z_Construct_UClass_UShatteredFatesBlueprintLibrary_Statics::ClassParams = {
	&UShatteredFatesBlueprintLibrary::StaticClass,
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
	METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_UShatteredFatesBlueprintLibrary_Statics::Class_MetaDataParams), Z_Construct_UClass_UShatteredFatesBlueprintLibrary_Statics::Class_MetaDataParams)
};
void UShatteredFatesBlueprintLibrary::StaticRegisterNativesUShatteredFatesBlueprintLibrary()
{
	UClass* Class = UShatteredFatesBlueprintLibrary::StaticClass();
	FNativeFunctionRegistrar::RegisterFunctions(Class, MakeConstArrayView(Z_Construct_UClass_UShatteredFatesBlueprintLibrary_Statics::Funcs));
}
UClass* Z_Construct_UClass_UShatteredFatesBlueprintLibrary()
{
	if (!Z_Registration_Info_UClass_UShatteredFatesBlueprintLibrary.OuterSingleton)
	{
		UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_UShatteredFatesBlueprintLibrary.OuterSingleton, Z_Construct_UClass_UShatteredFatesBlueprintLibrary_Statics::ClassParams);
	}
	return Z_Registration_Info_UClass_UShatteredFatesBlueprintLibrary.OuterSingleton;
}
UShatteredFatesBlueprintLibrary::UShatteredFatesBlueprintLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {}
DEFINE_VTABLE_PTR_HELPER_CTOR_NS(, UShatteredFatesBlueprintLibrary);
UShatteredFatesBlueprintLibrary::~UShatteredFatesBlueprintLibrary() {}
// ********** End Class UShatteredFatesBlueprintLibrary ********************************************

// ********** Begin Registration *******************************************************************
struct Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesProject_Public_ShatteredFatesBlueprintLibrary_h__Script_ShatteredFatesProject_Statics
{
	static constexpr FClassRegisterCompiledInInfo ClassInfo[] = {
		{ Z_Construct_UClass_UShatteredFatesBlueprintLibrary, UShatteredFatesBlueprintLibrary::StaticClass, TEXT("UShatteredFatesBlueprintLibrary"), &Z_Registration_Info_UClass_UShatteredFatesBlueprintLibrary, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(UShatteredFatesBlueprintLibrary), 3752903743U) },
	};
}; // Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesProject_Public_ShatteredFatesBlueprintLibrary_h__Script_ShatteredFatesProject_Statics 
static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesProject_Public_ShatteredFatesBlueprintLibrary_h__Script_ShatteredFatesProject_2167695642{
	TEXT("/Script/ShatteredFatesProject"),
	Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesProject_Public_ShatteredFatesBlueprintLibrary_h__Script_ShatteredFatesProject_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_liama_OneDrive_Documents_Shattered_Fates_UnrealProject_Source_ShatteredFatesProject_Public_ShatteredFatesBlueprintLibrary_h__Script_ShatteredFatesProject_Statics::ClassInfo),
	nullptr, 0,
	nullptr, 0,
};
// ********** End Registration *********************************************************************

PRAGMA_ENABLE_DEPRECATION_WARNINGS
