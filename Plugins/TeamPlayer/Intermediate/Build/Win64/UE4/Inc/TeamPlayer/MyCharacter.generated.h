// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FDamageEvent;
class AController;
class AActor;
class UPrimitiveComponent;
struct FHitResult;
struct FVector;
#ifdef TEAMPLAYER_MyCharacter_generated_h
#error "MyCharacter.generated.h already included, missing '#pragma once' in MyCharacter.h"
#endif
#define TEAMPLAYER_MyCharacter_generated_h

#define KGCA38Team_Plugins_TeamPlayer_Source_TeamPlayer_Public_MyCharacter_h_20_SPARSE_DATA
#define KGCA38Team_Plugins_TeamPlayer_Source_TeamPlayer_Public_MyCharacter_h_20_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execTakeDamage); \
	DECLARE_FUNCTION(execOnOverlapEnd); \
	DECLARE_FUNCTION(execOnOverlapBegin); \
	DECLARE_FUNCTION(execKnockbackPlayer);


#define KGCA38Team_Plugins_TeamPlayer_Source_TeamPlayer_Public_MyCharacter_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execTakeDamage); \
	DECLARE_FUNCTION(execOnOverlapEnd); \
	DECLARE_FUNCTION(execOnOverlapBegin); \
	DECLARE_FUNCTION(execKnockbackPlayer);


#define KGCA38Team_Plugins_TeamPlayer_Source_TeamPlayer_Public_MyCharacter_h_20_EVENT_PARMS \
	struct MyCharacter_eventDamageNumber_Parms \
	{ \
		int32 Damage; \
		FVector HitLocation; \
	}; \
	struct MyCharacter_eventOverlappedActor_Parms \
	{ \
		AActor* TagName; \
	};


#define KGCA38Team_Plugins_TeamPlayer_Source_TeamPlayer_Public_MyCharacter_h_20_CALLBACK_WRAPPERS
#define KGCA38Team_Plugins_TeamPlayer_Source_TeamPlayer_Public_MyCharacter_h_20_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMyCharacter(); \
	friend struct Z_Construct_UClass_AMyCharacter_Statics; \
public: \
	DECLARE_CLASS(AMyCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/TeamPlayer"), NO_API) \
	DECLARE_SERIALIZER(AMyCharacter)


#define KGCA38Team_Plugins_TeamPlayer_Source_TeamPlayer_Public_MyCharacter_h_20_INCLASS \
private: \
	static void StaticRegisterNativesAMyCharacter(); \
	friend struct Z_Construct_UClass_AMyCharacter_Statics; \
public: \
	DECLARE_CLASS(AMyCharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/TeamPlayer"), NO_API) \
	DECLARE_SERIALIZER(AMyCharacter)


#define KGCA38Team_Plugins_TeamPlayer_Source_TeamPlayer_Public_MyCharacter_h_20_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMyCharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMyCharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyCharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMyCharacter(AMyCharacter&&); \
	NO_API AMyCharacter(const AMyCharacter&); \
public:


#define KGCA38Team_Plugins_TeamPlayer_Source_TeamPlayer_Public_MyCharacter_h_20_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMyCharacter(AMyCharacter&&); \
	NO_API AMyCharacter(const AMyCharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyCharacter); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyCharacter); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMyCharacter)


#define KGCA38Team_Plugins_TeamPlayer_Source_TeamPlayer_Public_MyCharacter_h_20_PRIVATE_PROPERTY_OFFSET
#define KGCA38Team_Plugins_TeamPlayer_Source_TeamPlayer_Public_MyCharacter_h_17_PROLOG \
	KGCA38Team_Plugins_TeamPlayer_Source_TeamPlayer_Public_MyCharacter_h_20_EVENT_PARMS


#define KGCA38Team_Plugins_TeamPlayer_Source_TeamPlayer_Public_MyCharacter_h_20_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	KGCA38Team_Plugins_TeamPlayer_Source_TeamPlayer_Public_MyCharacter_h_20_PRIVATE_PROPERTY_OFFSET \
	KGCA38Team_Plugins_TeamPlayer_Source_TeamPlayer_Public_MyCharacter_h_20_SPARSE_DATA \
	KGCA38Team_Plugins_TeamPlayer_Source_TeamPlayer_Public_MyCharacter_h_20_RPC_WRAPPERS \
	KGCA38Team_Plugins_TeamPlayer_Source_TeamPlayer_Public_MyCharacter_h_20_CALLBACK_WRAPPERS \
	KGCA38Team_Plugins_TeamPlayer_Source_TeamPlayer_Public_MyCharacter_h_20_INCLASS \
	KGCA38Team_Plugins_TeamPlayer_Source_TeamPlayer_Public_MyCharacter_h_20_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define KGCA38Team_Plugins_TeamPlayer_Source_TeamPlayer_Public_MyCharacter_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	KGCA38Team_Plugins_TeamPlayer_Source_TeamPlayer_Public_MyCharacter_h_20_PRIVATE_PROPERTY_OFFSET \
	KGCA38Team_Plugins_TeamPlayer_Source_TeamPlayer_Public_MyCharacter_h_20_SPARSE_DATA \
	KGCA38Team_Plugins_TeamPlayer_Source_TeamPlayer_Public_MyCharacter_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	KGCA38Team_Plugins_TeamPlayer_Source_TeamPlayer_Public_MyCharacter_h_20_CALLBACK_WRAPPERS \
	KGCA38Team_Plugins_TeamPlayer_Source_TeamPlayer_Public_MyCharacter_h_20_INCLASS_NO_PURE_DECLS \
	KGCA38Team_Plugins_TeamPlayer_Source_TeamPlayer_Public_MyCharacter_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> TEAMPLAYER_API UClass* StaticClass<class AMyCharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID KGCA38Team_Plugins_TeamPlayer_Source_TeamPlayer_Public_MyCharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
