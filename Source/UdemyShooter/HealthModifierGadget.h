// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Gadget.h"
#include "HealthModifierGadget.generated.h"

/**
 * 
 */
UCLASS()
class UDEMYSHOOTER_API AHealthModifierGadget : public AGadget
{
	GENERATED_BODY()

public:
	AHealthModifierGadget();

	virtual void Consume(class AShooterCharacter* ShooterCharacter);

private:
	UPROPERTY(EditAnywhere)
		float ModifierValue = 15;



	
};
