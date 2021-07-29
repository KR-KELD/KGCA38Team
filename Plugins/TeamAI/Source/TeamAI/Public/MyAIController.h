// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Hearing.h"
#include "Perception/AISenseConfig_Sight.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Math/UnrealMathUtility.h"
#include "Kismet/KismetMathLibrary.h"
#include "AIDataStruct.h"
#include "AIBase.h"

#include "MyAIController.generated.h"
/**
 * 
 */



UCLASS()
class TEAMAI_API AMyAIController : public AAIController
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "KGCA_AI")
		class UBlackboardData* BBOject;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "KGCA_AI")
		class UBehaviorTree* BTObject;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "KGCA_AI")
		FName SelfActor = "SelfActor";
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "KGCA_AI")
		FName TargetActor = "TargetActor";
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "KGCA_AI")
		FName DestLocation = "DestLocation";
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "KGCA_AI")
		FName TargetLocation = "TargetLocation";
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "KGCA_AI")
		FName BBAIState = "AIState";
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "KGCA_AI")
		FName BattleState = "BattleState";
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "KGCA_AI")
		FName BBIsBBDead = "IsDead";
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "KGCA_AI")
		FName BBIsAttackReady = "IsAttackReady";
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "KGCA_AI")
		FName HasPatrolPoint = "HasPatrolPoint";
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "KGCA_AI")
		FString AIState = "State_Idle";
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "KGCA_AI")
		bool IsAttackReady = true;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "KGCA_AI")
		bool IsHit = false;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "KGCA_AI")
		bool IsDead = false;

private:
	UPROPERTY()
		class UAISenseConfig_Sight* SightConfig;
	UPROPERTY()
		class UAISenseConfig_Hearing* HearingConfig;
public:
	UPROPERTY(EditAnyWhere, BlueprintReadWrite)
		FAIDataStruct AIData;
public:
	virtual void OnPossess(APawn* InPawn) override;
	AMyAIController();
	UFUNCTION(BlueprintCallable, Category = "KGCA_AI")
		void UpdatePerceptionData();
	UFUNCTION(BlueprintCallable, Category = "KGCA_AI")
		void SetSenseOption(float SightRadius, float SightLoseRadius, float SightFov, float HearingRange, float Age);

	UFUNCTION(BlueprintCallable, Category = "KGCA_AI")
	void AttackReady(bool value);

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "KGCA_AI")
		FString StateSelect(AAIBase* AIBase);
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "KGCA_AI")
		FString BattleSelect(AAIBase* AIBase);
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "KGCA_AI")
		void SetAIState(const FString& StartState);
	UFUNCTION(BlueprintCallable, Category = "KGCA_AI")
	void UpdateState(FString State);

	UFUNCTION(BlueprintCallable, Category = "KGCA_AI")
	void HitCall(AActor* AttackActor);

	UFUNCTION(BlueprintCallable, Category = "KGCA_AI")
	void DeadCall(FString msg);

	UFUNCTION(BlueprintCallable, Category = "KGCA_AI")
	void RespawnCall(FString msg);

};
