// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <vector>
#include "CoreMinimal.h"

class Observer;
/**
 * 
 */
class UE4PANZER_API Subject
{
private:
	virtual void NotifyObservers();
	void AddToList(Observer* NewObserver);
protected:
	std::vector<Observer*> ObserverList;
public:
	int ID = 0;
	Subject();
	virtual ~Subject();
};
