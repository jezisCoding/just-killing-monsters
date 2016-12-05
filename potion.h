#ifndef POTION_H
#define POTION_H

#include "interactiveentity.h"
#include "creature.h"

class Potion : public InteractiveEntity
{
private:
    int healthBonus;
public:
    Potion(std::string mapSign, int healthBonus);
    ~Potion();
    int getHealthBonus();
    int interaction(Creature *with);
};

#endif // POTION_H
