#include "cylinder.h"

const std::string Cylinder::NAME = "cylinder";

Cylinder::Cylinder(float px0, float py0, float pz0, float r10, float h0, float angle0) : px(px0), py(py0), pz(pz0),
    r1(r10), h(h0), angle(angle0)
{
    add_sizeVec(px);
    add_sizeVec(py);
    add_sizeVec(pz);
    add_sizeVec(r1);
    add_sizeVec(h);
    add_sizeVec(angle);
    set_type("CYLINDER");
}

void Cylinder::drawOnScene(const Handle(AIS_InteractiveContext) &c)
{
    gp_Ax2 anAxis;
    anAxis.SetLocation(gp_Pnt(px,py,pz));
    TopoDS_Shape aTopoPie = BRepPrimAPI_MakeCylinder(anAxis, r1, h).Shape();
    //TopoDS_Shape aTopoPie = BRepPrimAPI_MakeCylinder(anAxis, r, h, angle).Shape();
    Handle(AIS_Shape) anAisPie = new AIS_Shape(aTopoPie);
    anAisPie->SetColor(Quantity_NOC_TAN);
    c->Display(anAisPie, Standard_True);
}

QDomElement Cylinder::xml_element(QDomDocument& document)
{
    QDomElement d = document.createElement(QString::fromStdString(NAME));
    d.setAttribute("px", px);
    d.setAttribute("py", py);
    d.setAttribute("pz", pz);
    d.setAttribute("r1", r1);
    d.setAttribute("h", h);
    d.setAttribute("angle", angle);
    return d;
}

std::shared_ptr<DrawableObject> Cylinder::create(QDomElement e)
{
    return std::make_shared<Cylinder>(e.attribute("px").toFloat(),
                                 e.attribute("py").toFloat(),
                                 e.attribute("pz").toFloat(),
                                 e.attribute("r1").toFloat(),
                                 e.attribute("h").toFloat(),
                                 e.attribute("angle").toFloat());
}
