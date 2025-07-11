#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotateActor.generated.h"

UCLASS()
class CH3_6TASK_API ARotateActor : public AActor
{
	GENERATED_BODY()
	
public:
	ARotateActor();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Rotation");
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation");
	float RotationSpeed;

	virtual void Tick(float DeltaTime) override;

};
