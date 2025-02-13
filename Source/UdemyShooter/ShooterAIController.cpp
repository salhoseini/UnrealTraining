// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterAIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "ShooterCharacter.h"

// Called when the game starts or when spawned
void AShooterAIController::BeginPlay()
{
	Super::BeginPlay();
	if (AIBehavior != nullptr) {

		//RunBehaviorTree(AIBehavior);
		//BlackBoard = GetBlackboardComponent();
		//playerPawn = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
		//APawn* pawn = GetPawn();
		//BlackBoard->SetValueAsVector(TEXT("StartingLocation"), pawn->GetActorLocation());
	}

}

void AShooterAIController::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);
}

bool AShooterAIController::IsDead() const
{
	AShooterCharacter* ControlledCharacter = Cast<AShooterCharacter>(GetPawn());
	if (ControlledCharacter != nullptr) {
		return ControlledCharacter->IsDead();
	}
	return true;
}
