#-------------------------------------------------
#
# Project created by QtCreator 2014-03-31T15:41:37
#
#-------------------------------------------------

QT       += core gui sensors widgets androidextras

TARGET = Ball
TEMPLATE = app
CONFIG += c++11


SOURCES +=	main.cpp\
		mainwindow.cpp \
		ball.cpp \
		scene.cpp \
		view.cpp \
		timecounter.cpp \
		pointcounter.cpp

HEADERS  +=	mainwindow.h \
		ball.h \
		scene.h \
		view.h \
		timecounter.h \
    		pointcounter.h

CONFIG += mobility
MOBILITY = 

ANDROID_PACKAGE_SOURCE_DIR = $$PWD/android

OTHER_FILES += android/AndroidManifest.xml

RESOURCES += res.qrc

