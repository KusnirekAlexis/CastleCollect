// Copyright Epic Games, Inc. All Rights Reserved.

#include "CastelCollectGameMode.h"
#include "CastelCollectPlayerController.h"
#include "CastelCollectCharacter.h"
#include "UObject/ConstructorHelpers.h"

ACastelCollectGameMode::ACastelCollectGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = ACastelCollectPlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	// set default controller to our Blueprinted controller
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerBPClass(TEXT("/Game/TopDown/Blueprints/BP_TopDownPlayerController"));
	if(PlayerControllerBPClass.Class != NULL)
	{
		PlayerControllerClass = PlayerControllerBPClass.Class;
	}
}