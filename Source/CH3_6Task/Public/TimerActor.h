#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TimerActor.generated.h"

UCLASS()
class CH3_6TASK_API ATimerActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ATimerActor(); 
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Timer");
	UStaticMeshComponent* Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Timer");
	float SetTime;

	FTimerHandle TimerActorHandle;
	FVector StartLocation;
	bool IsMoving;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Timer");
	float MaxRange;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Timer");
	float MoveDistance;

protected:
	virtual void BeginPlay() override;

	UFUNCTION()
	void OnTimerTick();

};
