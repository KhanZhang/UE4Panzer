// Fill out your copyright notice in the Description page of Project Settings.

#include "PanzerBarrel.h"
#include "Projectile.h"
#include "Turrent.h"
#include "PanzerTrack.h"
#include "Panzer.h"

// Sets default values
APanzer::APanzer()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	PanzerAimingComponent = CreateDefaultSubobject<UPanzerAimingComponent>(FName("Aiming Component"));

}

// Called when the game starts or when spawned
void APanzer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
/*void APanzer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}*/

// Called to bind functionality to input
void APanzer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void APanzer::AimAt(FVector HitLocation)
{
	//UE_LOG(LogTemp, Warning, TEXT("ss"))
	PanzerAimingComponent->AimAt(HitLocation, LaunchSpeed);
}

void APanzer::SetBarrelReference(UPanzerBarrel* BarrelToSet)
{
	Barrel = BarrelToSet;
	PanzerAimingComponent->SetBarrelReference(BarrelToSet);
}


void APanzer::SetTurrentReference(UTurrent* TurrentToSet)
{
	Turrent = TurrentToSet;
	PanzerAimingComponent->SetTurrentReference(TurrentToSet);
}
/*
void APanzer::SetRTrackReference(UPanzerTrack* TrackToSet)
{
	RTrack = TrackToSet;
}
void APanzer::SetLTrackReference(UPanzerTrack* TrackToSet)
{
	LTrack = TrackToSet;
}*/

void APanzer::Fire()
{
	bool isReloaded = (FPlatformTime::Seconds() - LastFiretime) > ReloadTime;

	if (Barrel && isReloaded)
	{
		LastFiretime = FPlatformTime::Seconds();
		if (fireball)
		{
			auto Projectile = GetWorld()->SpawnActor<AProjectile>(
				ProjectileBlueprint,
				Barrel->GetSocketLocation(FName("Projectile")),
				Barrel->GetSocketRotation(FName("Projectile"))
			);
			FVector Direction = GetBarrelDirection();
			Projectile->LaunchProjectile(Direction);
		}/*
		else {
			auto Ballshell = GetWorld()->SpawnActor<ABallShell>(
				BallShellBlueprint,
				Barrel->GetSocketLocation(FName("Projectile")),
				Barrel->GetSocketRotation(FName("Projectile"))
			);
			Ballshell->LaunchProjectile(LaunchSpeed);
		}*/
		

	}
}
/*
void APanzer::SetRealMoving(bool Real)
{
	if (LTrack) {
		LTrack->SetRealMoving(Real);
	}
	if (RTrack) {
		RTrack->SetRealMoving(Real);
	}
}*/

FVector APanzer::GetBarrelDirection() const
{
	return Barrel->GetSocketLocation(FName("Projectile")) - 
		Turrent->GetSocketLocation(FName("barrel"));
}


