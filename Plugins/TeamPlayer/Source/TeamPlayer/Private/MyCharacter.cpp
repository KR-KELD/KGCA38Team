// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Math/UnrealMathUtility.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Particles/ParticleSystem.h"


#include "Kismet/KismetSystemLibrary.h"
// Sets default values
AMyCharacter::AMyCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
}

AMyCharacter::AMyCharacter(const FObjectInitializer& obj)
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	m_TPSCameraBoomComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	m_TPSCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("PlayerCamera"));
	m_TPSCameraBoomComponent->SetupAttachment(RootComponent);
	m_TPSCamera->SetupAttachment(m_TPSCameraBoomComponent, USpringArmComponent::SocketName);
	m_TPSCameraBoomComponent->bUsePawnControlRotation = true;



	static ConstructorHelpers::FObjectFinder<USkeletalMesh> skelMesh(TEXT("SkeletalMesh'/TeamPlayer/LadyMarionCotillard/mesh/LadyMarion_RedEye.LadyMarion_RedEye'"));
	if (skelMesh.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(skelMesh.Object);
		GetMesh()->SetRelativeLocation(FVector(0, 0, -90.0f));
		GetMesh()->SetRelativeRotation(FRotator(0, -90.0f, 0).Quaternion());
		GetMesh()->SetAnimationMode(EAnimationMode::AnimationBlueprint);
		static ConstructorHelpers::FClassFinder<UAnimInstance> ABP_Player(TEXT("AnimBlueprint'/TeamPlayer/Blueprints/Character/ABP_Player.ABP_Player_C'"));
		if (ABP_Player.Succeeded())
		{
			GetMesh()->SetAnimInstanceClass(ABP_Player.Class);
		}
		static ConstructorHelpers::FObjectFinder<UAnimMontage> AttackMontage(TEXT("AnimMontage'/TeamPlayer/ImportedAnimation/VampCharacter/Animation/AM_AttackCombo.AM_AttackCombo'"));
		AM_AttackMontage = AttackMontage.Object;
		static ConstructorHelpers::FObjectFinder<UAnimMontage> DodgeMontage(TEXT("AnimMontage'/TeamPlayer/ImportedAnimation/VampCharacter/Animation/AM_Dodge.AM_Dodge'"));
		AM_DodgeMontage = DodgeMontage.Object;
		static ConstructorHelpers::FObjectFinder<UAnimMontage> KnockDownMontage(TEXT("AnimMontage'/TeamPlayer/ImportedAnimation/VampCharacter/Animation/AM_AirKnockBackIDLE.AM_AirKnockBackIDLE'"));
		AM_KnockDownTwistMontage = KnockDownMontage.Object;
		static ConstructorHelpers::FObjectFinder<UAnimMontage> ParryingMontage(TEXT("AnimMontage'/TeamPlayer/ImportedAnimation/VampCharacter/Animation/AM_Parrying.AM_Parrying'"));
		AM_Parrying = ParryingMontage.Object;
		static ConstructorHelpers::FObjectFinder<UAnimMontage> Skill_1(TEXT("AnimMontage'/TeamPlayer/ImportedAnimation/AttackAnim/AM_Skill1Montage.AM_Skill1Montage'"));
		AM_Skill_1 = Skill_1.Object;
		static ConstructorHelpers::FObjectFinder<UAnimMontage> Skill_2(TEXT("AnimMontage'/TeamPlayer/ImportedAnimation/AttackAnim/AM_Skill2Montage.AM_Skill2Montage'"));
		AM_Skill_2 = Skill_2.Object;
		static ConstructorHelpers::FObjectFinder<UAnimMontage> Skill_3(TEXT("AnimMontage'/TeamPlayer/ImportedAnimation/AttackAnim/AM_Skill3Montage.AM_Skill3Montage'"));
		AM_Skill_3 = Skill_3.Object;
		static ConstructorHelpers::FObjectFinder<UAnimMontage> Skill_4(TEXT("AnimMontage'/TeamPlayer/ImportedAnimation/AttackAnim/AM_Skill4Montage.AM_Skill4Montage'"));
		AM_Skill_4 = Skill_4.Object;
	}


	m_SM_WeaponSocket = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("WeaponSocket"));
	m_SM_WeaponSocket->SetupAttachment(GetMesh());
	static ConstructorHelpers::FObjectFinder<UStaticMesh> staticMesh(TEXT("StaticMesh'/TeamPlayer/LadyMarionCotillard/mesh/SM_Kantana_Color.SM_Kantana_Color'"));
	if (staticMesh.Succeeded())
	{
		m_SM_WeaponSocket->SetStaticMesh(staticMesh.Object);

		m_SM_WeaponSocket->AttachTo(GetMesh(), "WeaponSocket");
	}
	static ConstructorHelpers::FObjectFinder<UParticleSystem> AttackParticle(TEXT("ParticleSystem'/TeamPlayer/Effect/P_Hit.P_Hit'"));
	m_PS_AttackParticle = AttackParticle.Object;
	m_collision = CreateDefaultSubobject<UCapsuleComponent>(TEXT("collision"));
	//BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box_Collision"));
	m_collision->SetupAttachment(m_SM_WeaponSocket);
	//BoxCollision->SetupAttachment(m_SM_WeaponSocket);
	m_collision->SetGenerateOverlapEvents(true);
	//BoxCollision->SetGenerateOverlapEvents(true);
	m_collision->OnComponentBeginOverlap.AddDynamic(this, &AMyCharacter::OnOverlapBegin);
	//BoxCollision->OnComponentBeginOverlap.AddDynamic(this, &AMyCharacter::OnOverlapBegin);
	GetCapsuleComponent()->OnComponentBeginOverlap.AddDynamic(this, &AMyCharacter::OnOverlapBegin);
	GetCapsuleComponent()->OnComponentEndOverlap.AddDynamic(this, &AMyCharacter::OnOverlapEnd);
	
	//collision->OnComponentBeginOverLap.AddDynamic(this, &AMyCharacter::OnOverlapBegin);
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	m_collision->SetActive(false);
	fHP = 1000.0f;
	fMaxHP = 1000.0f;
	bHitOnAir = false;
	bMove = true;

	//collision->Activate(true);
	//collision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	SaveDeltaTime = DeltaTime;
	if (bDodge == false && IsHit == false && bHitOnAir == false && IsDead == false && bParrying == false && IsAttack == false &&
		bSkill_1 == false && bSkill_2 == false && bSkill_3 == false)
	{
		FRotator temp2 = UKismetMathLibrary::Conv_VectorToRotator(GetCharacterMovement()->GetCurrentAcceleration());
		FRotator temp = FMath::RInterpTo(GetActorRotation(), temp2, DeltaTime, 10.0f);
		float Yaw, Pitch, Roll;
		UKismetMathLibrary::BreakRotator(GetControlRotation(), Roll, Pitch, Yaw);
		FRotator breakRotZ = UKismetMathLibrary::MakeRotator(0, 0, Yaw);
		FVector FVec = UKismetMathLibrary::GetForwardVector(breakRotZ);

		if (GetInputAxisValue("MoveForward") != 0.0f || GetInputAxisValue("MoveRight") != 0.0f)
		{
			SetActorRotation(temp);

		}


		AddMovementInput(FVec, GetInputAxisValue("MovemForward"));
	}
	//
	//
	//SetActorRotation()
	//FMath::RInterpTo()

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &AMyCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMyCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &AMyCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &AMyCharacter::LookUpAtRate);
	PlayerInputComponent->BindAction("Attack", EInputEvent::IE_Pressed, this, &AMyCharacter::Attack);
	PlayerInputComponent->BindAction("Interect", EInputEvent::IE_Pressed, this, &AMyCharacter::InterectOverlap);
	PlayerInputComponent->BindAction("Dodge", EInputEvent::IE_Pressed, this, &AMyCharacter::Dodge);
	PlayerInputComponent->BindAction("Parrying", EInputEvent::IE_Pressed, this, &AMyCharacter::Parry);
	PlayerInputComponent->BindAction("Skill_1", EInputEvent::IE_Pressed, this, &AMyCharacter::Skill_1);
	PlayerInputComponent->BindAction("Skill_1", EInputEvent::IE_Released, this, &AMyCharacter::Skill_1_Trigger);
	PlayerInputComponent->BindAction("Skill_2", EInputEvent::IE_Pressed, this, &AMyCharacter::Skill_2);
	PlayerInputComponent->BindAction("Skill_3", EInputEvent::IE_Pressed, this, &AMyCharacter::Skill_3);


}

void AMyCharacter::Attack()
{

	if (IsDead == false && IsHit == false && bHitOnAir == false && IsDead == false && bDodge == false && bParrying == false && bSkill_1 == false && bSkill_2 == false && bSkill_3 == false)
	{
		//FRotator LookAtRot = LookAtTarget();
		//SetActorRotation(LookAtRot);
		float roll, pitch, yaw;
		FVector lookRot;
		FRotator look;
		UKismetMathLibrary::BreakVector(m_TPSCamera->GetForwardVector(), roll, pitch, yaw);
		lookRot = UKismetMathLibrary::MakeVector(roll, pitch, 0.0f);
		//look = FMath::RInterpTo(GetActorRotation(), UKismetMathLibrary::Conv_VectorToRotator(lookRot), SaveDeltaTime, 0.1f);
		SetActorRotation(UKismetMathLibrary::Conv_VectorToRotator(lookRot));
		if (IsAttack == false)
		{
			if (GetMesh()->GetAnimInstance()->Montage_IsPlaying(AM_Parrying) == true)
			{
				StopAnimMontage(AM_Parrying);
			}
			if (GetMesh()->GetAnimInstance()->Montage_IsPlaying(AM_DodgeMontage) == true)
			{
				StopAnimMontage(AM_DodgeMontage);
			}
			if (GetMesh()->GetAnimInstance()->IsAnyMontagePlaying() == true) GetMesh()->GetAnimInstance()->StopAllMontages(0.0);


			PlayAnimMontage(AM_AttackMontage, 1.0f, "Attack1");

			//AM_MontageSet = AM_AttackMontage;
			//PlayAnimMontage(AM_MontageSet, 1.0f, "Attack1");
			IsAttack = true;
		}
		else if (IsAttack == true && ComboOn == true)
		{
			FName SectionNameOfMontage = GetMesh()->GetAnimInstance()->Montage_GetCurrentSection(AM_AttackMontage);
			if (SectionNameOfMontage == "Attack1")
			{

				PlayAnimMontage(AM_AttackMontage, 1.0f, "Attack2");
				ComboOn = false;
			}
			else if (SectionNameOfMontage == "Attack2")
			{

				PlayAnimMontage(AM_AttackMontage, 1.0f, "Attack3");
				ComboOn = false;
			}
			else if (SectionNameOfMontage == "Attack3")
			{

				PlayAnimMontage(AM_AttackMontage, 1.0f, "Attack4");
				ComboOn = false;
			}
		}
	}
}

void AMyCharacter::Skill_1()
{
	if (bSkill_1 == true || bSkill_2 == true || bDodge == true || bParrying == true || IsHit == true || bSkill_3 == true) return;



	bSkill_1 = true;
	bHold = true;

	if (GetMesh()->GetAnimInstance()->Montage_IsActive(AM_Skill_1) == false)
	{
		float roll, pitch, yaw;
		FVector lookRot;
		FRotator look;
		UKismetMathLibrary::BreakVector(m_TPSCamera->GetForwardVector(), roll, pitch, yaw);
		lookRot = UKismetMathLibrary::MakeVector(roll, pitch, 0.0f);
		//look = FMath::RInterpTo(GetActorRotation(), UKismetMathLibrary::Conv_VectorToRotator(lookRot), SaveDeltaTime, 0.1f);
		SetActorRotation(UKismetMathLibrary::Conv_VectorToRotator(lookRot));
		PlayAnimMontage(AM_Skill_1, 1.0f, "Skill_1_Start");

	}
}

void AMyCharacter::Skill_1_Trigger()
{
	bHold = false;
}

void AMyCharacter::Skill_2()
{
	if (bSkill_2 == true || bSkill_1 == true || bDodge == true || bParrying == true || IsHit == true || bSkill_3 == true) return;

	bSkill_2 = true;

	if (GetMesh()->GetAnimInstance()->Montage_IsActive(AM_Skill_2) == false)
	{
		float roll, pitch, yaw;
		FVector lookRot;
		FRotator look;
		UKismetMathLibrary::BreakVector(m_TPSCamera->GetForwardVector(), roll, pitch, yaw);
		lookRot = UKismetMathLibrary::MakeVector(roll, pitch, 0.0f);
		look = FMath::RInterpTo(GetActorRotation(), UKismetMathLibrary::Conv_VectorToRotator(lookRot), SaveDeltaTime, 0.1f);
		SetActorRotation(UKismetMathLibrary::Conv_VectorToRotator(lookRot));
		PlayAnimMontage(AM_Skill_2, 1.0f, "Default");
	}

}

void AMyCharacter::Skill_3()
{
	if (bSkill_2 == true || bSkill_1 == true || bDodge == true || bParrying == true || IsHit == true || bSkill_3 == true) return;

	bSkill_3 = true;
	if (GetMesh()->GetAnimInstance()->Montage_IsActive(AM_Skill_3) == false)
	{
		float roll, pitch, yaw;
		FVector lookRot;
		FRotator look;
		UKismetMathLibrary::BreakVector(m_TPSCamera->GetForwardVector(), roll, pitch, yaw);
		lookRot = UKismetMathLibrary::MakeVector(roll, pitch, 0.0f);
		look = FMath::RInterpTo(GetActorRotation(), UKismetMathLibrary::Conv_VectorToRotator(lookRot), SaveDeltaTime, 0.1f);
		SetActorRotation(UKismetMathLibrary::Conv_VectorToRotator(lookRot));
		PlayAnimMontage(AM_Skill_3, 1.0f, "Default");
	}

}


void AMyCharacter::Dodge()
{
	if (bDodge == true || bHitOnAir == true || IsDead == true || bSkill_1 == true || bSkill_2 == true || IsHit == true || bSkill_3 == true) return;
	if (GetMesh()->GetAnimInstance()->Montage_IsPlaying(AM_KnockDownTwistMontage) == true) return;
	if (GetMesh()->GetAnimInstance()->Montage_IsPlaying(AM_DodgeMontage) == true) return;
	//USceneComponent::GetWorld
	float Roll, Pitch, Yaw;
	m_TPSCameraBoomComponent->GetComponentRotation();
	//m_SpringArmArrow->GetComponentRotation();
	bDodge = true;//
	FRotator CameraWorldRot = m_TPSCamera->GetComponentRotation();
	UKismetMathLibrary::BreakRotator(CameraWorldRot, Roll, Pitch, Yaw);
	FRotator newRot = UKismetMathLibrary::MakeRotator(Roll, 0.0f, Yaw);
	SetActorRotation(newRot);
	//PlayAnimMontage(AM_DodgeMontage, 1.0f, "Back");
	switch (DodgeDir)
	{
	case 0:	//Forward
		//LaunchCharacter()
		PlayAnimMontage(AM_DodgeMontage, 1.0f, "Dash");
		//PlayAnimMontage(AM_DodgeMontage, )
		break;
	case 1: //back
		PlayAnimMontage(AM_DodgeMontage, 1.0f, "Back");
		break;
	case 2: //Right
		PlayAnimMontage(AM_DodgeMontage, 1.0f, "Right");
		break;
	case 3: //Left
		PlayAnimMontage(AM_DodgeMontage, 1.0f, "Left");
		break;
	default:
		//DodgeDir = 0;
		break;

	}

}

void AMyCharacter::Parry()
{
	if (IsDead == true || IsHit == true || bHitOnAir == true || IsDead == true || bParrying == true || bDodge == true || bSkill_1 == true || bSkill_2 == true || bSkill_3 == true) return;
	if (GetMesh()->GetAnimInstance()->Montage_IsPlaying(AM_Parrying) == true) return;
	if (GetMesh()->GetAnimInstance()->IsAnyMontagePlaying() == true) GetMesh()->GetAnimInstance()->StopAllMontages(0.0);

	
	bParrying = true;
	IsAttack = false;
	StopAnimMontage(AM_AttackMontage);
	//AM_MontageSet = AM_Parrying;
	DisableInput(UGameplayStatics::GetPlayerController(this, 0));
	PlayAnimMontage(AM_Parrying, 1.0f, "Default");
}




void AMyCharacter::InterectOverlap()
{
	//UKismetSystemLibrary::PrintString(GetWorld(), TEXT("OverlapOn"));
	//if (IsOverlapItem == true)
	//{
	//	//UKismetSystemLibrary::PrintString(GetWorld(), TEXT("OverlappedItem"));
	//}
}

void AMyCharacter::MoveForward(float value)
{
	if (bDodge == true || bHitOnAir == true || IsDead == true || bSkill_2 == true || bSkill_3 == true) return;
	if (GetMesh()->GetAnimInstance()->Montage_GetCurrentSection(GetMesh()->GetAnimInstance()->GetCurrentActiveMontage()) == "Skill_1_Start") return;
	if (GetMesh()->GetAnimInstance()->Montage_IsActive(AM_AttackMontage)) return;
	if (GetMesh()->GetAnimInstance()->Montage_IsActive(AM_DodgeMontage)) return;
	if (GetMesh()->GetAnimInstance()->Montage_IsActive(AM_KnockDownTwistMontage)) return;
	if (GetMesh()->GetAnimInstance()->Montage_IsActive(AM_Parrying)) return;
	if (GetMesh()->GetAnimInstance()->Montage_IsActive(AM_Skill_2)) return;

	//when player is not dead or get hit is false, player can move
	if (IsDead == false && IsHit == false)
	{
		if (value != 0.0f && Controller != nullptr)
		{
			FRotator rot = this->Controller->GetControlRotation();
			FRotator yaw = FRotator(0, rot.Yaw, 0);
			FRotationMatrix mat = FRotationMatrix(yaw);
			FVector dir = mat.GetUnitAxis(EAxis::X);
			AddMovementInput(dir, value);

			if (value == 1)
			{
				DodgeDir = 0;
			}
			else if (value == -1)
			{
				DodgeDir = 1;
			}

		}
	}
	if (value == 0)
	{
		DodgeDir = 1;
	}

}
void AMyCharacter::MoveRight(float value)
{
	if (bDodge == true || bHitOnAir == true || IsDead == true || bParrying == true || bSkill_2 == true || bSkill_3 == true) return;
	if (IsDead == false && IsHit == false)
	{
		if (value != 0.0f && Controller != nullptr)
		{
			FRotator rot = this->Controller->GetControlRotation();
			FRotator yaw = FRotator(0, rot.Yaw, 0);
			FRotationMatrix mat = FRotationMatrix(yaw);
			FVector dir = mat.GetUnitAxis(EAxis::Y);
			if(bDodge == false)
			AddMovementInput(dir, value);

			if (value == 1)
			{
				DodgeDir = 2;
			}
			else if (value == -1)
			{
				DodgeDir = 3;
			}
		}
	}

}
void AMyCharacter::TurnAtRate(float value)
{
	if(bSkill_1 == false)
		AddControllerYawInput(value);
}
void AMyCharacter::LookUpAtRate(float value)
{
	AddControllerPitchInput(value);
}

void AMyCharacter::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		//if (OverlappedComp->ComponentHasTag("SkillCollision") == true)
		//{
		//	UGameplayStatics::ApplyDamage(OtherActor, 40.0f, NULL, this, NULL);
		//	UGameplayStatics::SpawnEmitterAttached(m_PS_AttackParticle, OverlappedComp);
		//	UGameplayStatics::SpawnEmitterAttached(m_PS_AttackParticle, OverlappedComp);
		//	UGameplayStatics::SpawnEmitterAttached(m_PS_AttackParticle, OverlappedComp);
		//}

		if (OtherComp->ComponentHasTag("EnemyCollision") == true)
		{
			if (m_collision->IsActive() == true)		//when give damage to enemy
			{
				UGameplayStatics::ApplyDamage(OtherActor, 20.0f, NULL, this, NULL);
				//UKismetSystemLibrary::PrintString(GetWorld(), TEXT("Hit"));
				UGameplayStatics::SpawnEmitterAttached(m_PS_AttackParticle, OverlappedComp);

			}
		}
		else if (OtherComp->ComponentHasTag("Item") == true)
		{
			OverlappedActor(OtherActor);
			//IsOverlapItem = true;
		}
		else if (OtherActor->ActorHasTag("TownNPC") == true || OtherActor->ActorHasTag("Partner"))
		{
			bNPC = true;
			OverlappedActor(OtherActor);
		}
	}
}

void AMyCharacter::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && (OtherActor != this) && OtherComp)	//when player interect with item
	{
		//UKismetSystemLibrary::PrintString(GetWorld(), TEXT("OverlappEnd"));
		IsOverlapItem = false;
		bNPC = false;
	}
}

float AMyCharacter::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser)
{
	//when player get damge from enemy
	float damage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	if (GetCapsuleComponent()->IsActive() == false)
	{
		return NULL;
	}

	if (bParrying == true)
	{
		if (GetMesh()->GetAnimInstance()->Montage_IsPlaying(AM_Parrying) == true)
		{
			if (GetMesh()->GetAnimInstance()->Montage_GetCurrentSection() != "ParryingSucceed")
			{
				//StopAnimMontage(AM_Parrying);
				PlayAnimMontage(AM_Parrying, 1.0f, "ParryingSucceed");
				//UGameplayStatics::PlaySoundAtLocation(,GetActorLocation());
				return NULL;
			}
		}
	}


	fHP -= damage;
	if (bSkill_1 == true || bSkill_2 == true || bSkill_3 == true)
	{
		return NULL;
	}





	if (fHP <= 0.0f)
	{
		IsDead = true;
		//PlayAnimMontage()
		return damage;
	}

	IsHit = true;
	float Roll, Pitch, Yaw;
	FRotator rot = UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), DamageCauser->GetActorLocation());
	UKismetMathLibrary::BreakRotator(rot, Roll, Pitch, Yaw);
	rot = UKismetMathLibrary::MakeRotator(0.0f, 0.0f, Yaw);

	SetActorRotation(rot);
	if (KnockBackRateFromEnemy != 0.0f)
	{
		bHitOnAir = true;
	}
	KnockbackPlayer(0.0f, 0.0f, DamageCauser->GetActorForwardVector());

	return damage;
}


void AMyCharacter::KnockbackPlayer(float KnockBackPower, float PushBack, FVector Loc)
{
	FVector FV = Loc;
	FVector FUV = GetActorUpVector();

	if (bHitOnAir == true)
	{
		FUV.Normalize();
		FV.Normalize();
		//FV.X *= -1.0f;
		//FV.Y *= -1.0f;
		FV.X *= HitBackRateFromEnemy;
		FV.Y *= HitBackRateFromEnemy;
		FUV.Z *= KnockBackRateFromEnemy;
		FV = UKismetMathLibrary::MakeVector(FV.X, FV.Y, FUV.Z);
		if (GetMesh()->GetAnimInstance()->Montage_IsPlaying(AM_KnockDownTwistMontage) == false)
		{

			PlayAnimMontage(AM_KnockDownTwistMontage, 1.0f, "Default");
			//bHitOnAir = true;
			
		}

		LaunchCharacter(FV, false, false);
	}
	else if (HitBackRateFromEnemy != 0.0f && KnockBackRateFromEnemy == 0.0f)
	{

		FUV.Normalize();
		FV.Normalize();
		FV.X *= HitBackRateFromEnemy;
		FV.Y *= HitBackRateFromEnemy;
		//FV.X *= -1.0f;
		//FV.Y *= -1.0f;
		FUV.Z *= KnockBackRateFromEnemy;
		FV = UKismetMathLibrary::MakeVector(FV.X, FV.Y, FUV.Z);
		LaunchCharacter(FV, false, false);
	}
}

FRotator AMyCharacter::LookAtTarget()
{
	//float Roll, Pitch, Yaw;
	//m_TPSCameraBoomComponent->GetComponentRotation();
	//FRotator rotator = m_TPSCameraBoomComponent->; //UKismetMathLibrary::FindLookAtRotation(GetActorLocation(), );
	//FRotator rotator = m_TPSCamera->GetForwardVector()
	//UKismetMathLibrary::BreakRotator(rotator, Roll, Pitch, Yaw);
	//rotator = UKismetMathLibrary::MakeRotator(Roll, 0.0f, Yaw);
	//
	//return rotator;
	return FRotator(0, 0, 0);
}

