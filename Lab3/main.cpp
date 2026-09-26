#include "RPG.h"
#include <iostream>

void printRPGobject(const RPG &RPG_object) {
    printf(
        "RPG Object at 0x%X\n"
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

    RPG definedPerson = RPG("Named one", 1, 2.2, 3.3, 4);
    printRPGobject(definedPerson);

    std::cout << std::endl;

    // **Testing Mutators**
    // Event: test dummy takes 1 damage
    printf(
        "Testing Mutators:\n"
        "\t%s failed their constitution roll. %s takes 1 damage!\n",
        definedPerson.getName().c_str(),
        definedPerson.getName().c_str()
        );
    definedPerson.setHitsTaken(definedPerson.getHitsTaken() + 1);

    printf(
        "\t%s is %s with %i hits taken.\n",
        definedPerson.getName().c_str(),
        definedPerson.isAlive() ? "alive" : "done for",
        definedPerson.getHitsTaken()
    );

    std::cout << std::endl;

    // Event: test dummy takes 2 damage
    printf("\t%s slipped! %s takes 2 damage!\n",
        definedPerson.getName().c_str(),
        definedPerson.getName().c_str()
    );

    definedPerson.setHitsTaken(definedPerson.getHitsTaken() + 2);

    printf(
        "\t%s is %s with %i hits taken.\n",
        definedPerson.getName().c_str(),
        definedPerson.isAlive() ? "alive" : "a goner",
        definedPerson.getHitsTaken()
    );

    return 0;
}