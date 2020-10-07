#ifndef CONE_H
#define CONE_H

#include "drawableobject.h"
#include <string>
#include <memory>

class Cone : public DrawableObject
{
    float px,py,pz,r1,r2,h;
public:
    static const std::string NAME;
    Cone(float px, float py, float pz, float r1, float r2, float h);
    virtual bool operator==(const DrawableObject&);
    QDomElement xml_element(QDomDocument&);
    static std::shared_ptr<DrawableObject> create(QDomElement);
};


#endif // CONE_H
