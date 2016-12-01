#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include "entity.h"

struct Environment : public Entity
{
    enum fieldType {Empty, Rock, Tree}; //new type declared
private:
    fieldType type;
public:
    Environment(fieldType type, std::string mapSign);
    fieldType getType();
};

#endif // ENVIRONMENT_H
