// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TeamAI/Public/AIDataStruct.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeAIDataStruct() {}
// Cross Module References
	TEAMAI_API UScriptStruct* Z_Construct_UScriptStruct_FAIDataStruct();
	UPackage* Z_Construct_UPackage__Script_TeamAI();
// End Cross Module References
class UScriptStruct* FAIDataStruct::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern TEAMAI_API uint32 Get_Z_Construct_UScriptStruct_FAIDataStruct_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FAIDataStruct, Z_Construct_UPackage__Script_TeamAI(), TEXT("AIDataStruct"), sizeof(FAIDataStruct), Get_Z_Construct_UScriptStruct_FAIDataStruct_Hash());
	}
	return Singleton;
}
template<> TEAMAI_API UScriptStruct* StaticStruct<FAIDataStruct>()
{
	return FAIDataStruct::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FAIDataStruct(FAIDataStruct::StaticStruct, TEXT("/Script/TeamAI"), TEXT("AIDataStruct"), false, nullptr, nullptr);
static struct FScriptStruct_TeamAI_StaticRegisterNativesFAIDataStruct
{
	FScriptStruct_TeamAI_StaticRegisterNativesFAIDataStruct()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("AIDataStruct")),new UScriptStruct::TCppStructOps<FAIDataStruct>);
	}
} ScriptStruct_TeamAI_StaticRegisterNativesFAIDataStruct;
	struct Z_Construct_UScriptStruct_FAIDataStruct_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_WalkSpeed_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_WalkSpeed;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RunSpeed_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_RunSpeed;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PatrolRange_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_PatrolRange;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AttackRange_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_AttackRange;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_AttackCooltime_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_AttackCooltime;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LookRange_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_LookRange;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_LostRange_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_LostRange;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SightAngle_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_SightAngle;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HearingRange_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_HearingRange;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PerceptionAge_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_PerceptionAge;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAIDataStruct_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "Public/AIDataStruct.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FAIDataStruct_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FAIDataStruct>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAIDataStruct_Statics::NewProp_WalkSpeed_MetaData[] = {
		{ "Category", "AIDataStruct" },
		{ "ModuleRelativePath", "Public/AIDataStruct.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAIDataStruct_Statics::NewProp_WalkSpeed = { "WalkSpeed", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FAIDataStruct, WalkSpeed), METADATA_PARAMS(Z_Construct_UScriptStruct_FAIDataStruct_Statics::NewProp_WalkSpeed_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAIDataStruct_Statics::NewProp_WalkSpeed_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAIDataStruct_Statics::NewProp_RunSpeed_MetaData[] = {
		{ "Category", "AIDataStruct" },
		{ "ModuleRelativePath", "Public/AIDataStruct.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAIDataStruct_Statics::NewProp_RunSpeed = { "RunSpeed", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FAIDataStruct, RunSpeed), METADATA_PARAMS(Z_Construct_UScriptStruct_FAIDataStruct_Statics::NewProp_RunSpeed_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAIDataStruct_Statics::NewProp_RunSpeed_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAIDataStruct_Statics::NewProp_PatrolRange_MetaData[] = {
		{ "Category", "AIDataStruct" },
		{ "ModuleRelativePath", "Public/AIDataStruct.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAIDataStruct_Statics::NewProp_PatrolRange = { "PatrolRange", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FAIDataStruct, PatrolRange), METADATA_PARAMS(Z_Construct_UScriptStruct_FAIDataStruct_Statics::NewProp_PatrolRange_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAIDataStruct_Statics::NewProp_PatrolRange_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAIDataStruct_Statics::NewProp_AttackRange_MetaData[] = {
		{ "Category", "AIDataStruct" },
		{ "ModuleRelativePath", "Public/AIDataStruct.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAIDataStruct_Statics::NewProp_AttackRange = { "AttackRange", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FAIDataStruct, AttackRange), METADATA_PARAMS(Z_Construct_UScriptStruct_FAIDataStruct_Statics::NewProp_AttackRange_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAIDataStruct_Statics::NewProp_AttackRange_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAIDataStruct_Statics::NewProp_AttackCooltime_MetaData[] = {
		{ "Category", "AIDataStruct" },
		{ "ModuleRelativePath", "Public/AIDataStruct.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAIDataStruct_Statics::NewProp_AttackCooltime = { "AttackCooltime", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FAIDataStruct, AttackCooltime), METADATA_PARAMS(Z_Construct_UScriptStruct_FAIDataStruct_Statics::NewProp_AttackCooltime_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAIDataStruct_Statics::NewProp_AttackCooltime_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAIDataStruct_Statics::NewProp_LookRange_MetaData[] = {
		{ "Category", "AIDataStruct" },
		{ "ModuleRelativePath", "Public/AIDataStruct.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAIDataStruct_Statics::NewProp_LookRange = { "LookRange", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FAIDataStruct, LookRange), METADATA_PARAMS(Z_Construct_UScriptStruct_FAIDataStruct_Statics::NewProp_LookRange_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAIDataStruct_Statics::NewProp_LookRange_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAIDataStruct_Statics::NewProp_LostRange_MetaData[] = {
		{ "Category", "AIDataStruct" },
		{ "ModuleRelativePath", "Public/AIDataStruct.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAIDataStruct_Statics::NewProp_LostRange = { "LostRange", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FAIDataStruct, LostRange), METADATA_PARAMS(Z_Construct_UScriptStruct_FAIDataStruct_Statics::NewProp_LostRange_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAIDataStruct_Statics::NewProp_LostRange_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAIDataStruct_Statics::NewProp_SightAngle_MetaData[] = {
		{ "Category", "AIDataStruct" },
		{ "ModuleRelativePath", "Public/AIDataStruct.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAIDataStruct_Statics::NewProp_SightAngle = { "SightAngle", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FAIDataStruct, SightAngle), METADATA_PARAMS(Z_Construct_UScriptStruct_FAIDataStruct_Statics::NewProp_SightAngle_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAIDataStruct_Statics::NewProp_SightAngle_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAIDataStruct_Statics::NewProp_HearingRange_MetaData[] = {
		{ "Category", "AIDataStruct" },
		{ "ModuleRelativePath", "Public/AIDataStruct.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAIDataStruct_Statics::NewProp_HearingRange = { "HearingRange", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FAIDataStruct, HearingRange), METADATA_PARAMS(Z_Construct_UScriptStruct_FAIDataStruct_Statics::NewProp_HearingRange_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAIDataStruct_Statics::NewProp_HearingRange_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FAIDataStruct_Statics::NewProp_PerceptionAge_MetaData[] = {
		{ "Category", "AIDataStruct" },
		{ "ModuleRelativePath", "Public/AIDataStruct.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FAIDataStruct_Statics::NewProp_PerceptionAge = { "PerceptionAge", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FAIDataStruct, PerceptionAge), METADATA_PARAMS(Z_Construct_UScriptStruct_FAIDataStruct_Statics::NewProp_PerceptionAge_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAIDataStruct_Statics::NewProp_PerceptionAge_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FAIDataStruct_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAIDataStruct_Statics::NewProp_WalkSpeed,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAIDataStruct_Statics::NewProp_RunSpeed,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAIDataStruct_Statics::NewProp_PatrolRange,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAIDataStruct_Statics::NewProp_AttackRange,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAIDataStruct_Statics::NewProp_AttackCooltime,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAIDataStruct_Statics::NewProp_LookRange,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAIDataStruct_Statics::NewProp_LostRange,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAIDataStruct_Statics::NewProp_SightAngle,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAIDataStruct_Statics::NewProp_HearingRange,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FAIDataStruct_Statics::NewProp_PerceptionAge,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FAIDataStruct_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_TeamAI,
		nullptr,
		&NewStructOps,
		"AIDataStruct",
		sizeof(FAIDataStruct),
		alignof(FAIDataStruct),
		Z_Construct_UScriptStruct_FAIDataStruct_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAIDataStruct_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000011),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FAIDataStruct_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FAIDataStruct_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FAIDataStruct()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FAIDataStruct_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_TeamAI();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("AIDataStruct"), sizeof(FAIDataStruct), Get_Z_Construct_UScriptStruct_FAIDataStruct_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FAIDataStruct_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FAIDataStruct_Hash() { return 1941375262U; }
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
