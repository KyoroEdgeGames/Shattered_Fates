#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "CharacterData.h"
#include "QuestData.h"
#include "ClanData.h"
#include "ItemData.h"
#include "HerbData.h"
#include "Engine/DataTable.h"
#include "DataTableRows.h"
#include "ShatteredFatesBlueprintLibrary.generated.h"

UCLASS()
class SHATTEREDFATES_API UShatteredFatesBlueprintLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, Category="ShatteredFates|Import")
    static UCharacterDataAsset* LoadCharactersFromJsonFile(const FString& AbsolutePath);

    UFUNCTION(BlueprintCallable, Category="ShatteredFates|Import")
    static UQuestDataAsset* LoadQuestsFromJsonFile(const FString& AbsolutePath);

    UFUNCTION(BlueprintCallable, Category="ShatteredFates|Import")
    static UClanDataAsset* LoadClansFromJsonFile(const FString& AbsolutePath);

    UFUNCTION(BlueprintCallable, Category="ShatteredFates|Import")
    static UItemDataAsset* LoadItemsFromJsonFile(const FString& AbsolutePath);

    UFUNCTION(BlueprintCallable, Category="ShatteredFates|Import")
    static UHerbDataAsset* LoadHerbsFromJsonFile(const FString& AbsolutePath);

    // Runtime CSV → DataTable loaders using predefined row structs
    UFUNCTION(BlueprintCallable, Category="ShatteredFates|Import")
    static UDataTable* LoadCharactersDataTableFromCsvFile(const FString& AbsolutePath);

    UFUNCTION(BlueprintCallable, Category="ShatteredFates|Import")
    static UDataTable* LoadQuestsDataTableFromCsvFile(const FString& AbsolutePath);

    UFUNCTION(BlueprintCallable, Category="ShatteredFates|Import")
    static UDataTable* LoadClansDataTableFromCsvFile(const FString& AbsolutePath);

    UFUNCTION(BlueprintCallable, Category="ShatteredFates|Import")
    static UDataTable* LoadItemsDataTableFromCsvFile(const FString& AbsolutePath);

    UFUNCTION(BlueprintCallable, Category="ShatteredFates|Import")
    static UDataTable* LoadHerbsDataTableFromCsvFile(const FString& AbsolutePath);

    UFUNCTION(BlueprintCallable, Category="ShatteredFates|Import")
    static UDataTable* LoadSkillsDataTableFromCsvFile(const FString& AbsolutePath);
};
