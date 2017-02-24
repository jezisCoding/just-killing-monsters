#ifndef MYXMLPARSER_H
#define MYXMLPARSER_H

//#include <QObject>
#include <QString>
#include <QFile>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QMap>
#include <QDebug>

#include "staticoutputstream.h"
#include "myexceptions.h"

class MyXMLParser
{
public:
    MyXMLParser();

    bool writeXml(const QString& fileName) throw (file_error);
    QMap<QString, QString> readXml(const QString& fileName) const throw(file_error);

    void testXML();
};

#endif // MYXMLPARSER_H
