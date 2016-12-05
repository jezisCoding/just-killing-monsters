#include "environment.h"

Environment::Environment(std::__cxx11::string mapSign, fieldType type) : Entity(mapSign)
{
    this->type = type;
}

Environment::fieldType Environment::getType()
{
    return type;
}
