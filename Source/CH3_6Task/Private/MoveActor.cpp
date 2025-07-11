#include "MoveActor.h"

AMoveActor::AMoveActor()
{
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");

	MaxRange = 300.0f;
	MoveSpeed = 200.0f;
	IsMoving = true;
}

void AMoveActor::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
}

void AMoveActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector Current = GetActorLocation();

	float DeltaMove = MoveSpeed * DeltaTime * (IsMoving ? 1.f : -1.f);

	Current.X += DeltaMove;

	SetActorLocation(Current);

	if(FMath::Abs(Current.X - StartLocation.X) >= MaxRange)
	{
		IsMoving = !IsMoving;
	}
}

