#define FMT_HEADER_ONLY

#include <iostream>
#include <time.h>
#include "fmt/format.h"

void Init()
{
    srand(time(NULL));
}

void PrintIntro()
{
    std::cout << "You are a secret agent breaking into a secure server room..." << std::endl;
    std::cout << "Enter the correct code in the form of `X X X` (where X is a number) to continue..." << std::endl;
}

int RandomInt(int Difficulty)
{
    const int Max = 3 * Difficulty;
    return rand() % Max + 1;
}

bool PlayLevel(int Difficulty)
{
    const int CodeA = RandomInt(Difficulty), CodeB = RandomInt(Difficulty), CodeC = RandomInt(Difficulty);
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;
    std::cout << "+ There are 3 numbers in the code" << std::endl;
    std::cout << fmt::format("+ The codes add-up to: {}", CodeSum) << std::endl;
    std::cout << fmt::format("+ The codes multiply to give: {}", CodeProduct) << std::endl;

    int GuessA, GuessB, GuessC;
    std::cout << "Your guess: ";
    if (!(std::cin >> GuessA >> GuessB >> GuessC))
    {
        // clear error flags and buffer
        std::cin.clear();
        std::cin.ignore();
    }
    const int GuessSum = GuessA + GuessB + GuessC;
    const int GuessProduct = GuessA * GuessB * GuessC;

    return GuessSum == CodeSum && GuessProduct == CodeProduct;
}

int main()
{
    Init();
    PrintIntro();

    auto LevelDifficulty = 1;
    const auto MaxDifficulty = 3;
    while (LevelDifficulty <= MaxDifficulty)
    {
        const auto bCompleted = PlayLevel(LevelDifficulty);
        std::cout << fmt::format("You guessed {}. ", bCompleted ? "right" : "wrong");
        if (bCompleted)
        {
            LevelDifficulty++;
            if (LevelDifficulty < MaxDifficulty)
            {
                std::cout << "Great, but the door doesn't open yet, instead you need to enter a new code" << std::endl;
                std::cout << fmt::format("It says on the display that you're on level {} now", LevelDifficulty) << std::endl;
            }
        }
        else
        {
            std::cout << "Careful, agent! Try again!" << std::endl;
        }
        std::cout << std::endl;
    }
    std::cout << "Hooray, the door finally opens. Time to get that secret data and get out of here...";

    return 0;
}
