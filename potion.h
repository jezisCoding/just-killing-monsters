#ifndef POTION_H
#define POTION_H

#include "entity.h"

class Potion : public Entity
{
private:
    int healthBonus;
public:
    Potion(Position* position, std::string mapSign, int healthBonus);
    ~Potion();

    int reaction(Creature &to);

    int getHealthBonus();
};

#endif // POTION_H
