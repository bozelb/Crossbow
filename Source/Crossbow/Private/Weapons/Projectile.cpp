// FPS_Crossbow


#include "Weapons/Projectile.h"
#include "Components/StaticMeshComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"

// Sets default values
AProjectile::AProjectile()
{
	PrimaryActorTick.bCanEverTick = true;

	// Creating Default objs,
	ProjectileMesh = CreateDefaultSubobject<UStaticMeshComponent>("Projectile Mesh");
	RootComponent = ProjectileMesh;
	BoxCollider = CreateDefaultSubobject<UBoxComponent>("BoxCollider");
	BoxCollider->SetupAttachment(RootComponent);
	ProjectileMoveComponent = CreateDefaultSubobject<UProjectileMovementComponent>("Projectile Movement Component");
	// Default values, will be update in BP
	Speed = 800.f;
	LifeTime = 10.f;

}

void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	
	// Adding a callback for overlap,
	BoxCollider->OnComponentBeginOverlap.AddDynamic(this, &AProjectile::OnOverlapBegin);
	BoxCollider->OnComponentEndOverlap.AddDynamic(this, &AProjectile::OnOverlapEnd);

	if (ProjectileMoveComponent)
	{
		ProjectileMoveComponent->InitialSpeed = Speed;
	}
}

void AProjectile::OnOverlapBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	//Destroy();
}

void AProjectile::OnOverlapEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{

}

void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

