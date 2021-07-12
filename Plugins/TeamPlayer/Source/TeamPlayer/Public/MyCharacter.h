// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
//#include "GameFramework/Actor.h"
#include "Animation/AnimMontage.h"
#include "Components/CapsuleComponent.h"
#include "Components/ArrowComponent.h"
#include "Kismet/GameplayStatics.h"
#include "MyCharacter.generated.h"


UCLASS()
class TEAMPLAYER_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

		//º¯¼ö
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = TeamProject)
		bool IsAttack;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = TeamProject)
		bool IsHit;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = TeamProject)
		float fHP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = TeamProject)
		float fMaxHP;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = TeamProject)
		bool IsDead;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = TeamProject)
		bool ComboOn;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = TeamProject)
		bool IsOverlapItem;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = TeamProject)
		bool bDodge;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = TeamProject)
		UAnimMontage * AM_AttackMontage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = TeamProject)
		UAnimMontage * AM_DodgeMontage;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = TeamProject)
		int DodgeDir;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = TeamProject)
		class UCameraComponent*			m_TPSCamera;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = TeamProject)
		class USpringArmComponent*		m_TPSCameraBoomComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = TeamProject)
		class USkeletalMeshComponent*	m_SKM_CharacterMeshComponent;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = TeamProject)
		class UStaticMeshComponent*		m_SM_WeaponSocket;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = TeamProject)
		class UCapsuleComponent*		m_collision;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = TeamProject)
		class UParticleSystem*			m_PS_AttackParticle;


public:
	// Sets default values for this character's properties
	AMyCharacter();
	AMyCharacter(const FObjectInitializer& obj);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveForward(float value);
	void MoveRight(float value);
	void TurnAtRate(float value);
	void LookUpAtRate(float value);

	void Attack();
	void InterectOverlap();
	void Dodge();

	


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UFUNCTION()
		void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	UFUNCTION()
		void OnOverlapEnd(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	UFUNCTION()
		virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, class AController* EventInstigator, class AActor* DamageCauser);
	UFUNCTION()
		void OverlappedActor(FName TagName);

};
