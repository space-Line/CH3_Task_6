#include "TimerActor.h"

ATimerActor::ATimerActor()
{
	PrimaryActorTick.bCanEverTick = false;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>("Mesh");

	SetTime = 3.0f;
	MaxRange = 100.0f;
	MoveDistance = 100.0f;
	IsMoving = true;
}

void ATimerActor::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
	
	GetWorld()->GetTimerManager().SetTimer(TimerActorHandle, this, &ATimerActor::OnTimerTick, SetTime, true, 1.0f);
}

void ATimerActor::OnTimerTick()
{
	FVector Telepo = GetActorLocation();

	if (FMath::Abs(Telepo.X - StartLocation.X) >= MaxRange)
	{
		IsMoving = !IsMoving;
	}

	float Move = IsMoving ? 1.f : -1.f;
	Telepo.X += MoveDistance * Move;

	SetActorLocation(Telepo);
}