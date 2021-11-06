// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS(Blueprintable)
class MMORPG_API AMyActor : public AActor
{
	GENERATED_BODY()

public:
	/** Constructor for AActor that takes an ObjectInitializer for backward compatibility */
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	AActor* CreateCloneOfMyActor(AActor* ExistingActor, FVector SpawnLocation, FRotator SpawnRotation);
	void SetActive(bool InOn);
	
private:
	UPROPERTY()
	int32 MyIntProp;

	UPROPERTY()
	USphereComponent* MyCollisionComp;
};
