#ifndef TORUS_H
#define TORUS_H

#include "drawableobject.h"
#include <string>
#include <memory>
#include <AIS_Shape.hxx>
#include <BRepPrimAPI_MakeTorus.hxx>

class Torus : public DrawableObject
{
    float px,py,pz,r1,r2,angle;
public:
    static const std::string NAME;
    Torus(float px, float py, float pz, float r1, float r2, float angle);
    QDomElement xml_element(QDomDocument&);
    void drawOnScene(const Handle(AIS_InteractiveContext) &c);
    static std::shared_ptr<DrawableObject> create(QDomElement);
};



#endif // TORUS_H
