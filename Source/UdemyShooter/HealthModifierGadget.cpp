// Fill out your copyright notice in the Description page of Project Settings.


#include "HealthModifierGadget.h"
#include "ShooterCharacter.h"

AHealthModifierGadget::AHealthModifierGadget()
{
}

void AHealthModifierGadget::Consume(AShooterCharacter* ShooterCharacter)
{
	if (ShooterCharacter == nullptr) {
		return;
	}
	ShooterCharacter->UpdateHealth(ModifierValue);
	Super::Consume(ShooterCharacter);
}
