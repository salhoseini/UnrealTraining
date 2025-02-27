// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthGadgetComponent.h"
#include "ShooterCharacter.h"

UHealthGadgetComponent::UHealthGadgetComponent()
{
}

void UHealthGadgetComponent::ApplyGadgetEffect(AShooterCharacter* ShooterCharacter) const
{
	Super::ApplyGadgetEffect(ShooterCharacter);
	if (ShooterCharacter == nullptr) {
		return;
	}
	ShooterCharacter->UpdateHealth(ModifierValue);
	
}
