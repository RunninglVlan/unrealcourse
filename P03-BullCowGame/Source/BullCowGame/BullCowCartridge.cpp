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
    if (!Validate(Input))
    {
        return;
    }

    if (Input.Equals(HiddenWord, ESearchCase::Type::IgnoreCase))
    {
        PrintLine(TEXT("Yes, you guessed right!"));
        PrintLine(FString::Printf(TEXT("The word was %s. To the next one!"), *HiddenWord));
        NewWord();
    }
    else
    {
        PrintLine(TEXT("Unfortunately you're wrong"));
        CountBullsAndCows(Input);
        if (--Lives > 0)
        {
            PrintLine(FString::Printf(TEXT("You got %d more lives. Try again."), Lives));
        }
        else
        {
            PrintLine(TEXT("You're out of lives."));
            PrintLine(FString::Printf(TEXT("The word was %s."), *HiddenWord));
            PrintLine(TEXT("Try one more time with a new word."));
            NewWord();
        }
    }
}

bool UBullCowCartridge::Validate(const FString& Input) const
{
    if (Input.Len() != HiddenWord.Len())
    {
        PrintLine(FString::Printf(TEXT("The word has %d letters, not %d. Try again."), HiddenWord.Len(), Input.Len()));
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
            PrintLine(FString::Printf(TEXT("%c is repeated. Try again."), Letter));
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
    PrintLine(FString::Printf(TEXT("Your guess has %d Bulls and %d Cows"), Bulls, Cows));
}
