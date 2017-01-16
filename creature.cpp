#include "creature.h"

Creature::Creature(Position *position, std::__cxx11::string mapSign, std::string name, int health, int attack)
    : Entity(position, mapSign)
{
    this->name = name;
    this->health = health;
    this->attack = attack;
}

Creature::Creature(const Creature& orig) : Entity(orig)
{
    this->name = orig.name;
    this->health = orig.health;
    this->attack = orig.attack;
}

Creature::~Creature()
{
    //std::cout << "A creature just died." << std::endl;
}

int Creature::interaction(Entity *with){
    return with->reaction(this);
}

int Creature::reaction(Creature *to){
    return defendYourselfFrom(to);
}

    /* attack and self defense when attacked
     *
     * bitwise return values: death of:
     * 0-nobody * 1-the other creature(who/attacker/hero) * 2-this creature(this/defender/monster) * 3-both creatures
     */
uint8_t Creature::defendYourselfFrom(Creature *who){
    who->dealDmg(this, who->getAttack());
    dealDmg(who, getAttack());
    std::cout << std::endl;

    uint8_t outcome = 0;    //bitwise
    if (who->getHealth() < 1) outcome |= 1;
    if (this->getHealth() < 1) outcome |= 2;
    return outcome;
}

void Creature::dealDmg(Creature *to, const int& dmgDealt){
    std::cout << this->getName() << " attacks " + to->getName() + "(" << to->getHealth() << "->";
    to->setHealth(to->getHealth() - dmgDealt);
    std::cout << to->getHealth() << ")" << std::endl;
}

std::string Creature::getName() const{
    return name;
}

int Creature::getAttack() const{
    return attack;
}

int Creature::getHealth() const{
    return health;
}

int Creature::getMAX_HEALTH(){
    return MAX_HEALTH;
}

void Creature::setHealth(const int &toValue){
    this->health = toValue;
}

bool Creature::operator== (const Creature& right){
    if (this->getName()==right.getName() && this->getHealth()==right.getHealth()) return true;
    return false;
}
