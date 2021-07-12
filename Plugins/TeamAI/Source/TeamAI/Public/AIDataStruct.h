// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIDataStruct.generated.h"
/**
 * 
 */
class TEAMAI_API AIDataStruct
{
public:
	AIDataStruct();
	~AIDataStruct();
};

USTRUCT(Atomic, BlueprintType)
struct FAIDataStruct
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int AIObjectCode;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float WalkSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float RunSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float PatrolRange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float AttackRange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float LookRange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float LostRange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float SightAngle;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float HearingRange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float PerceptionAge;
};