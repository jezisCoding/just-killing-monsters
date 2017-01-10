#include "gamefield.h"

GameField::GameField(Entity *fieldEntity, Environment *fieldEnvironment, Position *fieldPosition)
{
    this->fieldEntity = fieldEntity;
    this->fieldEnvironment = fieldEnvironment;
    this->fieldPosition = fieldPosition;
}

GameField::~GameField()
{
    delete fieldEntity;
    delete fieldEnvironment;
    delete fieldPosition;
}

std::string GameField::getPrintSign() const{
    if (fieldEntity != nullptr) return fieldEntity->getMapSign();
    return fieldEnvironment->getMapSign();
}

Entity *GameField::getFieldEntity() const{
    return fieldEntity;
}

Environment *GameField::getFieldEnvironment() const{
    return fieldEnvironment;
}

Position *GameField::getFieldPosition() const{
    return fieldPosition;
}


void GameField::setFieldEntity(Entity *toValue){
    fieldEntity = toValue;
}

void GameField::setFieldEnvironment(Environment *toValue){
    this->fieldEnvironment = toValue;
}
