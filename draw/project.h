#ifndef PROJECT_H
#define PROJECT_H

#include <list>
#include <memory>
class DrawableObject;
class Project
{
    std::list<std::shared_ptr<DrawableObject>> objects;

public:
    Project();
};


#endif // PROJECT_H
