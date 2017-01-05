#ifndef FEARSOMEMONSTER_H
#define FEARSOMEMONSTER_H

#include "monster.h"

class FearsomeMonster : public Monster
{
protected:
    float fearsomeness;
public:
    FearsomeMonster(std::string mapSign, std::string name, int health, int attack, float fearsomeness);
    virtual ~FearsomeMonster();
    int getAttack();
    int getFearsomeness();
};

#endif // FEARSOMEMONSTER_H
