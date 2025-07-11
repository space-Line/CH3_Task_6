#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MoveActor.generated.h"

UCLASS()
class CH3_6TASK_API AMoveActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AMoveActor();
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Move");
	UStaticMeshComponent* Mesh;

	FVector StartLocation;
	bool IsMoving;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Move");
	float MaxRange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Move");
	float MoveSpeed;

	virtual void Tick(float DeltaTime) override;
};
