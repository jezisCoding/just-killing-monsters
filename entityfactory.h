#ifndef EntityFactory_H
#define EntityFactory_H

#include "monsterfearsome.h"
#include "hero.h"
#include "potion.h"
#include "environment.h"
#include "position.h"

class EntityFactory
{
public:
    EntityFactory();
    Monster* getNewMonster(Position *pos, const bool& fearsome) const;
    Hero* getNewHero(Position* pos) const;
    Potion* getNewPotion(Position *pos) const;
    Environment* getNewEnvironment(Position *pos, const Environment::fieldType& type) const;
};

#endif // EntityFactory_H
