// Fill out your copyright notice in the Description page of Project Settings.


#include "DetectionCone.h"

// Sets default values for this component's properties
UDetectionCone::UDetectionCone()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UDetectionCone::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UDetectionCone::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	FOverlapResult OverlapResult;
	if (GetGadgetInReach(OverlapResult)) {
		FVector ToGadgetVector = OverlapResult.GetActor()->GetActorLocation() - GetComponentLocation();
		FVector ForwardVector = GetForwardVector();

		float DotProduct = FVector::DotProduct(ToGadgetVector, ForwardVector);

		float CosineThreshold = FMath::Cos(FMath::DegreesToRadians(ConeAngle / 2));

		if (DotProduct > CosineThreshold) {
			DetectedGadget = Cast<AGadget>(OverlapResult.GetActor());
			if (DetectedGadget == nullptr) {
				UE_LOG(LogTemp, Error, TEXT("Item is not of type Gadget"));
			}
			else {
				UE_LOG(LogTemp, Warning, TEXT("Found a Gadget %s"), *DetectedGadget->GetName());
			}
		}
	}
	else {
		DetectedGadget = nullptr;
	}

	// ...
}

AGadget* UDetectionCone::GetDetectedGadget() const
{
	return DetectedGadget;
}

bool UDetectionCone::GetGadgetInReach(FOverlapResult& OutOverlapResult) const
{
	TArray<FOverlapResult> OverlapResults;
	FVector Origin =  GetComponentLocation();
	FCollisionShape Shape = FCollisionShape::MakeSphere(MaxDetectionDistance);
	
	bool hits = GetWorld()->OverlapMultiByChannel(
		OverlapResults,
		Origin,
		FQuat::Identity,
		ECC_GameTraceChannel2,
		Shape
	);

	DrawDebugSphere(GetWorld(), Origin, MaxDetectionDistance, 32, FColor::Green, false);

	if (hits) {
		OutOverlapResult = OverlapResults[0];
	}

	return hits;
}

