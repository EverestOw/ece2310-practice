#ifndef RPG_H
#define RPG_H

#include <string>

//  RPG Class
class RPG {
    public:
    // Getter Functions
    std::string getName();
    int getHealth();
    int getStrength();
    int getDefense();

    // Setter Functions
    void setSkills();

    // Utility functions
    void printAction();
};

#endif