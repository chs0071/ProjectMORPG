// Copyright Epic Games, Inc. All Rights Reserved.

#include "MMORPGGameMode.h"
#include "MMORPGPlayerController.h"
#include "MMORPGCharacter.h"

AMMORPGGameMode::AMMORPGGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AMMORPGPlayerController::StaticClass();
	
	DefaultPawnClass = nullptr;
	HUDClass = nullptr;
	//PlayerControllerClass = nullptr;
	GameStateClass = nullptr;
	PlayerStateClass = nullptr;
	SpectatorClass = nullptr;

	// set default pawn class to our Blueprinted character
	// static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	// if (PlayerPawnBPClass.Class != NULL)
	// {
	// 	DefaultPawnClass = PlayerPawnBPClass.Class;
	// }
}
