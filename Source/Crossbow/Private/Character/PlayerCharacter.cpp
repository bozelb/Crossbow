// FPS_Crossbow


#include "Character/PlayerCharacter.h"
#include "Camera/CameraComponent.h"

APlayerCharacter::APlayerCharacter()
{
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	Camera->SetupAttachment(RootComponent);
}

void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
}
