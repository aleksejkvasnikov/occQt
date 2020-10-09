#include "drawableobject.h"

int DrawableObject::id_counter = 0;

DrawableObject::DrawableObject()
{
    id = id_counter++;
}

bool DrawableObject::operator==(const DrawableObject &o)
{
    if(const DrawableObject* v = dynamic_cast<const DrawableObject*>(&o)) {
        return v->sizes == sizes;
    }
    return false;
}

void DrawableObject::removeFromScene(const Handle(AIS_InteractiveContext)& c){
    c->Remove(obj,true);
}
