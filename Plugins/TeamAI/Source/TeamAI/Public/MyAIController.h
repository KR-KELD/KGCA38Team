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
		FName BBIsHit = "IsHit";
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "KGCA_AI")
		FName BBIsBBDead = "IsDead";
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "KGCA_AI")
		FString AIState = "State_Idle";
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "KGCA_AI")
		bool IsHit = false;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "KGCA_AI")
		bool IsDead = false;

private:
	UPROPERTY()
		class UAISenseConfig_Sight* SightConfig;
	UPROPERTY()
		class UAISenseConfig_Hearing* HearingConfig;
private:
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		float SightRadius = 3000.0f;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		float SightLoseRadius = SightRadius + 500.0f;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		float SightAge = 1.0f;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		float SightFOV = 60.0f;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		float HearingRange = 4000.0f;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		float HearingAge = 1.0f;
public:
	virtual void OnPossess(APawn* InPawn) override;
	AMyAIController();
	UFUNCTION(BlueprintCallable, Category = "KGCA_AI")
		void UpdateAIPerception();
	UFUNCTION(BlueprintCallable, Category = "KGCA_AI")
		void SetSenseSightOption(float Radius, float LoseRadius, float Age, float FOV);
	UFUNCTION(BlueprintCallable, Category = "KGCA_AI")
		void SetSenseHearingOption(float Range, float Age);
	//UFUNCTION(BlueprintCallable, Category = "KGCA_AI")
	//	virtual void ChangeState(FString State);


	UFUNCTION(BlueprintCallable, Category = "KGCA_AI")
	void AIPerceptionUpdate(AActor* Actor, FAIStimulus Info);

	UFUNCTION(BlueprintCallable, Category = "KGCA_AI")
	void UpdateState(FString State);

	UFUNCTION()
	void HitCall(FString msg);

	UFUNCTION()
	void DeadCall(FString msg);

};
