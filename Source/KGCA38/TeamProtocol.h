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
	EEventMonster UMETA(DisplayName = "EventMonster"),
	ENPC UMETA(DisplayName = "Npc"),
	EPartner UMETA(DisplayName = "Partner"),
	EPlayer UMETA(DisplayName = "Player"),
	EBoss UMETA(DisplayName = "Boss"),
};

UENUM(BlueprintType)
enum class EControlMode : uint8
{
	EControl_None UMETA(DisplayName = "None"),
	EControl_Accompany UMETA(DisplayName = "Accompany"),
	EControl_Accompnay_Aggressive UMETA(DisplayName = "Accompany_Aggressive"),
	EControl_Waiting_Aggressive UMETA(DisplayName = "Waiting_Aggressive"),
};


USTRUCT(Atomic, BlueprintType)
struct FCharacterDataStruct
{
	GENERATED_USTRUCT_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FName Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		EAIType Type;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float HP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Damage;
};