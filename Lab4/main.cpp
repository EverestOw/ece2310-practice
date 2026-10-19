#include "RPG.h"
#include "Game.h"
#include <iostream>

void printRPGobject(const RPG &RPG_object) {
    printf(
        "RPG Object at %p\n"
        "\tName:\t %s\n"
        "\tHits Taken:\t %i\n"
        "\tLuck:\t %f\n"
        "\tExp:\t %f\n"
        "\tLevel:\t %i\n",
        &RPG_object,
        RPG_object.getName().c_str(),
        RPG_object.getHitsTaken(),
        RPG_object.getLuck(),
        RPG_object.getExp(),
        RPG_object.getLevel()
    );
}

int main() {

    // Create game object
    Game gameInstance = Game();

    // Populate players into game object
    int numPlayers = 10;
    gameInstance.generatePlayers(numPlayers);

    // gameLoop
    gameInstance.gameLoop();

    // printFinalResults
    gameInstance.printFinalResults();

    return 0;
}