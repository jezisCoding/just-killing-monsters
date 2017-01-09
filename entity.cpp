#include "entity.h"
#include "creature.h"

Entity::Entity(Position* position, const std::__cxx11::string& mapSign)
{
    this->position = position;
    this->mapSign = mapSign;
}

Entity::~Entity()
{
    delete position;
    //std::cout << "An entity just died." << std::endl;
}

std::string Entity::getMapSign() const
{
    return mapSign;
}

Position* Entity::getPosition(){
    return position;
}

void Entity::setPosition(Position *position){
    this->position = position;
}

std::string Entity::getTypeIdStringPointer(){
    return typeid(this).name();
}

std::string Entity::getTypeIdStringValue(){
    return typeid(*this).name();
}
