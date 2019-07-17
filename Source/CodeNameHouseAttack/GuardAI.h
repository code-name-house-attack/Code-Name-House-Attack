// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GuardAI.generated.h"

UCLASS()
class CODENAMEHOUSEATTACK_API AGuardAI : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AGuardAI();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void MoveToWaypoints();

private:
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
	int CurrentWaypoint;

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
	int MaxWaypoint;

	TArray<AActor*> Waypoints;
};
