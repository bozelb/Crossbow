// FPS_Crossbow

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CrossbowController.generated.h"

// Forward declarations,
class UInputMappingContext;
class UInputAction;
class APlayerCharacter;
/**
 * 
 */
UCLASS()
class CROSSBOW_API ACrossbowController : public APlayerController
{
	GENERATED_BODY()

public:
	ACrossbowController();
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	
private: // Functions.
	void Move(const struct FInputActionValue& InputActionValue);
	void Dash(const struct FInputActionValue& InputActionValue);
	void DashOver();
	void Jump();
	void StopJumping();
	void LookAt(const struct FInputActionValue& InputActionValue);
	void FireWeapon();

private: // Vars,
	UPROPERTY(EditAnywhere, Category = "Input")
		TObjectPtr<UInputMappingContext> BaseControlsContext;
	
	UPROPERTY(EditAnywhere, Category = "Input")
		TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, Category = "Input")
		TObjectPtr<UInputAction> JumpAction;

	UPROPERTY(EditAnywhere, Category = "Input")
		TObjectPtr<UInputAction> LookAtAction;

	UPROPERTY(EditAnywhere, Category = "Input")
		TObjectPtr<UInputAction> DashAction;

	UPROPERTY(EditAnywhere, Category = "Input")
		TObjectPtr<UInputAction> FireWeaponAction;

	// Dash properties,
	UPROPERTY(EditAnywhere, Category = "Movement Values")
		float DashValue;

	bool bCanDash;

	// Reference to player character,
	TObjectPtr<APlayerCharacter> PlayerCharacter;
};
