// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "ItemData.generated.h"

UENUM(BlueprintType)
enum class ETestEnum : uint8
{
	TE_OptionA UMETA(DisplayName = "Food"),
	TE_OptionB UMETA(DisplayName = "Weapon"),
};

USTRUCT(Atomic, BlueprintType)
struct FItemData : public FTableRowBase
{
public:
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		int Code;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		ETestEnum ITemType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText Name;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Damage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Healing;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText Reference2D;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		FText Reference3D;
};
