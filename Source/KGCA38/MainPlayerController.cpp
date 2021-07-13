// Fill out your copyright notice in the Description page of Project Settings.

#include "MainPlayerController.h"
#include "Item.h"
#include "GameObject.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "DrawDebugHelpers.h"
#include "Components/WidgetComponent.h"
#include "Camera/CameraComponent.h"
#include "ItemType.h"

AMainPlayerController::AMainPlayerController() :
	bShouldTraceItem(false),
	OverlappedItemCount(0),
	bInterActionKey(false),
	bTraceIn(false)
{

}

void AMainPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// �� ������ ȣ���ؾ� ��.
	TraceForActors();

}

void AMainPlayerController::BeginPlay()
{
	Super::BeginPlay();

	Inventory.Reset(INVENTORY_MAXSIZE);
	QuickSlot.Reset(QUICKSLOT_MAXSIZE);

	for (int i = 0; i < INVENTORY_MAXSIZE; i++)
	{
		Inventory.Add(nullptr);
	}

	for (int i = 0; i < QUICKSLOT_MAXSIZE; i++)
	{
		QuickSlot.Add(nullptr);
	}
	Inventory.Add(nullptr);

}

void AMainPlayerController::EnableInterActionKey()
{
	if (/*TraceHitLastActor ||*/ TraceHitLastItem)
	{
		bInterActionKey = true;
	}
}

void AMainPlayerController::TraceForActors()
{
	if (bShouldTraceItem)
	{
		// ���� Ʈ���̽��� ��Ҵ���. ������ ���� ������ ���.
		FHitResult HitTraceResult;
		FVector HitLocation;
		//TraceUnderScreen(HitTraceResult, HitLocation);
		bool bCheckInventoryItem = false;

		if (HitTraceResult.bBlockingHit)
		{
		//	auto npcActor = Cast<ANPC_Characters>(HitTraceResult.GetActor());

			auto Item = Cast<AGameObject>(HitTraceResult.GetActor());

			if (Item && Item->GetPickupWidget())
			{
				Item->GetPickupWidget()->SetVisibility(true);
				bTraceIn = true;

				if (bInterActionKey && bTraceIn)
				{
					for (int i = 0; i < INVENTORY_MAXSIZE; i++)
					{
						if (Inventory[i] != nullptr)
						{
							if (Inventory[i]->GetItemName() == Item->GetItemName())
							{
								Inventory[i]->SetItemCount(Inventory[i]->GetItemCount() + Item->GetItemCount());
								Item->Destroy();

								bCheckInventoryItem = true;

								if (Item->GetPickupSound())
								{
									UGameplayStatics::PlaySound2D(this, Item->GetPickupSound());
								}

								break;
							}
						}
					}

					if (!bCheckInventoryItem)
					{
						for (int i = 0; i < INVENTORY_MAXSIZE; i++)
						{
							if (Inventory[i] == nullptr)
							{
								//UE_LOG(LogTemp, Warning, TEXT("Inventory Index : %d"), i);

								// �κ��丮�� ������ ������ �������� ������ �ʿ���� ����⸸ �ϸ� ��. 
								Item->GetObjectMesh()->SetSimulatePhysics(false);
								Item->SetActorHiddenInGame(true);
								Item->SetActorEnableCollision(false);
								Item->SetActorTickEnabled(false);

								Inventory[i] = Item;

								if (Item->GetPickupSound())
								{
									UGameplayStatics::PlaySound2D(this, Item->GetPickupSound());
								}

								break;
							}
						}
					}

					bInterActionKey = false;
				}
			}

			/*if (npcActor && npcActor->GetInteractionWidget())
			{
				npcActor->GetInteractionWidget()->SetVisibility(true);
				bTraceIn = true;

				if (bInterActionKey && bTraceIn)
				{
					npcActor->ShowNPCDialogText();
					bInterActionKey = false;
				}

			}*/

			//if (TraceHitLastActor)
			//{
			//	if (TraceHitLastActor != npcActor)
			//	{
			//		// ������ �浹������ ����� ���Ͱ� ����Ʈ���̽��� �浹���� ������ ����.
			//		TraceHitLastActor->GetInteractionWidget()->SetVisibility(false);
			//		bTraceIn = false;
			//	}
			//}

			if (TraceHitLastItem)
			{
				if (TraceHitLastItem != Item)
				{
					TraceHitLastItem->GetPickupWidget()->SetVisibility(false);
				}
			}

			// �������� �浹�� ���� ����
			//TraceHitLastActor = npcActor;
			TraceHitLastItem = Item;
		}
	}
}

bool AMainPlayerController::TraceUnderScreen(FHitResult& OutHitResult, FVector& OutHitLocation)
{
	// ĳ���ͷ� ĳ����
	//auto character = Cast<AMainCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));

	//if (character)
	//{
		FVector2D ViewportSize;
		if (GEngine && GEngine->GameViewport)
		{
			// ����Ʈ�� X,Y�� ���´�
			GEngine->GameViewport->GetViewportSize(ViewportSize);
		}

		// ĳ������ ī�޶�� ���������� ���;� �Ѵ�.
		FVector ScreenLocation;// = character->GetFollowCamera()->GetComponentLocation();
		FVector EndTrace;// = ScreenLocation + (character->FollowCamera->GetForwardVector() *
										//(character->GetCameraBoom()->TargetArmLength + 3000.0f));

		//FVector2D ScreenLocation(ViewportSize.X / 2.0f, ViewportSize.Y / 2.0f);
		// ��ġ�� �߾����� �����ش�.
		FVector ScreenWorldPos;
		FVector ScreenWorldDirection;

		// DeprojectScreenToWorld
		// 2Dȭ�� ���� ��ǥ�� 3D ���� ���� ��ǥ �� �������� ��ȯ
		//bool bScreenToWorld = UGameplayStatics::DeprojectScreenToWorld(UGameplayStatics::GetPlayerController(this, 0),
		//	ScreenLocation, ScreenWorldPos, ScreenWorldDirection);

		//if (bScreenToWorld)
		//{
		float LineTraceLength = 3000.0f;

		// ������ǥ�� ũ�ν����� ����Ʈ���̽�
		const FVector Start = ScreenWorldPos;
		const FVector End = Start + ScreenWorldDirection * LineTraceLength;

		//FCollisionQueryParams QueryParam;
		//QueryParam.bReturnPhysicalMaterial = true;

		GetWorld()->LineTraceSingleByChannel(OutHitResult, ScreenLocation, EndTrace, ECollisionChannel::ECC_Visibility,
			FCollisionQueryParams::DefaultQueryParam, FCollisionResponseParams::DefaultResponseParam);

		//DrawDebugLine(GetWorld(), ScreenLocation, EndTrace, FColor::Red, true, -1, 0, 2);

		OutHitLocation = EndTrace;
		if (!OutHitResult.bBlockingHit)
		{
			OutHitResult.Location = OutHitLocation;
			return true;
		}
	//}

	return false;

}

void AMainPlayerController::UseItem(int32 index)
{
	if (QuickSlot[index])
	{
		if (QuickSlot[index]->GetItemType() == EItemType::EIT_Food)
		{
			QuickSlot[index]->SetItemCount(QuickSlot[index]->GetItemCount() - 1);
		}
	}
}

void AMainPlayerController::DropActorSetInWorld(AItem* item)
{

	if (item)
	{
		auto object = Cast<AGameObject>(item);
		//auto character = Cast<AMainCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));

		if (object)// && character)
		{
			// ����ó���� �浹ó�� �� off �ߴ� ���¸� on���� ��ȯ.
			object->GetObjectMesh()->SetSimulatePhysics(true);
			object->SetActorHiddenInGame(false);
			object->SetActorEnableCollision(true);
			object->SetActorTickEnabled(true);
			//object->SetActorTransform(character->GetSceneComponent()->GetComponentTransform());

			if (object->GetDropItemSound())
			{
				UGameplayStatics::PlaySound2D(this, object->GetDropItemSound());
			}
		}
	}

}

void AMainPlayerController::IncreamentOverlappedItemCount(int8 Amount)
{
	if (OverlappedItemCount + Amount <= 0)
	{
		OverlappedItemCount = 0;
		bShouldTraceItem = false;
	}
	else
	{
		OverlappedItemCount += Amount;
		bShouldTraceItem = true;
	}
}