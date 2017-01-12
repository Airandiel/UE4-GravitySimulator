// Fill out your copyright notice in the Description page of Project Settings.

#include "GravitySymulator.h"
#include "Master.h"
#include "MyCube.h"
#include "specifications.h"
#include <vector>


// Sets default values
AMaster::AMaster()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMaster::BeginPlay()
{
	Super::BeginPlay();
	int mass=100;
	//for (int i = 0; i < 10; i++) {
	UWorld* const World = GetWorld();
	if (World)
	{
		AMyCube* const kubik = World->SpawnActor<AMyCube>(AMyCube::StaticClass());
		kubik->SetMass(50000);
		MassTotal += 50000;
		myArray.push_back(kubik);
		FVector Force(10, 10, 10);
		const FVector vel(0, 0, 0);
		myArray[CounterOfElements]->InitVelocity(vel);
		myArray[CounterOfElements]->SetLocation(FVector(0, 0, 0));
		specifications config(mass, myArray[CounterOfElements]->GetLocation(), Force);
		specs.push_back(config);
		specs[CounterOfElements].v = vel;
		CounterOfElements++;
		for (int i = 0; i < a; i++) {
			for (int j = 0; j < b; j++) {
				for (int k = 0; k < c; k++) {
					AMyCube* const kubik = World->SpawnActor<AMyCube>(AMyCube::StaticClass());

					//setting value of mass change for variable mass
					kubik->SetMass(mass);
					MassTotal += mass;
					//int index = i*b*c + j*c + k;

					myArray.push_back(kubik);
					FVector Force(10,10,10);
					const FVector vel(20, 20, 500);
					myArray[CounterOfElements]->InitVelocity(vel);
					myArray[CounterOfElements]->SetLocation(FVector(100 * i, 100 * j, 100 * k));
					specifications config(mass, myArray[CounterOfElements]->GetLocation(), Force);
					specs.push_back(config);
					specs[CounterOfElements].v = vel;

					//increase counter
					CounterOfElements++;
				}

			}
		}
		//sint previousCounter = CounterOfElements;
		for (int i = 0; i < 15; i++) {
			for (int j = 0; j < 5; j++) {
				for (int k = 0; k < 5; k++) {
					AMyCube* const kubik = World->SpawnActor<AMyCube>(AMyCube::StaticClass());

					//setting value of mass change for variable mass
					kubik->SetMass(mass);
					MassTotal += mass;
					//int index = i*b*c + j*c + k;

					myArray.push_back(kubik);
					FVector Force(10, 10, 10);
					const FVector vel(-200, -200, -20);
					myArray[CounterOfElements]->InitVelocity(vel);
					myArray[CounterOfElements]->SetLocation(FVector(1500+100 * i, 1500 + 100 * j, 1500 + 100 * k));

					specifications config(mass, myArray[CounterOfElements]->GetLocation(), Force);
					specs.push_back(config);
					specs[CounterOfElements].v = vel;

					//increase counter
					CounterOfElements++;
					/*FVector loc;
					loc= myArray[i*j*k + j*k + k]->GetLocation();
					loc.X = 2;
					loc.Y = 3;
					loc.Z = 98;*/
				}

			}
		}
		//World->SpawnActor<AMyCube>(SpawnParams);
	}

	//}


	
}

// Called every frame
void AMaster::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

	FVector MassCenter;

	//calculating Mass Center
	for (int i = 0; i < CounterOfElements; i++) {
		MassCenter.X += (float)(specs[i].loc.X * specs[i].m) / MassTotal;
		MassCenter.Y += (float)(specs[i].loc.Y * specs[i].m) / MassTotal;
		MassCenter.Z += (float)(specs[i].loc.Z * specs[i].m) / MassTotal;
	}


	//calculating forces 
	for (int i = 0; i < CounterOfElements; i++) {
		double r;
		r = sqrt(pow(MassCenter.X - specs[i].loc.X, 2) + pow(MassCenter.Y - specs[i].loc.Y, 2) + pow(MassCenter.Z - specs[i].loc.Z, 2));
		FVector R;
		R.X = specs[i].loc.X - MassCenter.X;
		R.Y = specs[i].loc.Y - MassCenter.Y;
		R.Z = specs[i].loc.Z - MassCenter.Z;
		specs[i].F.X = (R.X*G*specs[i].m*MassTotal) / pow(r, 3);
		specs[i].F.Y = (R.Y*G*specs[i].m*MassTotal) / pow(r, 3);
		specs[i].F.Z = (R.Z*G*specs[i].m*MassTotal) / pow(r, 3);
		specs[i].v.X += (specs[i].F.X / specs[i].m);
		specs[i].v.Y += (specs[i].F.Y / specs[i].m);
		specs[i].v.Z += (specs[i].F.Z / specs[i].m);
		/*FVector vel;
		vel.X= specs[i].F.X / specs[i].m;
		vel.Y = specs[i].F.Y / specs[i].m;
		vel.Z = specs[i].F.Z / specs[i].m;*/
		myArray[i]->SetVelocity(specs[i].v);
	}

}

