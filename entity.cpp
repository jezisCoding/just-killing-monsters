#include "entity.h"

Entity::Entity(std::string mapSign)
{
    this->mapSign = mapSign;
}

Entity::~Entity()
{
    std::cout << "An entity just died." << std::endl;
}

std::string Entity::getMapSign() const
{
    return mapSign;
}
/*
void Entita::printTypeId(){
    std::cout << typeid(this).name() << std::endl;
}

std::string Entita::getTypeId(){
    return typeid(this).name();
}
*/
