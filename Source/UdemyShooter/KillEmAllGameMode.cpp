// Fill out your copyright notice in the Description page of Project Settings.


#include "KillEmAllGameMode.h"
#include "GameFramework/Controller.h"
#include "EngineUtils.h"
#include "ShooterAIController.h"

void AKillEmAllGameMode::BeginPlay()
{
	for (AController* Controller : TActorRange<AController>(GetWorld())) {
		AllControllers.Add(Controller);
		if (Controller->IsPlayerController()) {
			continue;
		}
		totalPlayerCount++;
		remainingPlayerCount++;
	}
}

void AKillEmAllGameMode::PawnKilled(APawn* PawnKilled)
{
	Super::PawnKilled(PawnKilled);
	APlayerController* PlayerController = Cast<APlayerController>(PawnKilled->GetController());
	if (PlayerController != nullptr) {
		EndGame(false);
		return;
	}
	remainingPlayerCount--;
	for (AShooterAIController* AIController : TActorRange<AShooterAIController>(GetWorld())) {
		if (AIController->IsDead() == false) {
			return;
		}
	}
	EndGame(true);
	
}

FText AKillEmAllGameMode::GetRemainingPlayerText() const
{
	return FText::Format(FText::FromString("{0} / {1}"), remainingPlayerCount, totalPlayerCount);
}

void AKillEmAllGameMode::EndGame(bool isPlayerWinner)
{
	for (AController* Controller : AllControllers)
	{
		bool isWinner = Controller->IsPlayerController() == isPlayerWinner;
		Controller->GameHasEnded(Controller->GetPawn(), isWinner);
	}
}
