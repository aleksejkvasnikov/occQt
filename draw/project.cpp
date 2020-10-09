#include "project.h"
#include "drawableobject.h"
#include <QDomDocument>
#include <QFile>
#include <QTextStream>
#include "../dataobject.h"
#include "rectangle.h"
#include "box.h"
#include "cone.h"
#include "cylinder.h"
#include "sphere.h"
#include "torus.h"
std::map<std::string, std::function<std::shared_ptr<DrawableObject>(QDomElement)>> Project::creation_funcs = {
    { "box", [](QDomElement e) {return Box::create(e);}},
    { "cone", [](QDomElement e) {return Cone::create(e);}},
    { "cylinder", [](QDomElement e) {return Cylinder::create(e);}},
    { "sphere", [](QDomElement e) {return Sphere::create(e);}},
    { "torus", [](QDomElement e) {return Torus::create(e);}}
};

Project::Project(const QUrl& url0) : url(url0)
{
}

void Project::add_object(std::shared_ptr<DrawableObject> object)
{
    objects_map[object->get_id()] = object;
}

void Project::remove_object(int id)
{
    objects_map.erase(id);
}

void Project::remove_all_objects()
{
    objects_map.clear();
}

std::map<int, std::shared_ptr<DrawableObject>> Project::get_objects()
{
    return objects_map;
}

void Project::save()
{
    QDomDocument document;

    QDomElement d = document.createElement( "objects" );
    d.setAttribute("size", int(objects_map.size()));
    for (auto it: objects_map)
    {
        d.appendChild(it.second->xml_element(document));
    }
    document.appendChild(d);

    //Writing to a file
    QFile file(url.toLocalFile());
    if(!file.open( QIODevice::WriteOnly | QIODevice::Text ) )
    {
        qDebug( "Failed to open file for writing." );
        return;
    }
    QTextStream stream( &file );
    stream << document.toString();
    file.close();
}

void Project::load()
{
    QDomDocument doc;
    QFile file(url.toLocalFile());
    if (!file.open(QIODevice::ReadOnly))
        return;
    if (!doc.setContent(&file)) {
        file.close();
        return;
    }
    file.close();

    // print out the element names of all elements that are direct children
    // of the outermost element.
    QDomElement docElem = doc.documentElement();

    QDomNode n = docElem.firstChild();
    while(!n.isNull()) {
        QDomElement e = n.toElement(); // try to convert the node to an element.
        if(!e.isNull()) {
            auto t = e.tagName();
            auto creation_func = creation_funcs[e.tagName().toStdString()];
            if (creation_func)
            {
                add_object(creation_func(e)); // the node really is an element.
            }
        }
        n = n.nextSibling();
    }
}

QVariant Project::getData()
{
    QList<QObject *> dataList = { };
    int count = 0;
    for (auto it: objects_map)
    {
        dataList.append(new DataObject(it.second->toString(), count++%2 ? "grey" : "blue"));
    }
    return QVariant::fromValue(dataList);
}
