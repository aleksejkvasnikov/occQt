#include "box.h"

const std::string Box::NAME = "box";

Box::Box(float px0, float py0, float pz0, float x0, float y0, float z0) : px(px0), py(py0), pz(pz0), x(x0), y(y0), z(z0)
{
    add_sizeVec(px);
    add_sizeVec(py);
    add_sizeVec(pz);
    add_sizeVec(x);
    add_sizeVec(y);
    add_sizeVec(z);
    set_type("BOX");
}

bool Box::operator==(const DrawableObject &o)
{
    if(const Box* v = dynamic_cast<const Box*>(&o)) {
        return v->px == px && v->py == py && v->pz == pz && v->x == x && v->y == y && v->z == z;
    }
    return false;
}

QDomElement Box::xml_element(QDomDocument& document)
{
    QDomElement d = document.createElement(QString::fromStdString(NAME));
    d.setAttribute("px", px);
    d.setAttribute("py", py);
    d.setAttribute("pz", pz);
    d.setAttribute("x", x);
    d.setAttribute("y", y);
    d.setAttribute("z", z);
    return d;
}

std::shared_ptr<DrawableObject> Box::create(QDomElement e)
{
    return std::make_shared<Box>(e.attribute("px").toFloat(),
                                 e.attribute("py").toFloat(),
                                 e.attribute("pz").toFloat(),
                                 e.attribute("x").toFloat(),
                                 e.attribute("y").toFloat(),
                                 e.attribute("z").toFloat());
}
