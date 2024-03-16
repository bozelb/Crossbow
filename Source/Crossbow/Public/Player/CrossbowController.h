// FPS_Crossbow

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "CrossbowController.generated.h"

// Forward declarations,
class UInputMappingContext;
class UInputAction;
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
	void Jump();
	void StopJumping();
private: // Vars,
	UPROPERTY(EditAnywhere, Category = "Input")
		TObjectPtr<UInputMappingContext> BaseControlsContext;
	
	UPROPERTY(EditAnywhere, Category = "Input")
		TObjectPtr<UInputAction> MoveAction;

	UPROPERTY(EditAnywhere, Category = "Input")
		TObjectPtr<UInputAction> JumpAction;
};
