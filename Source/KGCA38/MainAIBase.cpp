// Fill out your copyright notice in the Description page of Project Settings.


#include "MainAIBase.h"

bool AMainAIBase::AIDeadCheck()
{
	if (CharacterInfo.HP < 0.0f)
	{
		return true;
	}
	return false;
}

void AMainAIBase::AIHit(AActor* AttackActor, float Damage)
{
	AAIBase::AIHit(AttackActor, Damage);
	CharacterInfo.HP -= Damage;
}
