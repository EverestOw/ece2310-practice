#ifndef GAME_H
#define GAME_H

#include <vector>
#include <set>
#include "RPG.h"

class Game {
    public: 
        Game() {}

        ~Game() {}
        // Mutators
        void generatePlayers(int num);
        int selectPlayer();

        void endRound(RPG* winner, RPG* loser, int loserIndex);

        void battleRound();

        void gameLoop();

        void printFinalResults();

    private:
        std::vector<RPG*> players;
        std::set<int> live_players;
};

#endif