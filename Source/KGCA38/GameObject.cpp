// Fill out your copyright notice in the Description page of Project Settings.

#include "GameObject.h"
#include "Components/StaticMeshComponent.h"
#include "Item.h"
#include "Components/SphereComponent.h"
#include "Components/WidgetComponent.h"

AGameObject::AGameObject()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ObjectMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ObjectMesh"));
	SetRootComponent(ObjectMesh);

	GetPickupSphere()->SetupAttachment(GetRootComponent());
	GetPickupWidget()->SetupAttachment(GetRootComponent());

	GetPickupSphere()->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));

}