#include "sphere.h"

const std::string Sphere::NAME = "sphere";

Sphere::Sphere(float px0, float py0, float pz0, float r0) : px(px0), py(py0), pz(pz0),r(r0)
{
    add_sizeVec(px);
    add_sizeVec(py);
    add_sizeVec(pz);
    add_sizeVec(r);
    set_type("SPHERE");
}

bool Sphere::operator==(const DrawableObject &o)
{
    if(const Sphere* v = dynamic_cast<const Sphere*>(&o)) {
        return v->px == px && v->py == py && v->pz == pz && v->r == r;
    }
    return false;
}

QDomElement Sphere::xml_element(QDomDocument& document)
{
    QDomElement d = document.createElement(QString::fromStdString(NAME));
    d.setAttribute("px", px);
    d.setAttribute("py", py);
    d.setAttribute("pz", pz);
    d.setAttribute("r", r);
    return d;
}

std::shared_ptr<DrawableObject> Sphere::create(QDomElement e)
{
    return std::make_shared<Sphere>(e.attribute("px").toFloat(),
                                 e.attribute("py").toFloat(),
                                 e.attribute("pz").toFloat(),
                                 e.attribute("r").toFloat());
}
