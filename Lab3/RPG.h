#ifndef RPG_H
#define RPG_H

#include <string>

const int INVENTORY_SIZE = 10;
const float HIT_FACTOR = 0.05;
const int MAX_HITS_TAKEN = 3;

//  RPG Class
class RPG {
    public:
        // Constructors
        RPG();
        RPG(std::string, int hits_taken, float luck, float exp, int level);

        // Destructor
        // Implicitly defined

        // Accessors Functions
        std::string getName() const;
        int getHitsTaken() const;
        float getLuck() const;
        float getExp() const;
        int getLevel() const;

        // Mutator Functions
        void setHitsTaken(int new_hits);
        void setSkills();

        // Utility Functions
        void printAction();

    private:
        std::string name;
        int hits_taken;
        float luck;
        float exp;
        int level;
};

#endif