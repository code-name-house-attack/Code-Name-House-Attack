// Fill out your copyright notice in the Description page of Project Settings.


#include "GuardAIController.h"
#include "GuardAI.h"

void AGuardAIController::OnMoveCompleted(FAIRequestID RequestID, const FPathFollowingResult & Result)
{
	AGuardAI* GuardAI = Cast<AGuardAI>(GetPawn());

	if (GuardAI)
	{
		GuardAI->MoveToWaypoints();
	}
}
