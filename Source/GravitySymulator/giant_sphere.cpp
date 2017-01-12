// Fill out your copyright notice in the Description page of Project Settings.

#include "GravitySymulator.h"
#include "giant_sphere.h"
#include "MyCube.h"
#include <vector>


// Sets default values
Agiant_sphere::Agiant_sphere()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true; 
	

}

// Called when the game starts or when spawned
void Agiant_sphere::BeginPlay(){

	Super::BeginPlay();

	//for (int i = 0; i < 10; i++) {
		UWorld* const World = GetWorld();
		if (World)
		{
			FVector newLoc(2, 2, 2);
			FRotator newRot(0, 0, 0);
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = Instigator;
			SpawnParams.Name = "hahaha";
			TSubclassOf<class AMyCube> majkubik;
		
			/*AMyCube* const kubik = World->SpawnActor<AMyCube>(majkubik, newLoc, newRot, SpawnParams);
			if (kubik)
			{
				// find launch direction
				const FVector vel(20, 20, 20);
				kubik->InitVelocity(vel);
			}*/
			std::vector <AMyCube*> myArray;
			for (int i = 0; i < 10; i++) {
				for (int j = 0; j < 10; j++) {
					for (int k = 0; k < 10; k++) {
						AMyCube* const kubik = World->SpawnActor<AMyCube>(AMyCube::StaticClass());
						myArray.push_back(kubik);
						const FVector vel(0, 0, 0);
						i++;
						j++;
						k++;
						myArray[i*j*k + j*k + k]->InitVelocity(vel);
						myArray[i*j*k + j*k + k]->SetLocation(FVector(100 * i, 100*j, 100*k));
						i--;
						j--;
						k--;
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
void Agiant_sphere::Tick( float DeltaTime )
{
	Super::Tick(DeltaTime);
	/*FVector newLoc(50*n, 50*n,50*n);
	FRotator newRot(0, 0, 0);
	FActorSpawnParameters SpawnParams;
	SpawnParams.Owner = this;
	SpawnParams.Instigator = Instigator;
	SpawnParams.Name = "hahaha";
	UWorld* const World = GetWorld();
	TSubclassOf<class AMyCube> majkubik;
	/*AMyCube* const kubik = World->SpawnActor<AMyCube>(majkubik, newLoc, newRot, SpawnParams);*/
	/*if (World)
	{
		//World->SpawnActor<AMyCube>(majkubik, newVel, newRot, SpawnParams);
		World->SpawnActor<AMyCube>(AMyCube::StaticClass());
	}*/
	//AMyCube* const kubik = World->SpawnActor<AMyCube>(AMyCube::StaticClass());
	//kubik::SetLoc(newLoc);
}

