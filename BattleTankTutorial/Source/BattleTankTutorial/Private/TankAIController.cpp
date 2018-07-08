// Fill out your copyright notice in the Description page of Project Settings.

#include "GameFramework/Actor.h"
#include "Engine/World.h"
#include "TankAIController.h"


void ATankAIController::BeginPlay()
{
	Super::BeginPlay(); // makes sure that the boilerplate code is called

	auto Playertank = GetPlayerTank();

	if (!Playertank)
		UE_LOG(LogTemp, Warning, TEXT("AIController not possesing a tank"))
	else
		UE_LOG(LogTemp, Warning, TEXT("AI possesing: %s"), *Playertank->GetName())


}

ATank * ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}

