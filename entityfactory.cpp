#include "entityfactory.h"

EntityFactory::EntityFactory()
{

}

Monster* EntityFactory::getNewMonster(Position *pos, const bool& fearsome) const{
    if (fearsome) return new MonsterFearsome(pos, "W", "A scary ass splitting monster",
                                             MonsterFearsome::getMAX_HEALTH(), 15, 1.5);
            else return new Monster(pos, "M", "A not too scary monster",
                                    Creature::getMAX_HEALTH(), 15);
}

Hero* EntityFactory::getNewHero(Position *pos) const{
    return new Hero(pos, "H", "The hero", Hero::getMAX_HEALTH(), 20, 15, true);
}

Potion* EntityFactory::getNewPotion(Position *pos) const{
    return new Potion(pos, "P", 50);
}

Environment* EntityFactory::getNewEnvironment(Position *pos, const Environment::fieldType &type) const{
    switch (type) {
    case Environment::Empty:
        return new Environment(pos, ".", Environment::Empty);
        break;
    case Environment::Corpse:
        return new Environment(pos, "X", Environment::Corpse);
        break;
    case Environment::Tree:
        return new Environment(pos, "T", Environment::Tree);
        break;
    case Environment::Rock:
        return new Environment(pos, "O", Environment::Rock);
        break;
    default:
        return 0; //nullptr
        break;
    }
}
