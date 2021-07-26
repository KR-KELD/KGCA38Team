// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MainAIBase.h"
#include "MainAIMonster.generated.h"

/**
 * 
 */
UCLASS()
class KGCA38_API AMainAIMonster : public AMainAIBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KGCA_AI")
		bool IsDayMonster = true;
};
