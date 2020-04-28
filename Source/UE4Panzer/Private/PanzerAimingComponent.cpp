// Fill out your copyright notice in the Description page of Project Settings.


#include "PanzerAimingComponent.h"
#include "Turrent.h"
#include "PanzerBarrel.h"
 

// Sets default values for this component's properties
UPanzerAimingComponent::UPanzerAimingComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void UPanzerAimingComponent::MoveBarrelTowards(FVector AimDirection)
{
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();

	auto DeltaRotator = AimAsRotator - BarrelRotator;

	Barrel->Elevate(DeltaRotator.Pitch);
}

void UPanzerAimingComponent::MoveTurrentTowards(FVector AimDirection)
{
	if (!Turrent) return;
	//UE_LOG(LogTemp, Warning, TEXT("?"));
	
	auto TurrentRotator = Turrent->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();

	auto DeltaRotator = AimAsRotator - TurrentRotator;
	if (DeltaRotator.Yaw > 180)  DeltaRotator.Yaw -= 360;
	if (DeltaRotator.Yaw < -180)  DeltaRotator.Yaw += 360;
	//UE_LOG(LogTemp, Warning, TEXT("%f"), DeltaRotator.Yaw);
	Turrent->Rotate(DeltaRotator.Yaw);
}

int UPanzerAimingComponent::GetRoundsleft() const
{
	return Roundsleft;
}
// Called when the game starts
void UPanzerAimingComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


void UPanzerAimingComponent::SetBarrelReference(UPanzerBarrel* BarrelToSet)
{
	Barrel = BarrelToSet;
}

void UPanzerAimingComponent::SetTurrentReference(UTurrent* TurrentToSet)
{
	Turrent = TurrentToSet;
}

// Called every frame
void UPanzerAimingComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UPanzerAimingComponent::AimAt(FVector HitLocation, float LaunchSpeed)
{
	if (!Barrel) return;

	FVector OutLaunchVelocity(0);
	FVector StartLocation = Barrel->GetSocketLocation(FName("Projectile"));
	if (UGameplayStatics::SuggestProjectileVelocity
	(
		this,
		OutLaunchVelocity,
		StartLocation,
		HitLocation,
		LaunchSpeed,
		false,
		0, 0,
		ESuggestProjVelocityTraceOption::DoNotTrace
	)
		)
	{
		auto AimDirection = OutLaunchVelocity.GetSafeNormal();
		//auto TankName = GetOwner()->GetName();
		//UE_LOG(LogTemp, Warning, TEXT("%s Firing at %s"), *TankName, *AimDirection.ToString());
		MoveBarrelTowards(AimDirection);
		MoveTurrentTowards(AimDirection);
	}
}



