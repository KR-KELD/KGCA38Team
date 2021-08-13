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
		FTimerHandle RespawnTimer;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KGCA_AI")
		FTransform RespawnTrans;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KGCA_AI")
		bool IsAIActive = true;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KGCA_AI")
		bool IsDead = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KGCA_AI")
		bool IsHit = false;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "KGCA_AI")
		bool IsRespawn = false;
#pragma endregion
public:
	AAIBase();
	//ȣ���� BroadCast ���ε�� BindUFunction
	//ĳ������ hit dead ��������Ʈ�� ȣ���ϸ� ��Ʈ�ѷ��� ������Ʈ�� �ٲ��
	//�߰��۾��� �Ϸ��� ���ε� ���ָ� �ȴ� ��Ģ�� ��Ʈ�� oneparam
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
