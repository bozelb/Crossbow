// FPS_Crossbow


#include "Weapons/WeaponBase.h"
#include "Crossbow/Crossbow.h"
#include "Components/SkeletalMeshComponent.h"
#include "Weapons/Projectile.h"

AWeaponBase::AWeaponBase()
{
	// Creating Mesh,
	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh"));
	WeaponMesh->SetupAttachment(RootComponent);
	// Creating Projectile Spawn
	ProjectileSpawn = CreateDefaultSubobject<USceneComponent>(TEXT("Projetile Spawn"));
	ProjectileSpawn->SetupAttachment(WeaponMesh);
	// Ideally we have a spawn pt right on the weapon mesh for the time being no weapon mesh,
}

void AWeaponBase::Fire()
{
	//WRITE_MESSAGE_TO_SCREEN("Weapon Fired");
	FVector Location(10.f, 10.f, 10.f);
	FRotator Rotation( 0.f, 0.f, 0.f);
	FActorSpawnParameters SpawnParams;
	GetWorld()->SpawnActor<AProjectile>(Projectile, ProjectileSpawn->GetComponentLocation(), GetActorRotation(), SpawnParams);

}

void AWeaponBase::ReloadWeapon()
{
	WRITE_MESSAGE_TO_SCREEN("Reloaded Weapon");
}
