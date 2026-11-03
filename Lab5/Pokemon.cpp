#include "Pokemon.h"
#include <cstdio>

// Constructors
Pokemon::Pokemon()
    : name("unindentified"), hp(0), attack(0), defense(0)
    {
    printf("Log: Default Constructor of Class Pokemon\n");
    }

/*
* @brief Overloaded constructor for Pokemon
*/
Pokemon::Pokemon(std::string name, int hp, int attack, int defense,
                 std::vector<std::string> type)
                :name(name), hp(hp), attack(attack), defense(defense),
                 type(type)
                 {
    printf("Log: Overloaded Constructor of Class Pokemon\n");
}

// Utility
void Pokemon::speak() { 
    printf("...\n");
};

void Pokemon::printStats() {
    std::string typeStr;
    for (std::string type : type) { // note to self: disambiguate type name
        typeStr += type;
    }

    printf("Name: %s\t"
            "HP: %i\t"
            "Attack: %i\t"
            "Defense: %i\t"
            "Type: %s\n",
            name.c_str(), hp, attack, defense, typeStr.c_str()
        );
}