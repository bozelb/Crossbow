// FPS_Crossbow

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

// Forward dec
class UStaticMeshComponent;
class UBoxComponent;
class UProjectileMovementComponent;


UCLASS()
class CROSSBOW_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	AProjectile();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

	// Collision Methods,
	virtual void OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	virtual void OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

private:

	// Collider for collision detections,
	UPROPERTY(EditAnywhere, Category = "Mesh")
		TObjectPtr<UBoxComponent> BoxCollider;

	// Mesh for arrows,
	UPROPERTY(EditAnywhere, Category = "Mesh")
		TObjectPtr<UStaticMeshComponent> ProjectileMesh;

	// Movement Comp for projectile movement,
	UPROPERTY(VisibleAnywhere, Category = "Movement")
		TObjectPtr<UProjectileMovementComponent> ProjectileMoveComponent;

	// float values,
	UPROPERTY(EditAnywhere, Category = "Projectile Values")
		float Speed;
	UPROPERTY(EditAnywhere, Category = "Projectile Values")
		float LifeTime;
};
