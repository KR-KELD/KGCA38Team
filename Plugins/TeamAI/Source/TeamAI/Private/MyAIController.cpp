// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAIController.h"


AMyAIController::AMyAIController()
{

#pragma region AIPerception

	SetPerceptionComponent(*CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerception")));
	SightConfig = CreateOptionalDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightConfig"));
	HearingConfig = CreateOptionalDefaultSubobject<UAISenseConfig_Hearing>(TEXT("HearingConfig"));
	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;

	HearingConfig->DetectionByAffiliation.bDetectEnemies = true;
	HearingConfig->DetectionByAffiliation.bDetectFriendlies = true;
	HearingConfig->DetectionByAffiliation.bDetectNeutrals = true;

	SightConfig->SightRadius = 3000.0f;
	SightConfig->LoseSightRadius = 3500.0f;
	SightConfig->PeripheralVisionAngleDegrees = 60.0f;
	SightConfig->SetMaxAge(1.0f);

	HearingConfig->HearingRange = 4000.0f;
	HearingConfig->SetMaxAge(1.0f);

	

	GetPerceptionComponent()->ConfigureSense(*SightConfig);
	GetPerceptionComponent()->ConfigureSense(*HearingConfig);
	GetPerceptionComponent()->SetDominantSense(*SightConfig->GetSenseImplementation());

	
	
#pragma endregion

	static ConstructorHelpers::FObjectFinder<UBlackboardData> BlackBoard(TEXT("BlackboardData'/TeamAI/BT/BB_Base.BB_Base'"));
	if (BlackBoard.Succeeded())
	{
		BBOject = BlackBoard.Object;
	}
	static ConstructorHelpers::FObjectFinder<UBehaviorTree> BehaviorTree(TEXT("BehaviorTree'/TeamAI/BT/BT_DayMonster.BT_DayMonster'"));
	if (BehaviorTree.Succeeded())
	{
		BTObject = BehaviorTree.Object;
	}
}

void AMyAIController::UpdatePerceptionData()
{
	UAISenseConfig* SightConfigOrigin = GetAIPerceptionComponent()->GetSenseConfig(
		UAISense::GetSenseID(UAISense_Sight::StaticClass()));
	UAISenseConfig_Sight* Sight = Cast<UAISenseConfig_Sight>(SightConfigOrigin);

	UAISenseConfig* HearingConfigOrigin = GetAIPerceptionComponent()->GetSenseConfig(
		UAISense::GetSenseID(UAISense_Hearing::StaticClass()));
	UAISenseConfig_Hearing* Hearing = Cast<UAISenseConfig_Hearing>(HearingConfigOrigin);

	Sight->SightRadius = AIData.LookRange;
	Sight->LoseSightRadius = AIData.LostRange;
	Sight->PeripheralVisionAngleDegrees = AIData.SightAngle;
	Sight->SetMaxAge(AIData.PerceptionAge);

	Hearing->HearingRange = AIData.HearingRange;
	Hearing->SetMaxAge(AIData.PerceptionAge);

}

void AMyAIController::SetSenseOption(float SightRadius, float SightLoseRadius, float SightFov, float HearingRange, float Age)
{
	AIData.LookRange = SightRadius;
	AIData.LostRange = SightLoseRadius;
	AIData.SightAngle = SightFov;
	AIData.HearingRange = HearingRange;
	AIData.PerceptionAge = Age;
}

void AMyAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	AAIBase* AIPawn = Cast<AAIBase>(InPawn);
	AIPawn->HitDelegate.AddDynamic(this, &AMyAIController::HitCall);
	AIPawn->DeadDelegate.AddDynamic(this, &AMyAIController::DeadCall);
	AIPawn->RespawnDelegate.AddDynamic(this, &AMyAIController::RespawnCall);

	if (UseBlackboard(BBOject, Blackboard))
	{
		if (RunBehaviorTree(BTObject))
		{
			//Blackboard->SetValueAsString(BehaviorState, AIState);

			//UpdateState("State_Patrol");
			UpdateState("State_Idle");
			Blackboard->SetValueAsBool(BBIsBBDead, IsDead);
			//Blackboard->SetValueAsBool(BBIsHit, IsHit);
			Blackboard->SetValueAsBool(BBIsAttackReady, IsAttackReady);
			if (AIPawn->PatrolPoints == nullptr)
			{
				Blackboard->SetValueAsBool(HasPatrolPoint, false);
			}
			else
			{
				Blackboard->SetValueAsBool(HasPatrolPoint, true);
			}
			Blackboard->SetValueAsString(BattleState, "Battle_Select");
			GetBrainComponent()->StopLogic("StartGame");
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Couldn't Run Behavior Tree"));
		}
	}
}

void AMyAIController::HitCall(AActor* AttackActor)
{
	IsHit = true;
	//Blackboard->SetValueAsBool(BBIsHit, IsHit);
}

void AMyAIController::DeadCall(FString msg)
{
	IsDead = true;
	Blackboard->SetValueAsBool(BBIsBBDead, IsDead);
}

void AMyAIController::RespawnCall(FString msg)
{
	IsDead = false;
	IsHit = false;
	AttackReady(true);
	Blackboard->SetValueAsBool(BBIsBBDead, IsDead);
	UpdateState("State_Patrol");
	Blackboard->SetValueAsString(BattleState, "Battle_Select");
	GetBrainComponent()->StartLogic();
	Cast<AAIBase>(GetPawn())->SetAIMove(AIData.WalkSpeed);
}

void AMyAIController::UpdateState(FString State)
{
	AIState = State;
	GetBlackboardComponent()->SetValueAsString(BBAIState, AIState);
}

void AMyAIController::AttackReady(bool value)
{
	IsAttackReady = value;
	Blackboard->SetValueAsBool(BBIsAttackReady, IsAttackReady);
}

