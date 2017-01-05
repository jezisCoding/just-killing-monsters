#include "entityfactory.h"

EntityFactory::EntityFactory()
{

}

Monster* EntityFactory::getNewMonster(bool fearsome){
    if (fearsome) return new FearsomeMonster("A scarier monster", "N", 100, 15, 1.5);
            else return new Monster("A not too scary monster", "M", 100, 15);
}

Hero* EntityFactory::getNewHero(Position *heroPos){
    return new Hero("The hero", "H", 100, 20, 15, true, heroPos);
}

Potion* EntityFactory::getNewPotion(){
    return new Potion("P", 50);
}

Environment* EntityFactory::getNewEnvironment(Environment::fieldType type){
    switch (type) {
    case Environment::Empty:
        return new Environment(".", Environment::Empty);
        break;
    case Environment::Corpse:
        return new Environment("X", Environment::Corpse);
        break;
    case Environment::Tree:
        return new Environment("T", Environment::Tree);
        break;
    case Environment::Rock:
        return new Environment("O", Environment::Rock);
        break;
    default:
        return 0; //nullptr
        break;
    }
}
