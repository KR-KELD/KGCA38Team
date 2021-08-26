// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FVector;
#ifdef TEAMAI_PatrolPoint_generated_h
#error "PatrolPoint.generated.h already included, missing '#pragma once' in PatrolPoint.h"
#endif
#define TEAMAI_PatrolPoint_generated_h

#define KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_PatrolPoint_h_21_SPARSE_DATA
#define KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_PatrolPoint_h_21_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetRoundTripPoint); \
	DECLARE_FUNCTION(execGetCirclePoint); \
	DECLARE_FUNCTION(execGetPatrolPoint);


#define KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_PatrolPoint_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetRoundTripPoint); \
	DECLARE_FUNCTION(execGetCirclePoint); \
	DECLARE_FUNCTION(execGetPatrolPoint);


#define KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_PatrolPoint_h_21_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAPatrolPoint(); \
	friend struct Z_Construct_UClass_APatrolPoint_Statics; \
public: \
	DECLARE_CLASS(APatrolPoint, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/TeamAI"), NO_API) \
	DECLARE_SERIALIZER(APatrolPoint)


#define KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_PatrolPoint_h_21_INCLASS \
private: \
	static void StaticRegisterNativesAPatrolPoint(); \
	friend struct Z_Construct_UClass_APatrolPoint_Statics; \
public: \
	DECLARE_CLASS(APatrolPoint, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/TeamAI"), NO_API) \
	DECLARE_SERIALIZER(APatrolPoint)


#define KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_PatrolPoint_h_21_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API APatrolPoint(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(APatrolPoint) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APatrolPoint); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APatrolPoint); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APatrolPoint(APatrolPoint&&); \
	NO_API APatrolPoint(const APatrolPoint&); \
public:


#define KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_PatrolPoint_h_21_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API APatrolPoint(APatrolPoint&&); \
	NO_API APatrolPoint(const APatrolPoint&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, APatrolPoint); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(APatrolPoint); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(APatrolPoint)


#define KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_PatrolPoint_h_21_PRIVATE_PROPERTY_OFFSET
#define KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_PatrolPoint_h_18_PROLOG
#define KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_PatrolPoint_h_21_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_PatrolPoint_h_21_PRIVATE_PROPERTY_OFFSET \
	KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_PatrolPoint_h_21_SPARSE_DATA \
	KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_PatrolPoint_h_21_RPC_WRAPPERS \
	KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_PatrolPoint_h_21_INCLASS \
	KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_PatrolPoint_h_21_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_PatrolPoint_h_21_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_PatrolPoint_h_21_PRIVATE_PROPERTY_OFFSET \
	KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_PatrolPoint_h_21_SPARSE_DATA \
	KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_PatrolPoint_h_21_RPC_WRAPPERS_NO_PURE_DECLS \
	KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_PatrolPoint_h_21_INCLASS_NO_PURE_DECLS \
	KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_PatrolPoint_h_21_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TEAMAI_API UClass* StaticClass<class APatrolPoint>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID KGCA38Team_Plugins_TeamAI_Source_TeamAI_Public_PatrolPoint_h


#define FOREACH_ENUM_EPATROLTYPE(op) \
	op(EPatrolType::EPatrol_RandomPoint) \
	op(EPatrolType::EPatrol_CirclePoints) \
	op(EPatrolType::EPatrol_RoundTripPoints) 

enum class EPatrolType : uint8;
template<> TEAMAI_API UEnum* StaticEnum<EPatrolType>();

PRAGMA_ENABLE_DEPRECATION_WARNINGS
