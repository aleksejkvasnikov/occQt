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

void Sphere::drawOnScene(const Handle(AIS_InteractiveContext) &c)
{
    gp_Ax2 anAxis;
    anAxis.SetLocation(gp_Pnt(px,py,pz));
    TopoDS_Shape aTopoSphere = BRepPrimAPI_MakeSphere(anAxis, r).Shape();
    Handle(AIS_Shape) anAisSphere = new AIS_Shape(aTopoSphere);
    anAisSphere->SetColor(Quantity_NOC_BLUE1);
    c->Display(anAisSphere, Standard_True);
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
