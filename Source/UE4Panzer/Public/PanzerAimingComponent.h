// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/GameplayStatics.h"
#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PanzerAimingComponent.generated.h"

class UPanzerBarrel;
class UTurrent;

UENUM()
enum class EFiringState : uint8
{
	OutOfAmmo
};


UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class UE4PANZER_API UPanzerAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	// Sets default values for this component's properties
	UPanzerAimingComponent();

	void MoveBarrelTowards(FVector AimDirection);

	void MoveTurrentTowards(FVector AimDirection);

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	void SetBarrelReference(UPanzerBarrel* BarrelToSet);
	void SetTurrentReference(UTurrent* TurrentToSet);
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void AimAt(FVector HitLocation, float LaunchSpeed);
	
	UFUNCTION(BlueprintCallable, Category = "Firing")
	int GetRoundsleft() const;
private:
	UPanzerBarrel* Barrel = nullptr;
	UTurrent* Turrent = nullptr;


	int Roundsleft = 3;
};