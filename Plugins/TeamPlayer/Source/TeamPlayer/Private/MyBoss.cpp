// Fill out your copyright notice in the Description page of Project Settings.


#include "MyBoss.h"

// Sets default values
AMyBoss::AMyBoss()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	static ConstructorHelpers::FObjectFinder<UAnimMontage> JumpAttackMontage(TEXT("AnimMontage'/TeamPlayer/Boss/EnemyAnimation/FrostGiant/AM_JumpAttack.AM_JumpAttack'"));
	AM_JumpAttack = JumpAttackMontage.Object;

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
}

// Called every frame
void AMyBoss::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	GetDirAndDistOfCharacter();
	//UKismetSystemLibrary::PrintString(GetWorld(), FString::SanitizeFloat(SavePlayerDist));
	SaveDeltaTime = DeltaTime;

	
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

		ECheckBossState = EBossState::EBS_Chase;
		bBossChase = true;
	}
	else if (JumpOrBreathDist >= SavePlayerDist && 
		SavePlayerDist > 700.0f && 
		bBossChase == true &&
		ECheckBossState != EBossState::EBS_Breath &&
		ECheckBossState != EBossState::EBS_JumpAttack)
	{
		int temp = rand() % 2;
		UKismetSystemLibrary::PrintString(GetWorld(), FString::SanitizeFloat(temp));
		switch (temp)
		{
		case 0:
			ECheckBossState = EBossState::EBS_Breath;
			//BreathAttack();
			break;
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
	TargetXY = UKismetMathLibrary::MakeVector(Roll, Pitch, Yaw);
	UKismetMathLibrary::BreakVector(GetActorLocation(), Roll, Pitch, Yaw);
	SelfXY = UKismetMathLibrary::MakeVector(Roll, Pitch, Yaw);
	SavePlayerLoc = FMath::VInterpTo(SelfXY, TargetXY, SaveDeltaTime, 3.0f);

	//FRotator CameraWorldRot = GetCapsuleComponent()->GetComponentRotation();
	//UKismetMathLibrary::BreakRotator(CameraWorldRot, Roll, Pitch, Yaw);
	//FRotator newRot = UKismetMathLibrary::MakeRotator(Roll, 0.0f, Yaw);


	FName JumpStart = "JumpStart";
	FName DropDown = "DropDown";
	if (SavePlayerLoc.Size() + 5 < (GetActorLocation() - SavePlayerLoc).Size())
	{
		PlayAnimMontage(AM_JumpAttack, 3.0f, "DropDown");
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

FRotator AMyBoss::LookAtPlayer()
{
	float Roll, Pitch, Yaw;
	FVector TargetLocation = pTarget->GetActorLocation();
	FRotator rotator = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), TargetLocation);
	UKismetMathLibrary::BreakRotator(rotator, Roll, Pitch, Yaw);
	rotator = UKismetMathLibrary::MakeRotator(Roll, 0.0f, Yaw);

	return rotator;
}