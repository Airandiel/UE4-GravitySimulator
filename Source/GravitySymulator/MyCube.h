// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "MyCube.generated.h"

UCLASS()
class GRAVITYSYMULATOR_API AMyCube : public AActor
{
	GENERATED_BODY()

		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Cube, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* Cube;

public:

	// static mesh

	//TSubobjectPtr<UStaticMeshComponent> MyBlock;

	
	// Sets default values for this actor's properties
	AMyCube();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;
	//virtual void SetLoc(FVector loc);
	virtual void InitVelocity(FVector vel) {
		Cube->SetPhysicsLinearVelocity(vel, false, TEXT("Cube0"));
	};
	virtual void SetLocation(FVector loc) {
		SetActorLocation(loc);
	};
	FVector GetLocation() {
		return Cube->GetComponentLocation();
	}
	virtual void SetMass(int mass) {
		Cube->SetMassOverrideInKg(TEXT("Cube0"), mass, true);
	}
	virtual void SetVelocity(FVector newVel) {
		Cube->SetPhysicsLinearVelocity(newVel, false);
	}
	float RunningTime;
};
