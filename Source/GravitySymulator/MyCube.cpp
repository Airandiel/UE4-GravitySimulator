// Fill out your copyright notice in the Description page of Project Settings.

#include "GravitySymulator.h"
#include "MyCube.h"

/*AMyCube::AMyCube(const class FPostConstructInitializeProperties& PCIP)
	: Super(PCIP)
{
	MyBlock = PCIP.CreateAbstractDefaultSubobject<UStaticMeshComponent>(this, TEXT("SolidBlock"));

	static ConstructorHelpers::FObjectFinder <UStaticMesh>StaticMesh(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	static ConstructorHelpers::FObjectFinder<UMaterial> Material(TEXT("MaterialInstanceConstant'/Game/StarterContent/Materials/M_Basic_Floor.M_Basic_Floor'"));

	MyBlock->SetStaticMesh(StaticMesh.Object);
	MyBlock->SetMaterial(0, Material.Object);
}*/
// Sets default values
AMyCube::AMyCube()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> CubeMesh(TEXT("/Game/StarterContent/Shapes/Shape_Cube.Shape_Cube"));
	Cube= CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Cube0"));
	Cube->SetStaticMesh(CubeMesh.Object);
	Cube->BodyInstance.SetCollisionProfileName(UCollisionProfile::PhysicsActor_ProfileName);
	Cube->SetSimulatePhysics(true);
	Cube->SetEnableGravity(false);
	Cube->SetCastShadow(false);
	Cube->SetMassOverrideInKg(TEXT("Cube0"), 100, true);
	Cube->SetAngularDamping(0);
	Cube->SetLinearDamping(0);
	//FVector newVel(2, 2, 2);
	//Cube->SetPhysicsLinearVelocity(newVel, false, TEXT("Cube0"));
	Cube->BodyInstance.MassScale = 3.5f;
	Cube->BodyInstance.MaxAngularVelocity = 800.0f;
	Cube->SetNotifyRigidBodyCollision(true);
	RootComponent = Cube;
}

// Called when the game starts or when spawned
void AMyCube::BeginPlay()
{
	/*FVector newVel(2, 2, 2);
	FRotator newRot(0, 0, 0);
	SpawnActor(newVel, newRot, NULL, Instigator, true);*/
	Super::BeginPlay();
	
}

// Called every frame
void AMyCube::Tick( float DeltaTime )
{
	Super::Tick(DeltaTime);
	FVector NewLocation = GetActorLocation();
	float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	NewLocation.Z += DeltaHeight * 20.0f;       //Scale our height by a factor of 20
	RunningTime += DeltaTime;
	SetActorLocation(NewLocation);
	//FVector newVel(20, 20, 20);
	//Cube->SetPhysicsLinearVelocity(newVel, false, TEXT("Cube0"));

}

//void AMyCube::InitVelocity(const FVector& vel) {
//
//	Cube->SetPhysicsLinearVelocity(vel, false, TEXT("Cube0"));
//}


//void AMyCube::SetLoc(FVector loc)
//{
	/*float DeltaHeight = (FMath::Sin(RunningTime + DeltaTime) - FMath::Sin(RunningTime));
	NewLocation.Z += DeltaHeight * 20.0f;       //Scale our height by a factor of 20
	RunningTime += DeltaTime;*/
	//Super::SetLoc(loc);
	//SetActorLocation(loc);
	/*FVector newVel(2, 2, 2);
	Cube->SetPhysicsLinearVelocity(newVel, false, TEXT("Cube0"));
	Super::Tick(DeltaTime);*/

//}*/
