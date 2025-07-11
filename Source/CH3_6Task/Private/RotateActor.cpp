#include "RotateActor.h"

ARotateActor::ARotateActor()
{
	PrimaryActorTick.bCanEverTick = true;
	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");

	RotationSpeed = 90.0f;
}

void ARotateActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FRotator DeltaRot(0.f, RotationSpeed * DeltaTime, 0.f);
	AddActorLocalRotation(DeltaRot);
}

