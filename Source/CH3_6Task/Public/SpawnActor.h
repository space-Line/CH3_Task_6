#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnActor.generated.h"

UCLASS()
class CH3_6TASK_API ASpawnActor : public AActor
{
	GENERATED_BODY()
	
public:
	ASpawnActor();

	UPROPERTY(EditAnywhere, Category = "Spawner")
	TSubclassOf<AActor> ActorClass;

	UPROPERTY(EditAnywhere, Category = "Spawner")
	int32 Count;

	UPROPERTY(EditAnywhere, Category = "Spawner")
	FVector SpawnExtent;

protected:
	virtual void BeginPlay() override;
};
