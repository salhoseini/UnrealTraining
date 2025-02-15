// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gadget.h"
#include "GadgetSpawner.generated.h"

UCLASS()
class UDEMYSHOOTER_API AGadgetSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGadgetSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(EditAnywhere)
	float SpawnInterval;

	UPROPERTY(EditAnywhere)
	TSubclassOf<AGadget> GadgetToSpawnClass;

	AGadget* SpawnedGadget;

	FTimerHandle SpawnTimer;

	void SpawnGadget() {
		SpawnedGadget = GetWorld()->SpawnActor<AGadget>(GadgetToSpawnClass, GetActorLocation(), GetActorRotation());
	}

	bool GadgetSpawned() const {
		return SpawnedGadget != nullptr;
	}

};
