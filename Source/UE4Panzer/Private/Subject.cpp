// Fill out your copyright notice in the Description page of Project Settings.

#include "Subject.h"
#include "Observer.h"

void Subject::NotifyObservers()
{
}

void Subject::AddToList(Observer* NewObserver)
{
	ObserverList.push_back(NewObserver);
}

Subject::Subject()
{
}

Subject::~Subject()
{
}
