// Fill out your copyright notice in the Description page of Project Settings.


#include "MyAIController.h"
#include "AIBase.h"

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

	GetPerceptionComponent()->OnTargetPerceptionUpdated.AddDynamic(this, &AMyAIController::AIPerceptionUpdate);
	
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

	if (UseBlackboard(BBOject, Blackboard))
	{
		if (RunBehaviorTree(BTObject))
		{
			//Blackboard->SetValueAsString(BehaviorState, AIState);

			UpdateState("State_Patrol");
			//UpdateState("State_Idle");
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

		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Couldn't Run Behavior Tree"));
		}
	}
}

void AMyAIController::HitCall(FString msg)
{
	IsHit = true;
	//Blackboard->SetValueAsBool(BBIsHit, IsHit);
}

void AMyAIController::DeadCall(FString msg)
{
	IsDead = true;
	Blackboard->SetValueAsBool(BBIsBBDead, IsDead);
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

void AMyAIController::AIPerceptionUpdate(AActor* Actor, FAIStimulus Info)
{
	//하나의 캐릭터를 상속받고 있지 않아서 태그로 구분
	if (Actor->ActorHasTag(L"Player") || Actor->ActorHasTag(L"TownNPC"))
	{
		if (AIState == "State_Idle" || AIState == "State_Patrol")
		{
			UpdateState("State_BattleReady");
		//전투준비
			GetBlackboardComponent()->SetValueAsObject(TargetActor, Actor);
		}

		//사운드 추가코드
		//if (Info.Tag == L"Sound")
		//{

		//}
		//else
		//{

		//}
	}
}
