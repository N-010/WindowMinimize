// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameViewportClient.h"

#include "TheWickedGameViewportClient.generated.h"

/**
 * 
 */
UCLASS()
class THEWICKED_API UTheWickedGameViewportClient : public UGameViewportClient
{
	GENERATED_BODY()

public:
	//~ Begin GameViewportClient Interface
	virtual void LostFocus(FViewport* LostFocusViewport) override;
	virtual void Init(struct FWorldContext& WorldContext, UGameInstance* OwningGameInstance, bool bCreateNewAudioDevice = true) override;
	//~ End GameViewportClient Interface

	//~ Begin UObject Interface
	virtual void PostInitProperties() override;
	//~ End UObject Interface

	UFUNCTION()
	void CheckWindowMinimize();

	UFUNCTION()
	void BindWindowDeactivatedEvent();

	virtual void WindowMinimize();
	
	
};
