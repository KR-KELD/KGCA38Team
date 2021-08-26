// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "MazeRunnerMapToolPlugins/Public/WallActor.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeWallActor() {}
// Cross Module References
	MAZERUNNERMAPTOOLPLUGINS_API UClass* Z_Construct_UClass_AWallActor_NoRegister();
	MAZERUNNERMAPTOOLPLUGINS_API UClass* Z_Construct_UClass_AWallActor();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_MazeRunnerMapToolPlugins();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USceneComponent_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(AWallActor::execUpdateWall)
	{
		P_GET_OBJECT(UStaticMeshComponent,Z_Param_Mesh);
		P_GET_PROPERTY(FFloatProperty,Z_Param_z);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UpdateWall(Z_Param_Mesh,Z_Param_z);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AWallActor::execReMoveBool)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->ReMoveBool();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AWallActor::execIsVisited)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		*(bool*)Z_Param__Result=P_THIS->IsVisited();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AWallActor::execLeftVisibility)
	{
		P_GET_UBOOL(Z_Param_SetBool);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->LeftVisibility(Z_Param_SetBool);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AWallActor::execRightVisibility)
	{
		P_GET_UBOOL(Z_Param_SetBool);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->RightVisibility(Z_Param_SetBool);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AWallActor::execDownVisibility)
	{
		P_GET_UBOOL(Z_Param_SetBool);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->DownVisibility(Z_Param_SetBool);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AWallActor::execUPVisibility)
	{
		P_GET_UBOOL(Z_Param_SetBool);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->UPVisibility(Z_Param_SetBool);
		P_NATIVE_END;
	}
	void AWallActor::StaticRegisterNativesAWallActor()
	{
		UClass* Class = AWallActor::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "DownVisibility", &AWallActor::execDownVisibility },
			{ "IsVisited", &AWallActor::execIsVisited },
			{ "LeftVisibility", &AWallActor::execLeftVisibility },
			{ "ReMoveBool", &AWallActor::execReMoveBool },
			{ "RightVisibility", &AWallActor::execRightVisibility },
			{ "UpdateWall", &AWallActor::execUpdateWall },
			{ "UPVisibility", &AWallActor::execUPVisibility },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AWallActor_DownVisibility_Statics
	{
		struct WallActor_eventDownVisibility_Parms
		{
			bool SetBool;
		};
		static void NewProp_SetBool_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_SetBool;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AWallActor_DownVisibility_Statics::NewProp_SetBool_SetBit(void* Obj)
	{
		((WallActor_eventDownVisibility_Parms*)Obj)->SetBool = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AWallActor_DownVisibility_Statics::NewProp_SetBool = { "SetBool", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(WallActor_eventDownVisibility_Parms), &Z_Construct_UFunction_AWallActor_DownVisibility_Statics::NewProp_SetBool_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AWallActor_DownVisibility_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AWallActor_DownVisibility_Statics::NewProp_SetBool,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AWallActor_DownVisibility_Statics::Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "ModuleRelativePath", "Public/WallActor.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AWallActor_DownVisibility_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AWallActor, nullptr, "DownVisibility", nullptr, nullptr, sizeof(WallActor_eventDownVisibility_Parms), Z_Construct_UFunction_AWallActor_DownVisibility_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AWallActor_DownVisibility_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AWallActor_DownVisibility_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AWallActor_DownVisibility_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AWallActor_DownVisibility()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AWallActor_DownVisibility_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AWallActor_IsVisited_Statics
	{
		struct WallActor_eventIsVisited_Parms
		{
			bool ReturnValue;
		};
		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AWallActor_IsVisited_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((WallActor_eventIsVisited_Parms*)Obj)->ReturnValue = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AWallActor_IsVisited_Statics::NewProp_ReturnValue = { "ReturnValue", nullptr, (EPropertyFlags)0x0010000000000580, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(WallActor_eventIsVisited_Parms), &Z_Construct_UFunction_AWallActor_IsVisited_Statics::NewProp_ReturnValue_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AWallActor_IsVisited_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AWallActor_IsVisited_Statics::NewProp_ReturnValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AWallActor_IsVisited_Statics::Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "ModuleRelativePath", "Public/WallActor.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AWallActor_IsVisited_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AWallActor, nullptr, "IsVisited", nullptr, nullptr, sizeof(WallActor_eventIsVisited_Parms), Z_Construct_UFunction_AWallActor_IsVisited_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AWallActor_IsVisited_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AWallActor_IsVisited_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AWallActor_IsVisited_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AWallActor_IsVisited()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AWallActor_IsVisited_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AWallActor_LeftVisibility_Statics
	{
		struct WallActor_eventLeftVisibility_Parms
		{
			bool SetBool;
		};
		static void NewProp_SetBool_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_SetBool;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AWallActor_LeftVisibility_Statics::NewProp_SetBool_SetBit(void* Obj)
	{
		((WallActor_eventLeftVisibility_Parms*)Obj)->SetBool = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AWallActor_LeftVisibility_Statics::NewProp_SetBool = { "SetBool", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(WallActor_eventLeftVisibility_Parms), &Z_Construct_UFunction_AWallActor_LeftVisibility_Statics::NewProp_SetBool_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AWallActor_LeftVisibility_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AWallActor_LeftVisibility_Statics::NewProp_SetBool,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AWallActor_LeftVisibility_Statics::Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "ModuleRelativePath", "Public/WallActor.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AWallActor_LeftVisibility_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AWallActor, nullptr, "LeftVisibility", nullptr, nullptr, sizeof(WallActor_eventLeftVisibility_Parms), Z_Construct_UFunction_AWallActor_LeftVisibility_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AWallActor_LeftVisibility_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AWallActor_LeftVisibility_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AWallActor_LeftVisibility_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AWallActor_LeftVisibility()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AWallActor_LeftVisibility_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AWallActor_ReMoveBool_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AWallActor_ReMoveBool_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/WallActor.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AWallActor_ReMoveBool_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AWallActor, nullptr, "ReMoveBool", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AWallActor_ReMoveBool_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AWallActor_ReMoveBool_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AWallActor_ReMoveBool()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AWallActor_ReMoveBool_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AWallActor_RightVisibility_Statics
	{
		struct WallActor_eventRightVisibility_Parms
		{
			bool SetBool;
		};
		static void NewProp_SetBool_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_SetBool;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AWallActor_RightVisibility_Statics::NewProp_SetBool_SetBit(void* Obj)
	{
		((WallActor_eventRightVisibility_Parms*)Obj)->SetBool = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AWallActor_RightVisibility_Statics::NewProp_SetBool = { "SetBool", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(WallActor_eventRightVisibility_Parms), &Z_Construct_UFunction_AWallActor_RightVisibility_Statics::NewProp_SetBool_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AWallActor_RightVisibility_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AWallActor_RightVisibility_Statics::NewProp_SetBool,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AWallActor_RightVisibility_Statics::Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "ModuleRelativePath", "Public/WallActor.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AWallActor_RightVisibility_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AWallActor, nullptr, "RightVisibility", nullptr, nullptr, sizeof(WallActor_eventRightVisibility_Parms), Z_Construct_UFunction_AWallActor_RightVisibility_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AWallActor_RightVisibility_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AWallActor_RightVisibility_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AWallActor_RightVisibility_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AWallActor_RightVisibility()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AWallActor_RightVisibility_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AWallActor_UpdateWall_Statics
	{
		struct WallActor_eventUpdateWall_Parms
		{
			UStaticMeshComponent* Mesh;
			float z;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Mesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Mesh;
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_z;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AWallActor_UpdateWall_Statics::NewProp_Mesh_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AWallActor_UpdateWall_Statics::NewProp_Mesh = { "Mesh", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(WallActor_eventUpdateWall_Parms, Mesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_AWallActor_UpdateWall_Statics::NewProp_Mesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_AWallActor_UpdateWall_Statics::NewProp_Mesh_MetaData)) };
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_AWallActor_UpdateWall_Statics::NewProp_z = { "z", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(WallActor_eventUpdateWall_Parms, z), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AWallActor_UpdateWall_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AWallActor_UpdateWall_Statics::NewProp_Mesh,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AWallActor_UpdateWall_Statics::NewProp_z,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AWallActor_UpdateWall_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "Public/WallActor.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AWallActor_UpdateWall_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AWallActor, nullptr, "UpdateWall", nullptr, nullptr, sizeof(WallActor_eventUpdateWall_Parms), Z_Construct_UFunction_AWallActor_UpdateWall_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AWallActor_UpdateWall_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AWallActor_UpdateWall_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AWallActor_UpdateWall_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AWallActor_UpdateWall()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AWallActor_UpdateWall_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AWallActor_UPVisibility_Statics
	{
		struct WallActor_eventUPVisibility_Parms
		{
			bool SetBool;
		};
		static void NewProp_SetBool_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_SetBool;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_AWallActor_UPVisibility_Statics::NewProp_SetBool_SetBit(void* Obj)
	{
		((WallActor_eventUPVisibility_Parms*)Obj)->SetBool = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AWallActor_UPVisibility_Statics::NewProp_SetBool = { "SetBool", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(WallActor_eventUPVisibility_Parms), &Z_Construct_UFunction_AWallActor_UPVisibility_Statics::NewProp_SetBool_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AWallActor_UPVisibility_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AWallActor_UPVisibility_Statics::NewProp_SetBool,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AWallActor_UPVisibility_Statics::Function_MetaDataParams[] = {
		{ "CallInEditor", "true" },
		{ "ModuleRelativePath", "Public/WallActor.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AWallActor_UPVisibility_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AWallActor, nullptr, "UPVisibility", nullptr, nullptr, sizeof(WallActor_eventUPVisibility_Parms), Z_Construct_UFunction_AWallActor_UPVisibility_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AWallActor_UPVisibility_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AWallActor_UPVisibility_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AWallActor_UPVisibility_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AWallActor_UPVisibility()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AWallActor_UPVisibility_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AWallActor_NoRegister()
	{
		return AWallActor::StaticClass();
	}
	struct Z_Construct_UClass_AWallActor_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_D_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_D;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Up_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Up;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Down_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Down;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Right_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Right;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Left_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Left;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AWallActor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_MazeRunnerMapToolPlugins,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AWallActor_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AWallActor_DownVisibility, "DownVisibility" }, // 2446916736
		{ &Z_Construct_UFunction_AWallActor_IsVisited, "IsVisited" }, // 740996001
		{ &Z_Construct_UFunction_AWallActor_LeftVisibility, "LeftVisibility" }, // 1511899833
		{ &Z_Construct_UFunction_AWallActor_ReMoveBool, "ReMoveBool" }, // 728169667
		{ &Z_Construct_UFunction_AWallActor_RightVisibility, "RightVisibility" }, // 594628518
		{ &Z_Construct_UFunction_AWallActor_UpdateWall, "UpdateWall" }, // 3438506790
		{ &Z_Construct_UFunction_AWallActor_UPVisibility, "UPVisibility" }, // 2562444821
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWallActor_Statics::Class_MetaDataParams[] = {
		{ "Comment", "//DECLARE_MULTICAST_DELEGATE(FReMoveMap);\n" },
		{ "IncludePath", "WallActor.h" },
		{ "ModuleRelativePath", "Public/WallActor.h" },
		{ "ToolTip", "DECLARE_MULTICAST_DELEGATE(FReMoveMap);" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWallActor_Statics::NewProp_D_MetaData[] = {
		{ "Category", "WallActor" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/WallActor.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AWallActor_Statics::NewProp_D = { "D", nullptr, (EPropertyFlags)0x001000000008000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWallActor, D), Z_Construct_UClass_USceneComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AWallActor_Statics::NewProp_D_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWallActor_Statics::NewProp_D_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWallActor_Statics::NewProp_Up_MetaData[] = {
		{ "Category", "WallActor" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/WallActor.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AWallActor_Statics::NewProp_Up = { "Up", nullptr, (EPropertyFlags)0x001000000008000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWallActor, Up), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AWallActor_Statics::NewProp_Up_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWallActor_Statics::NewProp_Up_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWallActor_Statics::NewProp_Down_MetaData[] = {
		{ "Category", "WallActor" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/WallActor.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AWallActor_Statics::NewProp_Down = { "Down", nullptr, (EPropertyFlags)0x001000000008000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWallActor, Down), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AWallActor_Statics::NewProp_Down_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWallActor_Statics::NewProp_Down_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWallActor_Statics::NewProp_Right_MetaData[] = {
		{ "Category", "WallActor" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/WallActor.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AWallActor_Statics::NewProp_Right = { "Right", nullptr, (EPropertyFlags)0x001000000008000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWallActor, Right), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AWallActor_Statics::NewProp_Right_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWallActor_Statics::NewProp_Right_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AWallActor_Statics::NewProp_Left_MetaData[] = {
		{ "Category", "WallActor" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/WallActor.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AWallActor_Statics::NewProp_Left = { "Left", nullptr, (EPropertyFlags)0x001000000008000d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AWallActor, Left), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AWallActor_Statics::NewProp_Left_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AWallActor_Statics::NewProp_Left_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AWallActor_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWallActor_Statics::NewProp_D,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWallActor_Statics::NewProp_Up,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWallActor_Statics::NewProp_Down,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWallActor_Statics::NewProp_Right,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AWallActor_Statics::NewProp_Left,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AWallActor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AWallActor>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AWallActor_Statics::ClassParams = {
		&AWallActor::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AWallActor_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AWallActor_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AWallActor_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AWallActor_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AWallActor()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AWallActor_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AWallActor, 629626542);
	template<> MAZERUNNERMAPTOOLPLUGINS_API UClass* StaticClass<AWallActor>()
	{
		return AWallActor::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AWallActor(Z_Construct_UClass_AWallActor, &AWallActor::StaticClass, TEXT("/Script/MazeRunnerMapToolPlugins"), TEXT("AWallActor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AWallActor);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
