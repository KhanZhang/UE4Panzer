// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <vector>
#include "CoreMinimal.h"

class Subject;
/**
 * 
 */
class UE4PANZER_API Observer
{
public:
	Observer();
	~Observer();
	virtual void Notified(Subject* Notifier);
};

