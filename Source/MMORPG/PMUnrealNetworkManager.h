#pragma once

#include "OnlineSubsystem.h"
#include "OnlineSubsystemUtils.h"

class FPMUnrealNetworkManager : public TSharedFromThis<FPMUnrealNetworkManager>
{
public:
	void Initialize();
	void Host();

private:
	void CreateSessionComplete(FName SessionName, bool bWasSuccessful);
	FOnCreateSessionCompleteDelegate CreateSessionCompleteD;
    FDelegateHandle CreateSessionCompleteDH;
    FOnlineSessionSettings SessionSettings;
};
