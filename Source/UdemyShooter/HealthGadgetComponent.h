// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GadgetComponent.h"
#include "HealthGadgetComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class UDEMYSHOOTER_API UHealthGadgetComponent : public UGadgetComponent
{
	GENERATED_BODY()

public:
	UHealthGadgetComponent();

	virtual void ApplyGadgetEffect(class AShooterCharacter* ShooterCharacter) const;

private:
	UPROPERTY(EditAnywhere)
		float ModifierValue = 15;
	
};
