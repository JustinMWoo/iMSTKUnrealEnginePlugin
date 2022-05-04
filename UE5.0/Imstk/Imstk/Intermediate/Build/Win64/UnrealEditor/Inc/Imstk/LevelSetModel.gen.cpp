// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Imstk/Public/LevelSetModel.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLevelSetModel() {}
// Cross Module References
	IMSTK_API UClass* Z_Construct_UClass_ULevelSetModel_NoRegister();
	IMSTK_API UClass* Z_Construct_UClass_ULevelSetModel();
	IMSTK_API UClass* Z_Construct_UClass_UDynamicalModel();
	UPackage* Z_Construct_UPackage__Script_Imstk();
	PROCEDURALMESHCOMPONENT_API UClass* Z_Construct_UClass_UProceduralMeshComponent_NoRegister();
// End Cross Module References
	void ULevelSetModel::StaticRegisterNativesULevelSetModel()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ULevelSetModel);
	UClass* Z_Construct_UClass_ULevelSetModel_NoRegister()
	{
		return ULevelSetModel::StaticClass();
	}
	struct Z_Construct_UClass_ULevelSetModel_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_MeshComp_MetaData[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_MeshComp;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ULevelSetModel_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UDynamicalModel,
		(UObject* (*)())Z_Construct_UPackage__Script_Imstk,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULevelSetModel_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n *///UCLASS(ClassGroup = (Imstk), meta = (BlueprintSpawnableComponent))\n" },
		{ "IncludePath", "LevelSetModel.h" },
		{ "ModuleRelativePath", "Public/LevelSetModel.h" },
		{ "ToolTip", "//UCLASS(ClassGroup = (Imstk), meta = (BlueprintSpawnableComponent))" },
	};
#endif
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULevelSetModel_Statics::NewProp_MeshComp_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/LevelSetModel.h" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ULevelSetModel_Statics::NewProp_MeshComp = { "MeshComp", nullptr, (EPropertyFlags)0x0020080000080008, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ULevelSetModel, MeshComp), Z_Construct_UClass_UProceduralMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ULevelSetModel_Statics::NewProp_MeshComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ULevelSetModel_Statics::NewProp_MeshComp_MetaData)) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ULevelSetModel_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ULevelSetModel_Statics::NewProp_MeshComp,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ULevelSetModel_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULevelSetModel>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ULevelSetModel_Statics::ClassParams = {
		&ULevelSetModel::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ULevelSetModel_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ULevelSetModel_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ULevelSetModel_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ULevelSetModel_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ULevelSetModel()
	{
		if (!Z_Registration_Info_UClass_ULevelSetModel.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ULevelSetModel.OuterSingleton, Z_Construct_UClass_ULevelSetModel_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ULevelSetModel.OuterSingleton;
	}
	template<> IMSTK_API UClass* StaticClass<ULevelSetModel>()
	{
		return ULevelSetModel::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ULevelSetModel);
	struct Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_LevelSetModel_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_LevelSetModel_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ULevelSetModel, ULevelSetModel::StaticClass, TEXT("ULevelSetModel"), &Z_Registration_Info_UClass_ULevelSetModel, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ULevelSetModel), 800118655U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_LevelSetModel_h_1877023522(TEXT("/Script/Imstk"),
		Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_LevelSetModel_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_HostProject_Plugins_Imstk_Source_Imstk_Public_LevelSetModel_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
