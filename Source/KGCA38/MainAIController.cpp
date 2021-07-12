// Fill out your copyright notice in the Description page of Project Settings.


#include "MainAIController.h"
AMainAIController::AMainAIController()
{
	GetPerceptionComponent()->OnTargetPerceptionUpdated.AddDynamic(this, &AMainAIController::AIPerceptionUpdate);
}
void AMainAIController::AIPerceptionUpdate(AActor* Actor, FAIStimulus Info)
{
	//�±׷� �����ص� �ǰ�

	//�ϳ��� ĳ���͸� ��ӹް� ���� �ʾƼ� �±׷� ����
	if (Actor->ActorHasTag(L"Player") || Actor->ActorHasTag(L"TownNPC"))
	{
		if (AIState == "State_Idle" || AIState == "State_Patrol")
		{
			UpdateState("State_BattleReady");
			//�����غ�
			GetBlackboardComponent()->SetValueAsObject(TargetActor, Actor);
		}

		//���� �߰��ڵ�
		//if (Info.Tag == L"Sound")
		//{

		//}
		//else
		//{

		//}
	}
}
