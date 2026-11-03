#include "Charmander.h"
#include <iostream>

// Constructors
Charmander::Charmander() : Pokemon() {
    type.push_back("Fire");
    skills.push_back("Growl");
    skills.push_back("Scratch");

    std::cout << "Log: Default Constructor of Class Charmander\n";
} 

Charmander::Charmander(std::string name, int hp, int att, int def,
                   std::vector<std::string> type,
                   std::vector<std::string> skills)
    : Pokemon(name, hp, att, def, type), skills(skills) {
    std::cout << "Log: Overloaded Constructor of Class Charmander\n";
    }



// Utility
void Charmander::speak() {
    std::cout << "Char!";
}

void Charmander::printStats() {
    Pokemon::printStats();

    // Print Charmander class specific member variables
    std::string skillsStr;
    for (std::string skill : skills) { skillsStr += skill; }

    std::cout << "\tSkills: " << skillsStr << '\n';
}