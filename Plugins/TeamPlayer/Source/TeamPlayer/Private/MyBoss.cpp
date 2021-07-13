// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBoss.h"

// Sets default values
AMyBoss::AMyBoss()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyBoss::BeginPlay()
{
	Super::BeginPlay();
	pTarget = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	ChaseDist = 500.0f;
	AttackDist = 120.0f;
	JumpOrBreathDist = 700;
}

// Called every frame
void AMyBoss::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	GetDirAndDistOfCharacter();
	UKismetSystemLibrary::PrintString(GetWorld(), FString::SanitizeFloat(SavePlayerDist));
	if (AttackDist >= SavePlayerDist)
	{
		ECheckBossState = EBossState::EBS_Attack;
	}
	else if (ChaseDist >= SavePlayerDist)
	{
		ECheckBossState = EBossState::EBS_Chase;
	}
	else if (JumpOrBreathDist >= SavePlayerDist)
	{
		int temp = rand() % 1;
		UKismetSystemLibrary::PrintString(GetWorld(), FString::SanitizeFloat(temp));
		switch (temp)
		{
		case 0:
			ECheckBossState = EBossState::EBS_Breath;
			break;
		case 1:
			ECheckBossState = EBossState::EBS_JumpAttack;
			break;
		}

	}
	else
	{
		ECheckBossState = EBossState::EBS_IDLE;
	}


	BossStateAction(ECheckBossState);
}

// Called to bind functionality to input
void AMyBoss::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMyBoss::ChasePlayer()
{
	
	AddMovementInput(SavePlayerDir);

}
void AMyBoss::BossStateAction(EBossState bs)
{
	if (bs != EPrevBossState)
	{
		EPrevBossState = bs;
	}
	switch (bs)
	{
	case  EBossState::EBS_Chase:
		ChasePlayer();
		break;

	case  EBossState::EBS_Attack:
		AttackPlayer();
		break;
	}
}

void AMyBoss::GetDirAndDistOfCharacter()
{
	FVector FVTemp;
	if (pTarget == NULL)
	{
		UKismetSystemLibrary::PrintString(GetWorld(), TEXT("Target is NULL"));
		return;
	}
	FVTemp = pTarget->GetActorLocation();
	FVTemp = FVTemp - GetActorLocation();

	SavePlayerDist = FVTemp.Size();

	SavePlayerDir = FVTemp;
	SavePlayerDir.Normalize();



}

void AMyBoss::AttackPlayer()
{

}