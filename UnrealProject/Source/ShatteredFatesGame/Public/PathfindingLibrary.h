#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PathfindingLibrary.generated.h"

UCLASS()
class SHATTEREDFATESGAME_API UPathfindingLibrary : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()
public:
    UFUNCTION(BlueprintCallable, Category="ShatteredFates|Pathfinding")
    static bool FindPathOnNavMesh(UObject* WorldContextObject, const FVector& Start, const FVector& End, TArray<FVector>& OutPath);
};
