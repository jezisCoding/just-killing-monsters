#include "environment.h"

Environment::Environment(Position *position, const char &mapSign, const fieldType& type)
    : Entity(position, mapSign)
{
    this->type = type;
}

Environment::~Environment()
{
    delete position;
}

int Environment::reaction(Creature *to){
    std::cout << "undefined interaction of " + getTypeIdStringValue() + " with " + to->getTypeIdStringValue() << std::endl;
    return 0;   //noone died
}

Environment::fieldType Environment::getType() const{
    return type;
}

bool Environment::passableEnvironment() const
{
    return type == Empty;
}
