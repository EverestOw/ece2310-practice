#include "RPG.h"
#include <iostream>

void printRPGobject(const RPG &RPG_object) {
    printf(
        "definedPerson:\n"
        "\tName:\t %s\n"
        "\tHits Taken:\t %i\n"
        "\tLuck:\t %f\n"
        "\tExp:\t %f\n"
        "\tLevel:\t %i\n",
        RPG_object.getName().c_str(),
        RPG_object.getHitsTaken(),
        RPG_object.getLuck(),
        RPG_object.getExp(),
        RPG_object.getLevel()
    );
}

int main() {
    RPG defaultPerson = RPG();
    RPG definedPerson = RPG("Named one", 1, 2.2, 3.3, 4);

    // **Testing constructors, accessors
    // printRPGobject(defaultPerson);
    // std::cout << std::endl;
    // printRPGobject(definedPerson);

    // **Testing Mutators**
    printf("Alive? :\t %b",definedPerson.isAlive());

    return 0;
}