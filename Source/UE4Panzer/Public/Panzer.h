// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "PanzerAimingComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Panzer.generated.h"

class AProjectile;
class UTurrent;

UCLASS()
class UE4PANZER_API APanzer : public APawn
{
	GENERATED_BODY()

private :
	// Sets default values for this pawn's properties
	APanzer();

	UPanzerBarrel* Barrel = nullptr;
	UTurrent* Turrent = nullptr;

	bool fireball = true;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPanzerAimingComponent* PanzerAimingComponent = nullptr;


public:	
	// Called every frame
	//virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void AimAt(FVector HitLocation);

	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetBarrelReference(UPanzerBarrel* BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetTurrentReference(UTurrent* TurrentToSet);

	UPROPERTY(EditAnywhere, Category = Firing)
		float LaunchSpeed = 10000;

	UFUNCTION(BlueprintCallable, Category = Firing)
		void Fire();

	UPROPERTY(EditAnywhere, Category = Setup)
		TSubclassOf<AProjectile> ProjectileBlueprint;
	/*UPROPERTY(EditAnywhere, Category = Setup)
		TSubclassOf<ABallShell> BallShellBlueprint;*/

	float ReloadTime = 3;

	float LastFiretime = 0;
};
