// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TeamProtocol.generated.h"
/**
 * 
 */
class KGCA38_API TeamProtocol
{
public:
	TeamProtocol();
	~TeamProtocol();
};


USTRUCT(Atomic, BlueprintType)
struct FCharacterDataStruct
{
	GENERATED_USTRUCT_BODY()
public:
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	//	int TeamNum;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float HP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Damage;
};