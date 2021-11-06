#include "PMUnrealNetworkManager.h"
#include "Kismet/GameplayStatics.h"

void FPMUnrealNetworkManager::Initialize()
{
	IOnlineSubsystem* OSInst = IOnlineSubsystem::Get();
	IOnlineSessionPtr SessionInst = OSInst->GetSessionInterface();

	CreateSessionCompleteD = FOnCreateSessionCompleteDelegate::CreateSP(AsShared(), &FPMUnrealNetworkManager::CreateSessionComplete);
	CreateSessionCompleteDH = SessionInst->AddOnCreateSessionCompleteDelegate_Handle(CreateSessionCompleteD);
}

void FPMUnrealNetworkManager::Host()
{
	SessionSettings.bIsLANMatch = true;
	SessionSettings.bAllowJoinInProgress = true;
	SessionSettings.bUsesPresence = true;   // What is presence?
	SessionSettings.bShouldAdvertise = true;

	IOnlineSubsystem* OSInst = IOnlineSubsystem::Get();
	IOnlineSessionPtr SessionInst = OSInst->GetSessionInterface();

	// If session isn't created then one might already exist so try to destroy it.	
	if (SessionInst->CreateSession(0, "cheese", SessionSettings))
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, "Yes: Create");
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, "No: Create");

		if (SessionInst->DestroySession("cheese"))
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, "Yes: Delete");
		else
			GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, "No: Delete");
	}
}

void FPMUnrealNetworkManager::CreateSessionComplete(FName SessionName, bool bWasSuccessful)
{
	if (bWasSuccessful)
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, "Pass: Create");
	else
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, "Fail: Create");
}