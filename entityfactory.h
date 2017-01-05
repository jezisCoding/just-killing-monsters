#ifndef EntityFactory_H
#define EntityFactory_H

#include "fearsomemonster.h"
#include "hero.h"
#include "potion.h"
#include "environment.h"
#include "position.h"

class EntityFactory
{
public:
    EntityFactory();
    Monster* getNewMonster(bool fearsome);
    Hero* getNewHero(Position* heroPos);
    Potion* getNewPotion();
    Environment* getNewEnvironment(Environment::fieldType type);
};

#endif // EntityFactory_H
