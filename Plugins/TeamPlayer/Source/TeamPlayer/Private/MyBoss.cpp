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
	ChaseDist = 700.0f;
	AttackDist = 230.0f;
	JumpOrBreathDist = 1000;
	bBossChase = false;
}

// Called every frame
void AMyBoss::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	GetDirAndDistOfCharacter();
	//UKismetSystemLibrary::PrintString(GetWorld(), FString::SanitizeFloat(SavePlayerDist));
	SaveDeltaTime = DeltaTime;
	if (AttackDist >= SavePlayerDist)
	{
		ECheckBossState = EBossState::EBS_Attack;
	}

	else if (JumpOrBreathDist >= SavePlayerDist && EPrevBossState != EBossState::EBS_Chase /*||  EPrevBossState != EBossState::EBS_IDLE)*/)
	{
		int temp = rand() % 2;
		UKismetSystemLibrary::PrintString(GetWorld(), FString::SanitizeFloat(temp));
		switch (1)
		{
		case 0:
			ECheckBossState = EBossState::EBS_Breath;
			break;
		case 1:
			ECheckBossState = EBossState::EBS_JumpAttack;
			SavePlayerLoc = pTarget->GetActorLocation();
			break;
		}

	}
	else if (ChaseDist >= SavePlayerDist)
	{
		//FRotator temp2 = UKismetMathLibrary::Conv_VectorToRotator(GetCharacterMovement()->GetCurrentAcceleration());
		//FRotator temp = FMath::RInterpTo(GetActorRotation(), temp2, DeltaTime, 10.0f);
		//float Yaw, Pitch, Roll;
		//UKismetMathLibrary::BreakRotator(GetControlRotation(), Roll, Pitch, Yaw);
		//FRotator breakRotZ = UKismetMathLibrary::MakeRotator(0, 0, Yaw);
		//FVector FVec = UKismetMathLibrary::GetForwardVector(breakRotZ);
		//SetActorRotation(temp);
		
		ECheckBossState = EBossState::EBS_Chase;
		bBossChase = true;
		//JumpAttack();
	}
	else if(bBossChase == false)
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
	case EBossState::EBS_JumpAttack:
		JumpAttack();
		break;
	case EBossState::EBS_Breath:
		BreathAttack();
		break;
	default:
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

void AMyBoss::JumpAttack()
{

	UKismetSystemLibrary::PrintString(GetWorld(), SavePlayerLoc.ToString());
	float Roll, Pitch, Yaw;
	FVector TargetXY, SelfXY;
	UKismetMathLibrary::BreakVector(pTarget->GetActorLocation(), Roll, Pitch, Yaw);
	TargetXY = UKismetMathLibrary::MakeVector(Roll, Pitch, 0);
	UKismetMathLibrary::BreakVector(GetActorLocation(), Roll, Pitch, Yaw);
	SelfXY = UKismetMathLibrary::MakeVector(Roll, Pitch, 0);
	
	SavePlayerLoc = FMath::VInterpTo(SelfXY, TargetXY, SaveDeltaTime, 10.0f);
	
	SetActorLocation(SavePlayerLoc);
	
}

void AMyBoss::BreathAttack()
{

}