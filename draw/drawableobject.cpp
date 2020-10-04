#include "drawableobject.h"

int DrawableObject::id_counter = 0;

DrawableObject::DrawableObject()
{
    id = id_counter++;
}

bool DrawableObject::operator==(const DrawableObject &o)
{
    return true;
}
