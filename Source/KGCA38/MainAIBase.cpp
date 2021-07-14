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

void AMainAIBase::AIHit(float Damage)
{
	AAIBase::AIHit(Damage);
	CharacterInfo.HP -= Damage;
}
