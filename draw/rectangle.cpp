#include "rectangle.h"

const std::string Rectangle::NAME = "rectangle";

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

QDomElement Rectangle::xml_element(QDomDocument& document)
{
    QDomElement d = document.createElement(QString::fromStdString(NAME));
    d.setAttribute("w", w);
    d.setAttribute("h", h);
    return d;
}

std::shared_ptr<DrawableObject> Rectangle::create(QDomElement e)
{
    return std::make_shared<Rectangle>(e.attribute("w").toFloat(), e.attribute("h").toFloat());
}
