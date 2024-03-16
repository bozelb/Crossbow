// FPS_Crossbow


#include "Player/CrossbowController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputMappingContext.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"

ACrossbowController::ACrossbowController()
{
	bReplicates = true;	
}

void ACrossbowController::BeginPlay()
{
	Super::BeginPlay();
	// Checking to make sure the context is valid.
	check(BaseControlsContext);
	// Getting ref to PlayerSubsystem via local player,
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	// Adding mapping context to subsystem,
	check(Subsystem);
	Subsystem->AddMappingContext(BaseControlsContext, 0);
}

void ACrossbowController::SetupInputComponent()
{
	Super::SetupInputComponent();
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	// Setting bindings,
	// Move,
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ACrossbowController::Move);
	// Jumping,Jumping values are set in BP,
	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACrossbowController::Jump);
	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACrossbowController::StopJumping);
}

void ACrossbowController::Move(const FInputActionValue& InputActionValue)
{
	// Getting the input from the player and storing it into a FVector,
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	// Getting rotation of player,
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}

}

void ACrossbowController::Jump()
{
	GetCharacter()->Jump();
}

void ACrossbowController::StopJumping()
{
	GetCharacter()->StopJumping();
}

