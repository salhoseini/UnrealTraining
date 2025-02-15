// Fill out your copyright notice in the Description page of Project Settings.


#include "GadgetSpawner.h"

// Sets default values
AGadgetSpawner::AGadgetSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGadgetSpawner::BeginPlay()
{
	Super::BeginPlay();
	SpawnGadget();
	
}

// Called every frame
void AGadgetSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GadgetSpawned() == false) {
		SpawnGadget();
	}
}

