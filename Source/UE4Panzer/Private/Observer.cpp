// Fill out your copyright notice in the Description page of Project Settings.


#include "Observer.h"
#include "Subject.h"

Observer::Observer()
{
}

Observer::~Observer()
{
}

void Observer::Notified(Subject* Notifier)
{
	UE_LOG(LogTemp, Warning, TEXT("Observer notified"));
	return;
}

