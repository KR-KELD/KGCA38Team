// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MainAIBase.h"
#include "MainAINPC.generated.h"

/**
 * 
 */
UCLASS()
class KGCA38_API AMainAINPC : public AMainAIBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "KGCA_AI")
	int DialogueCode = -1;
};
