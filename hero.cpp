#include "hero.h"

Hero::Hero(std::__cxx11::string mapSign, std::string name, int health, int attack, int readiness,
           bool surpriseHit, Position *position) : Creature(name, mapSign, health, attack)
{
    this->readiness = readiness;
    this->surpriseHit = surpriseHit;
    this->position = position;
}

Hero::~Hero(){
    std::cout << name + " is rip, git gud" << std::endl;
}

Position *Hero::getPosition(){
    return position;
}

void Hero::setPosition(Position *position){
    this->position = position;
}

void Hero::resetSurpriseHit(){
    surpriseHit = true;
}

int Hero::getAttack() {
    if (surpriseHit) {
        surpriseHit = false;
        return attack+readiness;
    }
    return attack;
}
