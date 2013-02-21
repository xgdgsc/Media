#-------------------------------------------------
#
# Project created by QtCreator 2012-03-27T13:57:13
#
#-------------------------------------------------

QT       += core gui opengl

TARGET = DIPfundamental
TEMPLATE = app


SOURCES += main.cpp\
    libs.cpp \
    fundamental.cpp \
    point.cpp \
    point_ui.cpp \
    qwtdialog.cpp \
    lineartrans.cpp \
    anticolor.cpp \
    threhold.cpp \
    histonorm.cpp \
    algebraic_ui.cpp \
    algebraic.cpp \
    geometry.cpp \
    geometry_ui.cpp \
    affine.cpp \
    morphological_ui.cpp \
    morphological.cpp \
    neighbor_ui.cpp \
    neighbor.cpp \
    report.cpp \
    2DDCT.cpp \
    2Dblocks_ui.cpp

HEADERS  += \
    fundamental.h \
    libs.h \
    point.h \
    qwtdialog.h \
    lineartrans.h \
    anticolor.h \
    threhold.h \
    histonorm.h \
    algebraic_ui.h \
    algebraic.h \
    geometry.h \
    geometry_ui.h \
    affine.h \
    morphological_ui.h \
    morphological.h \
    neighbor_ui.h \
    neighbor.h \
    report.h \
    2DDCT.h

FORMS    += mainwindow.ui \
    qwtdialog.ui \
    lineartrans.ui \
    anticolor.ui \
    threhold.ui \
    histonorm.ui \
    algebraic.ui \
    geometry.ui \
    affine.ui \
    morphological.ui \
    neighbor.ui \
    report.ui
win32 {
            INCLUDEPATH+="D:/Program Files/opencv/include/opencv"
            INCLUDEPATH+="D:/Program Files/qwt/include"
            #QMAKE_LFLAGS += -static-libgcc -static-libstdc++
            LIBS+="D:/Program Files/opencv/build/x86/mingw/lib/libopencv_core241.dll.a"
            LIBS+="D:/Program Files/opencv/build/x86/mingw/lib/libopencv_highgui241.dll.a"
            LIBS+="D:/Program Files/opencv/build/x86/mingw/lib/libopencv_imgproc241.dll.a"
            LIBS+="D:/Program Files/qwt/lib/libqwt.a"
            DEPENDPATH+="D:/Program Files/opencv/build/x86/mingw/bin"
            DEPENDPATH+="D:/Program Files/qwt/lib/"
}

unix {
            INCLUDEPATH+=/usr/include/qwt
            LIBS+= -static-libgcc -static-libstdc++ -lGLU -lopencv_core -lopencv_highgui -lopencv_imgproc -lqwt
}

RESOURCES += \
    icon.qrc
