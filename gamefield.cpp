#include "gamefield.h"

GameField::GameField(Environment *fieldEnvironment)
{
    this->fieldActor = nullptr;
    this->fieldEnvironment = fieldEnvironment;
}

GameField::~GameField()
{
    delete fieldActor;
    delete fieldEnvironment;
}

char GameField::getPrintSign() const{
    if (fieldActor != nullptr) return fieldActor->getMapSign();
    return fieldEnvironment->getMapSign();
}

FieldActor *GameField::getFieldActor(){
    return fieldActor;
}

Environment *GameField::getFieldEnvironment(){
    return fieldEnvironment;
}

void GameField::setFieldActor(FieldActor *toValue){
    fieldActor = toValue;
}

void GameField::setFieldEnvironment(Environment* toValue){
    this->fieldEnvironment = toValue;
}
