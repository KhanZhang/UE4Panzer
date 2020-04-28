// Fill out your copyright notice in the Description page of Project Settings.


#include "PanzerTrack.h"
void UPanzerTrack::SetThrottle(float Throttle)
{
	//UE_LOG(LogTemp, Warning, TEXT("%f"), Throttle);

	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto PanzerRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	PanzerRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}
