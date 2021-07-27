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
	// PickupSphere�� ��ġ�� ȣ��
	UFUNCTION()
	void OnPickupSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// PickupSphere�� �������� ������ ȣ��
	UFUNCTION()
	void OnPickupSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex);

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Object, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* ObjectMesh;

	// ������ Ÿ��
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item", meta = (AllowPrivateAccess = "true"))
	EItemType ItemType;

	// �κ��丮�� ���� ĭ ��ȣ
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Item", meta = (AllowPrivateAccess = "true"))
	int32 ItemIndex;

	// ������ ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item", meta = (AllowPrivateAccess = "true"))
	int32 ItemCount;

	// ������ ȸ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item", meta = (AllowPrivateAccess = "true"))
	int32 ItemHealingPoint;

	// ������ ȣ���� ��ġ
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item", meta = (AllowPrivateAccess = "true"))
	int32 ItemProbabilityPoint;

	// ������ �̸�
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item", meta = (AllowPrivateAccess = "true"))
	FString ItemName;

	// ������ ������ �ؽ�ó
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item", meta = (AllowPrivateAccess = "true"))
	UTexture2D* ItemIcon;

	// ���������� ����Ʈ���̽� Ȱ��ȭ
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Properties", meta = (AllowPrivateAccess = "true"))
	USphereComponent* PickupSphere;

	// ĳ���Ͱ� �ٶ������ �˾��� ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Properties", meta = (AllowPrivateAccess = "true"))
	UWidgetComponent* PickupWidget;

	// �Ⱦ��� ����� ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Properties", meta = (AllowPrivateAccess = "true"))
	USoundCue* PickupSound;

	// �κ��丮���� ����� ����߸��� ����� ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Properties", meta = (AllowPrivateAccess = "true"))
	USoundCue* DropItemSound;

	// ������ ���� ����� ����
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
	FORCEINLINE UStaticMeshComponent* GetObjectMesh() const { return ObjectMesh; }
	FORCEINLINE int32 GetItemHealingPoint() { return ItemHealingPoint; }

};
