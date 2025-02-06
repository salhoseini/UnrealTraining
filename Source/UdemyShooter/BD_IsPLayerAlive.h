// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Decorators/BTDecorator_BlackboardBase.h"
#include "BD_IsPLayerAlive.generated.h"

/**
 * 
 */
UCLASS()
class UDEMYSHOOTER_API UBD_IsPLayerAlive : public UBTDecorator_BlackboardBase
{
	GENERATED_BODY()

public:
	UBD_IsPLayerAlive();

protected:
	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;
	
};
