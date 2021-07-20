// Fill out your copyright notice in the Description page of Project Settings.


#include "MainAINPC.h"

bool AMainAINPC::AddFavorability(int iFavorPoint)
{
	if (Favorability >= 100) return false;
	Favorability += iFavorPoint;
	if (Favorability >= 100) Favorability = 100;
	return false;
}