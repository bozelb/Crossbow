// FPS_Crossbow


#include "Character/PlayerCharacter.h"
#include "Camera/CameraComponent.h"
#include "Weapons/WeaponBase.h"

APlayerCharacter::APlayerCharacter()
{
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(RootComponent);
		
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	SpawnDefaultWeapon();
}

void APlayerCharacter::SpawnDefaultWeapon()
{
	if (!DefaultWeapon) return;
	AWeaponBase* SpawnedWeapon = GetWorld()->SpawnActor<AWeaponBase>(DefaultWeapon);
	SpawnedWeapon->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
	CurrentWeapon = SpawnedWeapon;
}

void APlayerCharacter::FireWeapon()
{
	if (!CurrentWeapon) return;
	CurrentWeapon->Fire();
}
