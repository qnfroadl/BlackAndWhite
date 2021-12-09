// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "CPP_MainGM.generated.h"

/**
 * 
 */
UCLASS()
class BLACKANDWHITE_API ACPP_MainGM : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	ACPP_MainGM();
	
	// 이 방식이 맞는지 확인 필요.
	void PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage) override;

	UPROPERTY(EditAnywhere)
	int MaxPlayers;

};
