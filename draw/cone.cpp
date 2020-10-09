#include "cone.h"

const std::string Cone::NAME = "cone";

Cone::Cone(float px0, float py0, float pz0, float r10, float r20, float h0) : px(px0), py(py0), pz(pz0), r1(r10), r2(r20), h(h0)
{
    add_sizeVec(px);
    add_sizeVec(py);
    add_sizeVec(pz);
    add_sizeVec(r1);
    add_sizeVec(r2);
    add_sizeVec(h);
    set_type("CONE");
}

void Cone::drawOnScene(const Handle(AIS_InteractiveContext) &c)
{
    gp_Ax2 anAxis;
    anAxis.SetLocation(gp_Pnt(px,py,pz));
    TopoDS_Shape aTopoCone = BRepPrimAPI_MakeCone(anAxis, r1, r2, h).Shape();
    obj = new AIS_Shape(aTopoCone);
    obj->SetColor(Quantity_NOC_CHOCOLATE);
    c->Display(obj, Standard_True);
}

QDomElement Cone::xml_element(QDomDocument& document)
{
    QDomElement d = document.createElement(QString::fromStdString(NAME));
    d.setAttribute("px", px);
    d.setAttribute("py", py);
    d.setAttribute("pz", pz);
    d.setAttribute("r1", r1);
    d.setAttribute("r2", r2);
    d.setAttribute("h", h);
    return d;
}

std::shared_ptr<DrawableObject> Cone::create(QDomElement e)
{
    return std::make_shared<Cone>(e.attribute("px").toFloat(),
                                 e.attribute("py").toFloat(),
                                 e.attribute("pz").toFloat(),
                                 e.attribute("r1").toFloat(),
                                 e.attribute("r2").toFloat(),
                                 e.attribute("h").toFloat());
}
