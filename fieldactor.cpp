#include "fieldactor.h"

FieldActor::FieldActor(const char& mapSign) : FieldEntity(mapSign)
{
    this->mapSign = mapSign;
}

FieldActor::FieldActor(const FieldActor &orig) : FieldEntity(orig)
{
    this->mapSign = orig.mapSign;
}

FieldActor::~FieldActor()
{

}
