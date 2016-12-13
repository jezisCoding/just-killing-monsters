#include "gamefield.h"

GameField::GameField(Entity *fieldEntity, Environment *fieldEnvironment, Position *fieldPosition)
{
    this->fieldEntity = fieldEntity;
    this->fieldEnvironment = fieldEnvironment;
    this->fieldPosition = fieldPosition;
}

GameField::~GameField(){
    delete fieldEntity;
    delete fieldEnvironment;
    delete fieldPosition;
}

Position *GameField::getFieldPosition(){
    return fieldPosition;
}

Environment *GameField::getFieldEnvironment(){
    return fieldEnvironment;
}

Entity *GameField::getFieldEntity(){
    return fieldEntity;
}

std::string GameField::getPrintSign(){
    if (fieldEntity != nullptr) return fieldEntity->getMapSign();
    return fieldEnvironment->getMapSign();
}

void GameField::setFieldEntity(Entity *toValue){
    fieldEntity = toValue;
}

void GameField::setFieldEnvironment(Environment *toValue){
    this->fieldEnvironment = toValue;
}
