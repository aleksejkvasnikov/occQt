QT       += core gui opengl xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = occQt
TEMPLATE = app

SOURCES += main.cpp \
    draw/box.cpp \
    draw/cone.cpp \
    draw/cylinder.cpp \
    draw/drawableobject.cpp \
    draw/sphere.cpp \
    draw/torus.cpp \
    objectparamsform.cpp \
    occQt.cpp       \
    occView.cpp \
    draw/project.cpp

CONFIG += c++14

HEADERS  += \
    draw/box.h \
    draw/cone.h \
    draw/cylinder.h \
    draw/drawableobject.h \
    draw/sphere.h \
    draw/torus.h \
    objectparamsform.h \
    occQt.h \
    occView.h \
    draw/project.h

FORMS    += \
    objectparamsform.ui \
    occQt.ui

RESOURCES += \
    occqt.qrc

CASROOT = $$(CASROOTPATH)
CASINCLUDE = $$(CASINCLUDE)
isEmpty (CASROOT) {
    CASROOT = D:/CASCADE/CASROOT
}
isEmpty (CASINCLUDE) {
    CASINCLUDE = D:/CASCADE/CASROOT/include/opencascade
}

win32 {
DEFINES +=  \
    WNT
INCLUDEPATH +=  \
    $$CASROOT/inc

    win32-msvc2010 {
        compiler=vc10
    }

    win32-msvc2012 {
        compiler=vc11
    }

    win32-msvc2013 {
        compiler=vc12
    }

    win32-msvc2015 {
        compiler=vc14
    }
    win32-msvc2017 {
        compiler=vc15
    }
    win32-msvc2019 {
        compiler=vc16
    }
    win32-msvc {
        compiler=vc15
    }

    !contains(QMAKE_TARGET.arch, x86_64) {
        CONFIG(debug, debug|release) {
            message("Debug 32 build")
            LIBS += -L$$CASROOT/win32/$$compiler/libd
        }
        else {
            message("Release 32 build")
            LIBS += -L$$CASROOT/win32/$$compiler/lib
        }
    }
    else {
        CONFIG(debug, debug|release) {
            message("Debug 64 build")
            LIBS += -L$$CASROOT/win64/$$compiler/libd
        }
        else {
            message("Release 64 build")
            LIBS += -L$$CASROOT/win64/$$compiler/lib
        }
    }
}

linux-g++ {
    INCLUDEPATH +=  \
        $$CASINCLUDE

    LIBS +=         \
        -L$$CASROOT/lib
}

LIBS +=         \
    -lTKernel   \
    -lTKMath    \
    -lTKG3d     \
    -lTKBRep    \
    -lTKGeomBase\
    -lTKGeomAlgo\
    -lTKTopAlgo \
    -lTKPrim    \
    -lTKBO      \
    -lTKBool    \
    -lTKOffset  \
    -lTKService \
    -lTKV3d     \
    -lTKOpenGl  \
    -lTKFillet
