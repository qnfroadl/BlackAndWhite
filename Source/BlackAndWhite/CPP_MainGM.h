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
	
	// �� ����� �´��� Ȯ�� �ʿ�.
	void PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage) override;

	UPROPERTY(EditAnywhere)
	int MaxPlayers;

};
