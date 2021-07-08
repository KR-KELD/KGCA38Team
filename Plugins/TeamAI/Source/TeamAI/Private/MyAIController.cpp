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


	SightConfig->SightRadius = SightRadius;
	SightConfig->LoseSightRadius = SightLoseRadius;
	SightConfig->PeripheralVisionAngleDegrees = SightFOV;
	SightConfig->SetMaxAge(SightAge);

	HearingConfig->HearingRange = HearingRange;
	HearingConfig->SetMaxAge(HearingAge);

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

void AMyAIController::UpdateAIPerception()
{
	UAISenseConfig* SightConfigOrigin = GetAIPerceptionComponent()->GetSenseConfig(
		UAISense::GetSenseID(UAISense_Sight::StaticClass()));
	UAISenseConfig_Sight* Sight = Cast<UAISenseConfig_Sight>(SightConfigOrigin);

	UAISenseConfig* HearingConfigOrigin = GetAIPerceptionComponent()->GetSenseConfig(
		UAISense::GetSenseID(UAISense_Hearing::StaticClass()));
	UAISenseConfig_Hearing* Hearing = Cast<UAISenseConfig_Hearing>(HearingConfigOrigin);

	Sight->SightRadius = SightRadius;
	Sight->LoseSightRadius = SightLoseRadius;
	Sight->PeripheralVisionAngleDegrees = SightFOV;
	Sight->SetMaxAge(SightAge);

	Hearing->HearingRange = HearingRange;
	Hearing->SetMaxAge(HearingAge);

}

void AMyAIController::SetSenseSightOption(float Radius, float LoseRadius, float Age, float FOV)
{
	SightRadius = Radius;
	SightLoseRadius = LoseRadius;
	SightAge = Age;
	SightFOV = FOV;
}

void AMyAIController::SetSenseHearingOption(float Range, float Age)
{
	HearingRange = Range;
	HearingAge = Age;
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
			//AIState = "State_Idle";
			//AIState = "State_Patrol";
			//Blackboard->SetValueAsString(BehaviorState, AIState);

			UpdateState("State_Patrol");
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Couldn't Run Behavior Tree"));
		}
	}
}

void AMyAIController::HitCall(FString msg)
{
	UpdateState("State_Hit");
}

void AMyAIController::DeadCall(FString msg)
{
	UpdateState("State_Dead");

}

void AMyAIController::UpdateState(FString State)
{
	AIState = State;
	GetBlackboardComponent()->SetValueAsString(BBAIState, AIState);
}

void AMyAIController::AIPerceptionUpdate(AActor* Actor, FAIStimulus Info)
{
	//하나의 캐릭터를 상속받고 있지 않아서 태그로 구분
	if (Actor->ActorHasTag(L"Player") || Actor->ActorHasTag(L"TownNPC"))
	{
		if (AIState == "State_Idle" || AIState == "State_Patrol")
		{
			UpdateState("State_BattleReady");
		//여기서 무기 꺼내는 명령 내리기
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