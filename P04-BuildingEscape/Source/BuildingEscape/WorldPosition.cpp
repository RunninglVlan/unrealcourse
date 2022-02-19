#include "WorldPosition.h"

UWorldPosition::UWorldPosition()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UWorldPosition::BeginPlay()
{
	Super::BeginPlay();

	const FString Name = GetOwner()->GetName();
	UE_LOG(LogTemp, Warning, TEXT("%s"), *Name);
}

void UWorldPosition::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}
