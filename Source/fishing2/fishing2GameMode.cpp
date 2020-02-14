// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "fishing2GameMode.h"
#include "fishing2Character.h"
#include "UObject/ConstructorHelpers.h"

Afishing2GameMode::Afishing2GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
