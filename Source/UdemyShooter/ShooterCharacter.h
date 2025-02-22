// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShooterCharacter.generated.h"


class UInputMappingContext;
class UInputAction;
class AGun;
struct FInputActionValue;

UCLASS()
class UDEMYSHOOTER_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShooterCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		UInputMappingContext* DefaultMappingContext;

	///** Jump Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		UInputAction* JumpAction;

	///** Move Input Action */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		UInputAction* MoveAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		UInputAction* LookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		UInputAction* GamepadLookAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		UInputAction* ShootGunAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		UInputAction* InteractAction;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
		UInputAction* ReloadAction;
	

private:

	void Move(const FInputActionValue& MoveValue);

	void Look(const FInputActionValue& LookValue);

	void GamepadLook(const FInputActionValue& LookValue);

	void Jump(const FInputActionValue& JumpValue);

	void ShootGun(const FInputActionValue& ShootValue);

	void Pickup(const FInputActionValue& PickupValue);

	void Reload(const FInputActionValue& ReloadValue);

	UPROPERTY(EditDefaultsOnly)
		float MaxHealth = 100;

	UPROPERTY(VisibleAnywhere)
		float Health = 100;

	UPROPERTY(EditAnywhere)
		float GamePadLookRate = 10;

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<AGun> GunClass;

	UPROPERTY()
		AGun* Gun;

	UPROPERTY(EditAnywhere)
		float ShootInterval = 0.5f;

	float ShootTimePassed = ShootInterval;


public:	

	UFUNCTION(BlueprintPure)
		bool IsDead() const;

	UFUNCTION(BlueprintPure)
		float GetHealthPercentage() const;

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, AActor* DamageCauser) override;

	void Shoot();

	void UpdateHealth(float UpdateValue) {
		Health = FMath::Clamp(Health + UpdateValue, 0, MaxHealth);
	}

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Components")
		class UDetectionCone* DetectionCone;

};
