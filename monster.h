#ifndef MONSTER_H
#define MONSTER_H

#include "creature.h"

class Monster : public Creature
{
private:
    static int monsterCount;
public:
    Monster(Position* position, std::string mapSign, std::string name, int health, int attack);
    virtual ~Monster();

    static int getMonsterCount();

    bool operator==(const Monster &right);
};

#endif // MONSTER_H
