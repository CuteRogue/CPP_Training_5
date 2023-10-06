// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShooterCharacter.generated.h"

UCLASS()
class CPP_TRAINING_5_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AShooterCharacter();
	
protected:
	UFUNCTION(BlueprintCallable)
	void MoveByInput(const FVector2D InputAxis, const float MoveSpeed);
	UFUNCTION(BlueprintCallable)
	void LookByInputMouse(const FVector2D InputAxis, const float LookSpeed, const bool InvertPitch, const bool InvertYaw);
	UFUNCTION(BlueprintCallable)
	void LookByInputGamepad(const FVector2D InputAxis, const float LookRate, const bool InvertPitch, const bool InvertYaw);
};
