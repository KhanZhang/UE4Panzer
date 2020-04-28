// Fill out your copyright notice in the Description page of Project Settings.

#include "MagicBox.h"

// Sets default values
AMagicBox::AMagicBox()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//GetWorld()->GetFirstPlayerController()->PotentialObservers.push_back(this);
	
}

void AMagicBox::Notified(Subject* Notifier)
{
	UE_LOG(LogTemp, Warning, TEXT("notified"));
}

// Called when the game starts or when spawned
void AMagicBox::BeginPlay()
{
	Super::BeginPlay();
	//Cast<>(GetWorld()->GetAuthGameMode());
	Cast<UPGI>(GetGameInstance())->POlist.push_back(this);
}

// Called every frame
void AMagicBox::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
