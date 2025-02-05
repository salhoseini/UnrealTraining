// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Kismet/GameplayStatics.h"
#include "ShooterAIController.generated.h"

/**
 * 
 */
UCLASS()
class UDEMYSHOOTER_API AShooterAIController : public AAIController
{
	GENERATED_BODY()

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	APawn* PlayerPawn;

public:
	virtual void Tick(float DeltaTime) override;

	bool IsDead() const;


private:

	UPROPERTY(EditAnywhere)
		class UBehaviorTree* AIBehavior;

	class UBlackboardComponent* BlackBoard;

	APawn* playerPawn;

	
};
