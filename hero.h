#ifndef HERO_H
#define HERO_H

#include "creature.h"

class Hero : public Creature
{
private:
    int readiness;
    bool surpriseHit;
public:
    Hero(Position *position, std::string mapSign, std::string name, int health, int attack,
         int readiness, bool surpriseHit);
    ~Hero();

    int getAttack();
    void resetSurpriseHit();
};

#endif // HERO_H
