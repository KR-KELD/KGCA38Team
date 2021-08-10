// Fill out your copyright notice in the Description page of Project Settings.


#include "MainAIMonster.h"

AMainAIMonster::AMainAIMonster()
{
	HealthBar = CreateDefaultSubobject<UWidgetComponent>("HealthBar");
	HealthBar->SetupAttachment(RootComponent);
}

bool AMainAIMonster::AIDeadCheck()
{
	if (CharacterInfo.HP < 0.0f)
	{
		return true;
	}
	return false;
}

void AMainAIMonster::AIHit(AActor* AttackActor, float Damage)
{
	AAIBase::AIHit(AttackActor, Damage);
	
	CharacterInfo.HP -= Damage;
}