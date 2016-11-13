// Fill out your copyright notice in the Description page of Project Settings.

#include "MyBattleTank.h"
#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Error, TEXT("TankPlayerController missing pointer to ATank!"), )
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s"), *ControlledTank->GetName())
	}
}


ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
