#
# VLC-Qt Simple Player
# Copyright (C) 2015 Tadej Novak <tadej@tano.si>
#

TARGET      = simple-player
TEMPLATE    = app
CONFIG 	   += c++11

QT         += widgets

SOURCES    += main.cpp \
    SimplePlayer.cpp

HEADERS    += SimplePlayer.h

FORMS      += SimplePlayer.ui

#Debug
unix:!macx|win32: LIBS += -L$$PWD/VLCd/lib/ -llibVLCQtCored.dll
unix:!macx|win32: LIBS += -L$$PWD/VLCd/lib/ -llibVLCQtWidgetsd.dll

#Release
#unix:!macx|win32: LIBS += -L$$PWD/VLC/lib/ -llibVLCQtCore.dll
#unix:!macx|win32: LIBS += -L$$PWD/VLC/lib/ -llibVLCQtWidgets.dll

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include
