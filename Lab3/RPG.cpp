#include "RPG.h"

// Constructors
/*
* @brief Default constructor for RPG object. Object will initialize as a generic NPC.
* 
* @return RPG object with default NPC attributes
**/
RPG::RPG() {
    name = "NPC";
    hits_taken = 0;
    luck = 0.1;
    exp = 50.0;
    level = 1;
}

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
RPG::RPG(std::string name, int hits_taken, float luck, float exp, int level) {
    this->name = name;
    this->hits_taken = hits_taken;
    this->luck = luck;
    this->exp = exp;
    this->level = level;
}


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
    return this->hits_taken >= MAX_HITS_TAKEN;
}