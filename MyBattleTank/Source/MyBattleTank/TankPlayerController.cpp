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

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	AimAtReticule();
}



ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}



void ATankPlayerController::AimAtReticule()
{
	if (!GetControlledTank()){ return; }

	FVector HitLocation; // OUT Parameter
	if (GetSightRayHitLocation(HitLocation))
	{

	}
	// Get world location of linetrace through crosshair
	//it it hits landscape
		//tell controlled tank to aim at this point
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	HitLocation = FVector(1.0);
	return false;
}