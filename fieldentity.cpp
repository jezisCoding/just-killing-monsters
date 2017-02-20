#include "fieldentity.h"
//#include "creature.h"

FieldEntity::FieldEntity(const char &mapSign)
{
    this->mapSign = mapSign;
}

FieldEntity::FieldEntity(const FieldEntity& orig)
{
    this->mapSign = orig.mapSign;
}

FieldEntity::~FieldEntity()
{
    //StaticOutputStream::getStream() << "An entity was just destroyed." << std::endl;
}

void FieldEntity::setMapSign(const char &to)
{
    mapSign = to;
}

char FieldEntity::getMapSign() const
{
    return mapSign;
}

std::string FieldEntity::getTypeIdStringPointer(){
    return typeid(this).name();
}

std::string FieldEntity::getTypeIdStringValue(){
    return typeid(*this).name();
}
