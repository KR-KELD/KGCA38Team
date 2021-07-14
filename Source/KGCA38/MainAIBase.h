// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIBase.h"
#include "TeamProtocol.h"

#include "MainAIBase.generated.h"

/**
 * 
 */
UCLASS()
class KGCA38_API AMainAIBase : public AAIBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KGCA_AI")
		FCharacterDataStruct CharacterInfo;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KGCA_AI")
		int Code;
	virtual bool AIDeadCheck() override;
	virtual void AIHit(float Damage) override;
	UFUNCTION()
		virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser) override;
};