#ifndef PROJECT_H
#define PROJECT_H

#include <map>
#include <memory>
class DrawableObject;
class Project
{
    std::map<int, std::shared_ptr<DrawableObject>> objects_map;

public:
    Project();
    void add_object(std::shared_ptr<DrawableObject>);
    void remove_object(int id);
    std::map<int, std::shared_ptr<DrawableObject>> get_objects();
};


#endif // PROJECT_H
