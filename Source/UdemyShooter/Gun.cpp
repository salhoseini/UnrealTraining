// Fill out your copyright notice in the Description page of Project Settings.


#include "Gun.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
#include "Engine/DamageEvents.h"

// Sets default values
AGun::AGun()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);

}

// Called when the game starts or when spawned
void AGun::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AGun::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool AGun::GunTrace(FHitResult& HitResult, FVector& ShotDirection)
{

	AController* OwnerController = GetOwnerController();
	if (OwnerController == nullptr) { return false; }

	FVector viewPortLocation;
	FRotator viewPortRotator;
	OwnerController->GetPlayerViewPoint(viewPortLocation, viewPortRotator);
	ShotDirection = viewPortRotator.Vector() * -1;
	FVector End = viewPortLocation + viewPortRotator.Vector() * MaxRange;

	FCollisionQueryParams Params;
	TArray<AActor*> ignoreList;
	ignoreList.Add(this);
	ignoreList.Add(GetOwner());
	Params.AddIgnoredActors(ignoreList);
	return GetWorld()->LineTraceSingleByChannel(HitResult, viewPortLocation, End, ECollisionChannel::ECC_GameTraceChannel1, Params);
}

AController* AGun::GetOwnerController() const
{
	APawn* OwnerPawn = Cast<APawn>(GetOwner());
	if (OwnerPawn == nullptr) { return nullptr; }

	return OwnerPawn->GetController();
}

void AGun::PullTrigger() {

	UGameplayStatics::SpawnEmitterAttached(MuzzleFlash, Mesh, TEXT("MuzzleFlashSocket"));
	UGameplayStatics::SpawnSoundAttached(MuzzleSound, Mesh, TEXT("MuzzleFlashSocket"));
	FHitResult HitResult;
	FVector ShotDirection;
	
	if (GunTrace(HitResult, ShotDirection)) {
		
		UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), ImpactFlash, GetImpactEffectLocation(HitResult.ImpactPoint, ShotDirection), ShotDirection.Rotation(), true);
		UGameplayStatics::SpawnSoundAtLocation(GetWorld(), ImpactSound, GetImpactEffectLocation(HitResult.ImpactPoint, ShotDirection), ShotDirection.Rotation());
		AActor* hitActor = HitResult.GetActor();
		if (hitActor == nullptr) {
			return;
		}
		FPointDamageEvent DamageEvent(Damage, HitResult, ShotDirection, nullptr);
		hitActor->TakeDamage(Damage, DamageEvent, GetOwnerController(), this);
	}

}

