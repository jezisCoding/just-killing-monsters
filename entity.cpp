#include "entity.h"
#include "creature.h"

Entity::Entity(std::string mapSign)
{
    this->mapSign = mapSign;
}

Entity::~Entity()
{
    //std::cout << "An entity just died." << std::endl;
}

std::string Entity::getMapSign() const
{
    return mapSign;
}

int Entity::reaction(Creature &to){
    std::cout << "undefined interaction of " + getValueTypeIdString() + " with " + to.getValueTypeIdString() << std::endl;
    return 0;   //noone died
}

std::string Entity::getPointerTypeIdString(){
    return typeid(this).name();
}

std::string Entity::getValueTypeIdString(){
    return typeid(*this).name();
}
