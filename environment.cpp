#include "environment.h"

Environment::Environment(fieldType type, std::__cxx11::string mapSign) : Entity(mapSign)
{
    this->type = type;
}

Environment::fieldType Environment::getType()
{
    return type;
}
