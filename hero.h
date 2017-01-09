#ifndef HERO_H
#define HERO_H

#include "creature.h"

class Hero : public Creature
{
private:
    int readiness;
    bool surpriseAttack;
public:
    Hero(Position *position, std::string mapSign, std::string name, int health, int attack,
         int readiness, bool surpriseAttack);
    ~Hero();

    uint8_t defendYourselfFrom(Creature *who) override;
    void dealDmg(Creature *to, const int& dmgDealt);

    int getAttack() const;
    void resetSurpriseHit();
};

#endif // HERO_H
