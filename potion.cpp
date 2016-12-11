#include "potion.h"
#include "creature.h"

Potion::Potion(std::__cxx11::string mapSign, int healthBonus) : Entity(mapSign)
{
    this->healthBonus = healthBonus;
}

Potion::~Potion(){
    std::cout << "You drank the potion and its gone" << std::endl;
}
    //return  - potion is drank(its getting destroyed)
int Potion::reaction(Creature &to){ //you dont need this if 100 hp
    int userHealth = to.getHealth();

    if (userHealth > 99) {
        std::cout << "You don't need this yet, you are on full health" << std::endl;
        return 0;
    }

    std::cout << to.getName() << " drinks a potion ("
              << userHealth << "->";

    if (userHealth + healthBonus > 100){
        int overHeal = (userHealth + healthBonus) % 100;
        to.setHealth(userHealth + healthBonus - overHeal);
    } else to.setHealth(userHealth + healthBonus);
    std::cout << to.getHealth() << ")" << std::endl;
    return 2;
}

int Potion::getHealthBonus(){
    return healthBonus;
}

/*    //do i need the return value?
void Potion::reaction(BoardEntity* with){
    std::cout << "just sth useless tbh" <<std::endl;
        AALEBO SA NA TO PROSTE VYSEREM CELYT INTERFACE

    //with->interaction(this); //a tym padom sa to da dat do metody hera nemusia si to prehadzovat
    //with->setHealth(with->getHealth() + this->healthBonus);
}
*/
