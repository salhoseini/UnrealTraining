// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterPlayerController.h"
#include "Blueprint/UserWidget.h"


void AShooterPlayerController::BeginPlay() {
	HUD = CreateWidget(this, PlayerHUD);
	if (HUD != nullptr) {
		HUD->AddToViewport();
	}
}

void AShooterPlayerController::GameHasEnded(AActor* EndGameFocus, bool bIsWinner)
{
	Super::GameHasEnded(EndGameFocus, bIsWinner);

	if (bIsWinner) {
		UUserWidget* winScreen = CreateWidget(this, WinScreenClass);
		if (winScreen != nullptr) {
			winScreen->AddToViewport();
		}
	}
	else {
		UUserWidget* loseScreen = CreateWidget(this, LoseScreenClass);
		if (loseScreen != nullptr) {
			loseScreen->AddToViewport();
		}
	}
	HUD->RemoveFromViewport();
	GetWorldTimerManager().SetTimer(RetartTimer, this, &APlayerController::RestartLevel, RestartDelay);
}
