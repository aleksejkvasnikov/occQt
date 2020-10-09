#include "drawableobject.h"

int DrawableObject::id_counter = 0;

DrawableObject::DrawableObject()
{
    id = id_counter++;
}
