#ifndef CHARMANDER_H
#define CHARMANDER_H

#include "Pokemon.h"

class Charmander : Pokemon {
    public:
        Charmander();
        Charmander( std::string name, int hp, int att, int def,
                    std::vector<std::string> skills);

    private:
        void speak();
        void printStats();
};


#endif