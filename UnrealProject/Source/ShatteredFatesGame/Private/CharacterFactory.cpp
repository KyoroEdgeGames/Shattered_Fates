#include "CharacterFactory.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"

AActor* UCharacterFactory::SpawnCharacter(UObject* WorldContextObject, TSubclassOf<AActor> CharacterClass, const FVector& Location)
{
    UWorld* World = GEngine ? GEngine->GetWorldFromContextObject(WorldContextObject, EGetWorldErrorMode::ReturnNull) : nullptr;
    if (!World || !*CharacterClass) { return nullptr; }
    FActorSpawnParameters Params;
    return World->SpawnActor<AActor>(CharacterClass, Location, FRotator::ZeroRotator, Params);
}
