// FPS_Crossbow

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WeaponBase.generated.h"

// Forward Declarations,
class USkeletalMeshComponent;
class AProjectile;

UCLASS()
class CROSSBOW_API AWeaponBase : public AActor
{
	GENERATED_BODY()

public:
	AWeaponBase();
	virtual void Fire();	
	void ReloadWeapon();

protected:

private:
	UPROPERTY(EditAnywhere, Category = "Mesh")
		TObjectPtr<USkeletalMeshComponent> WeaponMesh;

	UPROPERTY(EditAnywhere, Category = "Projectile")
		TSubclassOf<AProjectile> Projectile;

	UPROPERTY(EditAnywhere, Category = "Transform")
		TObjectPtr<USceneComponent> ProjectileSpawn;
};
