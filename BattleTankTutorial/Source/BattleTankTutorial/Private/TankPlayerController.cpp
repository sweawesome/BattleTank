// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay(); // makes sure that the boilerplate code is called

	auto ControlledTank = GetControlledTank();

	if(!ControlledTank)
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possesing a tank"))
	else
		UE_LOG(LogTemp,Warning,TEXT("PlayerController possesing: %s"), *ControlledTank->GetName())


}
ATank* ATankPlayerController::GetControlledTank() const
{


	return Cast<ATank>(GetPawn());

}

