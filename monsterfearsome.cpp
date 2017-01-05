#include "monsterfearsome.h"

MonsterFearsome::MonsterFearsome(Position* position, std::string mapSign, std::string name,
                                 int health, int attack, float fearsomeness)
    : Monster(position, mapSign, name, health, attack)
{
    this->fearsomeness = fearsomeness;
}

MonsterFearsome::MonsterFearsome(const MonsterFearsome& from) : Monster(position, mapSign, name, health, attack)
{
    this->mapSign = "V";
    this->name = from.getName() + "(split)";
    this->health = from.getHealth();
    this->attack = from.getAttack()/2;
    this->fearsomeness = from.getFearsomeness();
}

MonsterFearsome::~MonsterFearsome()
{

}

int MonsterFearsome::defendYourselfFrom(Creature &who){
    int dmgReceived = who.getAttack();
    int dmgDealt = this->getAttack();

    std::cout << who.getName() << " just attacked " + this->getName() + " (" << this->getHealth() << "->";
    this->setHealth(this->getHealth() - dmgReceived);
    std::cout << this->getHealth() << ")" << std::endl;

    std::cout << this->getName() << " defends themself against " + who.getName() + " (" << who.getHealth() << "->";
    who.setHealth(who.getHealth() - dmgDealt);
    std::cout << who.getHealth() << ")" << std::endl << std::endl;

        //split in 2
    if (this->getHealth() <= this->getMAX_HEALTH()/2) {
        split(who.get)
        //zobere poziciu hera, checkne ci je volno naokolo, hodi mu klona,
    }

        //if hero attacks himself
    if (who == *this) if (this->getHealth() < 1 || who.getHealth() < 1) return 1;
    if (who.getHealth() < 1 && this->health < 1) return 3;
    if (this->getHealth() < 1) return 2;
    if (who.getHealth() < 1) return 1;
    return 0;
}

int MonsterFearsome::getAttack() const{
    return fearsomeness*attack;
}

int MonsterFearsome::getFearsomeness() const{
    return fearsomeness;
}
