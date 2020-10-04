#ifndef PROJECT_H
#define PROJECT_H

#include <map>
#include <memory>
#include <string>
#include <QUrl>
#include <functional>
#include <QDomElement>

class DrawableObject;
class Project
{
    std::map<int, std::shared_ptr<DrawableObject>> objects_map;
    QUrl url;
    static std::map<std::string, std::function<std::shared_ptr<DrawableObject>(QDomElement)> > creation_funcs;

public:
    Project(const QUrl&);
    void add_object(std::shared_ptr<DrawableObject>);
    void remove_object(int id);
    std::map<int, std::shared_ptr<DrawableObject>> get_objects();
    void save();
    void load();
};


#endif // PROJECT_H
