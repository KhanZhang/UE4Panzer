// Fill out your copyright notice in the Description page of Project Settings.


#include "PanzerTrack.h"
void UPanzerTrack::SetThrottle(float Throttle)
{
	bool SameDirection = GetOwner()->GetVelocity().Y * Throttle < 0;
	FVector v = GetOwner()->GetVelocity();
	UE_LOG(LogTemp, Warning, TEXT("%s"), *v.ToString());
	if (v.Size() >= 800 && SameDirection) return;
	auto ForceApplied = GetForwardVector() * Throttle * TrackMaxDrivingForce;
	auto ForceLocation = GetComponentLocation();
	auto PanzerRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	//if (!SameDirection) PanzerRoot->AddForceAtLocation(- v * 42000, ForceLocation);
	PanzerRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}
/*
void UPanzerTrack::SetRealMoving(bool Real)
{
	RealMoving = Real;
}*/
