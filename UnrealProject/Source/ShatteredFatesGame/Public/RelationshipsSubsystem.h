#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstanceSubsystem.h"
#include "RelationshipsSubsystem.generated.h"

UCLASS()
class SHATTEREDFATESGAME_API URelationshipsSubsystem : public UGameInstanceSubsystem
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, Category="ShatteredFates|Relationships")
    void ResetRelationships();

    UFUNCTION(BlueprintCallable, Category="ShatteredFates|Relationships")
    float GetAffinity(const FName& A, const FName& B) const;

    UFUNCTION(BlueprintCallable, Category="ShatteredFates|Relationships")
    float ModifyAffinity(const FName& A, const FName& B, float Delta);

    UFUNCTION(BlueprintCallable, Category="ShatteredFates|Relationships")
    void SetAffinity(const FName& A, const FName& B, float Value);

    UFUNCTION(BlueprintCallable, Category="ShatteredFates|Relationships")
    TMap<FName, float> GetRelationsFor(const FName& A) const;

private:
    FString MakeKey(const FName& A, const FName& B) const;

    UPROPERTY()
    TMap<FString, float> Affinity; // normalized pair key -> [-100..100]
};
