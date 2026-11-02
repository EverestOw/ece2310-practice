#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include <vector>

class Pokemon {
    public:
        // Constructors
        Pokemon();
        Pokemon(std::string name, int hp, int att, int def,
                std::vector<std::string> type);
        
        // Utility Functions
        void speak();
        void printStats();

    protected:
        std::string name;
        int hp;
        int attack;
        int defense;
        std::vector<std::string> type;
};

#endif