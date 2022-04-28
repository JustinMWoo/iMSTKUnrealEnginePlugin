// Fill out your copyright notice in the Description page of Project Settings.


#include "ImstkController.h"
#include "ImstkSubsystem.h"


void UImstkController::InitializeComponent()
{
	Super::InitializeComponent();
	
	if (GetWorld() && GetWorld()->GetGameInstance()) {
		SubsystemInstance = GetWorld()->GetGameInstance()->GetSubsystem<UImstkSubsystem>();
		UStaticMeshComponent* MeshComp = (UStaticMeshComponent*)GetOwner()->GetComponentByClass(UStaticMeshComponent::StaticClass());

		if (MeshComp)
			MeshComp->SetMobility(EComponentMobility::Type::Movable);
	}
	
}

// Sets default values for this component's properties
UImstkController::UImstkController()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	bWantsInitializeComponent = true;
	// ...
}


// Called when the game starts
void UImstkController::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UImstkController::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

// Unimplemented
void UImstkController::InitController()
{

}

std::shared_ptr<imstk::RigidObject2> UImstkController::GetToolObj()
{
	return ToolObj;
}

void UImstkController::SetToolPicking(std::shared_ptr<imstk::PbdRigidObjectGrasping> Picking)
{
	this->ToolPicking = Picking;
}

void UImstkController::SetStitching(std::shared_ptr<imstk::PbdObjectStitching> InputStitch)
{
	this->Stitching = InputStitch;
}

void UImstkController::UnInit()
{
	ToolObj.reset();
	//Stitching.reset();
}
