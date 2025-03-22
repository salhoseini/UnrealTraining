// Fill out your copyright notice in the Description page of Project Settings.


#include "Gadget.h"
#include "ShooterCharacter.h"
#include "GadgetComponent.h"
#include "Components/WidgetComponent.h"

// Sets default values
AGadget::AGadget()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	GadgetRoot = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	SetRootComponent(GadgetRoot);
	GadgetMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Gadget Mesh Renamed"));
	GadgetMesh->SetupAttachment(GadgetRoot);
	WidgetRoot = CreateDefaultSubobject<UWidgetComponent>(TEXT("WidgetRoot Renamed"));
	WidgetRoot->SetupAttachment(GadgetRoot);
}

// Called when the game starts or when spawned
void AGadget::BeginPlay()
{
	Super::BeginPlay();
	USceneComponent* sceneComponent = GetRootComponent();
	UE_LOG(LogTemp, Error, TEXT("Root : %s"), *sceneComponent->GetName());
	GadgetWidget = CreateWidget<UUserWidget>(GetWorld(), GadgetWidgetClass);
	if (GadgetWidget != nullptr) {
		WidgetRoot->SetWidget(GadgetWidget);
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("Gadget Widget is null"));
	}
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

