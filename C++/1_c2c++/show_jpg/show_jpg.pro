TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

INCLUDEPATH += ./jpeg-9.0/include

LIBPATH     += ./jpeg-9.0/lib
LIBS        += -ljpeg
LIBS        += -Wl,-rpath=./jpeglib/lib
