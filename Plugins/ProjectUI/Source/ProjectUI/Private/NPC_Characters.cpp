//// Fill out your copyright notice in the Description page of Project Settings.
//
//#include "ProjectUI.h"
//#include "NPC_Characters.h"
//#include "Components/SphereComponent.h"
//#include "Components/WidgetComponent.h"
//#include "MainCharacter.h"
//#include "MainPlayerController.h"
//#include "Kismet/GameplayStatics.h"
//
//
//ANPC_Characters::ANPC_Characters()
//{
//	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
//	PrimaryActorTick.bCanEverTick = true;
//
//	AreaSphere = CreateDefaultSubobject<USphereComponent>(TEXT("AreaSphere"));
//	AreaSphere->SetupAttachment(GetRootComponent());
//
//	InteractionWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("InterActionWidget"));
//	InteractionWidget->SetupAttachment(GetRootComponent());
//
//}
//
//// Called when the game starts or when spawned
//void ANPC_Characters::BeginPlay()
//{
//	Super::BeginPlay();
//
//	if (InteractionWidget)
//	{
//		// 정보 위젯 숨김
//		InteractionWidget->SetVisibility(false);
//	}
//
//	AreaSphere->OnComponentBeginOverlap.AddDynamic(this, &ANPC_Characters::OnSphereOverlap);
//	AreaSphere->OnComponentEndOverlap.AddDynamic(this, &ANPC_Characters::OnSphereEndOverlap);
//
//}
//
//// Called every frame
//void ANPC_Characters::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//}
//
//// Called to bind functionality to input
//void ANPC_Characters::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
//{
//	Super::SetupPlayerInputComponent(PlayerInputComponent);
//
//}
//
//void ANPC_Characters::OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
//	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
//{
//	if (OtherActor)
//	{
//		AMainCharacter* MainCharacter = Cast<AMainCharacter>(OtherActor);
//		AMainPlayerController* controller = Cast<AMainPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
//
//		// 겹친게 플레이어 캐릭터가 맞으면
//		if (MainCharacter && controller)
//		{
//			// 겹친 항목 수 증가
//			controller->IncreamentOverlappedItemCount(1);
//		}
//	}
//}
//
//void ANPC_Characters::OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
//	int32 OtherBodyIndex)
//{
//	if (OtherActor)
//	{
//		AMainCharacter* MainCharacter = Cast<AMainCharacter>(OtherActor);
//		AMainPlayerController* controller = Cast<AMainPlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
//
//		// 겹친게 플레이어 캐릭터가 맞으면
//		if (MainCharacter && controller)
//		{
//			// 겹친 항목 수 감소
//			controller->IncreamentOverlappedItemCount(-1);
//			controller->bInterActionKey = false;
//		}
//
//		InteractionWidget->SetVisibility(false);
//		HideNPCDialogText();
//	}
//
//}
//
