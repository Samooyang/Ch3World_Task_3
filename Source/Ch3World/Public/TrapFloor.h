#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TrapFloor.generated.h"

UCLASS()
class CH3WORLD_API ATrapFloor : public AActor
{
	GENERATED_BODY()
	
public:	
	ATrapFloor();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Platform|Components")
	USceneComponent* SceneRoot;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Platform|Components")
	UStaticMeshComponent* StaticMeshComp;

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Platform|Interval")
	float TrapInterval;

	bool bIsVisible;

	FTimerHandle ToggleTimerHandle;
	void ToggleTrapState();
};
