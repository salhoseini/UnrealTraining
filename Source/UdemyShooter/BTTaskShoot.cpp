// Fill out your copyright notice in the Description page of Project Settings.


#include "BTTaskShoot.h"
#include "ShooterCharacter.h"
#include "AIController.h"

UBTTaskShoot::UBTTaskShoot()
{
	NodeName = "Shoot";
}

EBTNodeResult::Type UBTTaskShoot::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
	Super::ExecuteTask(OwnerComp, NodeMemory);

	if (OwnerComp.GetAIOwner() == nullptr) {
		return EBTNodeResult::Failed;
	}
	AShooterCharacter* Controller = Cast<AShooterCharacter>(OwnerComp.GetAIOwner()->GetPawn());
	if (Controller == nullptr) {
		return EBTNodeResult::Failed;
	}
	Controller->Shoot();

	return EBTNodeResult::Succeeded;
}
