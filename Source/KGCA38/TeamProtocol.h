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


UENUM(BlueprintType)
enum class EAIType : uint8
{
	EMonster UMETA(DisplayName = "Monster"),
	ENPC UMETA(DisplayName = "Npc"),
	EPlayer UMETA(DisplayName = "Player"),
	EBoss UMETA(DisplayName = "Boss"),
};

USTRUCT(Atomic, BlueprintType)
struct FCharacterDataStruct
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EAIType Type;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float HP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Damage;
};