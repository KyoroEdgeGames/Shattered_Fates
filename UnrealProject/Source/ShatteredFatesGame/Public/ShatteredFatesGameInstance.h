#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "ShatteredFatesGameInstance.generated.h"

class UCharacterSubsystem;

UCLASS()
class SHATTEREDFATESGAME_API UShatteredFatesGameInstance : public UGameInstance
{
    GENERATED_BODY()
public:
    virtual void Init() override;

private:
    bool LoadCharactersAtStartup();
    FString GetCharactersJsonAbsolutePath() const;
};
