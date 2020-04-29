// Fill out your copyright notice in the Description page of Project Settings.

#include "Components/SphereComponent.h"
#include "Observer.h"
#include "Projectile.h"
#include "PGI.h"
#include "Components/PrimitiveComponent.h"
#include "GameFramework/Actor.h"
#include "math.h"

//make direction vector
void AProjectile::Unify(FVector& v)
{
	float length = sqrt(v.X * v.X + v.Y * v.Y + v.Z * v.Z);
	v.X /= length;
	v.Y /= length;
	v.Z /= length;
}

AProjectile::AProjectile()
{
	InitialLifeSpan = 555.0f;
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	CollisionMesh = CreateDefaultSubobject<UStaticMeshComponent>(FName("Collision Mesh"));
	SetRootComponent(CollisionMesh);
	CollisionMesh->SetNotifyRigidBodyCollision(true);
	CollisionMesh->SetVisibility(true);

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(FName("Projectile Movement"));
	ProjectileMovement->bAutoActivate = false;


}

void AProjectile::NotifyObservers()
{
	for (auto& member : Cast<UPGI>(GetGameInstance())->POlist) {
		//UE_LOG(LogTemp, Warning, TEXT("olist not empty"));
		member->Notified(this);
	}
}

// Called when the game starts or when spawned
/*void PostInitializeComponents()
{
	//CollisionMesh->OnComponentHit.AddDynamic(this, &AProjectile::OnHit);

}*/

void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	CollisionMesh->OnComponentHit.AddDynamic(this, &AProjectile::OnHit);
	//UE_LOG(LogTemp, Warning, TEXT("hit"));
}

void AProjectile::LaunchProjectile(float Speed, FVector Direction)
{
	//ProjectileMovement->SetVelocityInLocalSpace(FVector::ForwardVector * Speed);
	//ProjectileMovement->Activate();
	Unify(Direction);
	UE_LOG(LogTemp, Warning, TEXT("initial %s"), *Direction.ToString());
	CollisionMesh->AddImpulse(Direction * LaunchSpeed);
	//CollisionMesh->SetPhysicsLinearVelocity(FVector(50.f, 0, 0));
}

void AProjectile::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor != this && OtherComponent->IsSimulatingPhysics())
	{
		//ProjectileMovement->SetVelocityInLocalSpace(NormalImpulse - FVector::ForwardVector * LaunchSpeed);

		//ProjectileMovement->Activate();
		UE_LOG(LogTemp, Warning, TEXT("normal %s, forward %s"), *NormalImpulse.ToString(), *FVector::ForwardVector.ToString());
		//NotifyObservers();
	}
	
}


