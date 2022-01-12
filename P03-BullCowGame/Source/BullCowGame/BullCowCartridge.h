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
    TArray<FString> Isograms;
    FString HiddenWord;
    int32 Lives;
    bool bGameOver;
    TArray<FString> LoadIsograms() const;
    void NewWord();
    bool Validate(const FString& Guess) const;
    static bool IsIsogram(const FString& Word, TCHAR* RepeatedLetter = nullptr);
    void ProcessGuess(const FString& Word);
    void CountBullsAndCows(const FString& Word, int32& Bulls, int32& Cows) const;
    void AskForANewWord();
};
