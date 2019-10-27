// Fill out your copyright notice in the Description page of Project Settings.


#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("BeginPlay Method works"));

	auto ControlledTank = GetControlledTank();

	if (ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("Got %s"), *ControlledTank->GetName());
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("No Pawn found"));
	}

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

	FVector OutHitLocation;

	if (GetSightRayHitLocation(OutHitLocation)) //OutParameter Funktion die wir unten selbst erstellt haben
	{
		GetSightRayHitLocation(OutHitLocation);
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *OutHitLocation.ToString());
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const //hier erstellen wir eine Methode mit out parameter Funktion
{
	int32 ViewportSizeX, ViewportSizeY;
	GetViewportSize(ViewportSizeX, ViewportSizeY);  //Gibt die Größe des Bildschirms wieder

	//Gibt einen 2D vector zurück der genau aufs aiming redicle geht
	auto ScreenLocation = FVector2D(ViewportSizeX * CrossHairXLocation, ViewportSizeY * CrossHairYLocation);

	///Macht: Wo guckt der weiße aiming redicle hin (in Vectorform und von außen, nicht vom Spieler gesehen)
	FVector LookDirection; //out parameter
	if (GetLookLocation(ScreenLocation, LookDirection))
	{
		UE_LOG(LogTemp, Warning, TEXT("HitLocation: %s"), *LookDirection.ToString());
	}

	return true;
}

bool ATankPlayerController::GetLookLocation(FVector2D ScreenLocation, FVector& LookDirection) const //
{
	FVector CameraWorldLocation;
	return DeprojectScreenPositionToWorld(
		ScreenLocation.X, //Die X Koordianten von unserem 2D Vector zum aiming redicle
		ScreenLocation.Y, //Die Y Koordianten von unserem 2D Vector zum aiming redicle
		CameraWorldLocation, //Brauchen wir nicht, musst aber wegen der syntax gemacht werden
		LookDirection); //Out Parameter
}





// allgemeine Fragen: const