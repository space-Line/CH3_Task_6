#include "SpawnActor.h"
#include "Kismet/KismetMathLibrary.h"
#include "MoveActor.h"
#include "RotateActor.h"

ASpawnActor::ASpawnActor()
{
	PrimaryActorTick.bCanEverTick = false;

	Count = 10;
	SpawnExtent = FVector(1000, 1000, 0);
}

void ASpawnActor::BeginPlay()
{
	Super::BeginPlay();
	
	if (!ActorClass) return;

	for (int32 i = 0; i < Count; i++)
	{
		FVector Origin = GetActorLocation();
		FVector Offset = UKismetMathLibrary::RandomPointInBoundingBox(FVector::ZeroVector, SpawnExtent);
		FVector SpawnLoc = Origin + Offset;
		FRotator SpawnRot = FRotator::ZeroRotator;

		AActor* NewActor = GetWorld()->SpawnActor<AActor>(ActorClass, SpawnLoc, SpawnRot);

		if (!NewActor) continue;

		if (auto MR = Cast<ARotateActor>(NewActor))
		{
			MR->RotationSpeed = FMath::RandRange(90.f, 180.f);
		}
		else if (auto TP = Cast<AMoveActor>(NewActor))
		{
			TP->MoveSpeed = FMath::RandRange(100.f, 500.f);
			TP->MaxRange = FMath::RandRange(300.f, 800.f);
		}
	}
}

