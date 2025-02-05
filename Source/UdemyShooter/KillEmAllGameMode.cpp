// Fill out your copyright notice in the Description page of Project Settings.


#include "KillEmAllGameMode.h"
#include "GameFramework/Controller.h"
#include "EngineUtils.h"
#include "ShooterAIController.h"

void AKillEmAllGameMode::PawnKilled(APawn* PawnKilled)
{
	Super::PawnKilled(PawnKilled);
	APlayerController* PlayerController = Cast<APlayerController>(PawnKilled->GetController());
	if (PlayerController != nullptr) {
		EndGame(false);
	}
	for (AShooterAIController* AIController : TActorRange<AShooterAIController>(GetWorld())) {
		if (AIController->IsDead() == false) {
			return;
		}
	}
	EndGame(true);
	
}

void AKillEmAllGameMode::EndGame(bool isPlayerWinner)
{
	for (AController* Controller : TActorRange<AController>(GetWorld()))
	{
		bool isWinner = Controller->IsPlayerController() == isPlayerWinner;
		Controller->GameHasEnded(Controller->GetPawn(), isWinner);
	}
}
