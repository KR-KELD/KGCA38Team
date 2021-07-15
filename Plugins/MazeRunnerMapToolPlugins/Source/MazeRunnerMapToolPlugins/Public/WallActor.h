// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WallActor.generated.h"

//DECLARE_MULTICAST_DELEGATE(FReMoveMap);

UCLASS()
class MAZERUNNERMAPTOOLPLUGINS_API AWallActor : public AActor
{
	GENERATED_BODY()
public:
	// Sets default values for this actor's properties
	AWallActor();

	//DECLARE_EVENT(AWallActor, FMapEvent)
	//FMapEvent& MapEvent(){return ChangedEvent;}
protected:
	//FMapEvent ChangedEvent;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:
	bool UpVeow;
	bool DownVeow;
	bool RightVeow;
	bool LeftVeow;
	int x;
	int y;
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class USceneComponent* D;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UStaticMeshComponent* Up;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UStaticMeshComponent* Down;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UStaticMeshComponent* Right;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		class UStaticMeshComponent* Left;
public:
	UFUNCTION(BlueprintCallable, CallInEditor)
		void UPVisibility(bool SetBool);
	UFUNCTION(BlueprintCallable, CallInEditor)
		void DownVisibility(bool SetBool);
	UFUNCTION(BlueprintCallable, CallInEditor)
		void RightVisibility(bool SetBool);
	UFUNCTION(BlueprintCallable, CallInEditor)
		void LeftVisibility(bool SetBool);
	UFUNCTION(BlueprintCallable, CallInEditor)
		bool IsVisited();
	UFUNCTION()
		void ReMoveBool();
	UFUNCTION()
		void UpdateWall(UStaticMeshComponent* Mesh, float z);
	//UFUNCTION(BlueprintCallable, CallInEditor)

public:
	//FReMoveMap ReMove;
};
