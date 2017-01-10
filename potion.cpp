#include "potion.h"
#include "creature.h"

Potion::Potion(Position* position, std::__cxx11::string mapSign, int healthBonus)
    : Entity(position, mapSign)
{
    this->healthBonus = healthBonus;
}

Potion::~Potion()
{
    std::cout << "You drank the potion and its gone" << std::endl;
}

    /**
     * return 2 - potion is drank(its getting destroyed)
     * you dont need this if 100 hp
     */
int Potion::reaction(Creature *to){
    int userHealth = to->getHealth();
    int userMaxHealth = to->getMAX_HEALTH();

    if (userHealth > userMaxHealth-1) {
        std::cout << "You don't need this yet, you are on full health" << std::endl;
        return 0;
    }

    std::cout << to->getName() << " drinks a potion ("
              << userHealth << "->";

    if (userHealth + healthBonus > userMaxHealth){
        int overHeal = (userHealth + healthBonus) % userMaxHealth;
        to->setHealth(userHealth + healthBonus - overHeal);
    } else to->setHealth(userHealth + healthBonus);

    std::cout << to->getHealth() << ")" << std::endl;
    return 2;
}

int Potion::getHealthBonus(){
    return healthBonus;
}
