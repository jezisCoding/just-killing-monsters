#include "gamefield.h"

GameField::GameField(MyEntityPointer fieldEntity, MyEnvironmentPointer fieldEnvironment)
{
    this->fieldEntity = fieldEntity;
    this->fieldEnvironment = fieldEnvironment;
}

GameField::~GameField()
{
    delete fieldEntity;
    delete fieldEnvironment;
}

std::__cxx11::string GameField::getPrintSign() const
{
    if (fieldEntity != nullptr) return fieldEntity->getMapSign();
    return fieldEnvironment->getMapSign();
}

Entity *GameField::getFieldEntity() const{
    return fieldEntity;
}

Environment *GameField::getFieldEnvironment() const{
    return fieldEnvironment;
}

void GameField::setFieldEntity(Entity *toValue){
    fieldEntity = toValue;
}

void GameField::setFieldEnvironment(Environment *toValue){
    this->fieldEnvironment = toValue;
}
