// Fill out your copyright notice in the Description page of Project Settings.

#include "Item.h"
#include "Components/SphereComponent.h"
#include "Components/WidgetComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Sound/SoundCue.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/PlayerController.h"
#include "MainPlayerController.h"
#include "Kismet/GameplayStatics.h"
#include "Particles/ParticleSystemComponent.h"

// Sets default values
AItem::AItem()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ObjectMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ObjectMesh"));
	//ObjectMesh->SetWorldScale3D(FVector(2.0f));
	SetRootComponent(ObjectMesh);

	PickupSphere = CreateDefaultSubobject<USphereComponent>(TEXT("PickupSphere"));
	PickupSphere->SetSphereRadius(300.0f);
	PickupSphere->SetupAttachment(GetRootComponent());

	PickupWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("PickupWidget"));
	PickupWidget->SetupAttachment(GetRootComponent());

	ItemParticle = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Particles"));
	ItemParticle->SetupAttachment(GetRootComponent());

}

// Called when the game starts or when spawned
void AItem::BeginPlay()
{
	Super::BeginPlay();

	if (PickupWidget)
	{
		// ???? ???? ????
		PickupWidget->SetVisibility(false);
	}

	if (ItemParticle)
	{
		ItemParticle->Activate();
	}

	PickupSphere->OnComponentBeginOverlap.AddDynamic(this, &AItem::OnPickupSphereOverlap);
	PickupSphere->OnComponentEndOverlap.AddDynamic(this, &AItem::OnPickupSphereEndOverlap);

}

// Called every frame
void AItem::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AItem::OnPickupSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->ActorHasTag(FName(TEXT("Player"))))
	{

		//AMainCharacter* MainCharacter = Cast<AMainCharacter>(OtherActor);
		AMainPlayerController* controller = Cast<AMainPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
		UE_LOG(LogTemp, Warning, TEXT("Item Overlap"));
		// ??ģ?? ?÷??̾? ĳ???Ͱ? ??????
		if (controller)
		{
			if (controller->bSetOverlap == true)
			{
				// ??ģ ?׸? ?? ????
				PickupWidget->SetVisibility(true);
				controller->bInterActionKey = true;
				controller->SetOverlapItem(this);
				controller->IncreamentOverlappedItemCount(1);
			}
		}

	}
}

void AItem::OnPickupSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex)
{
	if (OtherActor->ActorHasTag(FName(TEXT("Player"))))
	{
		//AMainCharacter* MainCharacter = Cast<AMainCharacter>(OtherActor);
		AMainPlayerController* controller = Cast<AMainPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));

		// ??ģ?? ?÷??̾? ĳ???Ͱ? ??????
		if (controller)
		{
			// ??ģ ?׸? ?? ????
			controller->IncreamentOverlappedItemCount(-1);
			controller->bInterActionKey = false;
			controller->SetOverlapItem(nullptr);
		}

		PickupWidget->SetVisibility(false);
		//HideNPCDialogText();
	}

}



