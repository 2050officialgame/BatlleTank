// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("BeginPlay Method works"));

	auto TankController = GetControlledTank();

	if (TankController)
	{
		UE_LOG(LogTemp, Warning, TEXT("Got %s"), *TankController->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No Pawn found"));
		return;
	}

}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}
