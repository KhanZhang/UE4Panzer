// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Panzer.h"
#include <vector>
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PanzerPlayerController.generated.h"

/**
 * 
 */


//class Observer;

UCLASS()
class UE4PANZER_API APanzerPlayerController : public APlayerController
{
	GENERATED_BODY()
public: 
    virtual void Tick(float Deltatime) override;

    APanzer* GetControlledPanzer() const;

    virtual void BeginPlay() override;

    void AimTowardsCrosshair();

    bool GetSightRayHitLocation(FVector& OutLocation) const;

    UPROPERTY(EditAnywhere)
        float CrosshairXLocation = 0.5;

    UPROPERTY(EditAnywhere)
        float CrosshairYLocation = 0.3333;
    UPROPERTY(EditAnywhere)
        float LineTraceRange = 1000000;

    bool GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const;

    bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
    /*
public:
    std::vector<Observer*> PotentialObservers;*/
};
