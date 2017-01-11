#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include "entity.h"
#include "environment.h"
#include "position.h"
#include "hero.h"

class GameField
{
private:
    Entity *fieldEntity;
    Environment *fieldEnvironment;
public:
    GameField(Entity *fieldEntity, Environment *fieldEnvironment);
    ~GameField();

    std::string getPrintSign() const;

    Entity *getFieldEntity() const;
    Environment *getFieldEnvironment() const;
    void setFieldEntity(Entity *toValue);
    void setFieldEnvironment(Environment *toValue);
};

#endif // GAMEFIELD_H
