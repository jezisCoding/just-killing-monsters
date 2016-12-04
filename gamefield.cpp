#include "gamefield.h"

GameField::GameField(InteractiveEntity *fieldEntity, Environment *fieldEnvironment, Position *fieldPosition)
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

InteractiveEntity *GameField::getFieldEntity(){
    return fieldEntity;
}

std::string GameField::getPrintSign(){
    if (fieldEntity != nullptr) return fieldEntity->getMapSign();
    return fieldEnvironment->getMapSign();
}

void GameField::setFieldEntity(InteractiveEntity* toValue){
    fieldEntity = toValue;
}

