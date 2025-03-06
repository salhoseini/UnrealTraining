// Fill out your copyright notice in the Description page of Project Settings.


#include "AmmoGadgetComponent.h"
#include "ShooterCharacter.h"
#include "Gun.h"

UAmmoGadgetComponent::UAmmoGadgetComponent()
{
}

void UAmmoGadgetComponent::ApplyGadgetEffect_Impl(AShooterCharacter* ShooterCharacter)
{
	if (ShooterCharacter == nullptr) {
		return;
	}
	AGun* Gun = ShooterCharacter->GetCurrentGun();
	if(Gun == nullptr) {
		return;
	}
	Gun->UpdateAmmoCount(AmmoCount);
}
