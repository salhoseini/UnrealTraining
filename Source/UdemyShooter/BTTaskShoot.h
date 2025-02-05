// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/BTTaskNode.h"
#include "BTTaskShoot.generated.h"

/**
 * 
 */
UCLASS()
class UDEMYSHOOTER_API UBTTaskShoot : public UBTTaskNode
{
	GENERATED_BODY()

public:
	UBTTaskShoot();

protected:
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) override;
	
};
