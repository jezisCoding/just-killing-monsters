#ifndef FEARSOMEMONSTER_H
#define FEARSOMEMONSTER_H

#include "monster.h"

class MonsterFearsome : public Monster
{
protected:
    float fearsomeness;
public:
    MonsterFearsome(Position* position, std::string mapSign, std::string name, int health, int attack, float fearsomeness);
    MonsterFearsome(MonsterFearsome& from);
    ~MonsterFearsome();

    uint8_t defendYourselfFrom(Creature *who) override;

    int getAttack() const;
    int getFearsomeness() const;
    bool monsterSplit() const;
};

#endif // FEARSOMEMONSTER_H
