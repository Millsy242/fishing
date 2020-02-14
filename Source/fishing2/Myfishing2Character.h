// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "fishing2Character.h"
#include "Components/InputComponent.h"
#include "Myfishing2Character.generated.h"

/**
 * 
 */
UCLASS()
class FISHING2_API AMyfishing2Character : public Afishing2Character
{
	GENERATED_BODY()

public:
	void SetCanFish(bool fish); 


	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		int numFish = 0;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		bool isFishing = false;
	UPROPERTY(BlueprintReadOnly, VisibleAnywhere)
		bool canFish = false;

	int GetNumFish(); 

	bool getcanFish()
	{
		return canFish; 
	}

	bool getisFishing()
	{
		return isFishing;
	}

protected:
	void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override; 

	void F_KeyPressed();
	void F_KeyReleased();

	void AttemptToCatchFish();

private:
	
	

	int fishing_count = 0; 
	const int max_fishing_count = 5; 
	 
	FTimerHandle fishingtimer; 
};
