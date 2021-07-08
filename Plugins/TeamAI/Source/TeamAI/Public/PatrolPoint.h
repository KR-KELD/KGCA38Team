// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PatrolPoint.generated.h"

UCLASS()
class TEAMAI_API APatrolPoint : public AActor
{
	GENERATED_BODY()
public:	
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "KGCA_AI", Meta = (MakeEditWidget = true))
		TArray<FVector> PatrolPoints;
	// Sets default values for this actor's properties
	int DestIndex = -1;
	int Direction = 1;
	APatrolPoint();
public:
	UFUNCTION(BlueprintCallable, Category = "KGCA_AI")
		FVector GetCirclePoint();
	UFUNCTION(BlueprintCallable, Category = "KGCA_AI")
		FVector GetRoundTripPoint();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
