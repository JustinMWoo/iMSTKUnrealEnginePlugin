// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DeformableModel.h"
#include "Components/SplineComponent.h"
#include "imstkLineMesh.h"
#include "PBDThread.generated.h"

/**
 *   
 */
UCLASS(ClassGroup = (Imstk), meta = (BlueprintSpawnableComponent), hidecategories = ("General|Geometry"))
class IMSTK_API UPBDThread : public UDeformableModel
{
	GENERATED_BODY()


public:
	// Zeros the tangents for the spine in Unreal 
    // TODO: maybe remove this option
	UPROPERTY(EditAnywhere, Category = "General")
		bool bZeroTangents = false;

	UPROPERTY(EditAnywhere, Category = "Constraints")
		bool bUseBendConstraint = false;
	UPROPERTY(EditAnywhere, meta = (EditCondition = "bUseBendConstraint", EditConditionHides), Category = "Constraints")
		float BendStiffness = 0.0;

	// Spline component attached to the Actor
	UPROPERTY()
		USplineComponent* SplineComponent;

	/** Initializes the geometry and the PBD model for the deformable model
	* @return None
	*/
	virtual void Init() override;

	virtual void InitializeComponent() override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	/** Updates the mesh's vertices in Unreal to visualize the scene in imstk
	* @return None
	*/
	virtual void UpdateModel() override;


	/** Moves the specified vertex on the thread to the location. Note: Node on thread may need to be fixed for intended behaviour in iMSTK
	* @param VertIndex Vertex to move
	* @param Pos Position to move the vertex to
	* @return None
	*/
	UFUNCTION(BlueprintCallable, Category = "Imstk")
		void MoveVertexToLocation(int VertIndex, FVector Pos);

protected:
	// TODO: Move stuff like this and MeshGeom in pbdModel into dynamical model and make a GetVisualGeom() function
	std::shared_ptr<imstk::LineMesh> VisualGeom;

public:
	virtual void UnInit() override;
};
