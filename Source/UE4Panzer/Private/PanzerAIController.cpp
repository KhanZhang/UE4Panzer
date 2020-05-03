// Fill out your copyright notice in the Description page of Project Settings.

#include "PanzerAIController.h"
#include "UE4Panzer/UE4Panzer.h"

void APanzerAIController::Tick(float Deltatime)
{
	Super::Tick(Deltatime);
	auto PlayerPanzer = Cast<APanzer>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledPanzer = Cast<APanzer>(GetPawn());
	if (PlayerPanzer)
	{
		//Move and search

		//Aim
		ControlledPanzer->AimAt(PlayerPanzer->GetActorLocation());

		//Fire
		ControlledPanzer->Fire();
	}
}

