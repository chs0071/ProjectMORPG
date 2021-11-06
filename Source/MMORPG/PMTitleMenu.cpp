// Fill out your copyright notice in the Description page of Project Settings.

#include "PMTitleMenu.h"

#include "PMSingleton.h"

void UPMTitleMenu::OnClickedPlay()
{
	UPMSingleton::Play(GetWorld());
}
