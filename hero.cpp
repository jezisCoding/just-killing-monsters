#include "hero.h"

Hero::Hero(int readiness, bool surpriseHit, Position *position,
           int health, int attack, std::__cxx11::string mapSign)
            : Creature(health, attack, mapSign)
{
    this->readiness = readiness;
    this->surpriseHit = surpriseHit;
    this->position = position;
}

Position* Hero::getPosition(){
    return position;
}

void Hero::setPosition(Position* position){
    this->position = position;
}
