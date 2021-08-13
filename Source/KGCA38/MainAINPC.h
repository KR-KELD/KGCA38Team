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
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "KGCA_AI")
		int Favorability = 0;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "KGCA_AI")
		int MaxFavorability = 100;
	UFUNCTION(BlueprintCallable, Category = "KGCA_AI")
		bool AddFavorability(int iFavorPoint);
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "KGCA_AI")
		bool FavorCompleteCheck();
};
