#include "PathfindingLibrary.h"
#include "NavigationSystem.h"
#include "NavigationPath.h"

bool UPathfindingLibrary::FindPathOnNavMesh(UObject* WorldContextObject, const FVector& Start, const FVector& End, TArray<FVector>& OutPath)
{
    UWorld* World = GEngine ? GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull) : nullptr;
    if (!World) { return false; }
    UNavigationSystemV1* NavSys = FNavigationSystem::GetCurrent<UNavigationSystemV1>(World);
    if (!NavSys) { return false; }
    UNavigationPath* NavPath = NavSys->FindPathToLocationSynchronously(World, Start, End);
    if (!NavPath || NavPath->PathPoints.Num() == 0) { return false; }
    OutPath = NavPath->PathPoints;
    return true;
}
