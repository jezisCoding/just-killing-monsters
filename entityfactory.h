#ifndef EntityFactory_H
#define EntityFactory_H

#include "monsterfearsome.h"
#include "hero.h"
#include "potion.h"
#include "environment.h"
#include "position.h"



/*!
 * \brief The EntityFactory class
 *      This class is used for returning standardized instances of Entities.
 */
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
