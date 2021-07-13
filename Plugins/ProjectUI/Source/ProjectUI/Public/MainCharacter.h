//// Fill out your copyright notice in the Description page of Project Settings.
//
//#pragma once
//
//#include "CoreMinimal.h"
//#include "GameFramework/Character.h"
//#include "MainCharacter.generated.h"
//
//UCLASS()
//class PROJECTUI_API AMainCharacter : public ACharacter
//{
//	GENERATED_BODY()
//
//public:
//	// Sets default values for this character's properties
//	AMainCharacter();
//
//protected:
//	// Called when the game starts or when spawned
//	virtual void BeginPlay() override;
//
//public:	
//	// Called every frame
//	virtual void Tick(float DeltaTime) override;
//
//	// Called to bind functionality to input
//	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
//
//public:
//	/** Camera boom positioning the camera behind the character */
//	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
//	class USpringArmComponent* CameraBoom;
//
//	/** Follow camera */
//	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
//	class UCameraComponent* FollowCamera;
//
//	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
//	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
//	float BaseTurnRate;
//
//	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
//	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera)
//	float BaseLookUpRate;
//
//
//public:
//	// 현재 사용 안함.
//	UFUNCTION(BlueprintNativeEvent)
//	void DropSpawnActor(UClass* item);
//	void DropSpawnActor_Implementation(UClass* item);
//
//
//
//	////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	////////////////////////////////////////////////////////////////////////////////////////////////////////////
//			  // 추가해야 할 부분
//
//public:
//	FORCEINLINE USceneComponent* GetSceneComponent() const { return SpawnSocketScene; }
//
//private:
//
//	// 아이템을 인벤토리에서 월드로 드랍시 드랍 위치
//	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Character, meta = (AllowPrivateAccess = "true"))
//	USceneComponent* SpawnSocketScene;
//
//	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Character, meta = (AllowPrivateAccess = "true"))
//	float CurrentHealth;
//
//	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Character, meta = (AllowPrivateAccess = "true"))
//	float MaxHealth;
//
//	// 상호작용 액션키 바인드시 호출할 함수. 함수 내용만 빼가도 되지만,
//	// 플러그인 안에 있는 MainPlayerController 헤더 include 시켜줘야함.
//	void ShowActionWidget();
//
//	////////////////////////////////////////////////////////////////////////////////////////////////////////////
//	////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//
//protected:
//	/** Resets HMD orientation in VR. */
//	void OnResetVR();
//
//	/** Called for forwards/backward input */
//	void MoveForward(float Value);
//
//	/** Called for side to side input */
//	void MoveRight(float Value);
//
//	/**
//	 * Called via input to turn at a given rate.
//	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
//	 */
//	void TurnAtRate(float Rate);
//
//	/**
//	 * Called via input to turn look up/down at a given rate.
//	 * @param Rate	This is a normalized rate, i.e. 1.0 means 100% of desired turn rate
//	 */
//	void LookUpAtRate(float Rate);
//
//	/** Handler for when a touch input begins. */
//	void TouchStarted(ETouchIndex::Type FingerIndex, FVector Location);
//
//	/** Handler for when a touch input stops. */
//	void TouchStopped(ETouchIndex::Type FingerIndex, FVector Location);
//
//private:
//	bool bJump;
//
//public:
//	/** Returns CameraBoom subobject **/
//	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
//	/** Returns FollowCamera subobject **/
//	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
//};
