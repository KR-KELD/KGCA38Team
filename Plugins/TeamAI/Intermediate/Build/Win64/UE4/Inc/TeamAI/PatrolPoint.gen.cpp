// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TeamAI/Public/PatrolPoint.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePatrolPoint() {}
// Cross Module References
	TEAMAI_API UEnum* Z_Construct_UEnum_TeamAI_EPatrolType();
	UPackage* Z_Construct_UPackage__Script_TeamAI();
	TEAMAI_API UClass* Z_Construct_UClass_APatrolPoint_NoRegister();
	TEAMAI_API UClass* Z_Construct_UClass_APatrolPoint();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
// End Cross Module References
	static UEnum* EPatrolType_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_TeamAI_EPatrolType, Z_Construct_UPackage__Script_TeamAI(), TEXT("EPatrolType"));
		}
		return Singleton;
	}
	template<> TEAMAI_API UEnum* StaticEnum<EPatrolType>()
	{
		return EPatrolType_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_EPatrolType(EPatrolType_StaticEnum, TEXT("/Script/TeamAI"), TEXT("EPatrolType"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_TeamAI_EPatrolType_Hash() { return 3626574008U; }
	UEnum* Z_Construct_UEnum_TeamAI_EPatrolType()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_TeamAI();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("EPatrolType"), 0, Get_Z_Construct_UEnum_TeamAI_EPatrolType_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "EPatrolType::EPatrol_RandomPoint", (int64)EPatrolType::EPatrol_RandomPoint },
				{ "EPatrolType::EPatrol_CirclePoints", (int64)EPatrolType::EPatrol_CirclePoints },
				{ "EPatrolType::EPatrol_RoundTripPoints", (int64)EPatrolType::EPatrol_RoundTripPoints },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "BlueprintType", "true" },
				{ "EPatrol_CirclePoints.DisplayName", "Circle" },
				{ "EPatrol_CirclePoints.Name", "EPatrolType::EPatrol_CirclePoints" },
				{ "EPatrol_RandomPoint.DisplayName", "Random" },
				{ "EPatrol_RandomPoint.Name", "EPatrolType::EPatrol_RandomPoint" },
				{ "EPatrol_RoundTripPoints.DisplayName", "RoundTrip" },
				{ "EPatrol_RoundTripPoints.Name", "EPatrolType::EPatrol_RoundTripPoints" },
				{ "ModuleRelativePath", "Public/PatrolPoint.h" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_TeamAI,
				nullptr,
				"EPatrolType",
				"EPatrolType",
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
	DEFINE_FUNCTION(APatrolPoint::execGetRoundTripPoint)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector*)Z_Param__Result=P_THIS->GetRoundTripPoint();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(APatrolPoint::execGetCirclePoint)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector*)Z_Param__Result=P_THIS->GetCirclePoint();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(APatrolPoint::execGetPatrolPoint)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(FVector*)Z_Param__Result=P_THIS->GetPatrolPoint();
		P_NATIVE_END;
	}
	void APatrolPoint::StaticRegisterNativesAPatrolPoint()
	{
		UClass* Class = APatrolPoint::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "GetCirclePoint", &APatrolPoint::execGetCirclePoint },
			{ "GetPatrolPoint", &APatrolPoint::execGetPatrolPoint },
			{ "GetRoundTripPoint", &APatrolPoint::execGetRoundTripPoint },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_APatrolPoint_GetCirclePoint_Statics
	{
		struct PatrolPoint_eventGetCirclePoint_Parms
		{
			FVector ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_APatrolPoint_GetCirclePoint_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PatrolPoint_eventGetCirclePoint_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APatrolPoint_GetCirclePoint_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APatrolPoint_GetCirclePoint_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APatrolPoint_GetCirclePoint_Statics::Function_MetaDataParams[] = {
		{ "Category", "KGCA_AI" },
		{ "ModuleRelativePath", "Public/PatrolPoint.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_APatrolPoint_GetCirclePoint_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APatrolPoint, nullptr, "GetCirclePoint", nullptr, nullptr, sizeof(PatrolPoint_eventGetCirclePoint_Parms), Z_Construct_UFunction_APatrolPoint_GetCirclePoint_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APatrolPoint_GetCirclePoint_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_APatrolPoint_GetCirclePoint_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_APatrolPoint_GetCirclePoint_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_APatrolPoint_GetCirclePoint()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_APatrolPoint_GetCirclePoint_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_APatrolPoint_GetPatrolPoint_Statics
	{
		struct PatrolPoint_eventGetPatrolPoint_Parms
		{
			FVector ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_APatrolPoint_GetPatrolPoint_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PatrolPoint_eventGetPatrolPoint_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APatrolPoint_GetPatrolPoint_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APatrolPoint_GetPatrolPoint_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APatrolPoint_GetPatrolPoint_Statics::Function_MetaDataParams[] = {
		{ "Category", "KGCA_AI" },
		{ "ModuleRelativePath", "Public/PatrolPoint.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_APatrolPoint_GetPatrolPoint_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APatrolPoint, nullptr, "GetPatrolPoint", nullptr, nullptr, sizeof(PatrolPoint_eventGetPatrolPoint_Parms), Z_Construct_UFunction_APatrolPoint_GetPatrolPoint_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APatrolPoint_GetPatrolPoint_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_APatrolPoint_GetPatrolPoint_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_APatrolPoint_GetPatrolPoint_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_APatrolPoint_GetPatrolPoint()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_APatrolPoint_GetPatrolPoint_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_APatrolPoint_GetRoundTripPoint_Statics
	{
		struct PatrolPoint_eventGetRoundTripPoint_Parms
		{
			FVector ReturnValue;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_APatrolPoint_GetRoundTripPoint_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PatrolPoint_eventGetRoundTripPoint_Parms, ReturnValue), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_APatrolPoint_GetRoundTripPoint_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_APatrolPoint_GetRoundTripPoint_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_APatrolPoint_GetRoundTripPoint_Statics::Function_MetaDataParams[] = {
		{ "Category", "KGCA_AI" },
		{ "ModuleRelativePath", "Public/PatrolPoint.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_APatrolPoint_GetRoundTripPoint_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_APatrolPoint, nullptr, "GetRoundTripPoint", nullptr, nullptr, sizeof(PatrolPoint_eventGetRoundTripPoint_Parms), Z_Construct_UFunction_APatrolPoint_GetRoundTripPoint_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_APatrolPoint_GetRoundTripPoint_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04820401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_APatrolPoint_GetRoundTripPoint_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_APatrolPoint_GetRoundTripPoint_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_APatrolPoint_GetRoundTripPoint()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_APatrolPoint_GetRoundTripPoint_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_APatrolPoint_NoRegister()
	{
		return APatrolPoint::StaticClass();
	}
	struct Z_Construct_UClass_APatrolPoint_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_PatrolPoints_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PatrolPoints_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_PatrolPoints;
		static const UE4CodeGen_Private::FBytePropertyParams NewProp_PatrolType_Underlying;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_PatrolType_MetaData[];
#endif
		static const UE4CodeGen_Private::FEnumPropertyParams NewProp_PatrolType;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RandomRange_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_RandomRange;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_APatrolPoint_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_TeamAI,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_APatrolPoint_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_APatrolPoint_GetCirclePoint, "GetCirclePoint" }, // 896116575
		{ &Z_Construct_UFunction_APatrolPoint_GetPatrolPoint, "GetPatrolPoint" }, // 4165267682
		{ &Z_Construct_UFunction_APatrolPoint_GetRoundTripPoint, "GetRoundTripPoint" }, // 1298770081
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APatrolPoint_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "PatrolPoint.h" },
		{ "ModuleRelativePath", "Public/PatrolPoint.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_APatrolPoint_Statics::NewProp_PatrolPoints_Inner = { "PatrolPoints", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APatrolPoint_Statics::NewProp_PatrolPoints_MetaData[] = {
		{ "Category", "KGCA_AI" },
		{ "MakeEditWidget", "TRUE" },
		{ "ModuleRelativePath", "Public/PatrolPoint.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_APatrolPoint_Statics::NewProp_PatrolPoints = { "PatrolPoints", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APatrolPoint, PatrolPoints), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_APatrolPoint_Statics::NewProp_PatrolPoints_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APatrolPoint_Statics::NewProp_PatrolPoints_MetaData)) };
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_APatrolPoint_Statics::NewProp_PatrolType_Underlying = { "UnderlyingType", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, nullptr, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APatrolPoint_Statics::NewProp_PatrolType_MetaData[] = {
		{ "Category", "KGCA_AI" },
		{ "ModuleRelativePath", "Public/PatrolPoint.h" },
	};
#endif
	const UE4CodeGen_Private::FEnumPropertyParams Z_Construct_UClass_APatrolPoint_Statics::NewProp_PatrolType = { "PatrolType", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Enum, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APatrolPoint, PatrolType), Z_Construct_UEnum_TeamAI_EPatrolType, METADATA_PARAMS(Z_Construct_UClass_APatrolPoint_Statics::NewProp_PatrolType_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APatrolPoint_Statics::NewProp_PatrolType_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_APatrolPoint_Statics::NewProp_RandomRange_MetaData[] = {
		{ "Category", "KGCA_AI" },
		{ "ModuleRelativePath", "Public/PatrolPoint.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_APatrolPoint_Statics::NewProp_RandomRange = { "RandomRange", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(APatrolPoint, RandomRange), METADATA_PARAMS(Z_Construct_UClass_APatrolPoint_Statics::NewProp_RandomRange_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_APatrolPoint_Statics::NewProp_RandomRange_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_APatrolPoint_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APatrolPoint_Statics::NewProp_PatrolPoints_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APatrolPoint_Statics::NewProp_PatrolPoints,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APatrolPoint_Statics::NewProp_PatrolType_Underlying,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APatrolPoint_Statics::NewProp_PatrolType,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_APatrolPoint_Statics::NewProp_RandomRange,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_APatrolPoint_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<APatrolPoint>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_APatrolPoint_Statics::ClassParams = {
		&APatrolPoint::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_APatrolPoint_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_APatrolPoint_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_APatrolPoint_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_APatrolPoint_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_APatrolPoint()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_APatrolPoint_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(APatrolPoint, 324312423);
	template<> TEAMAI_API UClass* StaticClass<APatrolPoint>()
	{
		return APatrolPoint::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_APatrolPoint(Z_Construct_UClass_APatrolPoint, &APatrolPoint::StaticClass, TEXT("/Script/TeamAI"), TEXT("APatrolPoint"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(APatrolPoint);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
