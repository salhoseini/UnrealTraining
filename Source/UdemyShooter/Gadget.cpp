// Fill out your copyright notice in the Description page of Project Settings.


#include "Gadget.h"
#include "ShooterCharacter.h"
#include "GadgetComponent.h"

// Sets default values
AGadget::AGadget()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	GadgetMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Gadget Mesh"));
	GadgetMesh->SetupAttachment(GetRootComponent());
}

// Called when the game starts or when spawned
void AGadget::BeginPlay()
{
	Super::BeginPlay();

	GadgetComponent = FindComponentByClass<UGadgetComponent>();
	if (GadgetComponent == nullptr) {
		UE_LOG(LogTemp, Error, TEXT("No GadgetComponent Is added to the Gadget Actor"));
	}
}

// Called every frame
void AGadget::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGadget::Consume(AShooterCharacter* ShooterCharacter)
{
	UE_LOG(LogTemp, Warning, TEXT("Consuming Gadget %s") , *ShooterCharacter->GetName());
	if (GadgetComponent != nullptr) {
		GadgetComponent->ApplyGadgetEffect(ShooterCharacter);
	}
	Destroy();
}

