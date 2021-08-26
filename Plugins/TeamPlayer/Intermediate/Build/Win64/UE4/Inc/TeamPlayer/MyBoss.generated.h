// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef TEAMPLAYER_MyBoss_generated_h
#error "MyBoss.generated.h already included, missing '#pragma once' in MyBoss.h"
#endif
#define TEAMPLAYER_MyBoss_generated_h

#define KGCA38Team_Plugins_TeamPlayer_Source_TeamPlayer_Public_MyBoss_h_30_SPARSE_DATA
#define KGCA38Team_Plugins_TeamPlayer_Source_TeamPlayer_Public_MyBoss_h_30_RPC_WRAPPERS
#define KGCA38Team_Plugins_TeamPlayer_Source_TeamPlayer_Public_MyBoss_h_30_RPC_WRAPPERS_NO_PURE_DECLS
#define KGCA38Team_Plugins_TeamPlayer_Source_TeamPlayer_Public_MyBoss_h_30_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMyBoss(); \
	friend struct Z_Construct_UClass_AMyBoss_Statics; \
public: \
	DECLARE_CLASS(AMyBoss, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/TeamPlayer"), NO_API) \
	DECLARE_SERIALIZER(AMyBoss)


#define KGCA38Team_Plugins_TeamPlayer_Source_TeamPlayer_Public_MyBoss_h_30_INCLASS \
private: \
	static void StaticRegisterNativesAMyBoss(); \
	friend struct Z_Construct_UClass_AMyBoss_Statics; \
public: \
	DECLARE_CLASS(AMyBoss, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/TeamPlayer"), NO_API) \
	DECLARE_SERIALIZER(AMyBoss)


#define KGCA38Team_Plugins_TeamPlayer_Source_TeamPlayer_Public_MyBoss_h_30_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMyBoss(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMyBoss) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyBoss); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyBoss); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMyBoss(AMyBoss&&); \
	NO_API AMyBoss(const AMyBoss&); \
public:


#define KGCA38Team_Plugins_TeamPlayer_Source_TeamPlayer_Public_MyBoss_h_30_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMyBoss(AMyBoss&&); \
	NO_API AMyBoss(const AMyBoss&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyBoss); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyBoss); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMyBoss)


#define KGCA38Team_Plugins_TeamPlayer_Source_TeamPlayer_Public_MyBoss_h_30_PRIVATE_PROPERTY_OFFSET
#define KGCA38Team_Plugins_TeamPlayer_Source_TeamPlayer_Public_MyBoss_h_27_PROLOG
#define KGCA38Team_Plugins_TeamPlayer_Source_TeamPlayer_Public_MyBoss_h_30_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	KGCA38Team_Plugins_TeamPlayer_Source_TeamPlayer_Public_MyBoss_h_30_PRIVATE_PROPERTY_OFFSET \
	KGCA38Team_Plugins_TeamPlayer_Source_TeamPlayer_Public_MyBoss_h_30_SPARSE_DATA \
	KGCA38Team_Plugins_TeamPlayer_Source_TeamPlayer_Public_MyBoss_h_30_RPC_WRAPPERS \
	KGCA38Team_Plugins_TeamPlayer_Source_TeamPlayer_Public_MyBoss_h_30_INCLASS \
	KGCA38Team_Plugins_TeamPlayer_Source_TeamPlayer_Public_MyBoss_h_30_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define KGCA38Team_Plugins_TeamPlayer_Source_TeamPlayer_Public_MyBoss_h_30_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	KGCA38Team_Plugins_TeamPlayer_Source_TeamPlayer_Public_MyBoss_h_30_PRIVATE_PROPERTY_OFFSET \
	KGCA38Team_Plugins_TeamPlayer_Source_TeamPlayer_Public_MyBoss_h_30_SPARSE_DATA \
	KGCA38Team_Plugins_TeamPlayer_Source_TeamPlayer_Public_MyBoss_h_30_RPC_WRAPPERS_NO_PURE_DECLS \
	KGCA38Team_Plugins_TeamPlayer_Source_TeamPlayer_Public_MyBoss_h_30_INCLASS_NO_PURE_DECLS \
	KGCA38Team_Plugins_TeamPlayer_Source_TeamPlayer_Public_MyBoss_h_30_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TEAMPLAYER_API UClass* StaticClass<class AMyBoss>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID KGCA38Team_Plugins_TeamPlayer_Source_TeamPlayer_Public_MyBoss_h


#define FOREACH_ENUM_EBOSSSTATE(op) \
	op(EBossState::EBS_IDLE) \
	op(EBossState::EBS_Chase) \
	op(EBossState::EBS_Attack) \
	op(EBossState::EBS_JumpAttack) \
	op(EBossState::EBS_Breath) \
	op(EBossState::EBS_Rage) \
	op(EBossState::EBS_RageAttack) \
	op(EBossState::EBS_BossDead) 

enum class EBossState : uint8;
template<> TEAMPLAYER_API UEnum* StaticEnum<EBossState>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
