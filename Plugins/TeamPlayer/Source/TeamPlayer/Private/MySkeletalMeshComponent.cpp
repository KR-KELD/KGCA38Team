// Fill out your copyright notice in the Description page of Project Settings.


#include "MySkeletalMeshComponent.h"

UMySkeletalMeshComponent::UMySkeletalMeshComponent()
{
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> skelMesh(TEXT("SkeletalMesh'/Game/LadyMarionCotillard/mesh/LadyMarion_RedEye.LadyMarion_RedEye'"));
	if (skelMesh.Succeeded())
	{
		SetSkeletalMesh(skelMesh.Object);
		SetRelativeLocation(FVector(0, 0, -90.0f));
		SetRelativeRotation(FRotator(0, -90.0f, 0).Quaternion());
		SetAnimationMode(EAnimationMode::AnimationBlueprint);
		
	}
}