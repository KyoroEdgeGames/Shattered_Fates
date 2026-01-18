#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "ShatteredFatesHUD.generated.h"

UCLASS()
class SHATTEREDFATESGAME_API AShatteredFatesHUD : public AHUD
{
    GENERATED_BODY()
public:
    virtual void DrawHUD() override;
};
