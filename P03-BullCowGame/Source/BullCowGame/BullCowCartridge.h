#pragma once

#include "CoreMinimal.h"
#include "Console/Cartridge.h"
#include "BullCowCartridge.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class BULLCOWGAME_API UBullCowCartridge : public UCartridge
{
    GENERATED_BODY()

public:
    virtual void BeginPlay() override;
    virtual void OnInput(const FString& Input) override;

private:
    TArray<FString> Words;
    FString HiddenWord;
    int32 Lives;
    bool bGameOver;
    void NewWord();
    bool Validate(const FString& Guess) const;
    void ProcessGuess(const FString& Word);
    void CountBullsAndCows(const FString& Word) const;
    void AskForANewWord();
};
