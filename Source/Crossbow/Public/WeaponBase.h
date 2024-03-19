// FPS_Crossbow

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponBase.generated.h"


UCLASS(Abstract)
class CROSSBOW_API AWeaponBase : public AActor
{
	GENERATED_BODY()
public:
	AWeaponBase();
protected:
	virtual void Fire();
};
