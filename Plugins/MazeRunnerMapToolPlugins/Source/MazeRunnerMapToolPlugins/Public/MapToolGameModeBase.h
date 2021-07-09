// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once
#include "WallActor.h"
#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MapToolGameModeBase.generated.h"

/**
 *
 */
UCLASS()
class MAZERUNNERMAPTOOLPLUGINS_API AMapToolGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere)
		TSubclassOf<class AWallActor> MapActors;
	TArray<TArray<AWallActor*>> MapActorsArray;
	TArray<AWallActor*> CellStack;
	int MaxX;
	int MaxY;
public:
	AMapToolGameModeBase();
	UFUNCTION(BlueprintCallable, CallInEditor)
		void CM(int x, int y);
	TArray<AWallActor*> GetCall(int x, int y);
	void	GetNextCell(AWallActor* Actor);
	void	HideWallBetweenCells(AWallActor* Current, AWallActor* Next);
	UFUNCTION(BlueprintCallable, CallInEditor)
	void	ReSet();
	UFUNCTION(BlueprintCallable, CallInEditor)
	void	OpenTheDoor();
protected:
	virtual void BeginPlay() override;
};
