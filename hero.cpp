#include "hero.h"

Hero::Hero(std::__cxx11::string mapSign, int health, int attack, int readiness,
           bool surpriseHit, Position *position) : Creature(mapSign, health, attack)
{
    this->readiness = readiness;
    this->surpriseHit = surpriseHit;
    this->position = position;
}

Position *Hero::getPosition(){
    return position;
}

void Hero::setPosition(Position *position){
    this->position = position;
}

int Hero::interaction(InteractiveEntity *with){
    return with->interaction(this);
}
