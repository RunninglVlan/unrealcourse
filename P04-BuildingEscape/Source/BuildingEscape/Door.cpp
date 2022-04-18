#include "Door.h"

UDoor::UDoor()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UDoor::BeginPlay()
{
	Super::BeginPlay();
	TargetYaw = GetOwner()->GetActorRotation().Yaw + 90;
}

void UDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	const FRotator Rotation = GetOwner()->GetActorRotation();
	if (TargetYaw - Rotation.Yaw > .1f) {
		Open(Rotation, DeltaTime);
	}
}

void UDoor::Open(FRotator Rotation, const float DeltaTime) const
{
	Rotation.Yaw = FMath::FInterpTo(Rotation.Yaw, TargetYaw, DeltaTime, 2);
	GetOwner()->SetActorRotation(Rotation);
}
