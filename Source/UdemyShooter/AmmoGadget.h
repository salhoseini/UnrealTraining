// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Gadget.h"
#include "AmmoGadget.generated.h"

/**
 * 
 */
UCLASS()
class UDEMYSHOOTER_API AAmmoGadget : public AGadget
{
	GENERATED_BODY()

public:
	AAmmoGadget();

	virtual void Consume(class AShooterCharacter* ShooterCharacter);

private:
	UPROPERTY(EditAnywhere)
		float AmmoCount = 20;
	
};
