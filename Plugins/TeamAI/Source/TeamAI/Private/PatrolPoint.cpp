// Fill out your copyright notice in the Description page of Project Settings.


#include "PatrolPoint.h"

// Sets default values
APatrolPoint::APatrolPoint()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APatrolPoint::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APatrolPoint::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

FVector APatrolPoint::GetPatrolPoint()
{
	switch (PatrolType)
	{
		case EPatrolType::EPatrol_RandomPoint:
		{
			return GetActorLocation();
		}break;
		case EPatrolType::EPatrol_CirclePoints:
		{
			return GetCirclePoint();
		}break;
		case EPatrolType::EPatrol_RoundTripPoints:
		{
			return GetRoundTripPoint();
		}break;
		default:
		{
			return GetActorLocation();
		}break;
	}
}

FVector APatrolPoint::GetCirclePoint()
{
	DestIndex += Direction;
	if (DestIndex >= PatrolPoints.Num())
	{
		DestIndex = 0;
	}
	if (PatrolPoints.IsValidIndex(DestIndex))
	{
		return (PatrolPoints[DestIndex] + GetActorLocation());
	}
	return FVector::ZeroVector;
}

FVector APatrolPoint::GetRoundTripPoint()
{
	DestIndex += Direction;
	if (DestIndex >= PatrolPoints.Num() || DestIndex <= -1)
	{
		Direction *= -1;
		DestIndex += Direction * 2;
	}
	if (PatrolPoints.IsValidIndex(DestIndex))
	{
		return (PatrolPoints[DestIndex] + GetActorLocation());
	}
	return FVector::ZeroVector;
}