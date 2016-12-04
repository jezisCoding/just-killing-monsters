#ifndef HERO_H
#define HERO_H

#include "creature.h"
#include "position.h"

class Hero : public Creature
{
private:
    int readiness;
    bool surpriseHit;
    Position* position;
public:
    Hero(int readiness, bool surpriseHit, Position *position, int health, int attack, std::string mapSign);
    ~Hero();
    int getAttack();
    int attack(InteractiveEntity target);
    Position* getPosition();
    void setPosition(Position* position);
    int interaction(InteractiveEntity *with);
};

#endif // HERO_H
