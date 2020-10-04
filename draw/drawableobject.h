#ifndef DRAWABLEOBJECT_H
#define DRAWABLEOBJECT_H

#include <QDomElement>
#include <QDomDocument>

class DrawableObject
{
    static int id_counter;
    int id;
public:
    DrawableObject();
    virtual bool operator==(const DrawableObject&)=0;
    int get_id() {return id;}
    virtual QDomElement xml_element(QDomDocument&)=0;
};

#endif // DRAWABLEOBJECT_H
