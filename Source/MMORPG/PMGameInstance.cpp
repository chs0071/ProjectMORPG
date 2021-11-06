// Fill out your copyright notice in the Description page of Project Settings.


#include "PMGameInstance.h"
#include "PMSingleton.h"

void UPMGameInstance::Init()
{
	UPMSingleton::Initialize();
}

void UPMGameInstance::Shutdown()
{
	UPMSingleton::Release();
}
