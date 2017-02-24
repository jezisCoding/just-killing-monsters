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

void FieldActor::addToXml(QFile& where, QXmlStreamWriter& writer) const
{
    FieldEntity::addToXml(where, writer);
}
