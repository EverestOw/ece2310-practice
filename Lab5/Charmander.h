#ifndef CHARMANDER_H
#define CHARMANDER_H

#include "Pokemon.h"

class Charmander : Pokemon {
    public:
        // Constructors
        Charmander();
        Charmander( std::string name, int hp, int att, int def,
                    std::vector<std::string> skills);

        // Utility
        void speak();
        void printStats();

    private:
        std::vector<std::string> skills;
};


#endif