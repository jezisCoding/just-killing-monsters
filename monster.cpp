#include "monster.h"

Monster::Monster(std::__cxx11::string mapSign, int health, int attack, int fearsomeness)
    : Creature(mapSign, health, attack)
{
    this->fearsomeness = fearsomeness;
}

int Monster::getFearsomeness(){
    return fearsomeness;
}

    //i need to find out how to use this
/*void Monster::dealDamage(int amount){
    setHealth(health - amount);

    if (health < 1){
        //zemri()//engine bude checkovat health?
    } else {
        if (hrozostrasnost - oKolko/10 < 0) {
            hrozostrasnost = 0;
        } else {
            hrozostrasnost -= oKolko/10;
        }
    }
}*/
