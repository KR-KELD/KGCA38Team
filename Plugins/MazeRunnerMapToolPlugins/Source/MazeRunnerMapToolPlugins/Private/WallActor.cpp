// Fill out your copyright notice in the Description page of Project Settings.

#include "WallActor.h"

// Sets default values
AWallActor::AWallActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//FName Path = TEXT("StaticMesh'/Game/ParagonProps/Monolith/Ruins/Meshes/JunglePillarBlockPiece_03A.JunglePillarBlockPiece_03A'");
	//Up = Cast<UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(), NULL, *Path.ToString()));
	//Down = Cast<UClass>(StaticLoadObject(UClass::StaticClass(), NULL, *Path.ToString()));
	//Right = Cast<UClass>(StaticLoadObject(UClass::StaticClass(), NULL, *Path.ToString()));
	//Left = Cast<UClass>(StaticLoadObject(UClass::StaticClass(), NULL, *Path.ToString()));
	D = CreateDefaultSubobject<USceneComponent>(TEXT("D"));
	Up = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Up"));
	Down = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Down"));
	Right = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Right"));
	Left = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Left"));

	static ConstructorHelpers::FObjectFinder<UStaticMesh> Wall(TEXT("StaticMesh'/MazeRunnerMapToolPlugins/ParagonProps/Monolith/Ruins/Meshes/JunglePillarBlockPiece_03A.JunglePillarBlockPiece_03A'"));

	if (Wall.Succeeded())
	{
		RootComponent = D;
		Up->SetStaticMesh(Wall.Object);
		Up->SetupAttachment(RootComponent);
		//FAttachmentTransformRules asdf(FRotator(0.0f, 0.0f, 0.0f), FVector(240.0f, 0, 0), FVector(1, 1, 1)));
		//Up->AttachToComponent(RootComponent,);
		Down->SetStaticMesh(Wall.Object);
		Down->SetupAttachment(RootComponent);
		Right->SetStaticMesh(Wall.Object);
		Right->SetupAttachment(RootComponent);
		Left->SetStaticMesh(Wall.Object);
		Left->SetupAttachment(RootComponent);
	}
	//FRotator abc(0,0,0);	
	Up->SetRelativeTransform(FTransform(FRotator(0.0f, 0.0f, 0.0f), FVector(750.0f, 0, 0.0f), FVector(2.0f,8.0f, 5.0f)));
	Down->SetRelativeTransform(FTransform(FRotator(0.0f, 0.0f, 0.0f), FVector(-750.0f, 0, 0.0f), FVector(2.0f, 8.0f, 5.0f)));
	Right->SetRelativeTransform(FTransform(FRotator(0.0f, 90.0f, 0.0f), FVector(0, 750.0f, 0.0f), FVector(2.0f, 8.0f, 5.0f)));
	Left->SetRelativeTransform(FTransform(FRotator(0.0f, 90.0f, 0.0f), FVector(0, -750.0f, 0.0f), FVector(2.0f, 8.0f, 5.0f)));

	UpVeow = true;
	DownVeow = true;
	RightVeow = true;
	LeftVeow = true;


}

// Called when the game starts or when spawned
void AWallActor::BeginPlay()
{
	Super::BeginPlay();

	//ReMove.AddUFunction(this, "ReMoveBool");
	//ReMove.AddLambda(ReMoveBool());
}

// Called every frame
void AWallActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	/*if (UpVeow)
	{
		if (Up->GetRelativeLocation().Z < 539.0f)
		{
			UpdateWall(Up, 540.0f);
		}
		
	}
	else
	{
		if (Up->GetRelativeLocation().Z > -699.0f)
		{
			UpdateWall(Up, -700.0f);
		}
	}

	if (DownVeow)
	{
		if (Down->GetRelativeLocation().Z < 539.0f)
		{
			UpdateWall(Down, 540.0f);
		}

	}
	else
	{
		if (Down->GetRelativeLocation().Z > -699.0f)
		{
			UpdateWall(Down, -700.0f);
		}
	}

	if (RightVeow)
	{
		if (Right->GetRelativeLocation().Z < 539.0f)
		{
			UpdateWall(Right, 540.0f);
		}
	}
	else
	{
		if (Right->GetRelativeLocation().Z > -699.0f)
		{
			UpdateWall(Right, -700.0f);
		}
	}

	if (LeftVeow)
	{
		if (Left->GetRelativeLocation().Z < 539.0f)
		{
			UpdateWall(Left, 540.0f);
		}

	}
	else
	{
		if (Left->GetRelativeLocation().Z > -699.0f)
		{
			UpdateWall(Left, -700.0f);
		}
	}*/
}

void AWallActor::UPVisibility(bool SetBool)
{
	UpVeow = SetBool;
	//Up->SetVisibility(UpVeow, true);
	//if (!UpVeow)
	//{
	//	Up->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	//}
}
void AWallActor::DownVisibility(bool SetBool)
{
	DownVeow = SetBool;
	//Down->SetVisibility(DownVeow, true);
	//if (!DownVeow)
	//{
	//	Down->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	//}
}
void AWallActor::RightVisibility(bool SetBool)
{
	RightVeow = SetBool;
	//Right->SetVisibility(RightVeow, true);
	//if (!RightVeow)
	//{
	//	Right->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	//}
}
void AWallActor::LeftVisibility(bool SetBool)
{
	LeftVeow = SetBool;
	//Left->SetVisibility(LeftVeow, true);
	//if (!LeftVeow)
	//{
	//	Left->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	//}
}

bool AWallActor::IsVisited()
{
	if (UpVeow & DownVeow & RightVeow & LeftVeow)
	{
		return true;
	}
	return false;
}
void AWallActor::ReMoveBool()
{
	UpVeow = true;
	DownVeow = true;
	RightVeow = true;
	LeftVeow = true;
}

void AWallActor::UpdateWall(UStaticMeshComponent* Mesh, float z)
{
	//SetRelativeTransform
	//Mesh->SetRelativeLocation(FVector(Mesh->GetComponentLocation()[0], Mesh->GetComponentLocation()[2],
	//	FMath::FInterpTo(Mesh->GetComponentLocation()[3], z, GetWorld()->GetDeltaSeconds(), 3.0f)));
	Mesh->SetRelativeLocation(FVector(Mesh->GetRelativeLocation().X, Mesh->GetRelativeLocation().Y,
		FMath::FInterpTo(Mesh->GetRelativeLocation().Z, z, GetWorld()->GetDeltaSeconds(),3.0f)));
}