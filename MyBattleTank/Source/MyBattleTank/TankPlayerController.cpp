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
		UE_LOG(LogTemp, Warning, TEXT("HitLocation is: %s"), *HitLocation.ToString())
	}
}


bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	// Find the crosshair position in pixel coordinates
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);
	FVector2D ScreenLocation = FVector2D( ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation );

	// "De-prpject" the screen position of the crosshair to a world direction
	FVector LookDirection;
	FVector WorldLocation;
	if (DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WorldLocation, LookDirection)) 
	{
		// Line-trace along that look direction, and see what we hit(up to the max range)
		GetLookVectorHitLocation(HitLocation, LookDirection);
	}
	return true;
}

bool ATankPlayerController::GetLookVectorHitLocation(FVector & HitLocation, FVector LookDirection) const
{
	FHitResult TraceHitResult;
	FVector StartLocation = PlayerCameraManager->GetCameraLocation();
	FVector EndLocation = StartLocation + (LookDirection * LineTraceRange);
	if(GetWorld()->LineTraceSingleByChannel(
		TraceHitResult,
		StartLocation,
		EndLocation,
		ECollisionChannel::ECC_Visibility)
		)
	{ 
		HitLocation = TraceHitResult.Location;
		return true;
	}
		HitLocation = FVector(0);
		return false;
}
