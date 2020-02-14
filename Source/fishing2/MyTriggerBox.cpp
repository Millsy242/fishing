// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTriggerBox.h"
// include draw debug helpers header file
#include "DrawDebugHelpers.h"
#include "Myfishing2Character.h"
AMyTriggerBox::AMyTriggerBox()
{
}

void AMyTriggerBox::BeginPlay()
{
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &AMyTriggerBox::OnOverlapBegin);
	OnActorEndOverlap.AddDynamic(this, &AMyTriggerBox::OnOverlapEnd);

	DrawDebugBox(GetWorld(), GetActorLocation(), GetComponentsBoundingBox().GetExtent(), FColor::Green, true, -1, 0, 5);
}

void AMyTriggerBox::OnOverlapBegin(AActor* OverlappedActor, AActor* OtherActor)
{
	//if the overlapping actor is the specific actor we identified in the editor
	if (OtherActor && (OtherActor != this))// && OtherActor == SpecificActor)
	{
		

		if (Cast<AMyfishing2Character>(OtherActor) != nullptr)
		{
			auto other = Cast<AMyfishing2Character>(OtherActor);
			other->SetCanFish(true);
		}
	}
}

void AMyTriggerBox::OnOverlapEnd(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OtherActor && (OtherActor != this))// && OtherActor == SpecificActor)
	{
		
		if (Cast<AMyfishing2Character>(OtherActor) != nullptr)
		{
			auto other = Cast<AMyfishing2Character>(OtherActor);
			other->SetCanFish(false);
			
		}
		


	}
}
