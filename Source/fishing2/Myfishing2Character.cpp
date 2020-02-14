// Fill out your copyright notice in the Description page of Project Settings.


#include "Myfishing2Character.h"

void AMyfishing2Character::SetCanFish(bool fish)
{
	canFish = fish; 
	if (isFishing && !canFish)
	{
		isFishing = false;
	}
}

void AMyfishing2Character::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Fishing", IE_Pressed, this, &AMyfishing2Character::F_KeyPressed);
	PlayerInputComponent->BindAction("Fishing", IE_Released, this, &AMyfishing2Character::F_KeyReleased);


}

void AMyfishing2Character::F_KeyPressed()
{
	if(canFish && !isFishing)
		GetWorldTimerManager().SetTimer(fishingtimer, this, &AMyfishing2Character::AttemptToCatchFish, 1.0f, true, 0.0f);
}
void AMyfishing2Character::F_KeyReleased()
{
	GetWorldTimerManager().ClearTimer(fishingtimer);
	isFishing = false;
	fishing_count = 0;
}
void AMyfishing2Character::AttemptToCatchFish()
{
	if (fishing_count > max_fishing_count)
	{
		GetWorldTimerManager().ClearTimer(fishingtimer);
		isFishing = false;
		fishing_count = 0;
	}
	else if (canFish)
	{
		fishing_count++;
	//	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("fishing"));
		isFishing = true;
		
		if (rand() % 5 == 1)
		{
			numFish++;
		//	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("CAUGHT"));
			GetWorldTimerManager().ClearTimer(fishingtimer);
			fishing_count = 0; 

		}
	}
}
int AMyfishing2Character::GetNumFish()
{
	return numFish;
}