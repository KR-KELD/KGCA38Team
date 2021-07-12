// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MyAIController.h"
#include "MainAIController.generated.h"

/**
 * 
 */
UCLASS()
class KGCA38_API AMainAIController : public AMyAIController
{
	GENERATED_BODY()
public:
	AMainAIController();

public:
	UFUNCTION(BlueprintCallable, Category = "KGCA_AI")
		void AIPerceptionUpdate(AActor* Actor, FAIStimulus Info);
	
};
