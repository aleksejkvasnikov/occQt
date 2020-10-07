#ifndef BOX_H
#define BOX_H

#include "drawableobject.h"
#include <string>
#include <memory>

class Box : public DrawableObject
{
    float px,py,pz,x,y,z;
public:
    static const std::string NAME;
    Box(float px, float py, float pz, float x, float y, float z);
    virtual bool operator==(const DrawableObject&);
    QDomElement xml_element(QDomDocument&);
    static std::shared_ptr<DrawableObject> create(QDomElement);
};

#endif // BOX_H
