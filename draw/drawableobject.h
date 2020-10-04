#ifndef DRAWABLEOBJECT_H
#define DRAWABLEOBJECT_H


class DrawableObject
{
    static int id_counter;
    int id;
public:
    DrawableObject();
    virtual bool operator==(const DrawableObject&)=0;
    int get_id() {return id;}
};

#endif // DRAWABLEOBJECT_H
