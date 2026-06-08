#include "TrapFloor.h"

ATrapFloor::ATrapFloor()
{	
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	//'/Game/Resources/Props/Floor_400x400.Floor_400x400'
	//'/Game/Resources/Props/Materials/M_Bush.M_Bush'
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Props/Floor_400x400.Floor_400x400"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Resources/Props/Materials/M_Bush.M_Bush"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	}

	PrimaryActorTick.bCanEverTick = false;
	TrapInterval = 3.0f;
	bIsVisible = true;
}

void ATrapFloor::BeginPlay()
{
	Super::BeginPlay();

	GetWorld()->GetTimerManager().SetTimer(ToggleTimerHandle, this, &ATrapFloor::ToggleTrapState, TrapInterval, true);
}

void ATrapFloor::ToggleTrapState()
{
	bIsVisible = !bIsVisible;
	SetActorHiddenInGame(!bIsVisible);
	SetActorEnableCollision(bIsVisible);
}