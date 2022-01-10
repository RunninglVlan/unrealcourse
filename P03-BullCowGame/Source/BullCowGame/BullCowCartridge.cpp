// Fill out your copyright notice in the Description page of Project Settings.
#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay()
{
	Super::BeginPlay();
	PrintLine(TEXT("Welcome to Bulls & Cows!"));
	PrintLine(TEXT("Press Enter to continue..."));
}

void UBullCowCartridge::OnInput(const FString& Input)
{
	ClearScreen();
	FString HiddenWord = TEXT("duck");
	PrintLine(Input);
}
