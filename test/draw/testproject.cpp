#include "testproject.h"
#include <QtTest/QtTest>
#include <memory>
#include "../../draw/project.h"
#include "../../draw/rectangle.h"

TestProject::TestProject()
{

}

void TestProject::testProject()
{
    Project project("name");
    project.add_object(std::make_shared<Rectangle>(2, 3));
    project.add_object(std::make_shared<Rectangle>(1, 3));
    auto p = std::make_shared<Rectangle>(2, 3);
    project.add_object(p);
    auto l = project.get_objects();
    project.add_object(std::make_shared<Rectangle>(2, 3));
    project.remove_object(p->get_id());
    QVERIFY(project.get_objects() != l);
    l.erase(2);
    project.remove_object(3);
    QVERIFY(project.get_objects() == l);
}
