#include "potion.h"

Potion::Potion(std::__cxx11::string mapSign, int healthBonus) : InteractiveEntity(mapSign)
{
    this->healthBonus = healthBonus;
}

Potion::~Potion(){
    std::cout << "You drank the potion and its gone" << std::endl;
    //this should be deleted above(gameboard)
}

int Potion::getHealthBonus(){
    return healthBonus;
}

    //do i need the return value?
int Potion::interaction(Creature* with){
    with->setHealth(with->getHealth() + this->healthBonus);
    return 1;
}
