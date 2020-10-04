#include "project.h"
#include "drawableobject.h"

Project::Project(const std::string&)
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

std::map<int, std::shared_ptr<DrawableObject>> Project::get_objects()
{
    return objects_map;
}

