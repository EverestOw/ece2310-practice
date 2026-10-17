#include "RPG.h"
#include <random>

// Constructors
/*
* @brief Default constructor for RPG object. Object will initialize as a generic NPC.
* 
* @return RPG object with default NPC attributes
**/
RPG::RPG(): name("NPC"), hits_taken(0), luck(0.1), exp(50.0), level(1) {}

/*
* @brief Parameterized constructor for RPG object
* @param name
* @param hits_taken the initial number of hits the object has taken
* @param luck
* @param exp
* @param level
*
* @returns 
*/
RPG::RPG(std::string name, int hits_taken, float luck, float exp, int level)
    : name(name), hits_taken(hits_taken), luck(luck), exp(exp), level(level) {}


// Accessors
/*
* @brief returns the name of the object
* @return string
*/
std::string RPG::getName() const {
    return name;
}

/*
* @brief returns the level attribute
* @return int
*/
int RPG::getHitsTaken() const {
    return hits_taken;
}

/*
* @brief returns the luck attribute
* @return float
*/
float RPG::getLuck() const {
    return luck;
}

/*
* @brief returns the Exp attribute
* @return float
*/
float RPG::getExp() const {
    return exp;
}

/*
* @brief returns the level attribute
* @return int
*/
int RPG::getLevel() const {
    return level;
}


// Mutator
/*
* @brief sets the hits_taken member variable to new_hits
* @param new_hits: int
*/
void RPG::setHitsTaken(int new_hits) {
    this->hits_taken = new_hits;
}

/*
* @brief returns whether hits_taken is less than MAX_HITS_TAKEN
* A player is alive as long as they have not been MAX_HITS_TAKEN times.
*
* @return true : player is alive
* @return false : player is dead
*/
bool RPG::isAlive() const {
    return this->hits_taken < MAX_HITS_TAKEN;
}

void RPG::setName(std::string name) { this->name = name; }

/*
* @brief increases RPG exp attribute by +50.
*   If RPG exp passes a threshhold, increase level by 1, reset experience to 0,
*   and increase luck by +0.1
*/
void RPG::updateExpLevel() {

    const float EXP_THRESHOLD = 100.0;
    const float EXP_GAIN = 50.0;
    exp += EXP_GAIN;

    const float LUCK_GAIN = 0.1;
    if (exp >= EXP_THRESHOLD) {
        luck += LUCK_GAIN;
        ++level;

        exp = 0.0;
    }

}

void RPG::attack(RPG* const opponent) {

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<double> distribution(0.0, 1.0);

    float roll = distribution(gen);

    // attack sequence
    if (roll > HIT_FACTOR * opponent->luck) {
        opponent->setHitsTaken(opponent->getHitsTaken() + 1);
    }


}

/*
* @brief prints out the name, hits taken, luck, exp, level
*   attributes of the RPG object into a single line.
*/
void RPG::printStats() {
    printf(
        "RPG Object at %p\n"
        "\tName: %s\t"
        "\tHits Taken: %i\t"
        "\tLuck: %.2f\t"
        "\tExp: %f\t"
        "\tLevel: %i\t",
        this,
        name.c_str(),
        hits_taken,
        luck,
        exp,
        level
    );
}