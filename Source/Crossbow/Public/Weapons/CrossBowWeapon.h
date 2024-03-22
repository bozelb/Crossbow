// FPS_Crossbow

#pragma once

#include "CoreMinimal.h"
#include "Weapons/WeaponBase.h"
#include "CrossbowWeapon.generated.h"

/**
 * 
 */
UCLASS()
class CROSSBOW_API ACrossbowWeapon : public AWeaponBase
{
	GENERATED_BODY()
public:
	virtual void Fire() override;
};
