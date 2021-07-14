// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "MyBoss.generated.h"

UENUM(BlueprintType)
enum class EBossState : uint8
{
	EBS_IDLE UMETA(DisplayName = "Idle"),
	EBS_Chase UMETA(DisplayName = "Chase"),
	EBS_Attack UMETA(DisplayName = "Attack"),
	EBS_JumpAttack UMETA(DisplayName = "JumpAttack"),
	EBS_Breath UMETA(DisplayName = "Breath"),
};

UCLASS()
class TEAMPLAYER_API AMyBoss : public ACharacter
{
	GENERATED_BODY()


public:
	ACharacter* pTarget;
	float		SavePlayerDist;
	FVector		SavePlayerDir;
	FVector 	SavePlayerLoc;
	float		SaveDeltaTime;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerDistCheck)
	float		ChaseDist;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerDistCheck)
	float		AttackDist;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerDistCheck)
		float	JumpOrBreathDist;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerDistCheck)
		bool	bBossChase;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PlayerDistCheck)
		bool	bBossJumpAttack;

	UPROPERTY(EditAnywhere)
		EBossState	ECheckBossState;
	UPROPERTY(EditAnywhere)
		EBossState	EPrevBossState;

public:
	// Sets default values for this character's properties
	AMyBoss();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	//for test
	void ChasePlayer();
	void AttackPlayer();
	void JumpAttack();
	void BreathAttack();
	void GetDirAndDistOfCharacter();
	void BossStateAction(EBossState bs);
};

