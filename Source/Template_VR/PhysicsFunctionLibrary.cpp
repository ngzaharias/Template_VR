// Fill out your copyright notice in the Description page of Project Settings.


#include "PhysicsFunctionLibrary.h"

#include "Components/PrimitiveComponent.h"

bool UPhysicsFunctionLibrary::GetNearestOverlappingActor
(
	const UPrimitiveComponent* PrimitiveComponent,
	AActor*& OutActor,
	const TSubclassOf<AActor> ActorFilter /*= nullptr*/,
	const TSubclassOf<UInterface> InterfaceFilter /*= nullptr*/
)
{
	TSet<AActor*> OverlappingActors;
	PrimitiveComponent->GetOverlappingActors(OverlappingActors);

	AActor* ClosestActor = nullptr;
	float ClosestSqr = BIG_NUMBER;
	const FVector OriginLocation = PrimitiveComponent->GetComponentLocation();
	for (AActor* Actor : OverlappingActors)
	{
		const FVector ActorLocation = Actor->GetActorLocation();
		const float DistanceSqr = FVector::DistSquared(ActorLocation, OriginLocation);
		if (DistanceSqr < ClosestSqr)
		{
			ClosestActor = Actor;
			ClosestSqr = DistanceSqr;
		}
	}

	if (!ClosestActor)
		return false;

	OutActor = ClosestActor;
	return true;
}
