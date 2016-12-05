#ifndef MONSTER_H
#define MONSTER_H

#include "creature.h"

class Monster : public Creature
{
private:
    int fearsomeness;
public:
    Monster(std::string mapSign, int health, int attack, int fearsomeness);
    int getFearsomeness();
    void dealDamage(int amount );
};

#endif // MONSTER_H
