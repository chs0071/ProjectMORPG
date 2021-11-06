// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PMSingleton.generated.h"

#define DECLARE_MANAGER(NAME) \
	public:\
	static TSharedPtr<FPM##NAME##Manager> Get##NAME##Manager() { return Get()->NAME##Manager; } \
	private: TSharedPtr<FPM##NAME##Manager> NAME##Manager = nullptr;

class FPMUnrealNetworkManager;
class FPMAssetManager;

UCLASS()
class MMORPG_API UPMSingleton : public UObject
{
	GENERATED_BODY()

public:
	
	static void Initialize();
	static void Release();
	static void Play(const UWorld* InWorld);
	
private:
	static UPMSingleton* Get()
	{
		return Cast<UPMSingleton>(GEngine->GameSingleton);
	}
	void InitializeInternal();
	void ReleaseInternal();

	DECLARE_MANAGER(UnrealNetwork);
	DECLARE_MANAGER(Asset);
};
