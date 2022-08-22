// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef IMSTK_DynamicalModel_generated_h
#error "DynamicalModel.generated.h already included, missing '#pragma once' in DynamicalModel.h"
#endif
#define IMSTK_DynamicalModel_generated_h

#define FID_HostProject_Plugins_Imstk_Source_Imstk_Public_DynamicalModel_h_19_SPARSE_DATA
#define FID_HostProject_Plugins_Imstk_Source_Imstk_Public_DynamicalModel_h_19_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execGetGeomOffset); \
	DECLARE_FUNCTION(execGetGeomScale);


#define FID_HostProject_Plugins_Imstk_Source_Imstk_Public_DynamicalModel_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execGetGeomOffset); \
	DECLARE_FUNCTION(execGetGeomScale);


#define FID_HostProject_Plugins_Imstk_Source_Imstk_Public_DynamicalModel_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUDynamicalModel(); \
	friend struct Z_Construct_UClass_UDynamicalModel_Statics; \
public: \
	DECLARE_CLASS(UDynamicalModel, UImstkBehaviour, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Config), CASTCLASS_None, TEXT("/Script/Imstk"), NO_API) \
	DECLARE_SERIALIZER(UDynamicalModel)


#define FID_HostProject_Plugins_Imstk_Source_Imstk_Public_DynamicalModel_h_19_INCLASS \
private: \
	static void StaticRegisterNativesUDynamicalModel(); \
	friend struct Z_Construct_UClass_UDynamicalModel_Statics; \
public: \
	DECLARE_CLASS(UDynamicalModel, UImstkBehaviour, COMPILED_IN_FLAGS(CLASS_Abstract | CLASS_Config), CASTCLASS_None, TEXT("/Script/Imstk"), NO_API) \
	DECLARE_SERIALIZER(UDynamicalModel)


#define FID_HostProject_Plugins_Imstk_Source_Imstk_Public_DynamicalModel_h_19_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDynamicalModel(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_ABSTRACT_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UDynamicalModel) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDynamicalModel); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDynamicalModel); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UDynamicalModel(UDynamicalModel&&); \
	NO_API UDynamicalModel(const UDynamicalModel&); \
public:


#define FID_HostProject_Plugins_Imstk_Source_Imstk_Public_DynamicalModel_h_19_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UDynamicalModel() { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UDynamicalModel(UDynamicalModel&&); \
	NO_API UDynamicalModel(const UDynamicalModel&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UDynamicalModel); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UDynamicalModel); \
	DEFINE_ABSTRACT_DEFAULT_CONSTRUCTOR_CALL(UDynamicalModel)


#define FID_HostProject_Plugins_Imstk_Source_Imstk_Public_DynamicalModel_h_16_PROLOG
#define FID_HostProject_Plugins_Imstk_Source_Imstk_Public_DynamicalModel_h_19_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_Imstk_Source_Imstk_Public_DynamicalModel_h_19_SPARSE_DATA \
	FID_HostProject_Plugins_Imstk_Source_Imstk_Public_DynamicalModel_h_19_RPC_WRAPPERS \
	FID_HostProject_Plugins_Imstk_Source_Imstk_Public_DynamicalModel_h_19_INCLASS \
	FID_HostProject_Plugins_Imstk_Source_Imstk_Public_DynamicalModel_h_19_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FID_HostProject_Plugins_Imstk_Source_Imstk_Public_DynamicalModel_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FID_HostProject_Plugins_Imstk_Source_Imstk_Public_DynamicalModel_h_19_SPARSE_DATA \
	FID_HostProject_Plugins_Imstk_Source_Imstk_Public_DynamicalModel_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	FID_HostProject_Plugins_Imstk_Source_Imstk_Public_DynamicalModel_h_19_INCLASS_NO_PURE_DECLS \
	FID_HostProject_Plugins_Imstk_Source_Imstk_Public_DynamicalModel_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> IMSTK_API UClass* StaticClass<class UDynamicalModel>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FID_HostProject_Plugins_Imstk_Source_Imstk_Public_DynamicalModel_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
