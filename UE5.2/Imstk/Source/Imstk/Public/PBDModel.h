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

	// Use a rigid body with pbd physics. This allows for rigid bodies that are impacted by the forces produced from deformable models
	UPROPERTY(EditAnywhere, Category = "iMSTK|RigidBody")
		bool bRigidBody = false;
	// Multiplier for the inertia of the rigid body
	UPROPERTY(EditAnywhere, meta = (EditCondition = "bRigidBody", EditConditionHides), Category = "iMSTK|RigidBody")
		double RBInertiaMultiplier = 1;

	// Tetrahedral mesh asset to be used for the PBDModel.Can be generated by importing tetrahedral mesh files into Unreal. Should match the surface mesh attached to the actor
	UPROPERTY(EditAnywhere, meta = (EditCondition = "!bRigidBody", EditConditionHides), Category = "iMSTK")
		UTetrahedralMeshAsset* TetrahedralMesh;

	// Angular constraint between two triangular faces
	UPROPERTY(EditAnywhere, meta = (EditCondition = "!bRigidBody && TetrahedralMesh == nullptr", EditConditionHides), Category = "iMSTK|Constraints")
		bool bUseDihedralConstraint = false;
	// Stiffness of the dihedral constraint
	UPROPERTY(EditAnywhere, meta = (EditCondition = "!bRigidBody && bUseDihedralConstraint && TetrahedralMesh == nullptr", EditConditionHides), Category = "iMSTK|Constraints")
		float DihedralConstraint = 1;

	// Volume constraint for tetrahedral elements
	UPROPERTY(EditAnywhere, meta = (EditCondition = "!bRigidBody && TetrahedralMesh != nullptr", EditConditionHides), Category = "iMSTK|Constraints")
		bool bUseVolumeConstraint = false;
	// Stiffness of the volume constraint
	UPROPERTY(EditAnywhere, meta = (EditCondition = "!bRigidBody && bUseVolumeConstraint && TetrahedralMesh != nullptr", EditConditionHides), Category = "iMSTK|Constraints")
		float VolumeConstraint = 1000;

	// Constraint as the elastic energy computed by linear shape functions with tetrahedral mesh
	UPROPERTY(EditAnywhere, meta = (EditCondition = "!bRigidBody && TetrahedralMesh != nullptr", EditConditionHides), Category = "iMSTK|Constraints")
		bool bUseFEMConstraint = false;
	UPROPERTY(EditAnywhere, meta = (EditCondition = "!bRigidBody && bUseFEMConstraint && TetrahedralMesh != nullptr", EditConditionHides), Category = "iMSTK|Constraints")
		float YoungsModulus = 1000;
	UPROPERTY(EditAnywhere, meta = (EditCondition = "!bRigidBody && bUseFEMConstraint && TetrahedralMesh != nullptr", EditConditionHides), Category = "iMSTK|Constraints")
		float PossionsRatio = 0.2;
	// Material type of the FEM Constraint
	UPROPERTY(EditAnywhere, meta = (EditCondition = "!bRigidBody && bUseFEMConstraint && TetrahedralMesh != nullptr", EditConditionHides), Category = "iMSTK|Constraints")
		TEnumAsByte<FemConstraintMaterial> MaterialType = FemConstraintMaterial::StVK;

	// Generates constraints per cell of a SurfaceMesh
	UPROPERTY(EditAnywhere, meta = (EditCondition = "!bRigidBody && TetrahedralMesh == nullptr", EditConditionHides), Category = "iMSTK|Constraints")
		bool bUseAreaConstraint = false;
	// Stiffness of the area constraint
	UPROPERTY(EditAnywhere, meta = (EditCondition = "!bRigidBody && bUseAreaConstraint && TetrahedralMesh == nullptr", EditConditionHides), Category = "iMSTK|Constraints")
		float AreaConstraint = 100;

	// Generate a new surface mesh from the tetrahedral mesh. Simulation may be more accurate, but most material information will be lost
	UPROPERTY(EditAnywhere, meta = (EditCondition = "!bRigidBody && TetrahedralMesh != nullptr", EditConditionHides), Category = "iMSTK")
		bool bGenerateSurfaceFromTetrahedral = false;

	// Clean the mesh to remove duplicated vertices (useful for uv seams), only works with surface meshes. Note: May result in unintended geometry
	UPROPERTY(EditAnywhere, meta = (EditCondition = "TetrahedralMesh == nullptr", EditConditionHides), Category = "iMSTK")
		bool bCleanMesh = false;

	// Tolerance for merging points on the surface mesh
	UPROPERTY(EditAnywhere, meta = (EditCondition = "TetrahedralMesh == nullptr && bCleanMesh", EditConditionHides), Category = "iMSTK")
		float Tolerance = 0;

	/*UPROPERTY(EditAnywhere, Category = "iMSTK")
		bool bIsTearable = false;
	UPROPERTY(EditAnywhere, meta = (EditCondition = "bIsTearable", EditConditionHides), Category = "iMSTK")
		double MaxStrain = 0.5;*/

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void InitializeComponent() override;

	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent);

	// Assigns preset values for the constraints of the PBDModel
	UPROPERTY(EditAnywhere, Category = "iMSTK")
		TEnumAsByte<EPBDModelPresets> Preset = EPBDModelPresets::ClothPreset;

	/** Initializes the geometry and the PBD model for the deformable model
	* @return None
	*/
	virtual void Init() override;

	virtual void UnInit() override;

	void UpdateVisualFromTet();

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
