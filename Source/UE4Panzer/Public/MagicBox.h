// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Observer.h"
#include <vector>
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PGI.h"
#include "MagicBox.generated.h"

UCLASS()
class UE4PANZER_API AMagicBox : public AActor, public Observer
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMagicBox();
	void Notified(Subject* Notifier) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//std::vector<Observer*> PotentialObservers;// = Cast<UPGI>(GetGameInstance())->POlist;
};

