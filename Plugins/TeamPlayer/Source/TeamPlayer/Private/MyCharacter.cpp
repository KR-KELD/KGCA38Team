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
	fHP = 100;

	//collision->Activate(true);
	//collision->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

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
	//PlayerInputComponent->BindAction("Interect", EInputEvent::IE_Pressed, this, &AMyCharacter::InterectOverlap);

}

void AMyCharacter::Attack()
{
	if (IsDead == false)
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
		UKismetSystemLibrary::PrintString(GetWorld(), TEXT("OverlappedItem"));
	}
}

void AMyCharacter::MoveForward(float value)
{
	if (IsDead == false)
		if (value != 0.0f && Controller != nullptr)
		{
			FRotator rot = this->Controller->GetControlRotation();
			FRotator yaw = FRotator(0, rot.Yaw, 0);
			FRotationMatrix mat = FRotationMatrix(yaw);
			FVector dir = mat.GetUnitAxis(EAxis::X);
			AddMovementInput(dir, value);
		}
}
void AMyCharacter::MoveRight(float value)
{
	if (IsDead == false)
		if (value != 0.0f && Controller != nullptr)
		{
			FRotator rot = this->Controller->GetControlRotation();
			FRotator yaw = FRotator(0, rot.Yaw, 0);
			FRotationMatrix mat = FRotationMatrix(yaw);
			FVector dir = mat.GetUnitAxis(EAxis::Y);
			AddMovementInput(dir, value);
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
			if (m_collision->IsActive() == true)
			{
				UGameplayStatics::ApplyDamage(OtherActor, 20.0f, NULL, GetOwner(), NULL);
				UKismetSystemLibrary::PrintString(GetWorld(), TEXT("Hit"));
				//UParticleSystem* Emitter = 
				//UGameplayStatics::SpawnEmitterAttached(m_PS_AttackParticle, OverlappedComp, NULL, NULL, NULL, NULL);
				UGameplayStatics::SpawnEmitterAttached(m_PS_AttackParticle, OverlappedComp);
				//UGameplayStatics::SpawnEmitterAttached(m_PS_AttackParticle, OverlappedComp, NULL);
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
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		UKismetSystemLibrary::PrintString(GetWorld(), TEXT("OverlappEnd"));
		IsOverlapItem = false;
	}
}

float AMyCharacter::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser)
{
	float damage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);

	fHP -= damage;
	IsHit = true;

	UKismetSystemLibrary::PrintString(GetWorld(), FString::SanitizeFloat(fHP));
	if (fHP <= 0.0f)
	{
		IsDead = true;
		//PlayAnimMontage()
		return damage;
	}
	return damage;
}