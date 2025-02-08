// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SimpleShooterGameMode.h"
#include "KillEmAllGameMode.generated.h"

/**
 * 
 */
UCLASS()
class UDEMYSHOOTER_API AKillEmAllGameMode : public ASimpleShooterGameMode
{
	GENERATED_BODY()

public:
	void PawnKilled(APawn* PawnKilled) override;

	UFUNCTION(BlueprintPure)
		FText GetRemainingPlayerText() const;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	
	int totalPlayerCount;
	
	int remainingPlayerCount;

	UPROPERTY()
		TArray<AController*> AllControllers;

	void EndGame(bool isPlayerWinner);
	
};
