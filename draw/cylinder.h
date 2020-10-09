#ifndef CYLINDER_H
#define CYLINDER_H

#include "drawableobject.h"
#include <string>
#include <memory>
#include <AIS_Shape.hxx>
#include <BRepPrimAPI_MakeCylinder.hxx>

class Cylinder : public DrawableObject
{
    float px,py,pz,r1,h,angle;
public:
    static const std::string NAME;
    Cylinder(float px, float py, float pz, float r1, float h, float angle);
    QDomElement xml_element(QDomDocument&);
    void drawOnScene(const Handle(AIS_InteractiveContext) &c);
    static std::shared_ptr<DrawableObject> create(QDomElement);
};


#endif // CYLINDER_H
