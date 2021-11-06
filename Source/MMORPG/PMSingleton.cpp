// Fill out your copyright notice in the Description page of Project Settings.
#include "PMSingleton.h"
#include "PMAssetManager.h"
#include "PMLevelTable.h"
#include "PMUnrealNetworkManager.h"
#include "Kismet/GameplayStatics.h"

#define INITIALIZE_MANAGER(NAME) \
	NAME##Manager = MakeShareable(new FPM##NAME##Manager()); \
	NAME##Manager->Initialize();

void UPMSingleton::Initialize()
{
	Get()->InitializeInternal();
}

void UPMSingleton::Release()
{
	Get()->ReleaseInternal();
}

void UPMSingleton::Play(const UWorld* InWorld)
{
	FString LocalLevelPath = GetAssetManager()->LoadLevel(ELevelName::Field);
	UGameplayStatics::OpenLevel(InWorld, *LocalLevelPath);
}

void UPMSingleton::InitializeInternal()
{
	INITIALIZE_MANAGER(UnrealNetwork);
	INITIALIZE_MANAGER(Asset);
}

void UPMSingleton::ReleaseInternal()
{
	UnrealNetworkManager.Reset();
}
