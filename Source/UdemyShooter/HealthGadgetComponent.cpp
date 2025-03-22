// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthGadgetComponent.h"
#include "ShooterCharacter.h"

UHealthGadgetComponent::UHealthGadgetComponent()
{
}

void UHealthGadgetComponent::ApplyGadgetEffect_Impl(AShooterCharacter* ShooterCharacter)
{
	if (ShooterCharacter == nullptr) {
		return;
	}
	ShooterCharacter->UpdateHealth(ModifierValue);
	
}

float UHealthGadgetComponent::GetGadgetValue_Impl()
{
	return ModifierValue;
}
