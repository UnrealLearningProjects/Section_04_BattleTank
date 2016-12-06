// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/NavMovementComponent.h"
#include "TankMovementComponent.generated.h"

class UTankTrack;

/**
 * 
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class MYBATTLETANK_API UTankMovementComponent : public UNavMovementComponent
{
	GENERATED_BODY()
	
public:
	UFUNCTION(Blueprintcallable, Category = Setup)
	void IntendMoveForward(float Throw);

	UFUNCTION(Blueprintcallable, Category = Setup)
	void IntendTurnRight(float Throw);

	UFUNCTION(Blueprintcallable, Category = Setup)
	void Initialise(UTankTrack* LeftTrack, UTankTrack* RightTrack);
	
private:
	UTankTrack* LeftTrack = nullptr;
	UTankTrack* RightTrack = nullptr;
};
