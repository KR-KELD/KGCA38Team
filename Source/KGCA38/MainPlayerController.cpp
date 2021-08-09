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
	bTraceIn(false),
	HitNumberDestroyTime(1.5f)
{

}

void AMainPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// 라인 트레이스 사용 시 매 프레임 호출해야 함.
	//TraceForActors();
	UpdateHitNumbers();
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

void AMainPlayerController::OverlapEndItems()
{
	if (OverlapItem)
	{
		OverlapItem->GetPickupWidget()->SetVisibility(false);
	}
}

void AMainPlayerController::OverlapBeginItems(AItem* item)
{
	if (item)
	{
		item->GetPickupWidget()->SetVisibility(true);
	}
}

void AMainPlayerController::OverlapSetInventoryItems(AItem* item)
{

	bool bCheckInventoryItem = false;

	if (item && bInterActionKey)
	{
		for (int i = 0; i < INVENTORY_MAXSIZE; i++)
		{
			if (Inventory[i] != nullptr)
			{
				if (Inventory[i]->GetItemName() == item->GetItemName())
				{
					Inventory[i]->SetItemCount(Inventory[i]->GetItemCount() + item->GetItemCount());
					item->Destroy();

					bCheckInventoryItem = true;

					if (item->GetPickupSound())
					{
						UGameplayStatics::PlaySound2D(this, item->GetPickupSound());
					}

					OverlapItem = nullptr;

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

					// 인벤토리에 넣을때 월드의 아이템을 삭제할 필요없이 숨기기만 하면 됨. 
					item->GetObjectMesh()->SetSimulatePhysics(false);
					item->SetActorHiddenInGame(true);
					item->SetActorEnableCollision(false);
					item->SetActorTickEnabled(false);
					MeshScale = item->GetObjectMesh()->GetRelativeScale3D();

					Inventory[i] = item;

					if (item->GetPickupSound())
					{
						UGameplayStatics::PlaySound2D(this, item->GetPickupSound());
					}

					OverlapItem = nullptr;

					break;
				}
			}
		}

	}

	bInterActionKey = false;
	
}

void AMainPlayerController::TraceForActors()
{
	if (bShouldTraceItem)
	{
		// 라인 트레이스에 닿았는지. 닿으면 정보 위젯을 띄움.
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

								// 인벤토리에 넣을때 월드의 아이템을 삭제할 필요없이 숨기기만 하면 됨. 
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
			//		// 마지막 충돌정보가 저장된 액터가 라인트레이스와 충돌되지 않으면 숨김.
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

			// 마지막에 충돌된 액터 저장
			//TraceHitLastActor = npcActor;
			TraceHitLastItem = Item;
		}
	}
}

bool AMainPlayerController::TraceUnderScreen(FHitResult& OutHitResult, FVector& OutHitLocation)
{
	// 캐릭터로 캐스팅
	//auto character = Cast<AMainCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0));

	//if (character)
	//{
		FVector2D ViewportSize;
		if (GEngine && GEngine->GameViewport)
		{
			// 뷰포트의 X,Y를 얻어온다
			GEngine->GameViewport->GetViewportSize(ViewportSize);
		}

		// 캐릭터의 카메라와 스프링암을 얻어와야 한다.
		FVector ScreenLocation;// = character->GetFollowCamera()->GetComponentLocation();
		FVector EndTrace;// = ScreenLocation + (character->FollowCamera->GetForwardVector() *
										//(character->GetCameraBoom()->TargetArmLength + 3000.0f));

		//FVector2D ScreenLocation(ViewportSize.X / 2.0f, ViewportSize.Y / 2.0f);
		// 위치를 중앙으로 맞춰준다.
		FVector ScreenWorldPos;
		FVector ScreenWorldDirection;

		// DeprojectScreenToWorld
		// 2D화면 공간 좌표를 3D 월드 공간 좌표 및 방향으로 변환
		//bool bScreenToWorld = UGameplayStatics::DeprojectScreenToWorld(UGameplayStatics::GetPlayerController(this, 0),
		//	ScreenLocation, ScreenWorldPos, ScreenWorldDirection);

		//if (bScreenToWorld)
		//{
		float LineTraceLength = 3000.0f;

		// 월드좌표로 크로스헤어에서 라인트레이스
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
		if (QuickSlot[index]->GetItemType() == EItemType::EIT_Food || QuickSlot[index]->GetItemType() == EItemType::EIT_Medical)
		{
			if (QuickSlot[index]->GetItemCount() > 0)
			{
				QuickSlot[index]->SetItemCount(QuickSlot[index]->GetItemCount() - 1);
				UseItemHealingPoint(QuickSlot[index]->GetItemHealingPoint());
			}

			if (QuickSlot[index]->GetItemCount() <= 0 && QuickSlot[index] != nullptr)
			{
				for (int i = 0; i < INVENTORY_MAXSIZE; i++)
				{
					if (Inventory[i] != nullptr)
					{
						if (Inventory[i]->GetItemName() == QuickSlot[index]->GetItemName())
						{
							for (int j = 0; j < QUICKSLOT_MAXSIZE; j++)
							{
								if (QuickSlot[j] != nullptr)
								{
									if (Inventory[i]->GetItemName() == QuickSlot[j]->GetItemName())
									{
										QuickSlot[j] = nullptr;
									}
								}
							}

							Inventory[i] = nullptr;
							break;
						}
					}
				}
			}

			//return QuickSlot[index];
		}
	}

	//return nullptr;
}

void AMainPlayerController::DropActorSetInWorld(AItem* item, FTransform transform)
{

	if (item)
	{
		auto object = Cast<AGameObject>(item);
		if (object)
		{	
			bSetOverlap = false;
			// 숨김처리와 충돌처리 등 off 했던 상태를 on으로 전환.
			object->GetObjectMesh()->SetSimulatePhysics(true);
			object->SetActorHiddenInGame(false);
			object->SetActorEnableCollision(true);
			object->SetActorTickEnabled(true);
			transform.SetScale3D(MeshScale);
			object->SetActorTransform(transform);

			if (object->GetDropItemSound())
			{
				UGameplayStatics::PlaySound2D(this, object->GetDropItemSound());
			}
			GetWorld()->GetTimerManager().SetTimer(OverlapTimer, this, &AMainPlayerController::ChangeSetOverlap, 0.5f);
		}
	}

}

void AMainPlayerController::ChangeSetOverlap()
{
	bSetOverlap = true;
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

void AMainPlayerController::StoreHitNumber(UUserWidget* HitNumber, FVector Location)
{
	HitNumbers.Add(HitNumber, Location);

	FTimerHandle HitNumberTimer;
	FTimerDelegate HitNumberDelegate;
	HitNumberDelegate.BindUFunction(this, FName("DestroyHitNumber"), HitNumber);
	GetWorld()->GetTimerManager().SetTimer(HitNumberTimer, HitNumberDelegate, HitNumberDestroyTime, false);

}

void AMainPlayerController::UpdateHitNumbers()
{
	for (auto& HitPair : HitNumbers)
	{
		UUserWidget* HitNumber{ HitPair.Key };
		const FVector Location{ HitPair.Value };
		FVector2D ScreenPosition;
		UGameplayStatics::ProjectWorldToScreen(
			GetWorld()->GetFirstPlayerController(),
			Location,
			ScreenPosition);
		HitNumber->SetPositionInViewport(ScreenPosition);
	}
}

void AMainPlayerController::DestroyHitNumber(UUserWidget* HitNumber)
{
	HitNumbers.Remove(HitNumber);
	HitNumber->RemoveFromParent();
}