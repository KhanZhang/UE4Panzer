// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "PanzerTrack.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class UE4PANZER_API UPanzerTrack : public UStaticMeshComponent
{
	GENERATED_BODY()

private:
	bool RealMoving = true;
public:
	UFUNCTION(BlueprintCallable, Category = Input)
	void SetThrottle(float Throttle);

	UPROPERTY(EditDefaultsOnly)
	float TrackMaxDrivingForce = 37400000.0;

	//void SetRealMoving(bool Real = false);
};
