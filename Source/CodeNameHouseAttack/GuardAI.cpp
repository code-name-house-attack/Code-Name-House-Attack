// Fill out your copyright notice in the Description page of Project Settings.


#include "GuardAI.h"
#include "Engine/World.h"
#include "GuardAIController.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "Waypoint.h"

// Sets default values
AGuardAI::AGuardAI()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGuardAI::BeginPlay()
{
	Super::BeginPlay();
	
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AWaypoint::StaticClass(), Waypoints);
	MoveToWaypoints();
}

// Called every frame
void AGuardAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AGuardAI::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AGuardAI::MoveToWaypoints()
{
	AGuardAIController* GuardAIController = Cast<AGuardAIController>(GetController());

	if (GuardAIController)
	{
		if (CurrentWaypoint >= MaxWaypoint)
		{
			CurrentWaypoint = 1;
		}
		if (CurrentWaypoint <= Waypoints.Num())
		{
			for (AActor* Waypoint : Waypoints)
			{
				AWaypoint* WaypointItr = Cast<AWaypoint>(Waypoint);

				if (WaypointItr)
				{
					if (WaypointItr->GetWaypointOrder() == CurrentWaypoint)
					{
						GuardAIController->MoveToActor(WaypointItr, 5.0f);
						CurrentWaypoint++;
						break;
					}
				}
			}
		}
	}
}

