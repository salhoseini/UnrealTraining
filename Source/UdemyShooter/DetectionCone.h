// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Gadget.h"
#include "DetectionCone.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class UDEMYSHOOTER_API UDetectionCone : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDetectionCone();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:

	UPROPERTY(EditAnywhere)
	float MaxDetectionDistance = 10;

	UPROPERTY(EditAnywhere)
	float ConeAngle = 90;

	UPROPERTY()
	AGadget* DetectedGadget;

	bool GetGadgetInReach(FOverlapResult& OutOverlapResult) const;


		
};
