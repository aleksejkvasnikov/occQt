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
    Project project(QUrl(""));
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

void TestProject::testProjectSave()
{
    Project project(QUrl::fromLocalFile("file.txt"));
    project.add_object(std::make_shared<Rectangle>(2, 3));
    project.add_object(std::make_shared<Rectangle>(1, 3));
    project.add_object(std::make_shared<Rectangle>(2, 3));
    project.add_object(std::make_shared<Rectangle>(2, 3));
    project.save();
    Project project2(QUrl::fromLocalFile("file2.txt"));
    project.add_object(std::make_shared<Rectangle>(2, 3));
    project.add_object(std::make_shared<Rectangle>(1, 3));
    project.save();
    Project project3(QUrl::fromLocalFile("file.txt"));
    project3.load();
    auto o1 = project.get_objects();
    auto o3 = project3.get_objects();
    QVERIFY(o1.size() == o3.size());
    QVERIFY(project2.get_objects().size() != project3.get_objects().size());
}
