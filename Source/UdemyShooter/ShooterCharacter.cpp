// Fill out your copyright notice in the Description page of Project Settings.


#include "ShooterCharacter.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "Gun.h"
#include "Components/CapsuleComponent.h"
#include "SimpleShooterGameMode.h"

// Sets default values
AShooterCharacter::AShooterCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AShooterCharacter::BeginPlay()
{
	Super::BeginPlay();
	Gun = GetWorld()->SpawnActor<AGun>(GunClass);
	GetMesh()->HideBoneByName(TEXT("weapon_r"), EPhysBodyOp::PBO_None);
	Gun->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("WeaponSocket"));
	Gun->SetOwner(this);
	Health = MaxHealth;
	
}

// Called every frame
void AShooterCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ShootTimePassed += DeltaTime;

}

// Called to bind functionality to input
void AShooterCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	const APlayerController* PC = Cast<APlayerController>(GetController());

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer());

	Subsystem->ClearAllMappings();
	Subsystem->AddMappingContext(DefaultMappingContext, 0);

	UEnhancedInputComponent* PEI = Cast<UEnhancedInputComponent>(PlayerInputComponent);

	PEI->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AShooterCharacter::Move);
	PEI->BindAction(LookAction, ETriggerEvent::Triggered, this, &AShooterCharacter::Look);
	PEI->BindAction(GamepadLookAction, ETriggerEvent::Triggered, this, &AShooterCharacter::GamepadLook);
	PEI->BindAction(JumpAction, ETriggerEvent::Triggered, this, &ACharacter::Jump);
	PEI->BindAction(ShootGunAction, ETriggerEvent::Triggered, this, &AShooterCharacter::ShootGun);
	PEI->BindAction(InteractAction, ETriggerEvent::Triggered, this, &AShooterCharacter::Pickup);

}

float AShooterCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	float DamageApplied = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	Health -= DamageApplied;
	Health = FMath::Clamp(Health, 0, MaxHealth);

	if (IsDead()) {
		ASimpleShooterGameMode* GameMode = GetWorld()->GetAuthGameMode<ASimpleShooterGameMode>();
		if (GameMode != nullptr) {
			GameMode->PawnKilled(this);
		}
		DetachFromControllerPendingDestroy();
		GetCapsuleComponent()->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		
	}

	return DamageApplied;
}


void AShooterCharacter::Shoot()
{
	if (ShootTimePassed > ShootInterval) {
		Gun->PullTrigger();
		ShootTimePassed = 0;
	}
}

void AShooterCharacter::Move(const FInputActionValue& MoveValue)
{
	// input is a Vector2D
	FVector2D MovementVector = MoveValue.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add movement 
		AddMovementInput(GetActorForwardVector(), MovementVector.Y);
		AddMovementInput(GetActorRightVector(), MovementVector.X);
	}
}

void AShooterCharacter::Look(const FInputActionValue& LookValue)
{
	// input is a Vector2D
	FVector2D LookVector = LookValue.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add movement 
		AddControllerYawInput(LookVector.X);
		AddControllerPitchInput(LookVector.Y);
	}
}

void AShooterCharacter::GamepadLook(const FInputActionValue& LookValue)
{
	// input is a Vector2D
	FVector2D LookVector = LookValue.Get<FVector2D>();

	if (Controller != nullptr)
	{
		// add movement 
		AddControllerYawInput(LookVector.X * GamePadLookRate * GetWorld()->GetDeltaSeconds());
		AddControllerPitchInput(LookVector.Y * GamePadLookRate * GetWorld()->GetDeltaSeconds());
	}
}

void AShooterCharacter::ShootGun(const FInputActionValue& ShootValue) 
{
	Shoot();
}

void AShooterCharacter::Pickup(const FInputActionValue& PickupValue) {
	UE_LOG(LogTemp, Warning, TEXT("Pick up"));
}


bool AShooterCharacter::IsDead() const {
	return Health <= 0;
}

float AShooterCharacter::GetHealthPercentage() const
{
	return Health / MaxHealth;
}

