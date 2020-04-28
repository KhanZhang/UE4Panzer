// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Panzer.h"
#include "CoreMinimal.h"
#include "AIController.h"
#include "PanzerAIController.generated.h"

/**
 * 
 */
UCLASS()
class UE4PANZER_API APanzerAIController : public AAIController
{
	GENERATED_BODY()
    virtual void Tick(float Deltatime) override;
    //APanzer* GetControlledPanzer() const;
    //APanzer* GetPlayerPanzer() const;
    void AimTowardsCrosshair();
};
