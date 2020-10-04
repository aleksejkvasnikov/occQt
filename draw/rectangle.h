#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "drawableobject.h"
#include <string>
#include <memory>

class Rectangle : public DrawableObject
{
    float w, h;
public:
    static const std::string NAME;

    Rectangle(float w, float h);
    virtual bool operator==(const DrawableObject&);
    QDomElement xml_element(QDomDocument&);
    static std::shared_ptr<DrawableObject> create(QDomElement);
};

#endif // RECTANGLE_H
