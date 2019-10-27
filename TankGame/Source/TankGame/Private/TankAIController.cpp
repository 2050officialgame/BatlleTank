// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

	auto AIControlledTank = GetControlledTank();
	if (!AIControlledTank) { return; }

	auto PlayerControlledTank = GetPlayerControlledTank();
	if (PlayerControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("%s identified %s as enemy tank"), *AIControlledTank->GetName(), *PlayerControlledTank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("%s couldn´t identify who is the enemy tank"), *AIControlledTank->GetName());
	}

}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn()); //Das Cast gibt es nur weil es möglicherweiße mehrere AI Tanks gibt und das returnd dann alle Pawns der AI kontrollierten Tanks
}

ATank* ATankAIController::GetPlayerControlledTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}

