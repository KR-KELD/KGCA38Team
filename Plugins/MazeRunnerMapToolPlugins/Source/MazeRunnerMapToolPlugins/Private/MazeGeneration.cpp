// Fill out your copyright notice in the Description page of Project Settings.

#include "MazeGeneration.h"
#include "Kismet/KismetMathLibrary.h"

/// Sets default values
AMazeGeneration::AMazeGeneration()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
	D = CreateDefaultSubobject<USceneComponent>(TEXT("D"));
	RootComponent = D;
	FName Path = TEXT("Class'/Script/MazeRunnerMapToolPlugins.WallActor'");
	MapActors = Cast<UClass>(StaticLoadObject(UClass::StaticClass(), NULL, *Path.ToString()));
	TSubclassOf<AActor> wall = MapActors;
	MaxX = 20;
	MaxY = 8;
	ch.SetNum(MaxX);
	for (int i = 0; i < MaxX; i++)
	{
		ch[i].SetNum(MaxY);
		for (int j = 0; j < MaxY; j++)
		{

			//UWorld* world = GetWorld();
			//if (world)
			//{
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			FRotator rotator(0.0f, 0.0f, 0.0f);
			FVector  SpawnLocation(i * 1480, j * 1480, -410.0f);
			FString a;
			a += FString::FromInt(i);
			a += ",";
			a += FString::FromInt(j);
			ch[i][j] = CreateDefaultSubobject<UChildActorComponent>(FName(*a));
			ch[i][j]->SetupAttachment(RootComponent);
			ch[i][j]->SetChildActorClass(wall);
			ch[i][j]->SetRelativeTransform(FTransform(rotator, SpawnLocation, FVector(1, 1, 1)));
			//((AWallActor*)ch[i][j]->GetChildActor())->x = i;
			//((AWallActor*)ch[i][j]->GetChildActor())->y = j;
		//}
		}
	}
}

// Called when the game starts or when spawned
void AMazeGeneration::BeginPlay()
{

	Super::BeginPlay();

	for (int i = 0; i < MaxX; i++)
	{
		for (int j = 0; j < MaxY; j++)
		{
			((AWallActor*)ch[i][j]->GetChildActor())->x = i;
			((AWallActor*)ch[i][j]->GetChildActor())->y = j;
		}
	}


	CellStack.Add(ch[UKismetMathLibrary::RandomInteger(MaxX)][UKismetMathLibrary::RandomInteger(MaxY)]);
	GetNextCell(CellStack[0]);
	//static ConstructorHelpers::FObjectFinder<AActor> Wall(TEXT("Class'/Script/MazeRunnerMapToolPlugins.WallActor'"));



}

void	AMazeGeneration::GetNextCell(UChildActorComponent* Actor)
{

	TArray<UChildActorComponent*> Next;
	Next = GetCall(((AWallActor*)Actor->GetChildActor())->x, ((AWallActor*)Actor->GetChildActor())->y);
	UChildActorComponent* NextCell;
	if (Next.Num() != 0)
	{
		NextCell = Next[UKismetMathLibrary::RandomInteger(Next.Num())];
		HideWallBetweenCells(((AWallActor*)Actor->GetChildActor()), ((AWallActor*)NextCell->GetChildActor()));
		CellStack.Add(NextCell);
		GetNextCell(NextCell);
	}
	else
	{
		if (CellStack.Num() != 0)
		{
			NextCell = CellStack.Last();
			CellStack.RemoveAt(CellStack.Num() - 1);
			GetNextCell(NextCell);
		}
		else
		{
			return;
		}
	}
}

TArray<UChildActorComponent*> AMazeGeneration::GetCall(int x, int y)
{
	TArray<UChildActorComponent*> Colls;
	if (((y + 1) <= MaxY - 1))
	{
		if (((AWallActor*)ch[x][y + 1]->GetChildActor())->IsVisited())
		{
			Colls.Add(ch[x][y + 1]);
		}
	}
	if (((y - 1) >= 0))
	{
		if (((AWallActor*)ch[x][y - 1]->GetChildActor())->IsVisited())
		{
			Colls.Add(ch[x][y - 1]);
		}

	}
	if (((x + 1) <= MaxX - 1))
	{
		if (((AWallActor*)ch[x + 1][y]->GetChildActor())->IsVisited())
		{
			Colls.Add(ch[x + 1][y]);
		}

	}
	if (((x - 1) >= 0))
	{
		if (((AWallActor*)ch[x - 1][y]->GetChildActor())->IsVisited())
		{
			Colls.Add(ch[x - 1][y]);
		}
	}
	return Colls;
}

void	AMazeGeneration::HideWallBetweenCells(AWallActor* Current, AWallActor* Next)
{
	if (Current->x == Next->x)
	{
		if (Current->y > Next->y)
		{
			Current->LeftVisibility(false);
			Next->RightVisibility(false);
		}
		else
		{
			Current->RightVisibility(false);
			Next->LeftVisibility(false);
		}
	}
	else
	{
		if (Current->x > Next->x)
		{
			Current->DownVisibility(false);
			Next->UPVisibility(false);
		}
		else
		{
			Current->UPVisibility(false);
			Next->DownVisibility(false);
		}
	}
}

void AMazeGeneration::ReSet()
{
	for (int i = 0; i < MaxX; i++)
	{
		for (int j = 0; j < MaxY; j++)
		{
			((AWallActor*)ch[i][j]->GetChildActor())->ReMoveBool();
		}
	}

	CellStack.Add(ch[UKismetMathLibrary::RandomInteger(MaxX)][UKismetMathLibrary::RandomInteger(MaxY)]);
	GetNextCell(CellStack[0]);
}

void	AMazeGeneration::OpenTheDoor()
{
	((AWallActor*)ch[0][1]->GetChildActor())->DownVisibility(false);
	//ch[0][1]->DownVisibility(false);
}