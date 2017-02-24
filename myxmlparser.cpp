#include "myxmlparser.h"

MyXMLParser::MyXMLParser()
{

}

bool MyXMLParser::writeXml(const QString &fileName) throw(file_error)
{
    QFile file(fileName);   //.split("\\").at(1)
    if(file.open(QIODevice::WriteOnly)){
        QXmlStreamWriter writer;
        writer.setDevice(&file);

        writer.writeStartDocument();

        writer.writeStartElement("actors");

        writer.writeStartElement("hero");

        writer.writeTextElement("mapSign", "H");
        writer.writeTextElement("name", "kappa");
        writer.writeTextElement("health", "50");
        writer.writeTextElement("attack", "31");
        writer.writeTextElement("readiness", "0");
        writer.writeTextElement("surpriseAttack", "10");
        writer.writeTextElement("pos", "11");

        writer.writeEndElement();   //hero

        writer.writeEndElement();   //actors

        writer.writeEndDocument();

        file.close();
        return true;
        /*
         * kazda entita - toXml, fromXml, addToXmlStream(staticoutput, ten to potom printne naraz),
         *  loadFromXml/createFromXml(deletnut pointery, =new instance)/konstruktor na zaklade QStringu alebo coho
         *
         * xml - map:
         * engine
         *  -hero
         * gameboard
         *  -sethero
         * board
         *  -for(.at(pos)=new gamefield)
         *
         * returnne string ktory tam len zapicim?
         */
    } else {
        throw new file_error("File was not open(writeXml)");
    }
    return false;
}

QMap<QString, QString> MyXMLParser::readXml(const QString &fileName) const throw(file_error)
{
    QFile file(fileName);
    QMap<QString, QString> values;

    if(file.open(QIODevice::ReadOnly)){
        QXmlStreamReader reader;
        reader.setDevice(&file);

        reader.readNext();

        while (!reader.isEndDocument()) {
            if(reader.isStartElement()){
                QString name = reader.name().toString();
                QString key = "";
                QString value = "";

                if(name == "hero"){
                    reader.readNext();
                    key = reader.name().toString();
                    //reader.readNext();
                    value = reader.readElementText();
                    values.insert(key, value);







                    /*reader.readNext();
                    id = reader.name().toString();

                    reader.readNext();reader.readNext();

                    QString tmep = reader.tokenString();

                    value = reader.readElementText();
                    values.insert(id, value);*/
                    StaticOutputStream::getStream() << key.toStdString() + ": " + value.toStdString() << std::endl;
                }
            } //else if(reader.isEndElement())
            reader.readNext();

            if(reader.hasError()){
                qDebug() << "XML error: " << reader.errorString().data() << "\n";
            }
        }

    file.close();
    } else {
        qDebug() << "Cannot open file \n";
        throw new file_error("File was not open(readXml)");
    }

    return values;
}

void MyXMLParser::testXML()
{
    QFile file("atributdpc.xml");
    if(file.open(QIODevice::WriteOnly)){
        QXmlStreamWriter writer;
        writer.setDevice(&file);

        writer.writeStartDocument();

        writer.writeStartElement("element");
        writer.writeAttribute("atribut", "hodnota");
        writer.writeStartElement("dalsielement");
        writer.writeEndElement();
        writer.writeEmptyElement("tretielement");
        writer.writeEndElement();

        writer.writeEndDocument();

        file.close();
    }
}
