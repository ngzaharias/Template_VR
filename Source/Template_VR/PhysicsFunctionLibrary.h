// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PhysicsFunctionLibrary.generated.h"

class UPrimitiveComponent;

/**
 * 
 */
UCLASS()
class TEMPLATE_VR_API UPhysicsFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	/**
	 * Returns the nearest actor that the primitive component is overlapping.
	 * @param PrimitiveComponent	[in] The primitive to check for overlaps.
	 * @param OverlappingActors		[out] Returned list of overlapping actors.
	 * @param ActorFilter			[optional] If set, only returns actors of this class or subclasses.
	 * @param InterfaceFilter		[optional] If set, only returns actors of this class or subclasses.
	 */
	UFUNCTION(BlueprintCallable)
	static bool GetNearestOverlappingActor
	(
		const UPrimitiveComponent* PrimitiveComponent, 
		AActor*& OutActor, 
		const TSubclassOf<AActor> ActorFilter = nullptr, 
		const TSubclassOf<UInterface> InterfaceFilter = nullptr
	);
};
