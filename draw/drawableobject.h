#ifndef DRAWABLEOBJECT_H
#define DRAWABLEOBJECT_H

#include <QDomElement>
#include <QDomDocument>
#include <vector>
class DrawableObject
{   
    static int id_counter;
    int id;
    QString type;
    std::vector<float> sizes;
public:   
    DrawableObject();
    virtual bool operator==(const DrawableObject&)=0;
    int get_id() {return id;}
    void add_sizeVec(float a) {sizes.push_back(a);}
    std::vector<float> get_sizeVec(){return sizes;}
    QString get_type() {return type;}
    void set_type(QString t) {type=t;}
    virtual QDomElement xml_element(QDomDocument&)=0;
};

#endif // DRAWABLEOBJECT_H
