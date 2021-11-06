// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	// USceneComponent* LocalRootComponent = NewObject<USceneComponent>(this, USceneComponent::GetDefaultSceneRootVariableName(), RF_Transactional);
	// LocalRootComponent->Mobility = EComponentMobility::Movable;
	// //RootComponent->bVisualizeComponent = 1;
	// LocalRootComponent->SetWorldTransform(FTransform::Identity);
	//
	// SetRootComponent(LocalRootComponent);
	// AddInstanceComponent(LocalRootComponent);

	//LocalRootComponent->RegisterComponent();
	
	MyIntProp = 42;

	MyCollisionComp = CreateDefaultSubobject<USphereComponent>(FName(TEXT("CollisionComponent")));
	MyCollisionComp->SetRelativeLocation(FVector::ZeroVector);
	MyCollisionComp->SetSphereRadius(20.0f);

	
}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	USphereComponent* SphereCollider = FindComponentByClass<USphereComponent>();
	// UActorComponent* PrimitiveComponent = GetComponentByClass(UPrimitiveComponent::StaticClass());
	// USphereComponent* SphereCollider = Cast<USphereComponent>(PrimitiveComponent);
	if (SphereCollider != nullptr)
	{
		SphereCollider->SetSphereRadius(60.0f);
		UE_LOG(LogTemp, Log, TEXT("SphereCollider is not null"));
	}
	
	UE_LOG(LogTemp, Log, TEXT("AMyActor::BeginPlay"));
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

AActor* AMyActor::CreateCloneOfMyActor(AActor* ExistingActor, FVector SpawnLocation, FRotator SpawnRotation)
{
	UWorld* World = ExistingActor->GetWorld();
	FActorSpawnParameters SpawnParams;
	SpawnParams.Template = ExistingActor;

	//auto NewObj = NewObject<UNewActorComponent>();
	return World->SpawnActor<AActor>(ExistingActor->GetClass(), SpawnLocation, SpawnRotation, SpawnParams);
}

void AMyActor::SetActive(bool InOn)
{
	SetActorHiddenInGame(InOn);

	// Disables collision components
	SetActorEnableCollision(!InOn);

	// Stops the Actor from ticking
	SetActorTickEnabled(!InOn);
}