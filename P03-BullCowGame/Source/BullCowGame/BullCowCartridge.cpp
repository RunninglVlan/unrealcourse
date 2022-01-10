// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay()
{
	Super::BeginPlay();
	PrintLine("Welcome to Bulls & Cows!");
	PrintLine("Press Enter to continue...");
}

void UBullCowCartridge::OnInput(const FString& Input)
{
	ClearScreen();
}
