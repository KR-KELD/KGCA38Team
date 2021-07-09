//// Copyright Epic Games, Inc. All Rights Reserved.
//
//#include "TeamProjectCharacter.h"
//#include "HeadMountedDisplayFunctionLibrary.h"
//#include "Camera/CameraComponent.h"
//#include "Components/CapsuleComponent.h"
//#include "Components/InputComponent.h"
//#include "GameFramework/CharacterMovementComponent.h"
//#include "GameFramework/Controller.h"
//#include "GameFramework/SpringArmComponent.h"
//#include "Kismet/GameplayStatics.h"
//#include "DrawDebugHelpers.h"
//#include "Components/WidgetComponent.h"
////#include "NPC_Character.h"
////#include "Item.h"
////#include "GameObject.h"
//#include "GameFramework/Actor.h"
//#include "Kismet/KismetMathLibrary.h"
//#include "Engine/World.h"
//#include "Sound/SoundCue.h"
//
//ATeamProjectCharacter::ATeamProjectCharacter() :
//	bShouldTraceItem(false),
//	OverlappedItemCount(0),
//	bInterActionKey(false),
//	bTraceIn(false)
//{
//	// Set size for collision capsule
//	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);
//
//	// set our turn rates for input
//	BaseTurnRate = 45.f;
//	BaseLookUpRate = 45.f;
//
//	// Don't rotate when the controller rotates. Let that just affect the camera.
//	bUseControllerRotationPitch = false;
//	bUseControllerRotationYaw = false;
//	bUseControllerRotationRoll = false;
//
//	// Configure character movement
//	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
//	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
//	GetCharacterMovement()->JumpZVelocity = 600.f;
//	GetCharacterMovement()->AirControl = 0.2f;
//
//	// Create a camera boom (pulls in towards the player if there is a collision)
//	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
//	CameraBoom->SetupAttachment(RootComponent);
//	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
//	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller
//
//	// Create a follow camera
//	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
//	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
//	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm
//
//	SpawnSocketScene = CreateDefaultSubobject<USceneComponent>(TEXT("SpawnLocationScene"));
//	SpawnSocketScene->SetupAttachment(GetRootComponent());
//
//	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
//	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
//
//}
////////////////////////////////////////////////////////////////////////////
//// Input
//
//void ATeamProjectCharacter::BeginPlay()
//{
//	Super::BeginPlay();
//
//	//Inventory.Reset(INVENTORY_MAXSIZE);
//	//QuickSlot.Reset(QUICKSLOT_MAXSIZE);
//
//	//for (int i = 0; i < INVENTORY_MAXSIZE; i++)
//	//{
//	//	Inventory.Add(nullptr);
//	//}
//
//	//for (int i = 0; i < QUICKSLOT_MAXSIZE; i++)
//	//{
//	//	QuickSlot.Add(nullptr);
//	//}
//	//Inventory.Add(nullptr);
//
//}
//
//void ATeamProjectCharacter::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//	TraceForActors();
//
//}
//
//void ATeamProjectCharacter::DropSpawnActor_Implementation(UClass* item)
//{
//	//auto* obj = Cast<AGameObject>(item);
//	//if (item)
//	//{
//	//	UWorld* World = GetWorld();
//	//	FActorSpawnParameters SpawnPrams;
//	//	const FVector Location = SpawnSocketScene->GetComponentLocation();
//
//	//	AGameObject* obj = World->SpawnActor<AGameObject>(item, Location, FRotator(0.0f), SpawnPrams);
//	//}
//
//}
//
////void ATeamProjectCharacter::DropActorSetInWorld(AItem* item)
////{
////
////	//if (item)
////	//{
////	//	auto object = Cast<AGameObject>(item);
////
////	//	if (object)
////	//	{
////	//		// ����ó���� �浹ó�� �� off �ߴ� ���¸� on���� ��ȯ.
////	//		object->GetObjectMesh()->SetSimulatePhysics(true);
////	//		object->SetActorHiddenInGame(false);
////	//		object->SetActorEnableCollision(true);
////	//		object->SetActorTickEnabled(true);
////	//		object->SetActorTransform(SpawnSocketScene->GetComponentTransform());
////
////	//		if (object->GetDropItemSound())
////	//		{
////	//			UGameplayStatics::PlaySound2D(this, object->GetDropItemSound());
////	//		}
////	//	}
////	//}
////
////}
//
//void ATeamProjectCharacter::TraceForActors()
//{
//	//if (bShouldTraceItem)
//	//{
//	//	// ���� Ʈ���̽��� ��Ҵ���. ������ ���� ������ ���.
//	//	FHitResult HitTraceResult;
//	//	FVector HitLocation;
//	//	TraceUnderScreen(HitTraceResult, HitLocation);
//	//	bool bCheckInventoryItem = false;
//
//	//	if (HitTraceResult.bBlockingHit)
//	//	{
//	//		auto npcActor = Cast<ANPC_Character>(HitTraceResult.GetActor());
//
//	//		auto Item = Cast<AGameObject>(HitTraceResult.GetActor());
//
//	//		if (Item && Item->GetPickupWidget())
//	//		{
//	//			//UE_LOG(LogTemp, Warning, TEXT("Item!"));
//	//			Item->GetPickupWidget()->SetVisibility(true);
//	//			bTraceIn = true;
//
//	//			if (bInterActionKey && bTraceIn)
//	//			{
//	//				for (int i = 0; i < INVENTORY_MAXSIZE; i++)
//	//				{
//	//					if (Inventory[i] != nullptr)
//	//					{
//	//						if (Inventory[i]->GetItemName() == Item->GetItemName())
//	//						{
//	//							Inventory[i]->SetItemCount(Inventory[i]->GetItemCount() + Item->GetItemCount());
//	//							Item->Destroy();
//
//	//							bCheckInventoryItem = true;
//
//	//							if (Item->GetPickupSound())
//	//							{
//	//								UGameplayStatics::PlaySound2D(this, Item->GetPickupSound());
//	//							}
//
//	//							break;
//	//						}
//	//					}
//	//				}
//
//	//				if (!bCheckInventoryItem)
//	//				{
//	//					for (int i = 0; i < INVENTORY_MAXSIZE; i++)
//	//					{
//	//						if (Inventory[i] == nullptr)
//	//						{
//	//							UE_LOG(LogTemp, Warning, TEXT("Inventory Index : %d"), i);
//
//	//							// �κ��丮�� ������ ������ �������� ������ �ʿ���� ����⸸ �ϸ� ��. 
//	//							Item->GetObjectMesh()->SetSimulatePhysics(false);
//	//							Item->SetActorHiddenInGame(true);
//	//							Item->SetActorEnableCollision(false);
//	//							Item->SetActorTickEnabled(false);
//
//	//							Inventory[i] = Item;
//
//	//							if (Item->GetPickupSound())
//	//							{
//	//								UGameplayStatics::PlaySound2D(this, Item->GetPickupSound());
//	//							}
//
//	//							break;
//	//						}
//	//					}
//	//				}
//
//	//				bInterActionKey = false;
//	//			}
//	//		}
//
//	//		if (npcActor && npcActor->GetInteractionWidget())
//	//		{
//	//			//UE_LOG(LogTemp, Warning, TEXT("Actor!"));
//	//			npcActor->GetInteractionWidget()->SetVisibility(true);
//	//			bTraceIn = true;
//
//	//			if (bInterActionKey && bTraceIn)
//	//			{
//	//				npcActor->ShowNPCDialogText();
//	//				bInterActionKey = false;
//	//			}
//
//	//		}
//
//	//		if (TraceHitLastActor)
//	//		{
//	//			if (TraceHitLastActor != npcActor)
//	//			{
//	//				TraceHitLastActor->GetInteractionWidget()->SetVisibility(false);
//	//				bTraceIn = false;
//	//			}
//	//		}
//
//	//		if (TraceHitLastItem)
//	//		{
//	//			if (TraceHitLastItem != Item)
//	//			{
//	//				TraceHitLastItem->GetPickupWidget()->SetVisibility(false);
//	//			}
//	//		}
//
//	//		// �������� �浹�� ���� ����
//	//		TraceHitLastActor = npcActor;
//	//		TraceHitLastItem = Item;
//	//	}
//	//	//else if (TraceHitLastActor)
//	//	//{
//	//	//	// ������ �浹������ ����� ���Ͱ� ����Ʈ���̽��� �浹���� ������ ����.
//	//	//	TraceHitLastActor->GetInteractionWidget()->SetVisibility(false);
//	//	//	bTraceIn = false;
//	//	//}
//
//	//}
//	//else if(TraceHitLastActor)
//	//{
//	//	// ������ �浹������ ����� ���Ͱ� ����Ʈ���̽��� �浹���� ������ ����.
//	//	TraceHitLastActor->GetInteractionWidget()->SetVisibility(false);
//	//	bTraceIn = false;
//	//}
//}
//
//bool ATeamProjectCharacter::TraceUnderScreen(FHitResult& OutHitResult, FVector& OutHitLocation)
//{
//	FVector2D ViewportSize;
//	if (GEngine && GEngine->GameViewport)
//	{
//		// ����Ʈ�� X,Y�� ���´�
//		GEngine->GameViewport->GetViewportSize(ViewportSize);
//	}
//
//	FVector ScreenLocation = FollowCamera->GetComponentLocation();
//	FVector EndTrace = ScreenLocation + (FollowCamera->GetForwardVector() * (CameraBoom->TargetArmLength + 3000.0f));
//
//	//FVector2D ScreenLocation(ViewportSize.X / 2.0f, ViewportSize.Y / 2.0f);
//	// ��ġ�� �߾����� �����ش�.
//	FVector ScreenWorldPos;
//	FVector ScreenWorldDirection;
//
//	// DeprojectScreenToWorld
//	// 2Dȭ�� ���� ��ǥ�� 3D ���� ���� ��ǥ �� �������� ��ȯ
//	//bool bScreenToWorld = UGameplayStatics::DeprojectScreenToWorld(UGameplayStatics::GetPlayerController(this, 0),
//	//	ScreenLocation, ScreenWorldPos, ScreenWorldDirection);
//
//	//if (bScreenToWorld)
//	//{
//	float LineTraceLength = 3000.0f;
//
//	// ������ǥ�� ũ�ν����� ����Ʈ���̽�
//	const FVector Start = ScreenWorldPos;
//	const FVector End = Start + ScreenWorldDirection * LineTraceLength;
//
//	//FCollisionQueryParams QueryParam;
//	//QueryParam.bReturnPhysicalMaterial = true;
//
//	GetWorld()->LineTraceSingleByChannel(OutHitResult, ScreenLocation, EndTrace, ECollisionChannel::ECC_Visibility,
//		FCollisionQueryParams::DefaultQueryParam, FCollisionResponseParams::DefaultResponseParam);
//
//	//DrawDebugLine(GetWorld(), ScreenLocation, EndTrace, FColor::Red, true, -1, 0, 2);
//
//	OutHitLocation = EndTrace;
//	if (!OutHitResult.bBlockingHit)
//	{
//		OutHitResult.Location = OutHitLocation;
//		return true;
//	}
//
//	//}
//
//	return false;
//
//}
//
//void ATeamProjectCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
//{
//	// Set up gameplay key bindings
//	check(PlayerInputComponent);
//	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
//	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
//
//	PlayerInputComponent->BindAxis("MoveForward", this, &ATeamProjectCharacter::MoveForward);
//	PlayerInputComponent->BindAxis("MoveRight", this, &ATeamProjectCharacter::MoveRight);
//
//	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
//	// "turn" handles devices that provide an absolute delta, such as a mouse.
//	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
//	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
//	PlayerInputComponent->BindAxis("TurnRate", this, &ATeamProjectCharacter::TurnAtRate);
//	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
//	PlayerInputComponent->BindAxis("LookUpRate", this, &ATeamProjectCharacter::LookUpAtRate);
//
//	// handle touch devices
//	PlayerInputComponent->BindTouch(IE_Pressed, this, &ATeamProjectCharacter::TouchStarted);
//	PlayerInputComponent->BindTouch(IE_Released, this, &ATeamProjectCharacter::TouchStopped);
//
//	// VR headset functionality
//	PlayerInputComponent->BindAction("ResetVR", IE_Pressed, this, &ATeamProjectCharacter::OnResetVR);
//
//	// ��ȣ�ۿ� Ű
//	PlayerInputComponent->BindAction("Talk", IE_Pressed, this, &ATeamProjectCharacter::ShowActionWidget);
//}
//
//void ATeamProjectCharacter::ShowActionWidget()
//{
//	if (CurrentHealth <= 0.0f)
//	{
//		CurrentHealth = 0.0f;
//	}
//	else
//	{
//		CurrentHealth -= 10.0f;
//	}
//
//	/*if (TraceHitLastActor || TraceHitLastItem)
//	{
//		bInterActionKey = true;
//	}*/
//}
//
//void ATeamProjectCharacter::IncreamentOverlappedItemCount(int8 Amount)
//{
//	if (OverlappedItemCount + Amount <= 0)
//	{
//		OverlappedItemCount = 0;
//		bShouldTraceItem = false;
//	}
//	else
//	{
//		OverlappedItemCount += Amount;
//		bShouldTraceItem = true;
//	}
//}
//
//void ATeamProjectCharacter::OnResetVR()
//{
//	// If TeamProject is added to a project via 'Add Feature' in the Unreal Editor the dependency on HeadMountedDisplay in TeamProject.Build.cs is not automatically propagated
//	// and a linker error will result.
//	// You will need to either:
//	//		Add "HeadMountedDisplay" to [YourProject].Build.cs PublicDependencyModuleNames in order to build successfully (appropriate if supporting VR).
//	// or:
//	//		Comment or delete the call to ResetOrientationAndPosition below (appropriate if not supporting VR)
//	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
//}
//
//void ATeamProjectCharacter::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
//{
//	Jump();
//}
//
//void ATeamProjectCharacter::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
//{
//	StopJumping();
//}
//
//void ATeamProjectCharacter::TurnAtRate(float Rate)
//{
//	// calculate delta for this frame from the rate information
//	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
//}
//
//void ATeamProjectCharacter::LookUpAtRate(float Rate)
//{
//	// calculate delta for this frame from the rate information
//	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
//}
//
//void ATeamProjectCharacter::MoveForward(float Value)
//{
//	if ((Controller != nullptr) && (Value != 0.0f))
//	{
//		// find out which way is forward
//		const FRotator Rotation = Controller->GetControlRotation();
//		const FRotator YawRotation(0, Rotation.Yaw, 0);
//
//		// get forward vector
//		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
//		AddMovementInput(Direction, Value);
//	}
//}
//
//void ATeamProjectCharacter::MoveRight(float Value)
//{
//	if ((Controller != nullptr) && (Value != 0.0f))
//	{
//		// find out which way is right
//		const FRotator Rotation = Controller->GetControlRotation();
//		const FRotator YawRotation(0, Rotation.Yaw, 0);
//
//		// get right vector 
//		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
//		// add movement in that direction
//		AddMovementInput(Direction, Value);
//	}
//}
