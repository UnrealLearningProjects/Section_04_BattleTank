// Fill out your copyright notice in the Description page of Project Settings.

#include "MyBattleTank.h"
#include "Tank.h"
#include "MyTankAIController.h"

void AMyTankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("AIController NOT posssesing tank!"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("ControlledTank: %s"), *ControlledTank->GetName())
	}
	
	
	auto PlayerTank = GetPlayerTank();
	if (!PlayerTank)
	{
		UE_LOG(LogTemp, Error, TEXT("PlayerTank NOT found!"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Found PlayerTank: %s"), *PlayerTank->GetName())
	}
}



ATank * AMyTankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}



ATank * AMyTankAIController::GetPlayerTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}

void AMyTankAIController::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	GetControlledTank()->AimAt(GetPlayerTank()->GetActorLocation());
}
