// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ItemType.h"
#include "Item.generated.h"

class USphereComponent;
class UWidgetComponent;
class USoundCue;

UCLASS()
class KGCA38_API AItem : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AItem();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	// PickupSphere와 겹치면 호출
	UFUNCTION()
	void OnPickupSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// PickupSphere의 오버랩이 끝나면 호출
	UFUNCTION()
	void OnPickupSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex);

private:
	// 아이템 타입
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item", meta = (AllowPrivateAccess = "true"))
	EItemType ItemType;

	// 인벤토리에 넣을 칸 번호
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item", meta = (AllowPrivateAccess = "true"))
	int32 ItemIndex;

	// 아이템 갯수
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item", meta = (AllowPrivateAccess = "true"))
	int32 ItemCount;

	// 아이템 이름
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item", meta = (AllowPrivateAccess = "true"))
	FString ItemName;

	// 아이템 아이콘 텍스처
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item", meta = (AllowPrivateAccess = "true"))
	UTexture2D* ItemIcon;

	// 겹쳐졌을때 라인트레이스 활성화
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Properties", meta = (AllowPrivateAccess = "true"))
	USphereComponent* PickupSphere;

	// 캐릭터가 바라봤을때 팝업될 위젯
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Properties", meta = (AllowPrivateAccess = "true"))
	UWidgetComponent* PickupWidget;

	// 픽업시 재생될 사운드
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Properties", meta = (AllowPrivateAccess = "true"))
	USoundCue* PickupSound;

	// 인벤토리에서 월드로 떨어뜨릴때 재생될 사운드
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Properties", meta = (AllowPrivateAccess = "true"))
	USoundCue* DropItemSound;

	// 아이템 사용시 재생될 사운드
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Properties", meta = (AllowPrivateAccess = "true"))
	USoundCue* UseItemSound;

public:
	FORCEINLINE UWidgetComponent* GetPickupWidget() const { return PickupWidget; }
	FORCEINLINE USphereComponent* GetPickupSphere() const { return PickupSphere; }
	FORCEINLINE int32 GetItemIndex() const { return ItemIndex; }
	FORCEINLINE void SetItemIndex(int32 index) { ItemIndex = index; }
	FORCEINLINE UTexture2D* GetItemIcon() const { return ItemIcon; }
	FORCEINLINE void SetItemIcon(UTexture2D* texture) { ItemIcon = texture; }
	FORCEINLINE int32 GetItemCount() { return ItemCount; }
	FORCEINLINE void SetItemCount(int32 Count) { ItemCount = Count; }
	FORCEINLINE FString GetItemName() { return ItemName; }
	FORCEINLINE void SetItemName(FString name) { ItemName = name; }
	FORCEINLINE USoundCue* GetPickupSound() const { return PickupSound; }
	FORCEINLINE USoundCue* GetDropItemSound() const { return DropItemSound; }
	FORCEINLINE USoundCue* GetUseItemSound() const { return UseItemSound; }
	FORCEINLINE EItemType GetItemType() const { return ItemType; }

};
