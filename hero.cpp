#include "hero.h"

Hero::Hero(Position *position, std::__cxx11::string mapSign, std::string name, int health, int attack, int readiness,
           bool surpriseHit) : Creature(position, mapSign, name, health, attack)
{
    this->readiness = readiness;
    this->surpriseAttack = surpriseHit;
}

Hero::~Hero(){
    std::cout << name + " is dead, git gud" << std::endl;
}

uint8_t Hero::fight(Creature *who){
    who->dealDmg(this, who->getAttack());
    dealDmg(who, getAttack());
    std::cout << std::endl;

    uint8_t outcome = 0;    //bitwise
    if (who->getHealth() < 1) outcome |= 1;
    if (this->getHealth() < 1) outcome |= 2;
    return outcome;
}

void Hero::dealDmg(Creature *to, const int& dmgDealt){
    surpriseAttack = false;

    std::cout << this->getName() << " attacks " + to->getName() + "(" << to->getHealth() << "->";
    to->setHealth(to->getHealth() - dmgDealt);
    std::cout << to->getHealth() << ")" << std::endl;
}

int Hero::getAttack() const{
    if (surpriseAttack) return attack+readiness;
    return attack;
}

void Hero::resetSurpriseHit(){
    surpriseAttack = true;
}


