#ifndef MYQMAP_H
#define MYQMAP_H

#include <QMap>
#include <QStringRef>

class MyQMap
{
private:
    QMap<QString, QString> map;
public:
    MyQMap(){}

    void insert(QStringRef key, QString value){
        map.insert(key.toString(), value);
    }

    std::string value(QString key, QString defaultValue = QString()) const{
        return map.value(key, defaultValue).toStdString();
    }

    void insert(QString key, QString value){
        map.insert(QString(key), value);
    }
};

#endif // MYQMAP_H
