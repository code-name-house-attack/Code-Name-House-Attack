// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "GuardAIController.generated.h"

/**
 * 
 */
UCLASS()
class CODENAMEHOUSEATTACK_API AGuardAIController : public AAIController
{
	GENERATED_BODY()
	
	void OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult& Result) override;
};
