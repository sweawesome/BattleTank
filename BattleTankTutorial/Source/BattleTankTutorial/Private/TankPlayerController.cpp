// Fill out your copyright notice in the Description page of Project Settings.

#include "Math/Vector.h"
#include "Containers/UnrealString.h"
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

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{

	return Cast<ATank>(GetPawn());

}

void ATankPlayerController::AimTowardsCrosshair()
{

	if (!GetControlledTank()) { return; }

	FVector HitLocation; // Out parameter


	if (GetSightRayHitLocation(HitLocation)) // HitLocation is out, Has "side-effect", is oging to line trace
	{
			//if  it hits the landscape
			//tell tcontrolled tank to aim at this point
	}


}

//Get World Location if linetrace through crosshair, true if hits landscape
bool ATankPlayerController::GetSightRayHitLocation(FVector &OutHitLocation) const
{
	//Find the crosshair position
	int32 ViewportSizeX = 13, ViewportSizeY = 12;
	GetViewportSize(ViewportSizeX, ViewportSizeY);

	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);
	
	//De-project the screen positoon of the crosshair to a world direction
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		UE_LOG(LogTemp, Warning, TEXT("Crosshair at %s"), *LookDirection.ToString())
	}
		//Line-trace along that look direction, and see what we hit(up to a max range)
		//Yes? change outhitlocation
		//NO? do nothing
		return true;
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector CameraWorldLocation;

	return DeprojectScreenPositionToWorld(
		ScreenLocation.X, 
		ScreenLocation.Y,
		CameraWorldLocation,
		LookDirection
	);
		
}

