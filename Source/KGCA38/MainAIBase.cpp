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

float AMainAIBase::TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser)
{
	float Damage = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	AIHit(Damage);
	if (AIDeadCheck())
	{
		AIDead();
	}
	return Damage;
}
