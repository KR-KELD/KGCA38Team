// Copyright Epic Games, Inc. All Rights Reserved.

#include "Kismet/KismetMathLibrary.h"
#include "MapToolGameModeBase.h"

AMapToolGameModeBase::AMapToolGameModeBase()
{
	//static ConstructorHelpers::FObjectFinder<UBlueprint> AmmoItem(TEXT("Blueprint'/Game/NewBlueprint.NewBlueprint_C'"));
	//if (AmmoItem.Object)
	//{
	//	MapActors = (UClass*)AmmoItem.Object->GeneratedClass;
	//}

	FName Path = TEXT("Class'/Script/MazeRunnerMapToolPlugins.WallActor'");
	MapActors = Cast<UClass>(StaticLoadObject(UClass::StaticClass(), NULL, *Path.ToString()));
}

void AMapToolGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	CM(20, 8);

	CellStack.Add(MapActorsArray[UKismetMathLibrary::RandomInteger(20)][UKismetMathLibrary::RandomInteger(8)]);
	GetNextCell(CellStack[0]);
	OpenTheDoor();

	//ReSet();
}

void AMapToolGameModeBase::CM(int x, int y)
{
	MaxX = x;
	MaxY = y;
	MapActorsArray.SetNum(x);
	for (int i = 0; i < x; i++)
	{
		MapActorsArray[i].SetNum(y);
		for (int j = 0; j < y; j++)
		{
			UWorld* world = GetWorld();
			if (world)
			{
				FActorSpawnParameters SpawnParams;
				SpawnParams.Owner = this;
				FRotator rotator(0.0f , 0.0f, 0.0f);
				FVector  SpawnLocation(i * 1480, j * 1480, -410.0f);
				AWallActor* Actor = world->SpawnActor<AWallActor>(MapActors, SpawnLocation, rotator, SpawnParams);
				Actor->x = i;
				Actor->y = j;
				MapActorsArray[i][j] = Actor;
			}
		}
	}
}

TArray<AWallActor*> AMapToolGameModeBase::GetCall(int x, int y)
{
	TArray<AWallActor*> Colls;
	if (((y + 1) <= MaxY - 1))
	{
		if (MapActorsArray[x][y + 1]->IsVisited())
		{
			Colls.Add(MapActorsArray[x][y + 1]);
		}
	}
	if (((y - 1) >= 0))
	{
		if (MapActorsArray[x][y - 1]->IsVisited())
		{
			Colls.Add(MapActorsArray[x][y - 1]);
		}

	}
	if (((x + 1) <= MaxX - 1))
	{
		if (MapActorsArray[x + 1][y]->IsVisited())
		{
			Colls.Add(MapActorsArray[x + 1][y]);
		}

	}
	if (((x - 1) >= 0))
	{
		if (MapActorsArray[x - 1][y]->IsVisited())
		{
			Colls.Add(MapActorsArray[x - 1][y]);
		}
	}
	return Colls;
}

void	AMapToolGameModeBase::GetNextCell(AWallActor* Actor)
{
	TArray<AWallActor*> Next;
	Next = GetCall(Actor->x, Actor->y);
	AWallActor* NextCell;
	if (Next.Num() != 0)
	{
		NextCell = Next[UKismetMathLibrary::RandomInteger(Next.Num())];
		HideWallBetweenCells(Actor, NextCell);
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
void	AMapToolGameModeBase::HideWallBetweenCells(AWallActor* Current, AWallActor* Next)
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

void AMapToolGameModeBase::ReSet()
{
	for (int i = 0; i < MaxX; i++)
	{
		for (int j = 0; j < MaxY; j++)
		{
			MapActorsArray[i][j]->ReMoveBool();
		}
	}

	CellStack.Add(MapActorsArray[UKismetMathLibrary::RandomInteger(15)][UKismetMathLibrary::RandomInteger(15)]);
	GetNextCell(CellStack[0]);
	//MapActorsArray[0][0]->ReMove.Broadcast();

	//CM(15, 15);
	//CellStack.Add(MapActorsArray[UKismetMathLibrary::RandomInteger(15)][UKismetMathLibrary::RandomInteger(15)]);
	//GetNextCell(CellStack[0]);
}

void	AMapToolGameModeBase::OpenTheDoor()
{
	MapActorsArray[0][1]->DownVisibility(false);
}