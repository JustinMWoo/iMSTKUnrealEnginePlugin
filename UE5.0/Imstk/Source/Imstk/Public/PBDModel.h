// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DeformableModel.h"
#include "TetrahedralMeshAsset.h"
#include "imstkSurfaceMesh.h"
#include "PBDModel.generated.h"

UENUM(BlueprintType)
enum EPBDModelPresets
{
	VolumetricTissuePreset,
	ClothPreset
};

/** \file PBDModel.h
 *  \brief Position based dynamics model to attach to an actor in Unreal to mark as an object to add into iMSTK.
 *  \details Has variables available in editor and blueprint to set the default values of the object in iMSTK. Converts attached static mesh or procedural mesh into a PBDModel in iMSTK. 
 *		     Attaches a procedural mesh to the object if it does not exist and updates the positions of the vertices to correspond with iMSTK. Can also be used to model tetrahedral meshes.
 */
UCLASS(ClassGroup = (Imstk), meta = (BlueprintSpawnableComponent))
class IMSTK_API UPBDModel : public UDeformableModel
{
	GENERATED_BODY()

public:
	UPBDModel();

	// Tetrahedral mesh asset to be used for the PBDModel.Can be generated by importing tetrahedral mesh files into Unreal. Should match the surface mesh attached to the actor
	UPROPERTY(EditAnywhere, Category = "General")
		UTetrahedralMeshAsset* TetrahedralMesh;

	UPROPERTY(EditAnywhere, meta = (EditCondition = "TetrahedralMesh == nullptr", EditConditionHides), Category = "General|Advanced|Constraints")
		bool bUseDihedralConstraint = false;
	UPROPERTY(EditAnywhere, meta = (EditCondition = "bUseDihedralConstraint && TetrahedralMesh == nullptr", EditConditionHides), Category = "General|Advanced|Constraints")
		float DihedralConstraint = 0.0;

	UPROPERTY(EditAnywhere, meta = (EditCondition = "TetrahedralMesh != nullptr", EditConditionHides), Category = "General|Advanced|Constraints")
		bool bUseVolumeConstraint = false;
	UPROPERTY(EditAnywhere, meta = (EditCondition = "bUseVolumeConstraint && TetrahedralMesh != nullptr", EditConditionHides), Category = "General|Advanced|Constraints")
		float VolumeConstraint = 0.0;

	UPROPERTY(EditAnywhere, meta = (EditCondition = "TetrahedralMesh != nullptr", EditConditionHides), Category = "General|Advanced|Constraints")
		bool bUseFEMConstraint = false;
	UPROPERTY(EditAnywhere, meta = (EditCondition = "bUseFEMConstraint && TetrahedralMesh != nullptr", EditConditionHides), Category = "General|Advanced|Constraints")
		float YoungsModulus = 0.0;
	UPROPERTY(EditAnywhere, meta = (EditCondition = "bUseFEMConstraint && TetrahedralMesh != nullptr", EditConditionHides), Category = "General|Advanced|Constraints")
		float PossionsRatio = 0.0;
	UPROPERTY(EditAnywhere, meta = (EditCondition = "bUseFEMConstraint && TetrahedralMesh != nullptr", EditConditionHides), Category = "General|Advanced|Constraints")
		TEnumAsByte<FemConstraintMaterial> MaterialType = FemConstraintMaterial::StVK;

	// Generate a new surface mesh from the tetrahedral mesh. Simulation may be more accurate, but most material information will be lost
	UPROPERTY(EditAnywhere, meta = (EditCondition = "TetrahedralMesh != nullptr", EditConditionHides), Category = "General")
		bool bGenerateSurfaceFromTetrahedral = false;

	// Clean the mesh to remove duplicated vertices (useful for uv seams)
	UPROPERTY(EditAnywhere, meta = (EditCondition = "TetrahedralMesh == nullptr", EditConditionHides), Category = "General")
		bool bCleanMesh = false;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void InitializeComponent() override;

	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent);

	UPROPERTY(EditAnywhere, Category = "General")
		TEnumAsByte<EPBDModelPresets> Preset = EPBDModelPresets::ClothPreset;

	/** Initializes the geometry and the PBD model for the deformable model
	* @return None
	*/
	virtual void Init() override;

	virtual void UnInit() override;

protected:
	// Procedural mesh component attached to the actor (will be generated if one is not attached)
	UPROPERTY()
		UProceduralMeshComponent* MeshComp;

	// Cached mesh geometry used to update Unreal procedural mesh
	std::shared_ptr<imstk::SurfaceMesh> MeshGeom;
	std::shared_ptr<imstk::SurfaceMesh> CleanMeshGeom;
	std::shared_ptr<imstk::PointSet> PointSetGeom;

	/** Updates the mesh's vertices in Unreal to visualize the scene in imstk
	* @return None
	*/
	virtual void UpdateModel() override;
	
};
