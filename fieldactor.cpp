#include "fieldactor.h"

FieldActor::FieldActor(const char mapSign) : FieldEntity(mapSign)
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

void FieldActor::die()
{

}

void FieldActor::addToXml(QXmlStreamWriter& writer) const
{
    FieldEntity::addAncestryToXml(writer);
}

void FieldActor::addAncestryToXml(QXmlStreamWriter &writer) const
{
    FieldEntity::addAncestryToXml(writer);
}
