// Fill out your copyright notice in the Description page of Project Settings.


#include "AIBase.h"
#include "MyAIController.h"


// Sets default values
AAIBase::AAIBase()
{
	//PatrolPoints = CreateDefaultSubobject<APatrolPoint>(TEXT("PatrolPoints"));
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AIControllerClass = AMyAIController::StaticClass();
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
	bUseControllerRotationYaw = false;
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 250.0f, 0.0f);
	GetCharacterMovement()->bUseControllerDesiredRotation = true;
	GetCharacterMovement()->bOrientRotationToMovement = false;
	GetCharacterMovement()->bUseRVOAvoidance = true;
	GetCharacterMovement()->AvoidanceConsiderationRadius = 450.0f;
	//GetCharacterMovement()->BrakingDecelerationWalking = 200.0f;
	//GetCharacterMovement()->GroundFriction = 2.0f;
}


// Called when the game starts or when spawned
void AAIBase::BeginPlay()
{
	Super::BeginPlay();
	RespawnTrans = GetActorTransform();
	RespawnDelegate.AddDynamic(this, &AAIBase::RespawnEvent);
}

void AAIBase::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	HitDelegate.Clear();
	DeadDelegate.Clear();
	RespawnDelegate.Clear();
}

// Called every frame
void AAIBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAIBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AAIBase::SetAIMove(float Speed, bool DesiredRot)
{
	GetCharacterMovement()->MaxWalkSpeed = Speed;
	GetCharacterMovement()->bUseControllerDesiredRotation = DesiredRot;
}

void AAIBase::Patrol()
{

}

//기본 히트함수를 호출시키던 이걸 쓰던 하기
void AAIBase::AIHit(AActor* AttackActor, float Damage)
{
	if (IsDead == false)
	{
		if (HitDelegate.IsBound() == true) HitDelegate.Broadcast(AttackActor);	
	}
}

//
void AAIBase::AIDead()
{
	if (IsDead == false)
	{
		if (DeadDelegate.IsBound() == true) DeadDelegate.Broadcast("Dead");
		IsDead = true;
	}
}

void AAIBase::AIRespawn()
{
	if (RespawnDelegate.IsBound() == true) RespawnDelegate.Broadcast("Respawn");
	if (IsRespawn)
	{
		SetActorTransform(RespawnTrans);
	}
}

bool AAIBase::AIDeadCheck()
{
	return true;
}

float AAIBase::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser)
{
	//if (IsHit == false)
	//{
	//	IsHit = true;
	//	GetWorldTimerManager().SetTimer(HitTimer, this, &AAIBase::HitEvent, 0.2f, false);
		float Damage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
		AIHit(DamageCauser, DamageAmount);
		if (AIDeadCheck())
		{
			AIDead();
			SetActorEnableCollision(false);
			GetWorldTimerManager().SetTimer(DeadTimer, this, &AAIBase::DeadEvent, 5.0f, false);

		}
		return Damage;
	//}
	return 0.0f;
}

void AAIBase::SetActorActive(bool IsActive)
{
	IsAIActive = IsActive;
	SetActorTickEnabled(IsActive);
	SetActorEnableCollision(IsActive);
	SetActorHiddenInGame(!IsActive);
}

void AAIBase::DeadEvent()
{
	SetActorLocation(FVector(9999.0f, 9999.0f, 9999.0f));
	SetActorActive(false);
	GetWorldTimerManager().ClearTimer(DeadTimer);
	if (IsRespawn)
	{
		GetWorldTimerManager().SetTimer(RespawnTimer, this, &AAIBase::AIRespawn, 15.0f, false);
	}
}

void AAIBase::HitEvent()
{
	IsHit = false;
	GetWorldTimerManager().ClearTimer(HitTimer);
}

void AAIBase::RespawnEvent(FString msg)
{
	IsDead = false;
	SetActorActive(true);
	AIReset();
	GetWorldTimerManager().ClearTimer(RespawnTimer);
}
