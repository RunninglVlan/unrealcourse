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
    PrintLine(TEXT("Guess the %d letter word, you have %d lives"), Lives, Lives);
    bGameOver = false;
}

void UBullCowCartridge::OnInput(const FString& Input)
{
    if (bGameOver)
    {
        ClearScreen();
        NewWord();
        return;
    }

    if (!Validate(Input))
    {
        return;
    }

    if (Input.Equals(HiddenWord, ESearchCase::Type::IgnoreCase))
    {
        PrintLine(TEXT("Congratulations, you are right!"));
        AskForANewWord();
    }
    else
    {
        PrintLine(TEXT("Unfortunately you're wrong"));
        if (--Lives > 0)
        {
            CountBullsAndCows(Input);
            PrintLine(TEXT("You got %d more lives. Try again."), Lives);
        }
        else
        {
            PrintLine(TEXT("And out of lives."));
            PrintLine(TEXT("The word was %s."), *HiddenWord);
            PrintLine(TEXT("Better luck next time"));
            AskForANewWord();
        }
    }
}

bool UBullCowCartridge::Validate(const FString& Input) const
{
    if (Input.Len() != HiddenWord.Len())
    {
        PrintLine(TEXT("The word has %d letters, not %d. Try again."), HiddenWord.Len(), Input.Len());
        return false;
    }
    TSet<TCHAR> Unique;
    for (TCHAR Letter : Input)
    {
        bool IsAlreadyInSet;
        Unique.Add(Letter, &IsAlreadyInSet);
        if (IsAlreadyInSet)
        {
            PrintLine(TEXT("Your word isn't an isogram"));
            PrintLine(TEXT("%c is repeated. Try again."), Letter);
            return false;
        }
    }
    return true;
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
    PrintLine(TEXT("Your guess has %d Bulls and %d Cows"), Bulls, Cows);
}

void UBullCowCartridge::AskForANewWord()
{
    PrintLine(TEXT("Do you want to try a new word?"));
    PrintLine(TEXT("Press Enter to continue..."));
    bGameOver = true;
}
