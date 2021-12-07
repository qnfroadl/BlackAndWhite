// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_NetPlayerController.h"

#include "SocketSubsystem.h"

FString ACPP_NetPlayerController::GetIPAddress()
{
	bool bCanBindAll = false;

	TSharedPtr<class FInternetAddr> Addr = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM)->GetLocalHostAddr(*GLog, bCanBindAll);
	FString MyIP = Addr->ToString(false);

	return MyIP;
	// 
	// 	if (nullptr == NetConnection)
	// 	{
	// 		return FString(TEXT("NetConnection is nullptr"));
	// 
	// 	}
	// 
	// 	return NetConnection->URL.Host;
}
