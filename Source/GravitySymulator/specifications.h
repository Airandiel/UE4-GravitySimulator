// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
/**
 * 
 */
class GRAVITYSYMULATOR_API specifications
{
public:
	int m; //mass
	FVector loc; //location
	FVector F; //force
	FVector a; //acceleration
	FVector v; //velocity


	specifications();
	specifications(int mass, FVector location, FVector force) {
		m = mass;
		loc = location;
		F = force;
	};
	~specifications();

};
