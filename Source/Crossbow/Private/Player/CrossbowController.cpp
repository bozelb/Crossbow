// FPS_Crossbow


#include "Player/CrossbowController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputMappingContext.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Crossbow/Crossbow.h"
#include "Kismet/GameplayStatics.h"

ACrossbowController::ACrossbowController()
{
	bReplicates = true;	
	DashDistance = 5000.f;
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
	// Dash,
	EnhancedInputComponent->BindAction(DashAction, ETriggerEvent::Triggered, this, &ACrossbowController::Dash);
	// Mouse input,
	EnhancedInputComponent->BindAction(LookAtAction, ETriggerEvent::Triggered, this, &ACrossbowController::LookAt);
	// Jumping,Jumping values are set in BP,
	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACrossbowController::Jump);
	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACrossbowController::StopJumping);
}

void ACrossbowController::Move(const FInputActionValue& InputActionValue)
{

	// Getting the input from the player and storing it into a FVector,
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		// Adding input to the controlled pawn,
		ControlledPawn->AddMovementInput(ControlledPawn->GetActorForwardVector(), InputAxisVector.Y);
		ControlledPawn->AddMovementInput(ControlledPawn->GetActorRightVector(), InputAxisVector.X);
	}

}

void ACrossbowController::Dash(const FInputActionValue& InputActionValue)
{
	// Getting the input from the player and storing it into a FVector,
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		// Getting 	
		UMovementComponent* MovementComp = GetCharacter()->GetCharacterMovement();
		// Adding dash distance to forward facing vector,
		//ControlledPawn->AddMovementInput(ControlledPawn->GetActorForwardVector(), DashDistance);	
		//ControlledPawn->AddMovementInput(MovementComp->Velocity, DashDistance);
		FVector LaunchVector = MovementComp->Velocity;
		LaunchVector *= 5.f;
		GetCharacter()->LaunchCharacter(LaunchVector, false, false);
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

void ACrossbowController::LookAt(const FInputActionValue& InputActionValue)
{
	// Getting input values and storing them,
	 FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		// Adding values to the controller,
		ControlledPawn->AddControllerYawInput(InputAxisVector.X);
		ControlledPawn->AddControllerPitchInput(InputAxisVector.Y);		
	}
}

