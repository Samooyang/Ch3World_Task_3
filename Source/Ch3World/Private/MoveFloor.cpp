#include "MoveFloor.h"

AMoveFloor::AMoveFloor()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	//'/Game/Resources/Props/Floor_400x400.Floor_400x400'
	//'/Game/Resources/Props/Materials/M_Rock.M_Rock'
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Resources/Props/Floor_400x400.Floor_400x400"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Resources/Props/Materials/M_Rock.M_Rock"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	}

	PrimaryActorTick.bCanEverTick = true;
	MoveSpeed = 2.0f;
	MoveDirection = FVector(0.0f, 1.0f, 0.0f);
	MaxRange = 150.0f;
	RunningTime = 0.0f;
}

void AMoveFloor::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
	MoveDirection = MoveDirection.GetSafeNormal();
}

void AMoveFloor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RunningTime += DeltaTime * MoveSpeed;
	float TimeValue = FMath::Sin(RunningTime);
	FVector NewLocation = StartLocation + (MoveDirection * MaxRange * TimeValue);
	SetActorLocation(NewLocation);
}