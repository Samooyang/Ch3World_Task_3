#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpinFloor.generated.h"

UCLASS()
class CH3WORLD_API ASpinFloor : public AActor
{
	GENERATED_BODY()
	
public:	
	ASpinFloor();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Platform|Components")
	USceneComponent* SceneRoot;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Platform|Components")
	UStaticMeshComponent* StaticMeshComp;

	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform|RotationSpeed")
	float RotationSpeed;
};
