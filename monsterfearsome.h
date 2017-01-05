#ifndef FEARSOMEMONSTER_H
#define FEARSOMEMONSTER_H

#include "monster.h"

class MonsterFearsome : public Monster
{
protected:
    float fearsomeness;
public:
    MonsterFearsome(Position* position, std::string mapSign, std::string name, int health, int attack, float fearsomeness);
    MonsterFearsome(const MonsterFearsome &from);
    ~MonsterFearsome();

    int defendYourselfFrom(Creature &who);

    int getAttack() const;
    int getFearsomeness() const;
};

#endif // FEARSOMEMONSTER_H
