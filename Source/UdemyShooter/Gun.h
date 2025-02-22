// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Gun.generated.h"

UCLASS()
class UDEMYSHOOTER_API AGun : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGun();

	void PullTrigger();

	void Reload();

	void UpdateAmmoCount(int count) {
		totalAmmoCount = FMath::Clamp(totalAmmoCount + count, 0, MaxAmmoCount);
	}

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	UPROPERTY(VisibleAnywhere)
		USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
		USkeletalMeshComponent* Mesh;

	UPROPERTY(EditAnywhere)
		UParticleSystem* MuzzleFlash;

	UPROPERTY(EditAnywhere)
		UParticleSystem* ImpactFlash;

	UPROPERTY(EditAnywhere)
		USoundBase* MuzzleSound;

	UPROPERTY(EditAnywhere)
		USoundBase* ImpactSound;

	UPROPERTY(EditAnywhere)
		float MaxRange = 1000;

	UPROPERTY(EditAnywhere)
		float Damage = 10;
	UPROPERTY(EditAnywhere)
		float HeadShotDamage = 30;
	UPROPERTY(EditAnywhere)
		float LimbDamage = 10;

	UPROPERTY(EditAnywhere, Category = "Ammmo")
		float MaxAmmoCount = 150;

	UPROPERTY(EditAnywhere, Category = "Ammmo")
		float MagazineCapacity = 30;

	float ammoCount;

	float totalAmmoCount;


	const float IMPACT_HIT_OFFSET = 5;

	const FVector GetImpactEffectLocation(FVector impactPoint, FVector direction) {
		return impactPoint + (direction * IMPACT_HIT_OFFSET);
	}

	bool GunTrace(FHitResult& HitResult, FVector& ShotDirection);

	AController* GetOwnerController() const;

};
