#include "creature.h"

Creature::Creature(std::__cxx11::string mapSign, std::string name, int health, int attack) : Entity(mapSign)
{
    this->name = name;
    this->health = health;
    this->attack = attack;
}

Creature::~Creature(){
    //std::cout << "A creature just died." << std::endl;
}

int Creature::getAttack(){
    return attack;
}

int Creature::getHealth() const{
    return health;
}

std::string Creature::getName() const{
    return name;
}

void Creature::setHealth(int toValue){
    this->health = toValue;
}

int Creature::reaction(Creature &to){
    return defendYourselfFrom(to);
}

int Creature::interaction(Entity *with){
    return with->reaction(*this);
}

    /* attack and self defense when attacked
     *
     * return values: death of:
     * 0-nobody * 1-this creature * 2-the other creature * 3-both creatures
     */
int Creature::defendYourselfFrom(Creature &who){
    int dmgReceived = who.getAttack();
    int dmgDealt = this->getAttack();

    std::cout << who.getName() << " just attacked " + this->getName() + " (" << this->getHealth() << "->";
    this->setHealth(this->getHealth() - dmgReceived);
    std::cout << this->getHealth() << ")" << std::endl;

    std::cout << this->getName() << " defends themself against " + who.getName() + " (" << who.getHealth() << "->";
    who.setHealth(who.getHealth() - dmgDealt);
    std::cout << who.getHealth() << ")" << std::endl << std::endl;

        //if hero attacks himself
    if (who == *this) if (this->getHealth() < 1 || who.getHealth() < 1) return 1;
    if (who.getHealth() < 1 && this->health < 1) return 3;
    if (this->getHealth() < 1) return 2;
    if (who.getHealth() < 1) return 1;
    return 0;
}

bool Creature::operator== (const Creature& right){
    if (this->getName()==right.getName() && this->getHealth()==right.getHealth()) return true;
    return false;
}
