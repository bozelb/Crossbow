// FPS_Crossbow

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpellBase.generated.h"

UCLASS(Abstract)
class CROSSBOW_API ASpellBase : public AActor
{
	GENERATED_BODY()
public:
	ASpellBase();
protected:
	 virtual void Cast();
};
