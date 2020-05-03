// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Observer.h"
#include "Subject.h"
#include <vector>
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PGI.h"
#include "MagicBox.generated.h"

UCLASS()
class UE4PANZER_API AMagicBox : public AActor, public Observer, public Subject
{
	GENERATED_BODY()
	

public:	
	// Sets default values for this actor's properties

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Setup)
		int Hpoint = 1;

	AMagicBox();
	virtual void Notified(Subject* Notifier) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = Setup)
	virtual void GetHit();
	//std::vector<Observer*> PotentialObservers;// = Cast<UPGI>(GetGameInstance())->POlist;
};

