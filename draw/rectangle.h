#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "drawableobject.h"

class Rectangle : public DrawableObject
{
    float w, h;
public:
    Rectangle(float w, float h);
    virtual bool operator==(const DrawableObject&);
};

#endif // RECTANGLE_H
