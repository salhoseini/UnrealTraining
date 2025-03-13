// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "GadgetComponent.generated.h"


UCLASS(Abstract)
class UDEMYSHOOTER_API UGadgetComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGadgetComponent();

public:	
	// Called every frame

	void ApplyGadgetEffect(class AShooterCharacter* ShooterCharacter);

	virtual void ApplyGadgetEffect_Impl(class AShooterCharacter* ShooterCharacter) PURE_VIRTUAL(UGadgetComponent::ApplyGadgetEffect) ;

};
