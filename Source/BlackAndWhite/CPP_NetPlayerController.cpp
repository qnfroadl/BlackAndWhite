// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_NetPlayerController.h"

#include "SocketSubsystem.h"

FString ACPP_NetPlayerController::GetIPAddress()
{
	bool bCanBindAll = false;
	FString MyIP = TEXT("Unknown");

	ISocketSubsystem* SocketSystem = ISocketSubsystem::Get(PLATFORM_SOCKETSUBSYSTEM);

	if (SocketSystem)
	{
		TSharedPtr<class FInternetAddr> Addr = SocketSystem->GetLocalHostAddr(*GLog, bCanBindAll);
		
		MyIP = Addr->ToString(false);
	}
	
	UWorld* world = GetWorld();
	if (world)
	{
		MyIP = MyIP + FString(":") +  FString::FromInt(world->URL.Port);
	}

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