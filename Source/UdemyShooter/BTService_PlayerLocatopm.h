// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"
#include "BTService_PlayerLocatopm.generated.h"

/**
 * 
 */
UCLASS()
class UDEMYSHOOTER_API UBTService_PlayerLocatopm : public UBTService_BlackboardBase
{
	GENERATED_BODY()

public:
	UBTService_PlayerLocatopm();

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
	
};
