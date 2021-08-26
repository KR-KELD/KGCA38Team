// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MazeRunnerMapToolPlugins/Public/MazeGeneration.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMazeGeneration() {}
// Cross Module References
	MAZERUNNERMAPTOOLPLUGINS_API UClass* Z_Construct_UClass_AMazeGeneration_NoRegister();
	MAZERUNNERMAPTOOLPLUGINS_API UClass* Z_Construct_UClass_AMazeGeneration();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_MazeRunnerMapToolPlugins();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	MAZERUNNERMAPTOOLPLUGINS_API UClass* Z_Construct_UClass_AWallActor_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(AMazeGeneration::execPuzzleDoor)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->PuzzleDoor();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMazeGeneration::execBattleDoor)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->BattleDoor();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMazeGeneration::execOpenTheDoor)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OpenTheDoor();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AMazeGeneration::execReSet)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ReSet();
		P_NATIVE_END;
	}
	void AMazeGeneration::StaticRegisterNativesAMazeGeneration()
	{
		UClass* Class = AMazeGeneration::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "BattleDoor", &AMazeGeneration::execBattleDoor },
			{ "OpenTheDoor", &AMazeGeneration::execOpenTheDoor },
			{ "PuzzleDoor", &AMazeGeneration::execPuzzleDoor },
			{ "ReSet", &AMazeGeneration::execReSet },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AMazeGeneration_BattleDoor_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMazeGeneration_BattleDoor_Statics::Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "ModuleRelativePath", "Public/MazeGeneration.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMazeGeneration_BattleDoor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMazeGeneration, nullptr, "BattleDoor", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMazeGeneration_BattleDoor_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMazeGeneration_BattleDoor_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMazeGeneration_BattleDoor()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMazeGeneration_BattleDoor_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMazeGeneration_OpenTheDoor_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMazeGeneration_OpenTheDoor_Statics::Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "ModuleRelativePath", "Public/MazeGeneration.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMazeGeneration_OpenTheDoor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMazeGeneration, nullptr, "OpenTheDoor", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMazeGeneration_OpenTheDoor_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMazeGeneration_OpenTheDoor_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMazeGeneration_OpenTheDoor()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMazeGeneration_OpenTheDoor_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMazeGeneration_PuzzleDoor_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMazeGeneration_PuzzleDoor_Statics::Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "ModuleRelativePath", "Public/MazeGeneration.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMazeGeneration_PuzzleDoor_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMazeGeneration, nullptr, "PuzzleDoor", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMazeGeneration_PuzzleDoor_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMazeGeneration_PuzzleDoor_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMazeGeneration_PuzzleDoor()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMazeGeneration_PuzzleDoor_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AMazeGeneration_ReSet_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AMazeGeneration_ReSet_Statics::Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "ModuleRelativePath", "Public/MazeGeneration.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AMazeGeneration_ReSet_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AMazeGeneration, nullptr, "ReSet", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AMazeGeneration_ReSet_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AMazeGeneration_ReSet_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AMazeGeneration_ReSet()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AMazeGeneration_ReSet_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AMazeGeneration_NoRegister()
	{
		return AMazeGeneration::StaticClass();
	}
	struct Z_Construct_UClass_AMazeGeneration_Statics
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
	UObject* (*const Z_Construct_UClass_AMazeGeneration_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_MazeRunnerMapToolPlugins,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AMazeGeneration_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AMazeGeneration_BattleDoor, "BattleDoor" }, // 2930697765
		{ &Z_Construct_UFunction_AMazeGeneration_OpenTheDoor, "OpenTheDoor" }, // 2015656949
		{ &Z_Construct_UFunction_AMazeGeneration_PuzzleDoor, "PuzzleDoor" }, // 1918759054
		{ &Z_Construct_UFunction_AMazeGeneration_ReSet, "ReSet" }, // 29157462
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMazeGeneration_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "MazeGeneration.h" },
		{ "ModuleRelativePath", "Public/MazeGeneration.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMazeGeneration_Statics::NewProp_MapActors_MetaData[] = {
		{ "Category", "MazeGeneration" },
		{ "ModuleRelativePath", "Public/MazeGeneration.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UClass_AMazeGeneration_Statics::NewProp_MapActors = { "MapActors", nullptr, (EPropertyFlags)0x0014000000000001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMazeGeneration, MapActors), Z_Construct_UClass_AWallActor_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UClass_AMazeGeneration_Statics::NewProp_MapActors_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMazeGeneration_Statics::NewProp_MapActors_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMazeGeneration_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMazeGeneration_Statics::NewProp_MapActors,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMazeGeneration_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMazeGeneration>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMazeGeneration_Statics::ClassParams = {
		&AMazeGeneration::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AMazeGeneration_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AMazeGeneration_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AMazeGeneration_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AMazeGeneration_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMazeGeneration()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMazeGeneration_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMazeGeneration, 2693410821);
	template<> MAZERUNNERMAPTOOLPLUGINS_API UClass* StaticClass<AMazeGeneration>()
	{
		return AMazeGeneration::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMazeGeneration(Z_Construct_UClass_AMazeGeneration, &AMazeGeneration::StaticClass, TEXT("/Script/MazeRunnerMapToolPlugins"), TEXT("AMazeGeneration"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMazeGeneration);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
