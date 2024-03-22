// FPS_Crossbow

#pragma once

#include "CoreMinimal.h"
#include "BaseCharacter.h"
#include "PlayerCharacter.generated.h"

class UCameraComponent;
class AWeaponBase;
/**
 * 
 */
UCLASS()
class CROSSBOW_API APlayerCharacter : public ABaseCharacter
{
	GENERATED_BODY()

public:

	APlayerCharacter();
	void FireWeapon();

protected:

	virtual void BeginPlay() override;
	void SpawnDefaultWeapon();

private: // Vars,

	UPROPERTY(EditAnywhere, Category = "Camera")
		TObjectPtr<UCameraComponent> Camera;

	UPROPERTY(VisibleAnywhere, Category = "Weapon", meta = (AllowPrivateAccess = "true"))
		TObjectPtr<AWeaponBase> CurrentWeapon;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Weapon", meta = (AllowPrivateAccess = "true"))
		TSubclassOf<AWeaponBase> DefaultWeapon;
};
