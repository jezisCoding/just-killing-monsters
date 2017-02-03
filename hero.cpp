#include "hero.h"

Hero::Hero(Position* pos, char mapSign, std::string name, int health, int attack, int readiness,
           bool surpriseHit) : Creature(mapSign, name, health, attack)
{
    this->pos = pos;
    this->readiness = readiness;
    this->surpriseAttack = surpriseHit;
}

Hero::~Hero(){

}

uint8_t Hero::defendYourselfFrom(FieldActor *who){
    Creature* attacker = dynamic_cast<Creature*>(who);

    attacker->dealDmg(this, attacker->getAttack());
    dealDmg(attacker, getAttack());
    std::cout << std::endl;

    uint8_t outcome = 0;    //bitwise
    if (attacker->getHealth() < 1) outcome |= 1;
    if (this->getHealth() < 1) outcome |= 2;
    return outcome;
}

void Hero::dealDmg(Creature *to, const int& dmgDealt){
    surpriseAttack = false;

    std::cout << this->getName() << " attacks " + to->getName() + "(" << to->getHealth() << "->";
    to->setHealth(to->getHealth() - dmgDealt);
    std::cout << to->getHealth() << ")" << std::endl;
}

void Hero::die()
{
    std::cout << name + " is dead, git gud" << std::endl;
}

int Hero::getAttack() const{
    if (surpriseAttack) return attack+readiness;
    return attack;
}

void Hero::resetSurpriseHit(){
    surpriseAttack = true;
}

Position *Hero::getPosition()
{
    return pos;
}

void Hero::setPosition(Position *to)
{
    pos = to;
}


