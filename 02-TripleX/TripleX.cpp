#define FMT_HEADER_ONLY

#include <iostream>
#include "fmt/format.h"

int main()
{
    std::cout << "You are a secret agent breaking into a secure server room..." << std::endl;
    std::cout << "Enter the correct code in the form of `X X X` (where X is a number) to continue..." << std::endl;

    const int CodeA = 2, CodeB = 3, CodeC = 4;
    const int CodeSum = CodeA + CodeB + CodeC;
    const int CodeProduct = CodeA * CodeB * CodeC;
    std::cout << "+ There are 3 numbers in the code" << std::endl;
    std::cout << fmt::format("+ The codes add-up to: {}", CodeSum) << std::endl;
    std::cout << fmt::format("+ The codes multiply to give: {}", CodeProduct) << std::endl;

    int GuessA, GuessB, GuessC;
    std::cout << "Your guess: ";
    std::cin >> GuessA >> GuessB >> GuessC;
    const int GuessSum = GuessA + GuessB + GuessC;
    const int GuessProduct = GuessA * GuessB * GuessC;

    return 0;
}
