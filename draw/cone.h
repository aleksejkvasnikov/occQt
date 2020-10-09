#ifndef CONE_H
#define CONE_H

#include "drawableobject.h"
#include <string>
#include <memory>
#include <AIS_Shape.hxx>
#include <BRepPrimAPI_MakeCone.hxx>

class Cone : public DrawableObject
{
    float px,py,pz,r1,r2,h;
public:
    static const std::string NAME;
    Cone(float px, float py, float pz, float r1, float r2, float h);
    QDomElement xml_element(QDomDocument&);
    void drawOnScene(const Handle(AIS_InteractiveContext) &c);
    static std::shared_ptr<DrawableObject> create(QDomElement);
};


#endif // CONE_H
