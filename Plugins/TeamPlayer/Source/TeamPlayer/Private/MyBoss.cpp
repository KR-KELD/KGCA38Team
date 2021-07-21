// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBoss.h"

// Sets default values
AMyBoss::AMyBoss()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UAnimMontage> JumpAttackMontage(TEXT("AnimMontage'/TeamPlayer/Boss/EnemyAnimation/FrostGiant/AM_JumpAttack.AM_JumpAttack'"));
	AM_JumpAttack = JumpAttackMontage.Object;

	static ConstructorHelpers::FObjectFinder<UAnimMontage> NormalAttackMontage(TEXT("AnimMontage'/TeamPlayer/Boss/EnemyAnimation/FrostGiant/AM_FGAttackmontage.AM_FGAttackmontage'"));
	AM_NormalAttack = NormalAttackMontage.Object;

}

// Called when the game starts or when spawned
void AMyBoss::BeginPlay()
{
	Super::BeginPlay();
	pTarget = UGameplayStatics::GetPlayerCharacter(GetWorld(), 0);
	ChaseDist = 700.0f;
	AttackDist = 300.0f;
	JumpOrBreathDist = 1000;
	bBossChase = false;
	iBossNormalAttackSplit = 0;
	iRageCount = 0;
	Damage = 0.0f;
	MaxHP = 1000.0f;
	HP = 1000.0f;
}

// Called every frame
void AMyBoss::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	GetDirAndDistOfCharacter();
	//UKismetSystemLibrary::PrintString(GetWorld(), FString::SanitizeFloat(SavePlayerDist));
	SaveDeltaTime = DeltaTime;
	if (iBossNormalAttackSplit >= 3)
	{
		iBossNormalAttackSplit = 0;
	}
	
	if (AttackDist >= SavePlayerDist && 
		ECheckBossState != EBossState::EBS_Breath &&
		ECheckBossState != EBossState::EBS_JumpAttack)
	{

		if (ECheckBossState != EBossState::EBS_Attack)
		{
			FRotator LookAtRot = LookAtPlayer();
			SetActorRotation(LookAtRot);
		}
		ECheckBossState = EBossState::EBS_Attack;
	}
	else if (ChaseDist >= SavePlayerDist &&
		ECheckBossState != EBossState::EBS_Breath &&
		ECheckBossState != EBossState::EBS_JumpAttack &&
		ECheckBossState != EBossState::EBS_Attack)
	{
		HitBackRate = 0.0f;
		AirBorneRate = 0.0f;
		ECheckBossState = EBossState::EBS_Chase;
		bBossChase = true;
	}
	else if (JumpOrBreathDist >= SavePlayerDist && 
		SavePlayerDist > 700.0f && 
		bBossChase == true &&
		ECheckBossState != EBossState::EBS_Breath &&
		ECheckBossState != EBossState::EBS_JumpAttack && 
		ECheckBossState != EBossState::EBS_Attack)
	{
		int temp = rand() % 2;
		//UKismetSystemLibrary::PrintString(GetWorld(), FString::SanitizeFloat(temp));
		if (iBossNormalAttackSplit < 2 || iBossNormalAttackSplit != 0)
		{
			if(ECheckBossState != EBossState::EBS_Breath && ECheckBossState != EBossState::EBS_JumpAttack)
				iRageCount++;
		}
		iBossNormalAttackSplit = 0;

		switch (temp)
		{
		case 0:
		{
		ECheckBossState = EBossState::EBS_Breath;
		FRotator LookAtRot = LookAtPlayer();
		SetActorRotation(LookAtRot);
		SavePlayerLoc = pTarget->GetActorLocation();
		//BreathAttack();
		}	break;
		case 1:
			if (GetMesh()->GetAnimInstance()->Montage_IsPlaying(AM_JumpAttack) == false)
			{
				FRotator LookAtRot = LookAtPlayer();
				SetActorRotation(LookAtRot);
				SavePlayerLoc = pTarget->GetActorLocation();
				//bBossJumpAttack = true;
				ECheckBossState = EBossState::EBS_JumpAttack;
			}
			break;
		}

	}
	else if(bBossChase == false)
	{
		ECheckBossState = EBossState::EBS_IDLE;
	}

	if (iRageCount > 2)
	{
		ECheckBossState = EBossState::EBS_Rage;
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
	if (ECheckBossState != EPrevBossState)
	{
		EPrevBossState = ECheckBossState;
	}
	switch (bs)
	{
	case EBossState::EBS_Rage:

		break;
	case EBossState::EBS_RageAttack:
		RageAttack();
		break;

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
		//UKismetSystemLibrary::PrintString(GetWorld(), TEXT("Target is NULL"));
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
	if (GetMesh()->GetAnimInstance()->Montage_IsPlaying(AM_NormalAttack) == true) return;
	if (iBossNormalAttackSplit == 0)
	{
		PlayAnimMontage(AM_NormalAttack, 1.0f, "Attack1");
		Damage = 30.0f;
		HitBackRate = 500.0f;
		AirBorneRate = 0.0f;
		iBossNormalAttackSplit++;
	}
	else if (iBossNormalAttackSplit == 1)
	{
		PlayAnimMontage(AM_NormalAttack, 1.0f, "Attack2");
		Damage = 30.0f;
		HitBackRate = 300.0f;
		AirBorneRate = 500.0f;
		iBossNormalAttackSplit++;
	}
	else if (iBossNormalAttackSplit == 2)
	{
		PlayAnimMontage(AM_NormalAttack, 1.0f, "Attack3");
		Damage = 50.0f;
		HitBackRate = 300.0f;
		//AirBorneRate = 
		iBossNormalAttackSplit++;
	}
}

void AMyBoss::JumpAttack()
{

	//UKismetSystemLibrary::PrintString(GetWorld(), SavePlayerLoc.ToString());
	float Roll, Pitch, Yaw;
	FVector TargetXY, SelfXY;
	UKismetMathLibrary::BreakVector(pTarget->GetActorLocation(), Roll, Pitch, Yaw);
	TargetXY = UKismetMathLibrary::MakeVector(Roll, Pitch, Yaw);
	UKismetMathLibrary::BreakVector(GetActorLocation(), Roll, Pitch, Yaw);
	SelfXY = UKismetMathLibrary::MakeVector(Roll, Pitch, Yaw);
	SavePlayerLoc = FMath::VInterpTo(SelfXY, TargetXY, SaveDeltaTime, 3.0f);

	//FRotator CameraWorldRot = GetCapsuleComponent()->GetComponentRotation();
	//UKismetMathLibrary::BreakRotator(CameraWorldRot, Roll, Pitch, Yaw);
	//FRotator newRot = UKismetMathLibrary::MakeRotator(Roll, 0.0f, Yaw);


	FName JumpStart = "JumpStart";
	FName DropDown = "DropDown";
	if (SavePlayerLoc.Size() + 10 < (GetActorLocation() - SavePlayerLoc).Size())
	{
		PlayAnimMontage(AM_JumpAttack, 10.0f, "DropDown");
		Damage = 80.0f;
		HitBackRate = 300.0f;
		AirBorneRate = 400.0f;
	}
	else if (GetMesh()->GetAnimInstance()->Montage_GetCurrentSection() != JumpStart && GetMesh()->GetAnimInstance()->Montage_GetCurrentSection() != DropDown)
	{
		//GetMesh()->GetAnimInstance()->Montage_Pause();
		SetActorLocation(SavePlayerLoc);
	}
	if (GetMesh()->GetAnimInstance()->Montage_IsPlaying(AM_JumpAttack) == false)
	{
		PlayAnimMontage(AM_JumpAttack, 1.0f, "JumpStart");
	}


}

void AMyBoss::BreathAttack()
{

}

void AMyBoss::RageAttack()
{

}

FRotator AMyBoss::LookAtPlayer()
{
	float Roll, Pitch, Yaw;
	FVector TargetLocation = pTarget->GetActorLocation();
	FRotator rotator = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), TargetLocation);
	UKismetMathLibrary::BreakRotator(rotator, Roll, Pitch, Yaw);
	rotator = UKismetMathLibrary::MakeRotator(Roll, 0.0f, Yaw);

	return rotator;
}