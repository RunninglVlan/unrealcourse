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
    const FString HiddenWords[8] = {
        TEXT("car"), TEXT("row"),
        TEXT("duck"), TEXT("game"),
        TEXT("chair"), TEXT("table"),
        TEXT("flower"), TEXT("change")
    };
    FString HiddenWord;
    int32 Lives;
    bool bGameOver;
    void NewWord();
    bool Validate(const FString& Guess) const;
    void ProcessGuess(const FString& Word);
    void CountBullsAndCows(const FString& Word) const;
    void AskForANewWord();
};
