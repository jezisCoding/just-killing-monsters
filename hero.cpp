#include "hero.h"

Hero::Hero(Position *position, std::__cxx11::string mapSign, std::string name, int health, int attack, int readiness,
           bool surpriseHit) : Creature(position, name, mapSign, health, attack)
{
    this->readiness = readiness;
    this->surpriseHit = surpriseHit;
}

Hero::~Hero(){
    std::cout << name + " is rip, git gud" << std::endl;
}

int Hero::getAttack() {
    if (surpriseHit) {
        surpriseHit = false;
        return attack+readiness;
    }
    return attack;
}

void Hero::resetSurpriseHit(){
    surpriseHit = true;
}


