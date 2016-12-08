// Fill out your copyright notice in the Description page of Project Settings.

#include "MyBattleTank.h"
#include "Tank.h"
#include "MyTankAIController.h"

void AMyTankAIController::BeginPlay()
{
	Super::BeginPlay();
}


void AMyTankAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);

	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());
	
	if (PlayerTank)
	{
		MoveToActor(PlayerTank, AcceptanceRadius);

		ControlledTank->AimAt(PlayerTank->GetActorLocation());

		// Fire
		ControlledTank->Fire();
	}
	

	
}
