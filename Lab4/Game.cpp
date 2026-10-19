#include "Game.h"
#include <random>

// Constructors, Deconstructors
Game::Game()
    : players(), live_players() {}

Game::~Game() {
    // TODO: dereference pointers, delete data structures
    for (RPG* iter : players)
    {
        delete iter;
        iter = nullptr;
    }
}

void Game::generatePlayers(int num) {
    // generates players
    // adds RPG object on the heap to players vector
    // add rpg object to map
    for (int i = 0; i < num; ++i)
    {
        RPG* ptrPlayer = new RPG();
        ptrPlayer->setName("NPC_" + std::to_string(i));

        players.push_back(ptrPlayer);
        live_players.insert(i);
    }
}

/*
* @brief returns a the index of a randomly chosen player
* @return index
*/
int Game::selectPlayer() {

    std::random_device rd;
    std::mt19937 gen(rd());

    std::uniform_int_distribution distribution(size_t(0), live_players.size() - 1);

    int randomIndex = distribution(gen);

    std::set<int>::iterator iter = live_players.begin();
    std::advance(iter, randomIndex);

    return *iter;
}

void Game::endRound(RPG* winner, RPG* loser, int loserIndex) {
    winner->setHitsTaken(0);
    winner->updateExpLevel();

    live_players.erase(loserIndex);

    printf("%s won against %s", winner->getName().c_str(), loser->getName().c_str());
}

void Game::battleRound() {
    // Defensive programming: if theres only one or less players remaining, battleRound() will loop forever.
    // TODO: log error message
    if (live_players.size() < 2) { return; }


    // Select two players
    int playerIndex1 = selectPlayer();
    int playerIndex2;

    do {
        playerIndex2 = selectPlayer();
    } while (playerIndex2 == playerIndex1);

    // Combat
    RPG* player1 = players[playerIndex1];
    RPG* player2 = players[playerIndex2];

    while(player1->isAlive() && player2->isAlive()) {

        // Note this logic is player1 favored. Reminder: player1 is randomly decided
        // It is not possible for both players to die in a battleround.
        player1->attack(player2);

        if (player2->isAlive()) { player2->attack(player1); }

    }

    if (player1->isAlive())
    {
        endRound(player1, player2, playerIndex2);
    }
    else //player2 is alive
    {
        endRound(player2, player1, playerIndex1);
    }

    printf("\n");
};

void Game::gameLoop() {
    while (live_players.size() > 1)
    {
        battleRound();
    }
};

void Game::printFinalResults() {
    for (RPG* player : players) {
        player->printStats();
        printf("\n");
    }
};