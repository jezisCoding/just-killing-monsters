#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include "interactiveentity.h"
#include "environment.h"
#include "position.h"
#include "hero.h"

class GameField
{
private:
    InteractiveEntity *fieldEntity;
    Environment *fieldEnvironment;
    Position *fieldPosition;
public:
    GameField(InteractiveEntity *fieldEntity, Environment *fieldEnvironment, Position *fieldPosition);
    ~GameField();
    Position *getFieldPosition();
    Environment *getFieldEnvironment();
    InteractiveEntity *getFieldEntity();
    std::string getPrintSign();
    void setFieldEntity(InteractiveEntity *toValue);
    void deleteFieldEntity();
};

#endif // GAMEFIELD_H
