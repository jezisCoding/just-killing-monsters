#include "gamefield.h"

GameField::GameField(Environment *fieldEnvironment)
{

    this->fieldEntity = nullptr;
    this->fieldEnvironment = fieldEnvironment;
}

GameField::~GameField()
{
    delete fieldEntity;
    delete fieldEnvironment;
}

char GameField::getPrintSign() const{
    if (fieldEntity != nullptr) return fieldEntity->getMapSign();
    return fieldEnvironment->getMapSign();
}

Entity* GameField::getFieldEntity(){
    return fieldEntity;
}

Environment *GameField::getFieldEnvironment(){
    return fieldEnvironment;
}

void GameField::setFieldEntity(Entity* toValue){
    fieldEntity = toValue;
}

void GameField::setFieldEnvironment(Environment* toValue){
    this->fieldEnvironment = toValue;
}
