#include "BullCowCartridge.h"

void UBullCowCartridge::BeginPlay()
{
    Super::BeginPlay();
    Isograms = LoadIsograms();
    PrintLine(TEXT("Welcome to Bulls & Cows!"));
    NewWord();
    PrintLine(TEXT("Input your word and press Enter..."));
}

TArray<FString> UBullCowCartridge::LoadIsograms() const
{
    const FString WordsPath = FPaths::ProjectContentDir() / TEXT("Words.txt");
    TArray<FString> ValidWords;
    FFileHelper::LoadFileToStringArrayWithPredicate(ValidWords, *WordsPath, [](const FString& Word)
    {
        const int32 Length = Word.Len();
        return Length >= 3 && Length <= 8 && IsIsogram(Word);
    });
    return ValidWords;
}

void UBullCowCartridge::NewWord()
{
    HiddenWord = Isograms[FMath::RandRange(0, Isograms.Num() - 1)];
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

    if (Validate(Input))
    {
        ProcessGuess(Input);
    }
}

bool UBullCowCartridge::Validate(const FString& Guess) const
{
    if (Guess.Len() != HiddenWord.Len())
    {
        PrintLine(TEXT("The word has %d letters, not %d. Try again."), HiddenWord.Len(), Guess.Len());
        return false;
    }

    TCHAR RepeatedLetter;
    if (!IsIsogram(Guess, &RepeatedLetter))
    {
        PrintLine(TEXT("Your word isn't an isogram"));
        PrintLine(TEXT("%c is repeated. Try again."), RepeatedLetter);
        return false;
    }
    return true;
}

bool UBullCowCartridge::IsIsogram(const FString& Word, TCHAR* RepeatedLetter)
{
    TSet<TCHAR> Unique;
    for (TCHAR Letter : Word)
    {
        bool IsAlreadyInSet;
        Unique.Add(Letter, &IsAlreadyInSet);
        if (IsAlreadyInSet)
        {
            if (RepeatedLetter)
            {
                *RepeatedLetter = Letter;
            }
            return false;
        }
    }
    return true;
}

void UBullCowCartridge::ProcessGuess(const FString& Word)
{
    if (Word.Equals(HiddenWord, ESearchCase::Type::IgnoreCase))
    {
        PrintLine(TEXT("Congratulations, you are right!"));
        AskForANewWord();
        return;
    }

    PrintLine(TEXT("Unfortunately you're wrong"));
    if (--Lives > 0)
    {
        const FBullsCowsCount Count = CountBullsAndCows(Word);
        PrintLine(TEXT("Your guess has %d Bulls and %d Cows"), Count.Bulls, Count.Cows);
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

FBullsCowsCount UBullCowCartridge::CountBullsAndCows(const FString& Word) const
{
    FBullsCowsCount Count;
    for (int32 Index = 0; Index < Word.Len(); Index++)
    {
        const TCHAR Letter = Word[Index];
        if (Letter == HiddenWord[Index])
        {
            Count.Bulls++;
            continue;
        }
        if (HiddenWord.GetCharArray().Contains(Letter))
        {
            Count.Cows++;
        }
    }
    return Count;
}

void UBullCowCartridge::AskForANewWord()
{
    PrintLine(TEXT("Do you want to try a new word?"));
    PrintLine(TEXT("Press Enter to continue..."));
    bGameOver = true;
}
