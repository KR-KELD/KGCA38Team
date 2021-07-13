// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Item.h"
#include "GameObject.generated.h"


class UStaticMeshComponent;
/**
 * 
 */
UCLASS()
class KGCA38_API AGameObject : public AItem
{
	GENERATED_BODY()
	
public:
	AGameObject();

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Object, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* ObjectMesh;

public:
	FORCEINLINE UStaticMeshComponent* GetObjectMesh() const { return ObjectMesh; }
};
