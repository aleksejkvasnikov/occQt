#include "rectangle.h"

Rectangle::Rectangle(float w0, float h0) : w(w0), h(h0)
{

}

bool Rectangle::operator==(const DrawableObject &o)
{
    if(const Rectangle* v = dynamic_cast<const Rectangle*>(&o)) {
       // old was safely casted to NewType
        return v->w == w && v->h == h;
    }
    return false;
}
