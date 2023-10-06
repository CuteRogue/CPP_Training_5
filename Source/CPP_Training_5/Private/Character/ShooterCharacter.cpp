// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/ShooterCharacter.h"

#include "Kismet/KismetMathLibrary.h"

// Sets default values
AShooterCharacter::AShooterCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AShooterCharacter::MoveByInput(const FVector2D InputAxis, const float MoveSpeed)
{
    FVector Direction = FRotationMatrix(GetControlRotation()).GetScaledAxis(EAxis::X);

	Direction = FVector(Direction.GetSafeNormal().X, Direction.GetSafeNormal().Y, 0.0f);
	AddMovementInput(UKismetMathLibrary::GetRightVector(GetControlRotation()) * InputAxis.X, MoveSpeed);
	AddMovementInput(UKismetMathLibrary::GetForwardVector(GetControlRotation()) * InputAxis.Y, MoveSpeed);
}

void AShooterCharacter::LookByInputMouse(const FVector2D InputAxis, const float LookSpeed, const bool InvertPitch, const bool InvertYaw)
{
	AddControllerYawInput(InputAxis.X * LookSpeed * (InvertYaw ? 1 : -1));
	AddControllerPitchInput(InputAxis.Y * LookSpeed * (InvertPitch ? 1 : -1));
}

void AShooterCharacter::LookByInputGamepad(const FVector2D InputAxis, const float LookRate, const bool InvertPitch, const bool InvertYaw)
{
	AddControllerYawInput(FMath::Clamp(InputAxis.X, -1.0f, 1.0f) * LookRate * GetWorld()->DeltaTimeSeconds * (InvertYaw ? 1 : -1));
	AddControllerPitchInput(FMath::Clamp(InputAxis.Y, -1.0f, 1.0f) * LookRate * GetWorld()->DeltaTimeSeconds * (InvertPitch ? 1 : -1));
}

