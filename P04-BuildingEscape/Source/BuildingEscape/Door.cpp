#include "Door.h"

UDoor::UDoor()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UDoor::BeginPlay()
{
	Super::BeginPlay();
	Open();
}

void UDoor::Open() const
{
	FRotator Rotation = GetOwner()->GetActorRotation();
	Rotation.Yaw += 90;
	GetOwner()->SetActorRotation(Rotation);
}

void UDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
