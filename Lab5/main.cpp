#include "Charmander.h"
#include <iostream>

/*
* @brief prints a fancy header line. Input with too many characters truncated
         followed by an ellipses (...)
* @input header
*/
void printHeaderLines(const std::string& header);

int main() {

    //-----Testing Suite-----///
    // Test Constructor
    // Initialize Charmander object
    printHeaderLines("Constructor Created");

    std::vector<std::string> type = {"Fire"};
    std::vector<std::string> skills = {"Growl","Scratch"};

    Charmander charmeleonJr = Charmander("Charmeleon Jr.", 39, 52, 43,
                                         type, skills);

    std::cout << std::endl;

    // Class accessibility test - speak()
    printHeaderLines("Direct Speak");
    charmeleonJr.speak();
    std::cout << std::endl;

    std::cout << std::endl;

    // Pointer test - Dynamic vs. static binding

    Pokemon* pokemonPtr = &charmeleonJr;
    Charmander* charmanderPtr = &charmeleonJr;

    printHeaderLines("virtual speak() from Pokemon pointer");
    std::cout << "Pokemon::speak(): ";
    pokemonPtr->speak();
    std::cout << std::endl;

    printHeaderLines("speak() from Charmander pointer");
    std::cout << "Charmander::speak(): ";
    charmanderPtr->speak();
    std::cout << std::endl;

    std::cout << std::endl;

    // printStats()
    printHeaderLines("Print Stats");
    charmeleonJr.printStats();

    return 0;
}

// Lots of edge cases not considered in this function
void printHeaderLines(const std::string& header) {
    constexpr char LINE_STYLE = '-';
    constexpr char MAX_HEADER_LENGTH = 64;
    constexpr char MIN_PADDING_LENGTH = 4;

    const size_t INPUT_LENGTH = header.size();

    std::string result;

    // Lambda function (Note: Compatible with C++11 and onwards)
    auto padString = [](std::string input, size_t numLeftPadding, size_t numRightPadding) {
        std::string result;
        
        for (size_t i = 0; i < numLeftPadding; ++i) { result += LINE_STYLE; }
        result += ' ' + input + ' ';
        for (size_t i = 0; i < numRightPadding; ++i) {result += LINE_STYLE; }
        
        return result;
    };

    if (INPUT_LENGTH <= MAX_HEADER_LENGTH) {
        // Cases: header has even or odd amount of characters
        const size_t LENGTH_DIFFERENCE = (MAX_HEADER_LENGTH - INPUT_LENGTH) / 2;
        bool isOdd = INPUT_LENGTH % 2;

        size_t leftPadding = LENGTH_DIFFERENCE;
        size_t rightPadding = isOdd ? LENGTH_DIFFERENCE + 1
                                    : LENGTH_DIFFERENCE;

        result = padString(header, leftPadding, rightPadding);
    }

    else { // INPUT_LENGTH > MAX_HEADER_LENGTH
           // Case: Header exceeds max length
        const std::string ELLIPSES = "...";
        size_t endIndex = MAX_HEADER_LENGTH 
                                  - (2 * MIN_PADDING_LENGTH)
                                  - ELLIPSES.size();

        std::string truncatedHeader = std::string(header, 0, endIndex) + ELLIPSES;
        
        result = padString(truncatedHeader, MIN_PADDING_LENGTH, MIN_PADDING_LENGTH);
    }

    std::cout << result << std::endl;
}