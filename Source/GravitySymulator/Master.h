// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include <vector>
#include "MyCube.h"
#include "specifications.h"
#include "GameFramework/Actor.h"
#include "Master.generated.h"

UCLASS()
class GRAVITYSYMULATOR_API AMaster : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMaster();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

private:
	std::vector <AMyCube*> myArray;
	std::vector <specifications> specs;
	//dimentions of cube
	const int a=10, b=10, c=10;
	long long int MassTotal = 0;
	int CounterOfElements = 0;
	//gravity constant
	/*struct G {
		double f = 6.6740831;
		int c = -11;
		double operator * (double val) {			
			val *= f*pow(10, c);
			return val;
		}
	};*/
	const double G = 6.67428e-11;

};
