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
	//GetCharacterMovement()->BrakingDecelerationWalking = 200.0f;
	//GetCharacterMovement()->GroundFriction = 2.0f;
}


// Called when the game starts or when spawned
void AAIBase::BeginPlay()
{
	Super::BeginPlay();

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
	if (HitDelegate.IsBound() == true) HitDelegate.Broadcast(AttackActor);
}

//
void AAIBase::AIDead()
{
	if (DeadDelegate.IsBound() == true) DeadDelegate.Broadcast("Dead");
}

void AAIBase::AIRespawn()
{
	if (RespawnDelegate.IsBound() == true) RespawnDelegate.Broadcast("Respawn");
}

bool AAIBase::AIDeadCheck()
{
	return true;
}

float AAIBase::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCursor)
{
	float Damage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCursor);
	AIHit(DamageCursor, DamageAmount);
	if (AIDeadCheck())
	{
		AIDead();
		GetWorldTimerManager().SetTimer(DeadTimer, this, &AAIBase::DeadEvent,5.0f, false);
	}
	return Damage;
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
}

void AAIBase::RespawnEvent(FString msg)
{
	SetActorActive(true);
	AIReset();
}
