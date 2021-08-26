// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TeamAI/Public/MyAIController.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyAIController() {}
// Cross Module References
	TEAMAI_API UClass* Z_Construct_UClass_AMyAIController_NoRegister();
	TEAMAI_API UClass* Z_Construct_UClass_AMyAIController();
	AIMODULE_API UClass* Z_Construct_UClass_AAIController();
	UPackage* Z_Construct_UPackage__Script_TeamAI();
	TEAMAI_API UClass* Z_Construct_UClass_AAIBase_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	AIMODULE_API UClass* Z_Construct_UClass_UBlackboardData_NoRegister();
	AIMODULE_API UClass* Z_Construct_UClass_UBehaviorTree_NoRegister();
	AIMODULE_API UClass* Z_Construct_UClass_UAISenseConfig_Sight_NoRegister();
	AIMODULE_API UClass* Z_Construct_UClass_UAISenseConfig_Hearing_NoRegister();
	TEAMAI_API UScriptStruct* Z_Construct_UScriptStruct_FAIDataStruct();
// End Cross Module References
	DEFINE_FUNCTION(AMyAIController::execRespawnCall)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_msg);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RespawnCall(Z_Param_msg);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMyAIController::execDeadCall)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_msg);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->DeadCall(Z_Param_msg);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMyAIController::execHitCall)
	{
		P_GET_OBJECT(AActor,Z_Param_AttackActor);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->HitCall(Z_Param_AttackActor);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMyAIController::execUpdateState)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_State);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UpdateState(Z_Param_State);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMyAIController::execAttackReady)
	{
		P_GET_UBOOL(Z_Param_value);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->AttackReady(Z_Param_value);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMyAIController::execSetSenseOption)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_SightRadius);
		P_GET_PROPERTY(FFloatProperty,Z_Param_SightLoseRadius);
		P_GET_PROPERTY(FFloatProperty,Z_Param_SightFov);
		P_GET_PROPERTY(FFloatProperty,Z_Param_HearingRange);
		P_GET_PROPERTY(FFloatProperty,Z_Param_Age);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->SetSenseOption(Z_Param_SightRadius,Z_Param_SightLoseRadius,Z_Param_SightFov,Z_Param_HearingRange,Z_Param_Age);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMyAIController::execUpdatePerceptionData)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UpdatePerceptionData();
		P_NATIVE_END;
	}
	static FName NAME_AMyAIController_BattleSelect = FName(TEXT("BattleSelect"));
	FString AMyAIController::BattleSelect(AAIBase* AIBase)
	{
		MyAIController_eventBattleSelect_Parms Parms;
		Parms.AIBase=AIBase;
		ProcessEvent(FindFunctionChecked(NAME_AMyAIController_BattleSelect),&Parms);
		return Parms.ReturnValue;
	}
	static FName NAME_AMyAIController_SetAIState = FName(TEXT("SetAIState"));
	void AMyAIController::SetAIState(const FString& StartState)
	{
		MyAIController_eventSetAIState_Parms Parms;
		Parms.StartState=StartState;
		ProcessEvent(FindFunctionChecked(NAME_AMyAIController_SetAIState),&Parms);
	}
	static FName NAME_AMyAIController_StateSelect = FName(TEXT("StateSelect"));
	FString AMyAIController::StateSelect(AAIBase* AIBase)
	{
		MyAIController_eventStateSelect_Parms Parms;
		Parms.AIBase=AIBase;
		ProcessEvent(FindFunctionChecked(NAME_AMyAIController_StateSelect),&Parms);
		return Parms.ReturnValue;
	}
	void AMyAIController::StaticRegisterNativesAMyAIController()
	{
		UClass* Class = AMyAIController::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "AttackReady", &AMyAIController::execAttackReady },
			{ "DeadCall", &AMyAIController::execDeadCall },
			{ "HitCall", &AMyAIController::execHitCall },
			{ "RespawnCall", &AMyAIController::execRespawnCall },
			{ "SetSenseOption", &AMyAIController::execSetSenseOption },
			{ "UpdatePerceptionData", &AMyAIController::execUpdatePerceptionData },
			{ "UpdateState", &AMyAIController::execUpdateState },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AMyAIController_AttackReady_Statics
	{
		struct MyAIController_eventAttackReady_Parms
		{
			bool value;
		};
		static void NewProp_value_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_value;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AMyAIController_AttackReady_Statics::NewProp_value_SetBit(void* Obj)
	{
		((MyAIController_eventAttackReady_Parms*)Obj)->value = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AMyAIController_AttackReady_Statics::NewProp_value = { "value", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(MyAIController_eventAttackReady_Parms), &Z_Construct_UFunction_AMyAIController_AttackReady_Statics::NewProp_value_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMyAIController_AttackReady_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyAIController_AttackReady_Statics::NewProp_value,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyAIController_AttackReady_Statics::Function_MetaDataParams[] = {
		{ "Category", "KGCA_AI" },
		{ "ModuleRelativePath", "Public/MyAIController.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyAIController_AttackReady_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyAIController, nullptr, "AttackReady", nullptr, nullptr, sizeof(MyAIController_eventAttackReady_Parms), Z_Construct_UFunction_AMyAIController_AttackReady_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyAIController_AttackReady_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyAIController_AttackReady_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyAIController_AttackReady_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyAIController_AttackReady()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMyAIController_AttackReady_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMyAIController_BattleSelect_Statics
	{
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_AIBase;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMyAIController_BattleSelect_Statics::NewProp_AIBase = { "AIBase", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyAIController_eventBattleSelect_Parms, AIBase), Z_Construct_UClass_AAIBase_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AMyAIController_BattleSelect_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyAIController_eventBattleSelect_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMyAIController_BattleSelect_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyAIController_BattleSelect_Statics::NewProp_AIBase,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyAIController_BattleSelect_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyAIController_BattleSelect_Statics::Function_MetaDataParams[] = {
		{ "Category", "KGCA_AI" },
		{ "ModuleRelativePath", "Public/MyAIController.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyAIController_BattleSelect_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyAIController, nullptr, "BattleSelect", nullptr, nullptr, sizeof(MyAIController_eventBattleSelect_Parms), Z_Construct_UFunction_AMyAIController_BattleSelect_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyAIController_BattleSelect_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyAIController_BattleSelect_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyAIController_BattleSelect_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyAIController_BattleSelect()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMyAIController_BattleSelect_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMyAIController_DeadCall_Statics
	{
		struct MyAIController_eventDeadCall_Parms
		{
			FString msg;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_msg;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AMyAIController_DeadCall_Statics::NewProp_msg = { "msg", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyAIController_eventDeadCall_Parms, msg), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMyAIController_DeadCall_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyAIController_DeadCall_Statics::NewProp_msg,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyAIController_DeadCall_Statics::Function_MetaDataParams[] = {
		{ "Category", "KGCA_AI" },
		{ "ModuleRelativePath", "Public/MyAIController.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyAIController_DeadCall_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyAIController, nullptr, "DeadCall", nullptr, nullptr, sizeof(MyAIController_eventDeadCall_Parms), Z_Construct_UFunction_AMyAIController_DeadCall_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyAIController_DeadCall_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyAIController_DeadCall_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyAIController_DeadCall_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyAIController_DeadCall()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMyAIController_DeadCall_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMyAIController_HitCall_Statics
	{
		struct MyAIController_eventHitCall_Parms
		{
			AActor* AttackActor;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_AttackActor;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMyAIController_HitCall_Statics::NewProp_AttackActor = { "AttackActor", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyAIController_eventHitCall_Parms, AttackActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMyAIController_HitCall_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyAIController_HitCall_Statics::NewProp_AttackActor,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyAIController_HitCall_Statics::Function_MetaDataParams[] = {
		{ "Category", "KGCA_AI" },
		{ "ModuleRelativePath", "Public/MyAIController.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyAIController_HitCall_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyAIController, nullptr, "HitCall", nullptr, nullptr, sizeof(MyAIController_eventHitCall_Parms), Z_Construct_UFunction_AMyAIController_HitCall_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyAIController_HitCall_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyAIController_HitCall_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyAIController_HitCall_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyAIController_HitCall()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMyAIController_HitCall_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMyAIController_RespawnCall_Statics
	{
		struct MyAIController_eventRespawnCall_Parms
		{
			FString msg;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_msg;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AMyAIController_RespawnCall_Statics::NewProp_msg = { "msg", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyAIController_eventRespawnCall_Parms, msg), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMyAIController_RespawnCall_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyAIController_RespawnCall_Statics::NewProp_msg,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyAIController_RespawnCall_Statics::Function_MetaDataParams[] = {
		{ "Category", "KGCA_AI" },
		{ "ModuleRelativePath", "Public/MyAIController.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyAIController_RespawnCall_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyAIController, nullptr, "RespawnCall", nullptr, nullptr, sizeof(MyAIController_eventRespawnCall_Parms), Z_Construct_UFunction_AMyAIController_RespawnCall_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyAIController_RespawnCall_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyAIController_RespawnCall_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyAIController_RespawnCall_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyAIController_RespawnCall()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMyAIController_RespawnCall_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMyAIController_SetAIState_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_StartState_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_StartState;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyAIController_SetAIState_Statics::NewProp_StartState_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AMyAIController_SetAIState_Statics::NewProp_StartState = { "StartState", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyAIController_eventSetAIState_Parms, StartState), METADATA_PARAMS(Z_Construct_UFunction_AMyAIController_SetAIState_Statics::NewProp_StartState_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyAIController_SetAIState_Statics::NewProp_StartState_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMyAIController_SetAIState_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyAIController_SetAIState_Statics::NewProp_StartState,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyAIController_SetAIState_Statics::Function_MetaDataParams[] = {
		{ "Category", "KGCA_AI" },
		{ "ModuleRelativePath", "Public/MyAIController.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyAIController_SetAIState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyAIController, nullptr, "SetAIState", nullptr, nullptr, sizeof(MyAIController_eventSetAIState_Parms), Z_Construct_UFunction_AMyAIController_SetAIState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyAIController_SetAIState_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyAIController_SetAIState_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyAIController_SetAIState_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyAIController_SetAIState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMyAIController_SetAIState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMyAIController_SetSenseOption_Statics
	{
		struct MyAIController_eventSetSenseOption_Parms
		{
			float SightRadius;
			float SightLoseRadius;
			float SightFov;
			float HearingRange;
			float Age;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_SightRadius;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_SightLoseRadius;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_SightFov;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_HearingRange;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Age;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AMyAIController_SetSenseOption_Statics::NewProp_SightRadius = { "SightRadius", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyAIController_eventSetSenseOption_Parms, SightRadius), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AMyAIController_SetSenseOption_Statics::NewProp_SightLoseRadius = { "SightLoseRadius", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyAIController_eventSetSenseOption_Parms, SightLoseRadius), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AMyAIController_SetSenseOption_Statics::NewProp_SightFov = { "SightFov", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyAIController_eventSetSenseOption_Parms, SightFov), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AMyAIController_SetSenseOption_Statics::NewProp_HearingRange = { "HearingRange", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyAIController_eventSetSenseOption_Parms, HearingRange), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AMyAIController_SetSenseOption_Statics::NewProp_Age = { "Age", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyAIController_eventSetSenseOption_Parms, Age), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMyAIController_SetSenseOption_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyAIController_SetSenseOption_Statics::NewProp_SightRadius,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyAIController_SetSenseOption_Statics::NewProp_SightLoseRadius,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyAIController_SetSenseOption_Statics::NewProp_SightFov,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyAIController_SetSenseOption_Statics::NewProp_HearingRange,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyAIController_SetSenseOption_Statics::NewProp_Age,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyAIController_SetSenseOption_Statics::Function_MetaDataParams[] = {
		{ "Category", "KGCA_AI" },
		{ "ModuleRelativePath", "Public/MyAIController.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyAIController_SetSenseOption_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyAIController, nullptr, "SetSenseOption", nullptr, nullptr, sizeof(MyAIController_eventSetSenseOption_Parms), Z_Construct_UFunction_AMyAIController_SetSenseOption_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyAIController_SetSenseOption_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyAIController_SetSenseOption_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyAIController_SetSenseOption_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyAIController_SetSenseOption()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMyAIController_SetSenseOption_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMyAIController_StateSelect_Statics
	{
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_AIBase;
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AMyAIController_StateSelect_Statics::NewProp_AIBase = { "AIBase", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyAIController_eventStateSelect_Parms, AIBase), Z_Construct_UClass_AAIBase_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AMyAIController_StateSelect_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyAIController_eventStateSelect_Parms, ReturnValue), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMyAIController_StateSelect_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyAIController_StateSelect_Statics::NewProp_AIBase,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyAIController_StateSelect_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyAIController_StateSelect_Statics::Function_MetaDataParams[] = {
		{ "Category", "KGCA_AI" },
		{ "ModuleRelativePath", "Public/MyAIController.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyAIController_StateSelect_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyAIController, nullptr, "StateSelect", nullptr, nullptr, sizeof(MyAIController_eventStateSelect_Parms), Z_Construct_UFunction_AMyAIController_StateSelect_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyAIController_StateSelect_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x0C020800, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyAIController_StateSelect_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyAIController_StateSelect_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyAIController_StateSelect()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMyAIController_StateSelect_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMyAIController_UpdatePerceptionData_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyAIController_UpdatePerceptionData_Statics::Function_MetaDataParams[] = {
		{ "Category", "KGCA_AI" },
		{ "ModuleRelativePath", "Public/MyAIController.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyAIController_UpdatePerceptionData_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyAIController, nullptr, "UpdatePerceptionData", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyAIController_UpdatePerceptionData_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyAIController_UpdatePerceptionData_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyAIController_UpdatePerceptionData()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMyAIController_UpdatePerceptionData_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMyAIController_UpdateState_Statics
	{
		struct MyAIController_eventUpdateState_Parms
		{
			FString State;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_State;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AMyAIController_UpdateState_Statics::NewProp_State = { "State", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MyAIController_eventUpdateState_Parms, State), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMyAIController_UpdateState_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMyAIController_UpdateState_Statics::NewProp_State,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMyAIController_UpdateState_Statics::Function_MetaDataParams[] = {
		{ "Category", "KGCA_AI" },
		{ "ModuleRelativePath", "Public/MyAIController.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMyAIController_UpdateState_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMyAIController, nullptr, "UpdateState", nullptr, nullptr, sizeof(MyAIController_eventUpdateState_Parms), Z_Construct_UFunction_AMyAIController_UpdateState_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyAIController_UpdateState_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMyAIController_UpdateState_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMyAIController_UpdateState_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMyAIController_UpdateState()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMyAIController_UpdateState_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AMyAIController_NoRegister()
	{
		return AMyAIController::StaticClass();
	}
	struct Z_Construct_UClass_AMyAIController_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BBOject_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_BBOject;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BTObject_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_BTObject;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SelfActor_MetaData[];
#endif
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_SelfActor;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TargetActor_MetaData[];
#endif
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_TargetActor;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DestLocation_MetaData[];
#endif
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_DestLocation;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TargetLocation_MetaData[];
#endif
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_TargetLocation;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BBAIState_MetaData[];
#endif
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_BBAIState;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BattleState_MetaData[];
#endif
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_BattleState;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BBIsBBDead_MetaData[];
#endif
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_BBIsBBDead;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BBIsAttackReady_MetaData[];
#endif
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_BBIsAttackReady;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HasPatrolPoint_MetaData[];
#endif
		static const UE4CodeGen_Private::FNamePropertyParams NewProp_HasPatrolPoint;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AIState_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_AIState;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IsAttackReady_MetaData[];
#endif
		static void NewProp_IsAttackReady_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_IsAttackReady;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IsHit_MetaData[];
#endif
		static void NewProp_IsHit_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_IsHit;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IsDead_MetaData[];
#endif
		static void NewProp_IsDead_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_IsDead;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SightConfig_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SightConfig;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HearingConfig_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_HearingConfig;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AIData_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_AIData;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMyAIController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AAIController,
		(UObject* (*)())Z_Construct_UPackage__Script_TeamAI,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AMyAIController_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AMyAIController_AttackReady, "AttackReady" }, // 3045139583
		{ &Z_Construct_UFunction_AMyAIController_BattleSelect, "BattleSelect" }, // 4165924266
		{ &Z_Construct_UFunction_AMyAIController_DeadCall, "DeadCall" }, // 2968317598
		{ &Z_Construct_UFunction_AMyAIController_HitCall, "HitCall" }, // 1296179348
		{ &Z_Construct_UFunction_AMyAIController_RespawnCall, "RespawnCall" }, // 2128016953
		{ &Z_Construct_UFunction_AMyAIController_SetAIState, "SetAIState" }, // 1522564501
		{ &Z_Construct_UFunction_AMyAIController_SetSenseOption, "SetSenseOption" }, // 2770207865
		{ &Z_Construct_UFunction_AMyAIController_StateSelect, "StateSelect" }, // 3174805319
		{ &Z_Construct_UFunction_AMyAIController_UpdatePerceptionData, "UpdatePerceptionData" }, // 2401076931
		{ &Z_Construct_UFunction_AMyAIController_UpdateState, "UpdateState" }, // 1911711523
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyAIController_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "MyAIController.h" },
		{ "ModuleRelativePath", "Public/MyAIController.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyAIController_Statics::NewProp_BBOject_MetaData[] = {
		{ "Category", "KGCA_AI" },
		{ "ModuleRelativePath", "Public/MyAIController.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyAIController_Statics::NewProp_BBOject = { "BBOject", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyAIController, BBOject), Z_Construct_UClass_UBlackboardData_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyAIController_Statics::NewProp_BBOject_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyAIController_Statics::NewProp_BBOject_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyAIController_Statics::NewProp_BTObject_MetaData[] = {
		{ "Category", "KGCA_AI" },
		{ "ModuleRelativePath", "Public/MyAIController.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyAIController_Statics::NewProp_BTObject = { "BTObject", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyAIController, BTObject), Z_Construct_UClass_UBehaviorTree_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyAIController_Statics::NewProp_BTObject_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyAIController_Statics::NewProp_BTObject_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyAIController_Statics::NewProp_SelfActor_MetaData[] = {
		{ "Category", "KGCA_AI" },
		{ "ModuleRelativePath", "Public/MyAIController.h" },
	};
#endif
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UClass_AMyAIController_Statics::NewProp_SelfActor = { "SelfActor", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyAIController, SelfActor), METADATA_PARAMS(Z_Construct_UClass_AMyAIController_Statics::NewProp_SelfActor_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyAIController_Statics::NewProp_SelfActor_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyAIController_Statics::NewProp_TargetActor_MetaData[] = {
		{ "Category", "KGCA_AI" },
		{ "ModuleRelativePath", "Public/MyAIController.h" },
	};
#endif
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UClass_AMyAIController_Statics::NewProp_TargetActor = { "TargetActor", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyAIController, TargetActor), METADATA_PARAMS(Z_Construct_UClass_AMyAIController_Statics::NewProp_TargetActor_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyAIController_Statics::NewProp_TargetActor_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyAIController_Statics::NewProp_DestLocation_MetaData[] = {
		{ "Category", "KGCA_AI" },
		{ "ModuleRelativePath", "Public/MyAIController.h" },
	};
#endif
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UClass_AMyAIController_Statics::NewProp_DestLocation = { "DestLocation", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyAIController, DestLocation), METADATA_PARAMS(Z_Construct_UClass_AMyAIController_Statics::NewProp_DestLocation_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyAIController_Statics::NewProp_DestLocation_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyAIController_Statics::NewProp_TargetLocation_MetaData[] = {
		{ "Category", "KGCA_AI" },
		{ "ModuleRelativePath", "Public/MyAIController.h" },
	};
#endif
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UClass_AMyAIController_Statics::NewProp_TargetLocation = { "TargetLocation", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyAIController, TargetLocation), METADATA_PARAMS(Z_Construct_UClass_AMyAIController_Statics::NewProp_TargetLocation_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyAIController_Statics::NewProp_TargetLocation_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyAIController_Statics::NewProp_BBAIState_MetaData[] = {
		{ "Category", "KGCA_AI" },
		{ "ModuleRelativePath", "Public/MyAIController.h" },
	};
#endif
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UClass_AMyAIController_Statics::NewProp_BBAIState = { "BBAIState", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyAIController, BBAIState), METADATA_PARAMS(Z_Construct_UClass_AMyAIController_Statics::NewProp_BBAIState_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyAIController_Statics::NewProp_BBAIState_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyAIController_Statics::NewProp_BattleState_MetaData[] = {
		{ "Category", "KGCA_AI" },
		{ "ModuleRelativePath", "Public/MyAIController.h" },
	};
#endif
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UClass_AMyAIController_Statics::NewProp_BattleState = { "BattleState", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyAIController, BattleState), METADATA_PARAMS(Z_Construct_UClass_AMyAIController_Statics::NewProp_BattleState_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyAIController_Statics::NewProp_BattleState_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyAIController_Statics::NewProp_BBIsBBDead_MetaData[] = {
		{ "Category", "KGCA_AI" },
		{ "ModuleRelativePath", "Public/MyAIController.h" },
	};
#endif
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UClass_AMyAIController_Statics::NewProp_BBIsBBDead = { "BBIsBBDead", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyAIController, BBIsBBDead), METADATA_PARAMS(Z_Construct_UClass_AMyAIController_Statics::NewProp_BBIsBBDead_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyAIController_Statics::NewProp_BBIsBBDead_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyAIController_Statics::NewProp_BBIsAttackReady_MetaData[] = {
		{ "Category", "KGCA_AI" },
		{ "ModuleRelativePath", "Public/MyAIController.h" },
	};
#endif
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UClass_AMyAIController_Statics::NewProp_BBIsAttackReady = { "BBIsAttackReady", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyAIController, BBIsAttackReady), METADATA_PARAMS(Z_Construct_UClass_AMyAIController_Statics::NewProp_BBIsAttackReady_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyAIController_Statics::NewProp_BBIsAttackReady_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyAIController_Statics::NewProp_HasPatrolPoint_MetaData[] = {
		{ "Category", "KGCA_AI" },
		{ "ModuleRelativePath", "Public/MyAIController.h" },
	};
#endif
	const UE4CodeGen_Private::FNamePropertyParams Z_Construct_UClass_AMyAIController_Statics::NewProp_HasPatrolPoint = { "HasPatrolPoint", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Name, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyAIController, HasPatrolPoint), METADATA_PARAMS(Z_Construct_UClass_AMyAIController_Statics::NewProp_HasPatrolPoint_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyAIController_Statics::NewProp_HasPatrolPoint_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyAIController_Statics::NewProp_AIState_MetaData[] = {
		{ "Category", "KGCA_AI" },
		{ "ModuleRelativePath", "Public/MyAIController.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_AMyAIController_Statics::NewProp_AIState = { "AIState", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyAIController, AIState), METADATA_PARAMS(Z_Construct_UClass_AMyAIController_Statics::NewProp_AIState_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyAIController_Statics::NewProp_AIState_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyAIController_Statics::NewProp_IsAttackReady_MetaData[] = {
		{ "Category", "KGCA_AI" },
		{ "ModuleRelativePath", "Public/MyAIController.h" },
	};
#endif
	void Z_Construct_UClass_AMyAIController_Statics::NewProp_IsAttackReady_SetBit(void* Obj)
	{
		((AMyAIController*)Obj)->IsAttackReady = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMyAIController_Statics::NewProp_IsAttackReady = { "IsAttackReady", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AMyAIController), &Z_Construct_UClass_AMyAIController_Statics::NewProp_IsAttackReady_SetBit, METADATA_PARAMS(Z_Construct_UClass_AMyAIController_Statics::NewProp_IsAttackReady_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyAIController_Statics::NewProp_IsAttackReady_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyAIController_Statics::NewProp_IsHit_MetaData[] = {
		{ "Category", "KGCA_AI" },
		{ "ModuleRelativePath", "Public/MyAIController.h" },
	};
#endif
	void Z_Construct_UClass_AMyAIController_Statics::NewProp_IsHit_SetBit(void* Obj)
	{
		((AMyAIController*)Obj)->IsHit = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMyAIController_Statics::NewProp_IsHit = { "IsHit", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AMyAIController), &Z_Construct_UClass_AMyAIController_Statics::NewProp_IsHit_SetBit, METADATA_PARAMS(Z_Construct_UClass_AMyAIController_Statics::NewProp_IsHit_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyAIController_Statics::NewProp_IsHit_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyAIController_Statics::NewProp_IsDead_MetaData[] = {
		{ "Category", "KGCA_AI" },
		{ "ModuleRelativePath", "Public/MyAIController.h" },
	};
#endif
	void Z_Construct_UClass_AMyAIController_Statics::NewProp_IsDead_SetBit(void* Obj)
	{
		((AMyAIController*)Obj)->IsDead = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_AMyAIController_Statics::NewProp_IsDead = { "IsDead", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(AMyAIController), &Z_Construct_UClass_AMyAIController_Statics::NewProp_IsDead_SetBit, METADATA_PARAMS(Z_Construct_UClass_AMyAIController_Statics::NewProp_IsDead_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyAIController_Statics::NewProp_IsDead_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyAIController_Statics::NewProp_SightConfig_MetaData[] = {
		{ "ModuleRelativePath", "Public/MyAIController.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyAIController_Statics::NewProp_SightConfig = { "SightConfig", nullptr, (EPropertyFlags)0x0040000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyAIController, SightConfig), Z_Construct_UClass_UAISenseConfig_Sight_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyAIController_Statics::NewProp_SightConfig_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyAIController_Statics::NewProp_SightConfig_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyAIController_Statics::NewProp_HearingConfig_MetaData[] = {
		{ "ModuleRelativePath", "Public/MyAIController.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyAIController_Statics::NewProp_HearingConfig = { "HearingConfig", nullptr, (EPropertyFlags)0x0040000000000000, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyAIController, HearingConfig), Z_Construct_UClass_UAISenseConfig_Hearing_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyAIController_Statics::NewProp_HearingConfig_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyAIController_Statics::NewProp_HearingConfig_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyAIController_Statics::NewProp_AIData_MetaData[] = {
		{ "Category", "MyAIController" },
		{ "ModuleRelativePath", "Public/MyAIController.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AMyAIController_Statics::NewProp_AIData = { "AIData", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyAIController, AIData), Z_Construct_UScriptStruct_FAIDataStruct, METADATA_PARAMS(Z_Construct_UClass_AMyAIController_Statics::NewProp_AIData_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyAIController_Statics::NewProp_AIData_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMyAIController_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyAIController_Statics::NewProp_BBOject,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyAIController_Statics::NewProp_BTObject,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyAIController_Statics::NewProp_SelfActor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyAIController_Statics::NewProp_TargetActor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyAIController_Statics::NewProp_DestLocation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyAIController_Statics::NewProp_TargetLocation,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyAIController_Statics::NewProp_BBAIState,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyAIController_Statics::NewProp_BattleState,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyAIController_Statics::NewProp_BBIsBBDead,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyAIController_Statics::NewProp_BBIsAttackReady,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyAIController_Statics::NewProp_HasPatrolPoint,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyAIController_Statics::NewProp_AIState,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyAIController_Statics::NewProp_IsAttackReady,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyAIController_Statics::NewProp_IsHit,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyAIController_Statics::NewProp_IsDead,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyAIController_Statics::NewProp_SightConfig,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyAIController_Statics::NewProp_HearingConfig,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyAIController_Statics::NewProp_AIData,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMyAIController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMyAIController>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMyAIController_Statics::ClassParams = {
		&AMyAIController::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AMyAIController_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AMyAIController_Statics::PropPointers),
		0,
		0x009002A4u,
		METADATA_PARAMS(Z_Construct_UClass_AMyAIController_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AMyAIController_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMyAIController()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMyAIController_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMyAIController, 2404091464);
	template<> TEAMAI_API UClass* StaticClass<AMyAIController>()
	{
		return AMyAIController::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMyAIController(Z_Construct_UClass_AMyAIController, &AMyAIController::StaticClass, TEXT("/Script/TeamAI"), TEXT("AMyAIController"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMyAIController);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
