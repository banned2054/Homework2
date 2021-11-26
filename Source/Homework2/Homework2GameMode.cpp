// Copyright Epic Games, Inc. All Rights Reserved.

#include "Homework2GameMode.h"
#include "Homework2Character.h"
#include "UObject/ConstructorHelpers.h"

AHomework2GameMode::AHomework2GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
