// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WallActor.h"
#include "MazeGeneration.generated.h"

UCLASS()
class MAZERUNNERMAPTOOLPLUGINS_API AMazeGeneration : public AActor
{
	GENERATED_BODY()
	
public:
	// Sets default values for this actor's properties
	AMazeGeneration();
	UPROPERTY(EditAnywhere)
		TSubclassOf<class AWallActor> MapActors;
	//UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class TArray< TArray<UChildActorComponent*>> ch;
	USceneComponent* D;
	TArray<UChildActorComponent*> CellStack;
	int MaxX;
	int MaxY;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	void	GetNextCell(UChildActorComponent* Actor);
	TArray<UChildActorComponent*> GetCall(int x, int y);
	void	HideWallBetweenCells(AWallActor* Current, AWallActor* Next);
	UFUNCTION(BlueprintCallable, CallInEditor)
		void	ReSet();
	UFUNCTION(BlueprintCallable, CallInEditor)
		void	OpenTheDoor();
	UFUNCTION(BlueprintCallable, CallInEditor)
		void	BattleDoor();
	UFUNCTION(BlueprintCallable, CallInEditor)
		void	PuzzleDoor();
};
