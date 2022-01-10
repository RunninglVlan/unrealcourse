#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay()
{
    Super::BeginPlay();
    PrintLine(TEXT("Welcome to Bulls & Cows!"));
    NewWord();
    PrintLine(TEXT("Input your word and press Enter..."));
}

void UBullCowCartridge::NewWord()
{
    HiddenWord = TEXT("duck");
    Lives = HiddenWord.Len();
    PrintLine(FString::Printf(TEXT("Guess the %d letter word, you have %d lives"), Lives, Lives));
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
        PrintLine(TEXT("The word was " + HiddenWord + ". To the next one!"));
        NewWord();
    }
    else
    {
        PrintLine(TEXT("Unfortunately you're wrong"));
        CountBullsAndCows(Input);
        if (--Lives > 0)
        {
            PrintLine(FString::Printf(TEXT("You got %d lives. Try again."), Lives));
        }
        else
        {
            PrintLine(TEXT("You're out of lives. Try with a new word."));
            NewWord();
        }
    }
}

void UBullCowCartridge::CountBullsAndCows(const FString& Input)
{
    int32 Bulls = 0, Cows = 0;
    for (int32 Index = 0; Index < Input.Len(); Index++)
    {
        const TCHAR Letter = Input[Index];
        if (Letter == HiddenWord[Index])
        {
            Bulls += 1;
        }
        int32 _;
        if (HiddenWord.FindChar(Letter, _))
        {
            Cows += 1;
        }
    }
    PrintLine(FString::Printf(TEXT("Your guess has %d Bulls and %d Cows"), Bulls, Cows));
}
