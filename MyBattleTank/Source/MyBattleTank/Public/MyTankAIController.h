// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "AIController.h"
#include "MyTankAIController.generated.h"

/**
 * 
 */
UCLASS()
class MYBATTLETANK_API AMyTankAIController : public AAIController
{
	GENERATED_BODY()
	
private:
	virtual void BeginPlay() override;
	ATank* GetControlledTank() const;
	ATank* GetPlayerTank() const;
	virtual void Tick(float DeltaSeconds) override;
};
