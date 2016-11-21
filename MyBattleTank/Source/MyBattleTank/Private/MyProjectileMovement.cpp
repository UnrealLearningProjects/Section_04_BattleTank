// Fill out your copyright notice in the Description page of Project Settings.

#include "MyBattleTank.h"
#include "MyProjectileMovement.h"


// Sets default values for this component's properties
UMyProjectileMovement::UMyProjectileMovement()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UMyProjectileMovement::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UMyProjectileMovement::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

