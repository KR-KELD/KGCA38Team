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

	// AreaSphere�� ��ġ�� ȣ��
	UFUNCTION()
	void OnSphereOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	// AreaSphere�� �������� ������ ȣ��
	UFUNCTION()
	void OnSphereEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp,
			int32 OtherBodyIndex);

private:
	// NPC �̸�.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPC", meta = (AllowPrivateAccess = "true"))
	FString Name;

	// NPC ��ȭ���� ����.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPC", meta = (AllowPrivateAccess = "true"))
	FString DialogText;

	// ���������� ����Ʈ���̽� Ȱ��ȭ
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "NPC", meta = (AllowPrivateAccess = "true"))
	USphereComponent* AreaSphere;

	// ĳ���Ͱ� �ٶ������ �˾��� ����
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "NPC", meta = (AllowPrivateAccess = "true"))
	UWidgetComponent* InteractionWidget;

	// �䱸 ������ Ÿ��
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPC", meta = (AllowPrivateAccess = "true"))
	EItemType NeedItemType;

	// �䱸 ������ ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPC", meta = (AllowPrivateAccess = "true"))
	int32 NeedItemCount;

	// �䱸 ������ �̸�
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "NPC", meta = (AllowPrivateAccess = "true"))
	FString NeedItemName;

public:
	FORCEINLINE UWidgetComponent* GetInteractionWidget() const { return InteractionWidget; }

};
