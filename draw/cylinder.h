#ifndef CYLINDER_H
#define CYLINDER_H

#include "drawableobject.h"
#include <string>
#include <memory>

class Cylinder : public DrawableObject
{
    float px,py,pz,r1,h,angle;
public:
    static const std::string NAME;
    Cylinder(float px, float py, float pz, float r1, float h, float angle);
    virtual bool operator==(const DrawableObject&);
    QDomElement xml_element(QDomDocument&);
    static std::shared_ptr<DrawableObject> create(QDomElement);
};


#endif // CYLINDER_H
