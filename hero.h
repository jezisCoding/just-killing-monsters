#ifndef HERO_H
#define HERO_H

#include "creature.h"
#include "position.h"

class Hero : public Creature
{
private:
    int readiness;
    bool surpriseHit;
    Position *position;
public:
    Hero(std::string mapSign, std::string name, int health, int attack, int readiness, bool surpriseHit,
         Position *position);
    ~Hero();
    int getAttack() ;
    Position *getPosition();
    void setPosition(Position *position);
    void resetSurpriseHit();
    //int interaction(Creature *with);
};

#endif // HERO_H
