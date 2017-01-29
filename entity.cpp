#include "entity.h"
#include "creature.h"

Entity::Entity(Position* position, const char &mapSign)
{
    this->position = position;
    this->mapSign = mapSign;
}

Entity::Entity(const Entity& orig)
{
    this->position = orig.position;
    this->mapSign = orig.mapSign;
}

Entity::~Entity()
{
    delete position;
    //std::cout << "An entity just died." << std::endl;
}

void Entity::setMapSign(const char &to)
{
    mapSign = to;
}

char Entity::getMapSign() const
{
    return mapSign;
}

void Entity::setPosition(Position *position){
    this->position = position;
}

Position* Entity::getPosition(){
    return position;
}

std::string Entity::getTypeIdStringPointer(){
    return typeid(this).name();
}

std::string Entity::getTypeIdStringValue(){
    return typeid(*this).name();
}
