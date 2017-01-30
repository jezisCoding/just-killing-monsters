#include "environment.h"

Environment::Environment(const char &mapSign, const fieldType& type)
    : FieldEntity(mapSign)
{
    this->type = type;
}

Environment::~Environment()
{

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
