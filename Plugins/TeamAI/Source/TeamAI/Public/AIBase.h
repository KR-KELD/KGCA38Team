// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "TimerManager.h"
#include "PatrolPoint.h"

#include "AIBase.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOneDynamicMultiCastDelegateString, FString, msg);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOneDynamicMultiCastDelegateActor, AActor*, actor);

UCLASS()
class TEAMAI_API AAIBase : public ACharacter
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "KGCA_AI", Meta = (MakeEditWidget = true))
		class APatrolPoint* PatrolPoints;
public:
#pragma region BaseFunc
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "KGCA_AI")
		void AttackEnemy(AActor* EnemyActor);
	UFUNCTION(BlueprintCallable, Category = "KGCA_AI")
		void SetAIMove(float Speed, bool DesiredRot = true);
	UFUNCTION(BlueprintCallable, Category = "KGCA_AI")
		virtual void Patrol();
	UFUNCTION(BlueprintCallable, Category = "KGCA_AI")
		virtual void AIHit(AActor* AttackActor, float Damage);
	UFUNCTION(BlueprintCallable, Category = "KGCA_AI")
		virtual void AIDead();
	UFUNCTION(BlueprintCallable, Category = "KGCA_AI")
		virtual void AIRespawn();
	UFUNCTION(BlueprintCallable, Category = "KGCA_AI")
		virtual bool AIDeadCheck();
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "KGCA_AI")
		void AIReset();
	UFUNCTION()
		virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, 
			class AController* EventInstigator, class AActor* DamageCauser) override;

	UFUNCTION(BlueprintCallable, Category = "KGCA_AI")
		virtual void SetActorActive(bool IsActive);
	UFUNCTION()
		void DeadEvent();
	UFUNCTION()
		void HitEvent();
	UFUNCTION()
		void RespawnEvent(FString msg);
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KGCA_AI")
		FTimerHandle DeadTimer;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KGCA_AI")
		FTimerHandle HitTimer;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KGCA_AI")
		bool IsAIActive = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KGCA_AI")
		bool IsDead = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KGCA_AI")
		bool IsHit = false;
#pragma endregion
public:
	AAIBase();
	//호출은 BroadCast 바인드는 BindUFunction
	//캐릭터의 hit dead 델리게이트를 호춯하면 컨트롤러의 스테이트가 바뀌고
	//추가작업을 하려면 바인딩 해주면 된다 규칙은 스트링 oneparam
	UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, Category = "KGCA_AI")
		FOneDynamicMultiCastDelegateActor	HitDelegate;
	UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, Category = "KGCA_AI")
		FOneDynamicMultiCastDelegateString	DeadDelegate;
	UPROPERTY(BlueprintAssignable, BlueprintCallable, BlueprintReadWrite, Category = "KGCA_AI")
		FOneDynamicMultiCastDelegateString	RespawnDelegate;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
