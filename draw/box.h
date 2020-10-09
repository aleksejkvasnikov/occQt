#ifndef BOX_H
#define BOX_H

#include "drawableobject.h"
#include <string>
#include <memory>
#include <AIS_Shape.hxx>
#include <BRepPrimAPI_MakeBox.hxx>

class Box : public DrawableObject
{
    float px,py,pz,x,y,z;
public:
    static const std::string NAME;
    Box(float px, float py, float pz, float x, float y, float z);
    QDomElement xml_element(QDomDocument&);
    void drawOnScene(const Handle(AIS_InteractiveContext) &c);
    void removeFromScene(const Handle(AIS_InteractiveContext) &c);
    static std::shared_ptr<DrawableObject> create(QDomElement);
};

#endif // BOX_H
