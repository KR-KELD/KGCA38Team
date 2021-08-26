// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TeamPlayer/Public/MyBoss.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyBoss() {}
// Cross Module References
	TEAMPLAYER_API UEnum* Z_Construct_UEnum_TeamPlayer_EBossState();
	UPackage* Z_Construct_UPackage__Script_TeamPlayer();
	TEAMPLAYER_API UClass* Z_Construct_UClass_AMyBoss_NoRegister();
	TEAMPLAYER_API UClass* Z_Construct_UClass_AMyBoss();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	ENGINE_API UClass* Z_Construct_UClass_UAnimMontage_NoRegister();
// End Cross Module References
	static UEnum* EBossState_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_TeamPlayer_EBossState, Z_Construct_UPackage__Script_TeamPlayer(), TEXT("EBossState"));
		}
		return Singleton;
	}
	template<> TEAMPLAYER_API UEnum* StaticEnum<EBossState>()
	{
		return EBossState_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EBossState(EBossState_StaticEnum, TEXT("/Script/TeamPlayer"), TEXT("EBossState"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_TeamPlayer_EBossState_Hash() { return 2368679644U; }
	UEnum* Z_Construct_UEnum_TeamPlayer_EBossState()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_TeamPlayer();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EBossState"), 0, Get_Z_Construct_UEnum_TeamPlayer_EBossState_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EBossState::EBS_IDLE", (int64)EBossState::EBS_IDLE },
				{ "EBossState::EBS_Chase", (int64)EBossState::EBS_Chase },
				{ "EBossState::EBS_Attack", (int64)EBossState::EBS_Attack },
				{ "EBossState::EBS_JumpAttack", (int64)EBossState::EBS_JumpAttack },
				{ "EBossState::EBS_Breath", (int64)EBossState::EBS_Breath },
				{ "EBossState::EBS_Rage", (int64)EBossState::EBS_Rage },
				{ "EBossState::EBS_RageAttack", (int64)EBossState::EBS_RageAttack },
				{ "EBossState::EBS_BossDead", (int64)EBossState::EBS_BossDead },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "EBS_Attack.DisplayName", "Attack" },
				{ "EBS_Attack.Name", "EBossState::EBS_Attack" },
				{ "EBS_BossDead.Displayname", "BossDead" },
				{ "EBS_BossDead.Name", "EBossState::EBS_BossDead" },
				{ "EBS_Breath.DisplayName", "Breath" },
				{ "EBS_Breath.Name", "EBossState::EBS_Breath" },
				{ "EBS_Chase.DisplayName", "Chase" },
				{ "EBS_Chase.Name", "EBossState::EBS_Chase" },
				{ "EBS_IDLE.DisplayName", "Idle" },
				{ "EBS_IDLE.Name", "EBossState::EBS_IDLE" },
				{ "EBS_JumpAttack.DisplayName", "JumpAttack" },
				{ "EBS_JumpAttack.Name", "EBossState::EBS_JumpAttack" },
				{ "EBS_Rage.Displayname", "Rage" },
				{ "EBS_Rage.Name", "EBossState::EBS_Rage" },
				{ "EBS_RageAttack.Displayname", "RageAttack" },
				{ "EBS_RageAttack.Name", "EBossState::EBS_RageAttack" },
				{ "ModuleRelativePath", "Public/MyBoss.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_TeamPlayer,
				nullptr,
				"EBossState",
				"EBossState",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::EnumClass,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
	void AMyBoss::StaticRegisterNativesAMyBoss()
	{
	}
	UClass* Z_Construct_UClass_AMyBoss_NoRegister()
	{
		return AMyBoss::StaticClass();
	}
	struct Z_Construct_UClass_AMyBoss_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ChaseDist_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ChaseDist;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AttackDist_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_AttackDist;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_JumpOrBreathDist_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_JumpOrBreathDist;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bBossChase_MetaData[];
#endif
		static void NewProp_bBossChase_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bBossChase;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bBossJumpAttack_MetaData[];
#endif
		static void NewProp_bBossJumpAttack_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bBossJumpAttack;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bBossRageAttackRun_MetaData[];
#endif
		static void NewProp_bBossRageAttackRun_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bBossRageAttackRun;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_bBossDead_MetaData[];
#endif
		static void NewProp_bBossDead_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bBossDead;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_iBossNormalAttackSplit_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_iBossNormalAttackSplit;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_iRageCount_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_iRageCount;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_iRageAttackCount_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_iRageAttackCount;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HP_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_HP;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaxHP_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_MaxHP;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Damage_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Damage;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HitBackRate_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_HitBackRate;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AirBorneRate_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_AirBorneRate;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_ECheckBossState_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ECheckBossState_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_ECheckBossState;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_EPrevBossState_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_EPrevBossState_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_EPrevBossState;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AM_JumpAttack_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_AM_JumpAttack;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AM_NormalAttack_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_AM_NormalAttack;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AM_RageAttack_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_AM_RageAttack;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMyBoss_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_TeamPlayer,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBoss_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "MyBoss.h" },
		{ "ModuleRelativePath", "Public/MyBoss.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBoss_Statics::NewProp_ChaseDist_MetaData[] = {
		{ "Category", "PlayerDistCheck" },
		{ "ModuleRelativePath", "Public/MyBoss.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMyBoss_Statics::NewProp_ChaseDist = { "ChaseDist", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBoss, ChaseDist), METADATA_PARAMS(Z_Construct_UClass_AMyBoss_Statics::NewProp_ChaseDist_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBoss_Statics::NewProp_ChaseDist_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBoss_Statics::NewProp_AttackDist_MetaData[] = {
		{ "Category", "PlayerDistCheck" },
		{ "ModuleRelativePath", "Public/MyBoss.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMyBoss_Statics::NewProp_AttackDist = { "AttackDist", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBoss, AttackDist), METADATA_PARAMS(Z_Construct_UClass_AMyBoss_Statics::NewProp_AttackDist_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBoss_Statics::NewProp_AttackDist_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBoss_Statics::NewProp_JumpOrBreathDist_MetaData[] = {
		{ "Category", "PlayerDistCheck" },
		{ "ModuleRelativePath", "Public/MyBoss.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMyBoss_Statics::NewProp_JumpOrBreathDist = { "JumpOrBreathDist", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBoss, JumpOrBreathDist), METADATA_PARAMS(Z_Construct_UClass_AMyBoss_Statics::NewProp_JumpOrBreathDist_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBoss_Statics::NewProp_JumpOrBreathDist_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBoss_Statics::NewProp_bBossChase_MetaData[] = {
		{ "Category", "PlayerDistCheck" },
		{ "ModuleRelativePath", "Public/MyBoss.h" },
	};
#endif
	void Z_Construct_UClass_AMyBoss_Statics::NewProp_bBossChase_SetBit(void* Obj)
	{
		((AMyBoss*)Obj)->bBossChase = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMyBoss_Statics::NewProp_bBossChase = { "bBossChase", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AMyBoss), &Z_Construct_UClass_AMyBoss_Statics::NewProp_bBossChase_SetBit, METADATA_PARAMS(Z_Construct_UClass_AMyBoss_Statics::NewProp_bBossChase_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBoss_Statics::NewProp_bBossChase_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBoss_Statics::NewProp_bBossJumpAttack_MetaData[] = {
		{ "Category", "PlayerDistCheck" },
		{ "ModuleRelativePath", "Public/MyBoss.h" },
	};
#endif
	void Z_Construct_UClass_AMyBoss_Statics::NewProp_bBossJumpAttack_SetBit(void* Obj)
	{
		((AMyBoss*)Obj)->bBossJumpAttack = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMyBoss_Statics::NewProp_bBossJumpAttack = { "bBossJumpAttack", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AMyBoss), &Z_Construct_UClass_AMyBoss_Statics::NewProp_bBossJumpAttack_SetBit, METADATA_PARAMS(Z_Construct_UClass_AMyBoss_Statics::NewProp_bBossJumpAttack_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBoss_Statics::NewProp_bBossJumpAttack_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBoss_Statics::NewProp_bBossRageAttackRun_MetaData[] = {
		{ "Category", "PlayerDistCheck" },
		{ "ModuleRelativePath", "Public/MyBoss.h" },
	};
#endif
	void Z_Construct_UClass_AMyBoss_Statics::NewProp_bBossRageAttackRun_SetBit(void* Obj)
	{
		((AMyBoss*)Obj)->bBossRageAttackRun = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMyBoss_Statics::NewProp_bBossRageAttackRun = { "bBossRageAttackRun", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AMyBoss), &Z_Construct_UClass_AMyBoss_Statics::NewProp_bBossRageAttackRun_SetBit, METADATA_PARAMS(Z_Construct_UClass_AMyBoss_Statics::NewProp_bBossRageAttackRun_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBoss_Statics::NewProp_bBossRageAttackRun_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBoss_Statics::NewProp_bBossDead_MetaData[] = {
		{ "Category", "PlayerDistCheck" },
		{ "ModuleRelativePath", "Public/MyBoss.h" },
	};
#endif
	void Z_Construct_UClass_AMyBoss_Statics::NewProp_bBossDead_SetBit(void* Obj)
	{
		((AMyBoss*)Obj)->bBossDead = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMyBoss_Statics::NewProp_bBossDead = { "bBossDead", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AMyBoss), &Z_Construct_UClass_AMyBoss_Statics::NewProp_bBossDead_SetBit, METADATA_PARAMS(Z_Construct_UClass_AMyBoss_Statics::NewProp_bBossDead_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBoss_Statics::NewProp_bBossDead_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBoss_Statics::NewProp_iBossNormalAttackSplit_MetaData[] = {
		{ "Category", "PlayerDistCheck" },
		{ "ModuleRelativePath", "Public/MyBoss.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_AMyBoss_Statics::NewProp_iBossNormalAttackSplit = { "iBossNormalAttackSplit", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBoss, iBossNormalAttackSplit), METADATA_PARAMS(Z_Construct_UClass_AMyBoss_Statics::NewProp_iBossNormalAttackSplit_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBoss_Statics::NewProp_iBossNormalAttackSplit_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBoss_Statics::NewProp_iRageCount_MetaData[] = {
		{ "Category", "PlayerDistCheck" },
		{ "ModuleRelativePath", "Public/MyBoss.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_AMyBoss_Statics::NewProp_iRageCount = { "iRageCount", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBoss, iRageCount), METADATA_PARAMS(Z_Construct_UClass_AMyBoss_Statics::NewProp_iRageCount_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBoss_Statics::NewProp_iRageCount_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBoss_Statics::NewProp_iRageAttackCount_MetaData[] = {
		{ "Category", "PlayerDistCheck" },
		{ "ModuleRelativePath", "Public/MyBoss.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_AMyBoss_Statics::NewProp_iRageAttackCount = { "iRageAttackCount", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBoss, iRageAttackCount), METADATA_PARAMS(Z_Construct_UClass_AMyBoss_Statics::NewProp_iRageAttackCount_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBoss_Statics::NewProp_iRageAttackCount_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBoss_Statics::NewProp_HP_MetaData[] = {
		{ "Category", "BossStat" },
		{ "ModuleRelativePath", "Public/MyBoss.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMyBoss_Statics::NewProp_HP = { "HP", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBoss, HP), METADATA_PARAMS(Z_Construct_UClass_AMyBoss_Statics::NewProp_HP_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBoss_Statics::NewProp_HP_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBoss_Statics::NewProp_MaxHP_MetaData[] = {
		{ "Category", "BossStat" },
		{ "ModuleRelativePath", "Public/MyBoss.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMyBoss_Statics::NewProp_MaxHP = { "MaxHP", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBoss, MaxHP), METADATA_PARAMS(Z_Construct_UClass_AMyBoss_Statics::NewProp_MaxHP_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBoss_Statics::NewProp_MaxHP_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBoss_Statics::NewProp_Damage_MetaData[] = {
		{ "Category", "BossStat" },
		{ "ModuleRelativePath", "Public/MyBoss.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMyBoss_Statics::NewProp_Damage = { "Damage", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBoss, Damage), METADATA_PARAMS(Z_Construct_UClass_AMyBoss_Statics::NewProp_Damage_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBoss_Statics::NewProp_Damage_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBoss_Statics::NewProp_HitBackRate_MetaData[] = {
		{ "Category", "BossStat" },
		{ "ModuleRelativePath", "Public/MyBoss.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMyBoss_Statics::NewProp_HitBackRate = { "HitBackRate", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBoss, HitBackRate), METADATA_PARAMS(Z_Construct_UClass_AMyBoss_Statics::NewProp_HitBackRate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBoss_Statics::NewProp_HitBackRate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBoss_Statics::NewProp_AirBorneRate_MetaData[] = {
		{ "Category", "BossStat" },
		{ "ModuleRelativePath", "Public/MyBoss.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AMyBoss_Statics::NewProp_AirBorneRate = { "AirBorneRate", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBoss, AirBorneRate), METADATA_PARAMS(Z_Construct_UClass_AMyBoss_Statics::NewProp_AirBorneRate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBoss_Statics::NewProp_AirBorneRate_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_AMyBoss_Statics::NewProp_ECheckBossState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBoss_Statics::NewProp_ECheckBossState_MetaData[] = {
		{ "Category", "BossStateCheck" },
		{ "ModuleRelativePath", "Public/MyBoss.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UClass_AMyBoss_Statics::NewProp_ECheckBossState = { "ECheckBossState", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBoss, ECheckBossState), Z_Construct_UEnum_TeamPlayer_EBossState, METADATA_PARAMS(Z_Construct_UClass_AMyBoss_Statics::NewProp_ECheckBossState_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBoss_Statics::NewProp_ECheckBossState_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_AMyBoss_Statics::NewProp_EPrevBossState_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBoss_Statics::NewProp_EPrevBossState_MetaData[] = {
		{ "Category", "BossStateCheck" },
		{ "ModuleRelativePath", "Public/MyBoss.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UClass_AMyBoss_Statics::NewProp_EPrevBossState = { "EPrevBossState", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBoss, EPrevBossState), Z_Construct_UEnum_TeamPlayer_EBossState, METADATA_PARAMS(Z_Construct_UClass_AMyBoss_Statics::NewProp_EPrevBossState_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBoss_Statics::NewProp_EPrevBossState_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBoss_Statics::NewProp_AM_JumpAttack_MetaData[] = {
		{ "Category", "Boss" },
		{ "ModuleRelativePath", "Public/MyBoss.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyBoss_Statics::NewProp_AM_JumpAttack = { "AM_JumpAttack", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBoss, AM_JumpAttack), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyBoss_Statics::NewProp_AM_JumpAttack_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBoss_Statics::NewProp_AM_JumpAttack_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBoss_Statics::NewProp_AM_NormalAttack_MetaData[] = {
		{ "Category", "Boss" },
		{ "ModuleRelativePath", "Public/MyBoss.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyBoss_Statics::NewProp_AM_NormalAttack = { "AM_NormalAttack", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBoss, AM_NormalAttack), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyBoss_Statics::NewProp_AM_NormalAttack_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBoss_Statics::NewProp_AM_NormalAttack_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBoss_Statics::NewProp_AM_RageAttack_MetaData[] = {
		{ "Category", "Boss" },
		{ "ModuleRelativePath", "Public/MyBoss.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyBoss_Statics::NewProp_AM_RageAttack = { "AM_RageAttack", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBoss, AM_RageAttack), Z_Construct_UClass_UAnimMontage_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyBoss_Statics::NewProp_AM_RageAttack_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBoss_Statics::NewProp_AM_RageAttack_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMyBoss_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBoss_Statics::NewProp_ChaseDist,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBoss_Statics::NewProp_AttackDist,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBoss_Statics::NewProp_JumpOrBreathDist,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBoss_Statics::NewProp_bBossChase,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBoss_Statics::NewProp_bBossJumpAttack,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBoss_Statics::NewProp_bBossRageAttackRun,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBoss_Statics::NewProp_bBossDead,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBoss_Statics::NewProp_iBossNormalAttackSplit,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBoss_Statics::NewProp_iRageCount,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBoss_Statics::NewProp_iRageAttackCount,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBoss_Statics::NewProp_HP,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBoss_Statics::NewProp_MaxHP,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBoss_Statics::NewProp_Damage,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBoss_Statics::NewProp_HitBackRate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBoss_Statics::NewProp_AirBorneRate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBoss_Statics::NewProp_ECheckBossState_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBoss_Statics::NewProp_ECheckBossState,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBoss_Statics::NewProp_EPrevBossState_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBoss_Statics::NewProp_EPrevBossState,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBoss_Statics::NewProp_AM_JumpAttack,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBoss_Statics::NewProp_AM_NormalAttack,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBoss_Statics::NewProp_AM_RageAttack,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMyBoss_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMyBoss>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMyBoss_Statics::ClassParams = {
		&AMyBoss::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AMyBoss_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AMyBoss_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AMyBoss_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBoss_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMyBoss()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMyBoss_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMyBoss, 3466840118);
	template<> TEAMPLAYER_API UClass* StaticClass<AMyBoss>()
	{
		return AMyBoss::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMyBoss(Z_Construct_UClass_AMyBoss, &AMyBoss::StaticClass, TEXT("/Script/TeamPlayer"), TEXT("AMyBoss"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMyBoss);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
