#ifndef POTION_H
#define POTION_H

#include "interactiveentity.h"
#include "creature.h"

class Potion : public InteractiveEntity
{
private:
    int healthBonus;
public:
    Potion(int healthBonus, std::string mapSign);
    ~Potion();
    int getHealthBonus();
    int interaction(Creature* with);
};

#endif // POTION_H
