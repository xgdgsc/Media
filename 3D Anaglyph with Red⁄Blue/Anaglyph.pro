#-------------------------------------------------
#
# Project created by QtCreator 2012-06-21T10:29:35
#
#-------------------------------------------------

QT       += core gui

TARGET = Anaglyph
TEMPLATE = app


SOURCES += main.cpp\
        anaglyph.cpp \
    libs.cpp \
    show.cpp

HEADERS  += anaglyph.h \
    libs.h \
    show.h

FORMS    += anaglyph.ui \
    show.ui

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
            DEPENDPATH+="D:/QtSDK/Desktop/Qt/4.8.1/mingw/bin"
}

unix {
            INCLUDEPATH+=/usr/include/qwt
            LIBS+= -static-libgcc -static-libstdc++ -lGLU -lopencv_core -lopencv_highgui -lopencv_imgproc -lqwt
}
