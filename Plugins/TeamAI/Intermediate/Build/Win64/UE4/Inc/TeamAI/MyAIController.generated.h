// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
class AAIBase;
#ifdef TEAMAI_MyAIController_generated_h
#error "MyAIController.generated.h already included, missing '#pragma once' in MyAIController.h"
#endif
#define TEAMAI_MyAIController_generated_h

#define KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_MyAIController_h_28_SPARSE_DATA
#define KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_MyAIController_h_28_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execRespawnCall); \
	DECLARE_FUNCTION(execDeadCall); \
	DECLARE_FUNCTION(execHitCall); \
	DECLARE_FUNCTION(execUpdateState); \
	DECLARE_FUNCTION(execAttackReady); \
	DECLARE_FUNCTION(execSetSenseOption); \
	DECLARE_FUNCTION(execUpdatePerceptionData);


#define KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_MyAIController_h_28_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execRespawnCall); \
	DECLARE_FUNCTION(execDeadCall); \
	DECLARE_FUNCTION(execHitCall); \
	DECLARE_FUNCTION(execUpdateState); \
	DECLARE_FUNCTION(execAttackReady); \
	DECLARE_FUNCTION(execSetSenseOption); \
	DECLARE_FUNCTION(execUpdatePerceptionData);


#define KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_MyAIController_h_28_EVENT_PARMS \
	struct MyAIController_eventBattleSelect_Parms \
	{ \
		AAIBase* AIBase; \
		FString ReturnValue; \
	}; \
	struct MyAIController_eventSetAIState_Parms \
	{ \
		FString StartState; \
	}; \
	struct MyAIController_eventStateSelect_Parms \
	{ \
		AAIBase* AIBase; \
		FString ReturnValue; \
	};


#define KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_MyAIController_h_28_CALLBACK_WRAPPERS
#define KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_MyAIController_h_28_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMyAIController(); \
	friend struct Z_Construct_UClass_AMyAIController_Statics; \
public: \
	DECLARE_CLASS(AMyAIController, AAIController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/TeamAI"), NO_API) \
	DECLARE_SERIALIZER(AMyAIController)


#define KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_MyAIController_h_28_INCLASS \
private: \
	static void StaticRegisterNativesAMyAIController(); \
	friend struct Z_Construct_UClass_AMyAIController_Statics; \
public: \
	DECLARE_CLASS(AMyAIController, AAIController, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/TeamAI"), NO_API) \
	DECLARE_SERIALIZER(AMyAIController)


#define KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_MyAIController_h_28_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMyAIController(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMyAIController) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyAIController); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyAIController); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMyAIController(AMyAIController&&); \
	NO_API AMyAIController(const AMyAIController&); \
public:


#define KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_MyAIController_h_28_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMyAIController(AMyAIController&&); \
	NO_API AMyAIController(const AMyAIController&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyAIController); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyAIController); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMyAIController)


#define KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_MyAIController_h_28_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__SightConfig() { return STRUCT_OFFSET(AMyAIController, SightConfig); } \
	FORCEINLINE static uint32 __PPO__HearingConfig() { return STRUCT_OFFSET(AMyAIController, HearingConfig); }


#define KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_MyAIController_h_25_PROLOG \
	KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_MyAIController_h_28_EVENT_PARMS


#define KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_MyAIController_h_28_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_MyAIController_h_28_PRIVATE_PROPERTY_OFFSET \
	KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_MyAIController_h_28_SPARSE_DATA \
	KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_MyAIController_h_28_RPC_WRAPPERS \
	KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_MyAIController_h_28_CALLBACK_WRAPPERS \
	KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_MyAIController_h_28_INCLASS \
	KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_MyAIController_h_28_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_MyAIController_h_28_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_MyAIController_h_28_PRIVATE_PROPERTY_OFFSET \
	KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_MyAIController_h_28_SPARSE_DATA \
	KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_MyAIController_h_28_RPC_WRAPPERS_NO_PURE_DECLS \
	KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_MyAIController_h_28_CALLBACK_WRAPPERS \
	KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_MyAIController_h_28_INCLASS_NO_PURE_DECLS \
	KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_MyAIController_h_28_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TEAMAI_API UClass* StaticClass<class AMyAIController>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_MyAIController_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
