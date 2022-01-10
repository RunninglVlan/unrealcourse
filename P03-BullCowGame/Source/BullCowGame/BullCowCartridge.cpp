#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay()
{
    Super::BeginPlay();
    PrintLine(TEXT("Welcome to Bulls & Cows!"));
    NewWord();
}

void UBullCowCartridge::NewWord()
{
    HiddenWord = TEXT("duck");
    PrintLine(FString::Printf(TEXT("Guess the %d letter word and press Enter..."), HiddenWord.Len()));
}

void UBullCowCartridge::OnInput(const FString& Input)
{
    ClearScreen();
    if (Input.Len() != HiddenWord.Len())
    {
        PrintLine(FString::Printf(TEXT("The word has %d letters, not %d. Try again."), HiddenWord.Len(), Input.Len()));
        return;
    }

    if (Input.Equals(HiddenWord, ESearchCase::Type::IgnoreCase))
    {
        PrintLine(TEXT("Yes, you guessed right!"));
        PrintLine(TEXT("The word is " + HiddenWord));
    }
    else
    {
        PrintLine(TEXT("Unfortunately you're wrong. Try again."));
    }
}
