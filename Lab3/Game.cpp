#include "Game.h"

// Constructors, Deconstructors
Game::Game()
    : players(), live_players() {}

Game::~Game() {
    // TODO: dereference pointers, delete data structures
    for (auto iter : players)
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
        //ptrPlayer->setName("NPC_" + to_string(i))
        players.push_back(ptrPlayer);
        live_players.insert(i);
    }
}

/*
* @brief returns a the index of a randomly chosen player
* @return index
*/
int selectPlayer() {
    return 0;
}

void Game::battleRound() {

};

void Game::gameLoop() {

};

void Game::printFinalResults() {

};