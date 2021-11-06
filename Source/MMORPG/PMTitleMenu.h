// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PMTitleMenu.generated.h"

/**
 * 
 */
UCLASS()
class MMORPG_API UPMTitleMenu : public UUserWidget
{
	GENERATED_BODY()
	
	UFUNCTION(BlueprintCallable)
	void OnClickedPlay();
};
