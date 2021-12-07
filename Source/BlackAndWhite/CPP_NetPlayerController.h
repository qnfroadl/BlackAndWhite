// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Gameframework/PlayerController.h"
#include "CPP_NetPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BLACKANDWHITE_API ACPP_NetPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	FString GetIPAddress();

};
