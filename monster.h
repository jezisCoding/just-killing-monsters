#ifndef MONSTER_H
#define MONSTER_H

#include "creature.h"

class Monster : public Creature
{
private:
    int fearsomeness;
public:
    Monster(int fearsomeness, int health, int attack, std::string mapSign);
    int getFearsomeness();
    void dealDamage(int amount );
};

#endif // MONSTER_H
