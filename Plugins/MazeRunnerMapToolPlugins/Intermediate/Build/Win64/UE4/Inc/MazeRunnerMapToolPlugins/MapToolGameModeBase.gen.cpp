// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MazeRunnerMapToolPlugins/Public/MapToolGameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMapToolGameModeBase() {}
// Cross Module References
	MAZERUNNERMAPTOOLPLUGINS_API UClass* Z_Construct_UClass_AMapToolGameModeBase_NoRegister();
	MAZERUNNERMAPTOOLPLUGINS_API UClass* Z_Construct_UClass_AMapToolGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_MazeRunnerMapToolPlugins();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	MAZERUNNERMAPTOOLPLUGINS_API UClass* Z_Construct_UClass_AWallActor_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(AMapToolGameModeBase::execOpenTheDoor)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OpenTheDoor();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMapToolGameModeBase::execReSet)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ReSet();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMapToolGameModeBase::execCM)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_x);
		P_GET_PROPERTY(FIntProperty,Z_Param_y);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->CM(Z_Param_x,Z_Param_y);
		P_NATIVE_END;
	}
	void AMapToolGameModeBase::StaticRegisterNativesAMapToolGameModeBase()
	{
		UClass* Class = AMapToolGameModeBase::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CM", &AMapToolGameModeBase::execCM },
			{ "OpenTheDoor", &AMapToolGameModeBase::execOpenTheDoor },
			{ "ReSet", &AMapToolGameModeBase::execReSet },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AMapToolGameModeBase_CM_Statics
	{
		struct MapToolGameModeBase_eventCM_Parms
		{
			int32 x;
			int32 y;
		};
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_x;
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_y;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_AMapToolGameModeBase_CM_Statics::NewProp_x = { "x", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MapToolGameModeBase_eventCM_Parms, x), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_AMapToolGameModeBase_CM_Statics::NewProp_y = { "y", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(MapToolGameModeBase_eventCM_Parms, y), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AMapToolGameModeBase_CM_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMapToolGameModeBase_CM_Statics::NewProp_x,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AMapToolGameModeBase_CM_Statics::NewProp_y,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMapToolGameModeBase_CM_Statics::Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "ModuleRelativePath", "Public/MapToolGameModeBase.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMapToolGameModeBase_CM_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMapToolGameModeBase, nullptr, "CM", nullptr, nullptr, sizeof(MapToolGameModeBase_eventCM_Parms), Z_Construct_UFunction_AMapToolGameModeBase_CM_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AMapToolGameModeBase_CM_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMapToolGameModeBase_CM_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMapToolGameModeBase_CM_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMapToolGameModeBase_CM()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMapToolGameModeBase_CM_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMapToolGameModeBase_OpenTheDoor_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMapToolGameModeBase_OpenTheDoor_Statics::Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "ModuleRelativePath", "Public/MapToolGameModeBase.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMapToolGameModeBase_OpenTheDoor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMapToolGameModeBase, nullptr, "OpenTheDoor", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMapToolGameModeBase_OpenTheDoor_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMapToolGameModeBase_OpenTheDoor_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMapToolGameModeBase_OpenTheDoor()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMapToolGameModeBase_OpenTheDoor_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMapToolGameModeBase_ReSet_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMapToolGameModeBase_ReSet_Statics::Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "ModuleRelativePath", "Public/MapToolGameModeBase.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMapToolGameModeBase_ReSet_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMapToolGameModeBase, nullptr, "ReSet", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMapToolGameModeBase_ReSet_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMapToolGameModeBase_ReSet_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMapToolGameModeBase_ReSet()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMapToolGameModeBase_ReSet_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AMapToolGameModeBase_NoRegister()
	{
		return AMapToolGameModeBase::StaticClass();
	}
	struct Z_Construct_UClass_AMapToolGameModeBase_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MapActors_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp_MapActors;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMapToolGameModeBase_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_MazeRunnerMapToolPlugins,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AMapToolGameModeBase_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AMapToolGameModeBase_CM, "CM" }, // 1942706138
		{ &Z_Construct_UFunction_AMapToolGameModeBase_OpenTheDoor, "OpenTheDoor" }, // 2175022431
		{ &Z_Construct_UFunction_AMapToolGameModeBase_ReSet, "ReSet" }, // 1263356319
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMapToolGameModeBase_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n *\n */" },
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "MapToolGameModeBase.h" },
		{ "ModuleRelativePath", "Public/MapToolGameModeBase.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMapToolGameModeBase_Statics::NewProp_MapActors_MetaData[] = {
		{ "Category", "MapToolGameModeBase" },
		{ "ModuleRelativePath", "Public/MapToolGameModeBase.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_AMapToolGameModeBase_Statics::NewProp_MapActors = { "MapActors", nullptr, (EPropertyFlags)0x0014000000000001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMapToolGameModeBase, MapActors), Z_Construct_UClass_AWallActor_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AMapToolGameModeBase_Statics::NewProp_MapActors_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMapToolGameModeBase_Statics::NewProp_MapActors_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMapToolGameModeBase_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMapToolGameModeBase_Statics::NewProp_MapActors,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMapToolGameModeBase_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMapToolGameModeBase>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMapToolGameModeBase_Statics::ClassParams = {
		&AMapToolGameModeBase::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AMapToolGameModeBase_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AMapToolGameModeBase_Statics::PropPointers),
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AMapToolGameModeBase_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AMapToolGameModeBase_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMapToolGameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMapToolGameModeBase_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMapToolGameModeBase, 1185281205);
	template<> MAZERUNNERMAPTOOLPLUGINS_API UClass* StaticClass<AMapToolGameModeBase>()
	{
		return AMapToolGameModeBase::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMapToolGameModeBase(Z_Construct_UClass_AMapToolGameModeBase, &AMapToolGameModeBase::StaticClass, TEXT("/Script/MazeRunnerMapToolPlugins"), TEXT("AMapToolGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMapToolGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
