#ifndef SPHERE_H
#define SPHERE_H

#include "drawableobject.h"
#include <string>
#include <memory>

class Sphere : public DrawableObject
{
    float px,py,pz,r;
public:
    static const std::string NAME;
    Sphere(float px, float py, float pz, float r);
    virtual bool operator==(const DrawableObject&);
    QDomElement xml_element(QDomDocument&);
    static std::shared_ptr<DrawableObject> create(QDomElement);
};

#endif // SPHERE_H
