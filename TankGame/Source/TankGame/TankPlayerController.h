// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Tank.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class TANKGAME_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	virtual void BeginPlay() override;

	virtual void Tick( float DeltaTime ) override;

private:

	ATank* GetControlledTank() const;

	void AimTowardsCrosshair();

	bool GetSightRayHitLocation(FVector& OutHitLocation) const;

	///Legen hier fest wo unser wei�er aim redicle proportional zum bildschirm ist
	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5;  
	UPROPERTY(EditAnywhere)
	float CrossHairYLocation = 0.33333;


	bool GetLookLocation(FVector2D ScreenLocation, FVector& LookDirection) const;

};
