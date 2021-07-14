// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MyStaticLibrary.generated.h"

/**
 * 
 */
UCLASS()
class KGCA38_API UMyStaticLibrary : public UObject
{
	GENERATED_BODY()
	

public:
	UFUNCTION(BlueprintCallable)
	static FString GetNPC_Name(int32 index);

	UFUNCTION(BlueprintCallable)
	static FString GetNPC_Text(int32 index);

	UFUNCTION(BlueprintCallable)
	static void ShowWidget(class UUserWidget* widget);

	UFUNCTION(BlueprintCallable)
	static void HideWidget(UUserWidget* widget);

	UFUNCTION(BlueprintCallable)
	static float CallCharacterCurrentHealth(float curHealth);

	UFUNCTION(BlueprintCallable)
	static float CallCharacterMaxHealth(float maxHealth);

	static bool bShowInventory;

	UFUNCTION(BlueprintCallable)
	static void SetShowInventory(bool bInventory);

	UFUNCTION(BlueprintCallable)
	static bool GetShowInventory();
};
