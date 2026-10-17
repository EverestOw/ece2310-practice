#include "RPG.h"
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

    // **Testing constructors, accessors
    printf("Testing constructors\n");
    RPG defaultPerson = RPG();
    printRPGobject(defaultPerson);

    std::cout << std::endl;

    RPG definedPerson = RPG("Named one", 1, 200.2, 3.3, 4);
    printRPGobject(definedPerson);

    std::cout << std::endl;

    // **Testing Mutators**
    // setName()
    defaultPerson.setName("Bad guy");

    // updateExpLevel()
    defaultPerson.updateExpLevel();
    definedPerson.updateExpLevel();

    // Event: Attack
    definedPerson.attack(&defaultPerson);
    definedPerson.printStats();
    std::cout << std::endl;
    defaultPerson.printStats();

    std::cout << "\n\nAttack round 2" << std::endl;
    defaultPerson.attack(&definedPerson);
    definedPerson.printStats();
    std::cout << std::endl;
    defaultPerson.printStats();

    return 0;
}