#ifndef TESTPROJECT_H
#define TESTPROJECT_H

#include <QtTest/QtTest>

class TestProject : public QObject
{
    Q_OBJECT
public:
    TestProject();
private slots:
    void testProject();
};

#endif // TESTPROJECT_H
