#ifndef CREATURE_H
#define CREATURE_H

#include "interactiveentity.h"

class Creature : public InteractiveEntity
{
protected:
    int health;
    int attack;
public:
    Creature(std::string mapSign, int health, int attack);
    int getAttack() const;
    int getHealth() const;
    void setHealth(int toValue);
    int interaction(InteractiveEntity *with);
    int interaction(Creature *with);
};

#endif // CREATURE_H
