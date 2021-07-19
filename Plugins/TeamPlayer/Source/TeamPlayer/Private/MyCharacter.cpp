// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
//#include "Components/CapsuleComponent.h"
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
	m_collision->SetupAttachment(m_SM_WeaponSocket);
	m_collision->SetGenerateOverlapEvents(true);
	m_collision->OnComponentBeginOverlap.AddDynamic(this, &AMyCharacter::OnOverlapBegin);
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

	//collision->Activate(true);
	//collision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bDodge == false && IsHit == false && bHitOnAir == false && IsDead == false)
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
	//PlayerInputComponent->BindAction("Interect", EInputEvent::IE_Pressed, this, &AMyCharacter::InterectOverlap);

}

void AMyCharacter::Attack()
{
	if (IsDead == false && IsHit == false && bHitOnAir == false && IsDead == false)
	{
		if (IsAttack == false)
		{
			PlayAnimMontage(AM_AttackMontage, 1.0f, "Attack1");
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

void AMyCharacter::Dodge()
{
	if (bDodge == true || bHitOnAir == true || IsDead == true) return;
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

void AMyCharacter::OverlappedActor(FName TagName)
{
	//UKismetSystemLibrary::PrintString(GetWorld(), TagName.ToString());
	IsOverlapItem = true;
}

void AMyCharacter::InterectOverlap()
{
	//UKismetSystemLibrary::PrintString(GetWorld(), TEXT("OverlapOn"));
	if (IsOverlapItem == true)
	{
		//UKismetSystemLibrary::PrintString(GetWorld(), TEXT("OverlappedItem"));
	}
}

void AMyCharacter::MoveForward(float value)
{
	if (bDodge == true || bHitOnAir == true || IsDead == true) return;
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
			else if (value == 0)
			{
				DodgeDir = 1;
			}

		}
	}

}
void AMyCharacter::MoveRight(float value)
{
	if (bDodge == true || bHitOnAir == true || IsDead == true) return;
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
			else if(value == 0)
			{
				DodgeDir = 1;
			}
		}
	}

}
void AMyCharacter::TurnAtRate(float value)
{
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
		if (OtherComp->ComponentHasTag("EnemyCollision") == true)
		{
			if (m_collision->IsActive() == true)		//when give damage to enemy
			{
				UGameplayStatics::ApplyDamage(OtherActor, 20.0f, NULL, GetOwner(), NULL);
				//UKismetSystemLibrary::PrintString(GetWorld(), TEXT("Hit"));
				UGameplayStatics::SpawnEmitterAttached(m_PS_AttackParticle, OverlappedComp);

			}
		}
		else if (OtherComp->ComponentHasTag("Item") == true)
		{
			OverlappedActor(OtherComp->ComponentTags[0]);
			//IsOverlapItem = true;
		}
	}
}

void AMyCharacter::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && (OtherActor != this) && OtherComp)	//when player interect with item
	{
		//UKismetSystemLibrary::PrintString(GetWorld(), TEXT("OverlappEnd"));
		IsOverlapItem = false;
	}
}

float AMyCharacter::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser)
{
	//when player get damge from enemy
	float damage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	

	fHP -= damage;

	//UKismetSystemLibrary::PrintString(GetWorld(), FString::SanitizeFloat(fHP));
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