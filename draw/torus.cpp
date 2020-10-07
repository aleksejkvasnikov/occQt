#include "torus.h"

const std::string Torus::NAME = "torus";

Torus::Torus(float px0, float py0, float pz0, float r10, float r20, float angle0) : px(px0), py(py0), pz(pz0),
    r1(r10), r2(r20), angle(angle0)
{
    add_sizeVec(px);
    add_sizeVec(py);
    add_sizeVec(pz);
    add_sizeVec(r1);
    add_sizeVec(r2);
    add_sizeVec(angle);
    set_type("TORUS");
}

bool Torus::operator==(const DrawableObject &o)
{
    if(const Torus* v = dynamic_cast<const Torus*>(&o)) {
        return v->px == px && v->py == py && v->pz == pz && v->r1 == r1 && v->r2 == r2 && v->angle == angle;
    }
    return false;
}

QDomElement Torus::xml_element(QDomDocument& document)
{
    QDomElement d = document.createElement(QString::fromStdString(NAME));
    d.setAttribute("px", px);
    d.setAttribute("py", py);
    d.setAttribute("pz", pz);
    d.setAttribute("r1", r1);
    d.setAttribute("r2", r2);
    d.setAttribute("angle", angle);
    return d;
}

std::shared_ptr<DrawableObject> Torus::create(QDomElement e)
{
    return std::make_shared<Torus>(e.attribute("px").toFloat(),
                                 e.attribute("py").toFloat(),
                                 e.attribute("pz").toFloat(),
                                 e.attribute("r1").toFloat(),
                                 e.attribute("r2").toFloat(),
                                 e.attribute("angle").toFloat());
}
