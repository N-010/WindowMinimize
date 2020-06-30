// Fill out your copyright notice in the Description page of Project Settings.


#include "TheWickedGameViewportClient.h"

#include "Engine/Engine.h"
#include "Engine/World.h"
#include "GameState/TheWickedGameStateBase.h"
#include "Widgets/SWindow.h"

void UTheWickedGameViewportClient::LostFocus(FViewport* LostFocusViewport)
{
    Super::LostFocus(LostFocusViewport);
}

void UTheWickedGameViewportClient::Init(FWorldContext& WorldContext, UGameInstance* OwningGameInstance,
                                        bool bCreateNewAudioDevice)
{
    Super::Init(WorldContext, OwningGameInstance, bCreateNewAudioDevice);
    UWorld* MyWorld = GetWorld();
    //Check if the window is minimized in the game, not in the editor
    if (MyWorld && MyWorld->WorldType == EWorldType::Game)
    {
        if (!OnBeginDraw().IsBoundToObject(this))
        {
            OnBeginDraw().AddUObject(this, &UTheWickedGameViewportClient::BindWindowDeactivatedEvent);
        }
    }
}

void UTheWickedGameViewportClient::PostInitProperties()
{
    Super::PostInitProperties();
}

void UTheWickedGameViewportClient::CheckWindowMinimize()
{
    if (const SWindow* W = GetWindow().Get())
    {
	//If you remove the check, the function will be called, every time the window is out of focus
        if (W->IsWindowMinimized())
        {
            WindowMinimize();
        }
    }
}

void UTheWickedGameViewportClient::BindWindowDeactivatedEvent()
{
    if (SWindow* W = GetWindow().Get())
    {
        if (!W->GetOnWindowDeactivatedEvent().IsBoundToObject(this))
        {
            W->GetOnWindowDeactivatedEvent().AddUObject(this, &UTheWickedGameViewportClient::CheckWindowMinimize);
        }
    }
    else
    {
        GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("!Window"));
    }
}

void UTheWickedGameViewportClient::WindowMinimize()
{
    if (World)
    {
        if (ATheWickedGameStateBase* GameStateBase = Cast<ATheWickedGameStateBase>(World->GetGameState()))
        {
            GameStateBase->Client_Pause();
        }
    }
}
