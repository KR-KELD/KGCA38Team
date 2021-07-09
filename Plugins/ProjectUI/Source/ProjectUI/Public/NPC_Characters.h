// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "NPC_Characters.generated.h"

class USphereComponent;
class UWidgetComponent;

UCLASS()
class PROJECTUI_API ANPC_Characters : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ANPC_Characters();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UFUNCTION(BlueprintImplementableEvent)
	void ShowNPCDialogText();

	UFUNCTION(BlueprintImplementableEvent)
	void HideNPCDialogText();

	// AreaSphere와 겹치면 호출
	UFUNCTION()
	void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// AreaSphere의 오버랩이 끝나면 호출
	UFUNCTION()
	void OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex);

private:
	// NPC 이름.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPC", meta = (AllowPrivateAccess = "true"))
	FString Name;

	// NPC 대화상자 내용.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPC", meta = (AllowPrivateAccess = "true"))
	FString DialogText;

	// 겹쳐졌을때 라인트레이스 활성화
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "NPC", meta = (AllowPrivateAccess = "true"))
	USphereComponent* AreaSphere;

	// 캐릭터가 바라봤을때 팝업될 위젯
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "NPC", meta = (AllowPrivateAccess = "true"))
	UWidgetComponent* InteractionWidget;

	// 요구 아이템 타입
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPC", meta = (AllowPrivateAccess = "true"))
	EItemType NeedItemType;

	// 요구 아이템 갯수
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPC", meta = (AllowPrivateAccess = "true"))
	int32 NeedItemCount;

	// 요구 아이템 이름
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPC", meta = (AllowPrivateAccess = "true"))
	FString NeedItemName;

public:
	FORCEINLINE UWidgetComponent* GetInteractionWidget() const { return InteractionWidget; }

};
