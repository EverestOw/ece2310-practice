/*
*   Add header info
*/

/*
*   @brief returns whether x is greater than y
*   
*   @param x : (double)
*   @param y : (int)
*   @return true: x is greater than y
*/
#include <fstream>
#include <iostream>

void readFile(std::string fileName) {
    /*
        reads file
    */
    //  Open file
    std::ifstream inputFile(fileName);

    //  Check if file is valid
    if (!inputFile.is_open()) { 
        std::cerr << "Error opening: " << fileName << "\n";
        return;
     }

    std::string line;
    while(std::getline(inputFile,line)) {

    } 


}

int main() {
        std::ifstream inputFile("fileInput.csv");

        if (!inputFile.is_open()) { return 1; }

    return 0;
}