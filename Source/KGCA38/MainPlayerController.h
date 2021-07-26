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
	// 팝업위젯이 뜬 상태에서 액션키를 눌렀는지.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
	bool bInterActionKey;

	// 라인트레이스로 인한 팝업창이 떠 있고, 액션키가 눌렸을 때, 액션키 누른 시점에서 라인트레이스 충돌이 발생해있나 확인하는 용도.
	bool bTraceIn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory)
	bool bSetOverlap = false;

private:
	const int32 INVENTORY_MAXSIZE = 10;
	const int32 QUICKSLOT_MAXSIZE = 6;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory, meta = (AllowPrivateAccess = "true"))
	TArray<AItem*> Inventory;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory, meta = (AllowPrivateAccess = "true"))
	TArray<AItem*> QuickSlot;

	// True일 경우 팝업에 사용할 라인트레이스 활성화
	bool bShouldTraceItem;

	// 겹친 아이템의 갯수
	int8 OverlappedItemCount;

	// 마지막에 히트된 액터
	//class ANPC_Characters* TraceHitLastActor;

	// 마지막에 히트된 아이템
	class AItem* TraceHitLastItem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Inventory, meta = (AllowPrivateAccess = "true"))
	AItem* OverlapItem;

	FTimerHandle OverlapTimer;

protected:

	UFUNCTION(BlueprintCallable)
	void DropActorSetInWorld(AItem* item, FTransform transform);

	UFUNCTION(BlueprintCallable)
	AItem* UseItem(int32 index);

	// 오버랩 된 액터 확인
	void TraceForActors();

	// 라인트레이스가 부딪혔는지
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
	// 오버랩된 액터 수 확인. 액터가 겹쳤을때 팝업이 겹치지 않도록.
	void IncreamentOverlappedItemCount(int8 Amount);

	// 상호작용 액션키 눌림을 유효 시킬지
	void EnableInterActionKey();

	//FORCEINLINE ANPC_Characters* GetTraceHitLastActor() const {	return TraceHitLastActor; }
	FORCEINLINE AItem* GetTraceHitLastItem() const { return TraceHitLastItem; }
	FORCEINLINE void SetOverlapItem(AItem* item) { OverlapItem = item; }

};
