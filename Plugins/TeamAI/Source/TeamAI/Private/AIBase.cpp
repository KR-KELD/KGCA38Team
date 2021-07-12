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

	if (PatrolPoints == nullptr)
	{
		//PatrolPoints = APatrolPoint::StaticClass();
	}

}

void AAIBase::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
	HitDelegate.Clear();
	DeadDelegate.Clear();

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

//�⺻ ��Ʈ�Լ��� ȣ���Ű�� �̰� ���� �ϱ�
void AAIBase::AIHit()
{
	if (HitDelegate.IsBound() == true) HitDelegate.Broadcast("Hit");
}

//
void AAIBase::AIDead()
{
	if (DeadDelegate.IsBound() == true) DeadDelegate.Broadcast("Dead");
}

bool AAIBase::AIDeadCheck()
{
	return true;
}
