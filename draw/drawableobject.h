#ifndef DRAWABLEOBJECT_H
#define DRAWABLEOBJECT_H

#include <QDomElement>
#include <QDomDocument>
#include <vector>
#include <AIS_Shape.hxx>
#include <AIS_InteractiveContext.hxx>
class DrawableObject
{   
    static int id_counter;
    int id;
    QString type;
    std::vector<float> sizes;

public:   
    DrawableObject();
    bool operator==(DrawableObject const &o);
    int get_id() {return id;}
    void add_sizeVec(float a) {sizes.push_back(a);}
    std::vector<float> get_sizeVec(){return sizes;}
    QString get_type() {return type;}
    void set_type(QString t) {type=t;}
    virtual void drawOnScene(const Handle(AIS_InteractiveContext)&) = 0;
    void removeFromScene(const Handle(AIS_InteractiveContext)&);
    virtual QDomElement xml_element(QDomDocument&)=0;
    QString toString() {return QString("%1 %2").arg(type, QString::number(id));}
    Handle(AIS_Shape) obj;
};

#endif // DRAWABLEOBJECT_H
