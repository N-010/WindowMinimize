// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameState.h"
#include "TheWickedGameStateBase.generated.h"

/**
 * 
 */
UCLASS()
class THEWICKED_API ATheWickedGameStateBase : public AGameState
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintCosmetic, Category=Pause)
	void Client_Pause();
	UFUNCTION(BlueprintCallable, BlueprintImplementableEvent, BlueprintCosmetic, Category=Pause)
	void Client_UnPause();
};

