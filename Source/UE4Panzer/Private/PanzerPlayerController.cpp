// Fill out your copyright notice in the Description page of Project Settings.

#include "UE4Panzer/UE4Panzer.h"
#include "PanzerPlayerController.h"
#include "Components/InputComponent.h"

void APanzerPlayerController::Tick(float Deltatime)
{
	Super::Tick(Deltatime);
	if(Aiming) AimTowardsCrosshair();
}


APanzer* APanzerPlayerController::GetControlledPanzer() const {
	return Cast<APanzer>(GetPawn());
}

void APanzerPlayerController::SetAiming()
{
	if (Aiming) {
		Aiming = false;
	}
	else {
		Aiming = true;
	}
}

void APanzerPlayerController::BeginPlay() {
	Super::BeginPlay();
	//InputComponent = FindComponentByClass<UInputComponent>();

	InputComponent->BindAction("Aim", IE_Pressed, this, &APanzerPlayerController::SetAiming);

	auto Controlledpanzer = GetControlledPanzer();
	if (!Controlledpanzer) {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possessing a tank"));
	} else {
		UE_LOG(LogTemp, Warning, TEXT("PlayerController possessing: %s"), *Controlledpanzer->GetName());
	}
}


void APanzerPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledPanzer()) return;
	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation)) 
	{
		//UE_LOG(LogTemp, Warning, TEXT("Hit location: %s"), *HitLocation.ToString());
		GetControlledPanzer()->AimAt(HitLocation);
	}
}

bool APanzerPlayerController::GetSightRayHitLocation(FVector& OutLocation) const
{
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewportSizeX * CrosshairXLocation, ViewportSizeY * CrosshairYLocation);
	
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		return GetLookVectorHitLocation(LookDirection, OutLocation);
	}
	else 
	{
		return false;
	}
}

bool APanzerPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const
{
	FHitResult HitResult;
	auto StartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = StartLocation + (LookDirection * LineTraceRange);
	if (GetWorld()->LineTraceSingleByChannel(
			HitResult,
			StartLocation,
			EndLocation,
			ECollisionChannel::ECC_Visibility)
		)
	{
		HitLocation = HitResult.Location;
		return true;
	}
	return false;
}

bool APanzerPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation;
	DeprojectScreenPositionToWorld(
		ScreenLocation.X, 
		ScreenLocation.Y, 
		CameraWorldLocation, 
		LookDirection
	);
	return true;
}
