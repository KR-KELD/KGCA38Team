// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PatrolPoint.generated.h"


UENUM(BlueprintType)
enum class EPatrolType : uint8
{
	EPatrol_RandomPoint UMETA(DisplayName = "Random"),
	EPatrol_CirclePoints UMETA(DisplayName = "Circle"),
	EPatrol_RoundTripPoints UMETA(DisplayName = "RoundTrip"),
};

UCLASS()
class TEAMAI_API APatrolPoint : public AActor
{
	GENERATED_BODY()
public:	
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "KGCA_AI", Meta = (MakeEditWidget = true))
		TArray<FVector> PatrolPoints;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "KGCA_AI")
		EPatrolType PatrolType = EPatrolType::EPatrol_RandomPoint;
	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "KGCA_AI")
		float RandomRange = 1000.0f;
	// Sets default values for this actor's properties
	int DestIndex = -1;
	int Direction = 1;
	APatrolPoint();
public:
	UFUNCTION(BlueprintCallable, Category = "KGCA_AI")
		FVector GetPatrolPoint();
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
