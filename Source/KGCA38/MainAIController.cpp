// Fill out your copyright notice in the Description page of Project Settings.


#include "MainAIController.h"
AMainAIController::AMainAIController()
{
	GetPerceptionComponent()->OnTargetPerceptionUpdated.AddDynamic(this, &AMainAIController::AIPerceptionUpdate);
}
void AMainAIController::AIPerceptionUpdate(AActor* Actor, FAIStimulus Info)
{
	//태그로 구분해도 되고

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
