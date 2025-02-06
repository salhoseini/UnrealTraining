// Fill out your copyright notice in the Description page of Project Settings.


#include "BD_IsPLayerAlive.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "ShooterCharacter.h"

UBD_IsPLayerAlive::UBD_IsPLayerAlive()
{
	NodeName = "Is Player Alive";
}

bool UBD_IsPLayerAlive::CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const
{
	Super::CalculateRawConditionValue(OwnerComp, NodeMemory);
	UObject* SelectedKey = OwnerComp.GetBlackboardComponent()->GetValueAsObject(GetSelectedBlackboardKey());
	APawn* PlayerPawn = Cast<APawn>(SelectedKey);
	if (PlayerPawn == nullptr) {
		return false;
	}
	AShooterCharacter* PlayerShooterCharacter = Cast<AShooterCharacter>(PlayerPawn);
	if (PlayerShooterCharacter == nullptr) {
		return false;
	}


	return PlayerShooterCharacter->IsDead() == false;
}
