#include "environment.h"

Environment::Environment(const char &mapSign, const fieldType& type)
    : FieldEntity(mapSign)
{
    this->type = type;
}

Environment::~Environment()
{

}

Environment::fieldType Environment::getType() const{
    return type;
}

bool Environment::passableEnvironment() const
{
    return type == Empty;
}
