#ifndef SPHERE_H
#define SPHERE_H

#include "drawableobject.h"
#include <string>
#include <memory>
#include <AIS_Shape.hxx>
#include <BRepPrimAPI_MakeSphere.hxx>

class Sphere : public DrawableObject
{
    float px,py,pz,r;
public:
    static const std::string NAME;
    Sphere(float px, float py, float pz, float r);
    QDomElement xml_element(QDomDocument&);
    void drawOnScene(const Handle(AIS_InteractiveContext) &c);
    static std::shared_ptr<DrawableObject> create(QDomElement);
};

#endif // SPHERE_H
