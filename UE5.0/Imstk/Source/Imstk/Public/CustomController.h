// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ImstkController.h"
#include "DynamicalModel.h"

#include "imstkPbdObject.h"

#include "CustomController.generated.h"

UENUM(BlueprintType)
enum EControllerPreset
{
	CollidingPreset,
	GraspingPreset,
	CuttingPreset,
	StitchingPreset,
	LevelSetPreset
};

/** \file CustomController.h
 *  \brief Customizable controller to move an object within the iMSTK scene
 *  \details
 */
UCLASS(ClassGroup = (Imstk), meta = (BlueprintSpawnableComponent))
class IMSTK_API UCustomController : public UImstkController
{
	GENERATED_BODY()

public:
	UCustomController();

	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent);

	UPROPERTY(EditAnywhere, Category = "iMSTK")
		TEnumAsByte<EControllerPreset> Preset = EControllerPreset::CollidingPreset;

	virtual void InitializeComponent() override;

	/** Initializes the controller in imstk
	* @return None
	*/
	virtual void InitController() override;

	/** Moves the iMSTK object to the inputted location and orientation. Moves the Unreal Actor that the component is attached to to the specified location if bUpdateUnrealPosRot is set.
	* @param Location - The Unreal position to move the controller to
	* @param Orientation - The Unreal orientation to move the controller to
	* @param bUpdateUnrealPosRot - Updates the position and rotation of the Unreal Actor if true
	* @return None
	*/
	UFUNCTION(BlueprintCallable, Category = "iMSTK|Controller")
		void MoveControllerToLocation(FVector Location, FQuat Orientation, bool bUpdateUnrealPosRot = true);

	/** Projects a ray with the specified start and direction onto the supplied plane to find a point of intersection and moves the iMSTK object to that location.
	* Moves the Unreal Actor that the component is attached to to the specified location if bUpdateUnrealPosRot is set.
	* @param Location - The Unreal position to move the controller to
	* @param Orientation - The Unreal orientation to move the controller to
	* @param bUpdateUnrealPosRot - Updates the position and rotation of the Unreal Actor if true
	* @return The intersection location between the projected ray and the plane
	*/
	UFUNCTION(BlueprintCallable, Category = "iMSTK|Controller")
		FVector MoveControllerToRaycastOnPlane(FVector RayStart, FVector RayDir, FQuat Orientation, UDynamicalModel* PlaneActor, bool bUpdateUnrealPosRot = true);

protected:
	/** Helper function that updates the object in imstk the WorldPos, or a location on the plane determined by a raycast from the WorlPos in the
	* direction of WorldDir if the PlaneActor is provided
	* @param WorldPos - New world position of the mouse cursor or if a PlaneActor is provided, the starting point of the ray
	* @param WorldDir - Direction of the raycast if relevant
	* @param PlaneActor* - Pointer to a DynamicalModel that contains the plane to raycast onto
	* @return FVector - The position of the object in imstk
	*/
	FVector UpdateImstkPosRot(FVector WorldPos, FQuat Orientation, FVector WorldDir = FVector::ZeroVector, UDynamicalModel* PlaneActor = nullptr);

	/** Helper function that moves the object to the location in the imstk scene
	* @return None
	*/
	void UpdateUnrealPosRot();

	/** Starts a vertex grasp if the tool is set to a grasping tool and a PbdObjectGrasping interaction are set on the controller
	* @return None
	*/
	//UFUNCTION(BlueprintCallable, Category = "iMSTK|Controller")
		//void BeginVertexGrasp();

	/** Starts a cell grasp if the tool is set to a grasping tool and a PbdObjectGrasping interaction are set on the controller
	* @return None
	*/
	//UFUNCTION(BlueprintCallable, Category = "iMSTK|Controller")
		//void BeginCellGrasp();

	/** Starts a ray point grasp from RayStart in the direction provided if the tool is set to a grasping tool and a PbdObjectGrasping interaction are set on the controller
	* @param RayStart Starting point of the ray
	* @param RayDir Direction of the ray to be cast
	* @return None
	*/
	//UFUNCTION(BlueprintCallable, Category = "iMSTK|Controller")
		//void BeginRayPointGrasp(FVector RayStart, FVector RayDir);

	/** Ends the current grasp
	* @return None
	*/
	//UFUNCTION(BlueprintCallable, Category = "iMSTK|Controller")
		//void EndGrasp();

	/** Creates a stitching interaction between the two vertices of the line mesh tool. Requires geometry to be set to a LineMeshTool.
	* @return None
	*/
	//UFUNCTION(BlueprintCallable, Category = "iMSTK|Controller")
		//void BeginStitch();

	/** Applies the cut for each PbdObjectCutting interaction on the controller. Requires geometry to be set to a SurfaceMeshTool.
	* @return None
	*/
	//UFUNCTION(BlueprintCallable, Category = "iMSTK|Controller")
		//void BeginCut();

	//UFUNCTION(BlueprintCallable, Category = "iMSTK|Controller")
		//bool BeginTetrahedralCut();

	/*bool SplitTest(const std::array<imstk::Vec3d, 4>& InputTetVerts,
		const imstk::Vec3d& PlaneOrigin,
		const imstk::Vec3d& U, const double Width,
		const imstk::Vec3d& V, const double Height,
		const imstk::Vec3d& N);

	bool IsIntersect(const double A, const double B, const double C, const double D);*/

	// Mass of the object in iMSTK
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "iMSTK")
		float Mass = 0.2;

	// TODO: separate into a factory for the tool object?
	// Velocity damping of the tool's rigid body in iMSTK
	UPROPERTY(EditAnywhere, meta = (EditCondition = "ToolType != EToolType::TetrahedralCuttingTool", EditConditionHides), BlueprintReadWrite, Category = "iMSTK|RigidBody")
		float VelocityDamping = 1.0;

	// Angular velocity damping of the tool's rigid body in iMSTK
	UPROPERTY(EditAnywhere, meta = (EditCondition = "ToolType != EToolType::TetrahedralCuttingTool", EditConditionHides), BlueprintReadWrite, Category = "iMSTK|RigidBody")
		float AngularVelocityDamping = 1.0;

	// Maximum iterations of the tool's rigid body in iMSTK
	UPROPERTY(EditAnywhere, meta = (EditCondition = "ToolType != EToolType::TetrahedralCuttingTool", EditConditionHides), BlueprintReadWrite, Category = "iMSTK|RigidBody")
		int MaxNumIterations = 8;

	// Maximum constraints of the tool's rigid body in iMSTK
	UPROPERTY(EditAnywhere, meta = (EditCondition = "ToolType != EToolType::TetrahedralCuttingTool", EditConditionHides), BlueprintReadWrite, Category = "iMSTK|RigidBody")
		int MaxNumConstraints = 40;

	// Inertia tensor of the tool's rigid body in iMSTK
	UPROPERTY(EditAnywhere, meta = (EditCondition = "ToolType != EToolType::TetrahedralCuttingTool", EditConditionHides), BlueprintReadWrite, Meta = (ClampMin = "0.01"), Category = "iMSTK|RigidBody")
		float InertiaTensorMultiplier = 1.0;

	// Moves the tool using force rather than moving directly to the position given
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "iMSTK|ForceTool")
		bool bForceTool = false;

	// Material of the ghost models 
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "bForceTool", EditConditionHides), Category = "iMSTK|ForceTool")
		UMaterial* GhostMaterial;

	/** Sets the components used for the ghost object on force tools
	* @param SceneComponent - Pointer to the empty parent USceneComponent that holds the UStaticMeshComponents
	* @param StaticMeshComponents - Array of pointers to UStaticMeshComponents that represent the ghost model
	*/
	UFUNCTION(BlueprintCallable, Category = "iMSTK|CustomController")
		void SetGhostComponents(USceneComponent* SceneComponent, TArray<UStaticMeshComponent*> StaticMeshComponents);

	UPROPERTY(EditAnywhere, meta = (EditCondition = "bForceTool", EditConditionHides), BlueprintReadWrite, Category = "iMSTK|ForceTool|Force")
		bool bIgnoreAngularForce = true;

	// Spring force of the force applied to the tool
	UPROPERTY(EditAnywhere, meta = (EditCondition = "bForceTool && bIgnoreAngularForce", EditConditionHides), BlueprintReadWrite, Category = "iMSTK|ForceTool|Force")
		float SpringForce = 10000;

	// Spring damping of the force applied to the tool
	UPROPERTY(EditAnywhere, meta = (EditCondition = "bForceTool && bIgnoreAngularForce", EditConditionHides), BlueprintReadWrite, Category = "iMSTK|ForceTool|Force")
		float DamperForce = 100;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "bForceTool && !bIgnoreAngularForce", EditConditionHides), Category = "iMSTK|ForceTool|Force")
		FVector LinearKs = FVector(8000000.0, 8000000.0, 8000000.0);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "bForceTool && !bIgnoreAngularForce", EditConditionHides), Category = "iMSTK|ForceTool|Force")
		FVector AngularKs = FVector(10000.0, 10000.0, 10000.0);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "bForceTool && !bIgnoreAngularForce", EditConditionHides), Category = "iMSTK|ForceTool|Force")
		double LinearKd = 10000.0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "bForceTool && !bIgnoreAngularForce", EditConditionHides), Category = "iMSTK|ForceTool|Force")
		double AngularKd = 300.0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (EditCondition = "bForceTool && !bIgnoreAngularForce", EditConditionHides), Category = "iMSTK|ForceTool|Force")
		double ForceScale = 1;

	UFUNCTION(BlueprintCallable, Category = "iMSTK|CustomController")
		FVector GetControlleriMSTKPosition();

	//imstk::Vec3d SpringForce = imstk::Vec3d::Zero();
	//imstk::Vec3d DamperForce = imstk::Vec3d::Zero();

	imstk::Vec3d AngularSpringForce = imstk::Vec3d::Zero();
	imstk::Vec3d AngularDamperForce = imstk::Vec3d::Zero();

	// Prints the position of the object to the screen
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "iMSTK|Debugging")
		bool bPrintImstkPos = false;

	// Pointer to the empty parent USceneComponent that holds the UStaticMeshComponents. This is what will be moved around the scene to preserve offsets on the UStaticMeshComponents
	UPROPERTY()
		USceneComponent* GhostSceneComp;

	// Array of pointers to UStaticMeshComponents that represent the ghost model
	UPROPERTY()
		TArray<UStaticMeshComponent*> GhostMeshes;

	// Cached pointer of the tool as a rigid object to avoid constant dynamic casts
	std::shared_ptr<imstk::RigidObject2> RigidToolObj;

	std::shared_ptr<imstk::PbdObject> PbdToolObj;
public:
	virtual void UnInit() override;

};
