// FPS_Crossbow


#include "Player/CrossbowController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputMappingContext.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Crossbow/Crossbow.h"
#include "Kismet/GameplayStatics.h"
#include "Character/PlayerCharacter.h"

ACrossbowController::ACrossbowController()
{
	// Settig var values,
	bReplicates = true;	
	DashValue = 10.f;
	bCanDash = true;
	
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
	//float value = GetCharacter()->GetCharacterMovement()->FallingLateralFriction;
	// Getting ref to playerCharacter.
	 PlayerCharacter = Cast<APlayerCharacter>(GetCharacter());
	//FString Message{ "%f", value };
	//WRITE_MESSAGE_TO_SCREEN(Messeage);
}

void ACrossbowController::SetupInputComponent()
{
	Super::SetupInputComponent();
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	// Setting bindings,
	// Move,
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &ACrossbowController::Move);
	// Dash,
	EnhancedInputComponent->BindAction(DashAction, ETriggerEvent::Started, this, &ACrossbowController::Dash);
	EnhancedInputComponent->BindAction(DashAction, ETriggerEvent::Completed, this, &ACrossbowController::DashOver);
	// Mouse input,
	EnhancedInputComponent->BindAction(LookAtAction, ETriggerEvent::Triggered, this, &ACrossbowController::LookAt);
	// Jumping,Jumping values are set in BP,
	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Started, this, &ACrossbowController::Jump);
	EnhancedInputComponent->BindAction(JumpAction, ETriggerEvent::Completed, this, &ACrossbowController::StopJumping);
	// Weapon / Spell casting,
	EnhancedInputComponent->BindAction(FireWeaponAction, ETriggerEvent::Triggered, this, &ACrossbowController::FireWeapon);
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
	if (!bCanDash) return;
	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		// Getting Char movement comp,
		UCharacterMovementComponent* CharMovementComp = GetCharacter()->GetCharacterMovement();
		// Getting current velocity,
		FVector LaunchVector{ CharMovementComp->Velocity.X, CharMovementComp->Velocity.Y, 0.f };
		//WRITE_MESSAGE_TO_SCREEN("Velocity : " + MovementComp->Velocity.ToString());
		// Multiplying current velocity by dash scaler values,
		LaunchVector *= DashValue;


		//FVector ForwardFacingVector = ControlledPawn->GetActorForwardVector();
		CharMovementComp->FallingLateralFriction = 50.f;
		// Adding it to char movement via launchChar method,
		GetCharacter()->LaunchCharacter(LaunchVector, true, true);
		
		//WRITE_MESSAGE_TO_SCREEN("Friction :" + friction);
		bCanDash = false;
	}
}

void ACrossbowController::DashOver()
{
	// Getting Char movement comp,
	UCharacterMovementComponent* CharMovementComp = GetCharacter()->GetCharacterMovement();
	CharMovementComp->FallingLateralFriction = 0.f;
	bCanDash = true;
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

void ACrossbowController::FireWeapon()
{
	if (PlayerCharacter != nullptr)
	{
		PlayerCharacter->FireWeapon();
	}
}

