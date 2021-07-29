// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainPlayerController.generated.h"


class AItem;
/**
 * 
 */
UCLASS()
class KGCA38_API AMainPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	AMainPlayerController();

protected:
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	// �˾������� �� ���¿��� �׼�Ű�� ��������.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
	bool bInterActionKey;

	// ����Ʈ���̽��� ���� �˾�â�� �� �ְ�, �׼�Ű�� ������ ��, �׼�Ű ���� �������� ����Ʈ���̽� �浹�� �߻����ֳ� Ȯ���ϴ� �뵵.
	bool bTraceIn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
	bool bSetOverlap = false;

private:
	const int32 INVENTORY_MAXSIZE = 20;
	const int32 QUICKSLOT_MAXSIZE = 10;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory, meta = (AllowPrivateAccess = "true"))
	TArray<AItem*> Inventory;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory, meta = (AllowPrivateAccess = "true"))
	TArray<AItem*> QuickSlot;

	// True�� ��� �˾��� ����� ����Ʈ���̽� Ȱ��ȭ
	bool bShouldTraceItem;

	// ��ģ �������� ����
	int8 OverlappedItemCount;

	// �������� ��Ʈ�� ����
	//class ANPC_Characters* TraceHitLastActor;

	// �������� ��Ʈ�� ������
	class AItem* TraceHitLastItem;

	FVector MeshScale;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory, meta = (AllowPrivateAccess = "true"))
	AItem* OverlapItem;

	FTimerHandle OverlapTimer;

protected:

	UFUNCTION(BlueprintImplementableEvent)
	void UseItemHealingPoint(int32 IncreaseHealth);

	UFUNCTION(BlueprintCallable)
	void DropActorSetInWorld(AItem* item, FTransform transform);

	UFUNCTION(BlueprintCallable)
	void UseItem(int32 index);

	// ������ �� ���� Ȯ��
	void TraceForActors();

	// ����Ʈ���̽��� �ε�������
	bool TraceUnderScreen(FHitResult& OutHitResult, FVector& OutHitLocation);

	UFUNCTION(BlueprintCallable)
	void OverlapEndItems();

	UFUNCTION(BlueprintCallable)
	void OverlapBeginItems(AItem* item);

	void ChangeSetOverlap();

public:
	UFUNCTION(BlueprintCallable)
	void OverlapSetInventoryItems(AItem* item);


public:
	// �������� ���� �� Ȯ��. ���Ͱ� �������� �˾��� ��ġ�� �ʵ���.
	void IncreamentOverlappedItemCount(int8 Amount);

	// ��ȣ�ۿ� �׼�Ű ������ ��ȿ ��ų��
	void EnableInterActionKey();

	//FORCEINLINE ANPC_Characters* GetTraceHitLastActor() const {	return TraceHitLastActor; }
	FORCEINLINE AItem* GetTraceHitLastItem() const { return TraceHitLastItem; }
	FORCEINLINE void SetOverlapItem(AItem* item) { OverlapItem = item; }

};
