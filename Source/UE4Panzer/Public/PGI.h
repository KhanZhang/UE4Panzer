// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <vector>
#include "Engine/GameInstance.h"
#include "PGI.generated.h"

/**
 * 
 */

class Observer;

UCLASS()
class UE4PANZER_API UPGI : public UGameInstance
{
	GENERATED_BODY()


public:
	std::vector<Observer*> POlist;
};
