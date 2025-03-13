// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GadgetComponent.h"
#include "AmmoGadgetComponent.generated.h"

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class UDEMYSHOOTER_API UAmmoGadgetComponent : public UGadgetComponent
{
	GENERATED_BODY()

public:
	UAmmoGadgetComponent();

	virtual void ApplyGadgetEffect_Impl(class AShooterCharacter* ShooterCharacter) override;

private:
	UPROPERTY(EditAnywhere)
		float AmmoCount = 10;
	
};
