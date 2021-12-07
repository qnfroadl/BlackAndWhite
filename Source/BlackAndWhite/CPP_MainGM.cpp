// Fill out your copyright notice in the Description page of Project Settings.


#include "CPP_MainGM.h"
#include <Kismet/GameplayStatics.h>
#include <Net/OnlineEngineInterface.h>
#include <GameFramework/GameSession.h>


ACPP_MainGM::ACPP_MainGM()
	:AGameModeBase(), MaxPlayers(2)
{

}

void ACPP_MainGM::PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage)
{
	const bool bUniqueIdCheckOk = (!UniqueId.IsValid() || (UniqueId.GetType() == UOnlineEngineInterface::Get()->GetDefaultOnlineSubsystemName()));
	if (bUniqueIdCheckOk)
	{
		ErrorMessage = GameSession->ApproveLogin(Options);
	}
	else
	{
		ErrorMessage = TEXT("incompatible_unique_net_id");
	}

	if (ErrorMessage.IsEmpty())
	{
		TArray<AActor*> OutActors;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), APlayerController::StaticClass(), OutActors);

		if (this->MaxPlayers <= OutActors.Num())
		{
			ErrorMessage.Append(TEXT("Max Players"));
// 
// 			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("Max Players"));
		}
	}

	FGameModeEvents::GameModePreLoginEvent.Broadcast(this, UniqueId, ErrorMessage);
}

void ACPP_MainGM::BeginPlay()
{
	Super::BeginPlay();

	// GameModePreLoginEvent.AddDynamic(this, &ACPP_MainGM::PreLoginEvent);
}
// 
// void ACPP_MainGM::PreLoginEvent(AGameModeBase* GameMode, const FUniqueNetIdRepl& NewPlayer, FString& ErrorMessage)
// {
// 
// }
