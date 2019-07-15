// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "CodeNameHouseAttackGameMode.h"
#include "CodeNameHouseAttackCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACodeNameHouseAttackGameMode::ACodeNameHouseAttackGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
