// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
struct FDamageEvent;
class AController;
#ifdef TEAMAI_AIBase_generated_h
#error "AIBase.generated.h already included, missing '#pragma once' in AIBase.h"
#endif
#define TEAMAI_AIBase_generated_h

#define KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_AIBase_h_14_DELEGATE \
struct _Script_TeamAI_eventOneDynamicMultiCastDelegateActor_Parms \
{ \
	AActor* actor; \
}; \
static inline void FOneDynamicMultiCastDelegateActor_DelegateWrapper(const FMulticastScriptDelegate& OneDynamicMultiCastDelegateActor, AActor* actor) \
{ \
	_Script_TeamAI_eventOneDynamicMultiCastDelegateActor_Parms Parms; \
	Parms.actor=actor; \
	OneDynamicMultiCastDelegateActor.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_AIBase_h_13_DELEGATE \
struct _Script_TeamAI_eventOneDynamicMultiCastDelegateString_Parms \
{ \
	FString msg; \
}; \
static inline void FOneDynamicMultiCastDelegateString_DelegateWrapper(const FMulticastScriptDelegate& OneDynamicMultiCastDelegateString, const FString& msg) \
{ \
	_Script_TeamAI_eventOneDynamicMultiCastDelegateString_Parms Parms; \
	Parms.msg=msg; \
	OneDynamicMultiCastDelegateString.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_AIBase_h_19_SPARSE_DATA
#define KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_AIBase_h_19_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execRespawnEvent); \
	DECLARE_FUNCTION(execHitEvent); \
	DECLARE_FUNCTION(execDeadEvent); \
	DECLARE_FUNCTION(execSetActorActive); \
	DECLARE_FUNCTION(execTakeDamage); \
	DECLARE_FUNCTION(execAIDeadCheck); \
	DECLARE_FUNCTION(execAIRespawn); \
	DECLARE_FUNCTION(execAIDead); \
	DECLARE_FUNCTION(execAIHit); \
	DECLARE_FUNCTION(execPatrol); \
	DECLARE_FUNCTION(execSetAIMove);


#define KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_AIBase_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execRespawnEvent); \
	DECLARE_FUNCTION(execHitEvent); \
	DECLARE_FUNCTION(execDeadEvent); \
	DECLARE_FUNCTION(execSetActorActive); \
	DECLARE_FUNCTION(execTakeDamage); \
	DECLARE_FUNCTION(execAIDeadCheck); \
	DECLARE_FUNCTION(execAIRespawn); \
	DECLARE_FUNCTION(execAIDead); \
	DECLARE_FUNCTION(execAIHit); \
	DECLARE_FUNCTION(execPatrol); \
	DECLARE_FUNCTION(execSetAIMove);


#define KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_AIBase_h_19_EVENT_PARMS \
	struct AIBase_eventAttackEnemy_Parms \
	{ \
		AActor* EnemyActor; \
	};


#define KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_AIBase_h_19_CALLBACK_WRAPPERS
#define KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_AIBase_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAAIBase(); \
	friend struct Z_Construct_UClass_AAIBase_Statics; \
public: \
	DECLARE_CLASS(AAIBase, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/TeamAI"), NO_API) \
	DECLARE_SERIALIZER(AAIBase)


#define KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_AIBase_h_19_INCLASS \
private: \
	static void StaticRegisterNativesAAIBase(); \
	friend struct Z_Construct_UClass_AAIBase_Statics; \
public: \
	DECLARE_CLASS(AAIBase, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/TeamAI"), NO_API) \
	DECLARE_SERIALIZER(AAIBase)


#define KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_AIBase_h_19_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AAIBase(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AAIBase) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AAIBase); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AAIBase); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AAIBase(AAIBase&&); \
	NO_API AAIBase(const AAIBase&); \
public:


#define KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_AIBase_h_19_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AAIBase(AAIBase&&); \
	NO_API AAIBase(const AAIBase&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AAIBase); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AAIBase); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AAIBase)


#define KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_AIBase_h_19_PRIVATE_PROPERTY_OFFSET
#define KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_AIBase_h_16_PROLOG \
	KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_AIBase_h_19_EVENT_PARMS


#define KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_AIBase_h_19_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_AIBase_h_19_PRIVATE_PROPERTY_OFFSET \
	KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_AIBase_h_19_SPARSE_DATA \
	KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_AIBase_h_19_RPC_WRAPPERS \
	KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_AIBase_h_19_CALLBACK_WRAPPERS \
	KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_AIBase_h_19_INCLASS \
	KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_AIBase_h_19_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_AIBase_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_AIBase_h_19_PRIVATE_PROPERTY_OFFSET \
	KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_AIBase_h_19_SPARSE_DATA \
	KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_AIBase_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_AIBase_h_19_CALLBACK_WRAPPERS \
	KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_AIBase_h_19_INCLASS_NO_PURE_DECLS \
	KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_AIBase_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TEAMAI_API UClass* StaticClass<class AAIBase>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_AIBase_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
