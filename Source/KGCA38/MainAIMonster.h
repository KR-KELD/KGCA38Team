// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MainAIBase.h"
#include "Components/WidgetComponent.h"
#include "Components/CapsuleComponent.h"
#include "MainAIMonster.generated.h"

/**
 * 
 */
UCLASS()
class KGCA38_API AMainAIMonster : public AMainAIBase
{
	GENERATED_BODY()
public:
	AMainAIMonster();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KGCA_AI")
		UWidgetComponent* HealthBar;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KGCA_AI")
		bool IsDayMonster = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KGCA_AI")
		FTimerHandle HealthBarTimer;
	virtual bool AIDeadCheck() override;
	virtual void AIHit(AActor* AttackActor, float Damage) override;
};
