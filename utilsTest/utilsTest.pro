#-------------------------------------------------
#
# Project created by QtCreator 2018-07-12T22:01:46
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_utilstest
CONFIG   += console \
            c++14
CONFIG   -= app_bundle

TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        tst_utilstest.cpp

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../utils/release/ -lutils
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../utils/debug/ -lutils
else:unix: LIBS += -L$$OUT_PWD/../utils/ -lutils

INCLUDEPATH += $$PWD/../utils
DEPENDPATH += $$PWD/../utils

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../utils/release/libutils.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../utils/debug/libutils.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../utils/release/utils.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../utils/debug/utils.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../utils/libutils.a

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../testUtils/release/ -ltestUtils
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../testUtils/debug/ -ltestUtils
else:unix: LIBS += -L$$OUT_PWD/../testUtils/ -ltestUtils

INCLUDEPATH += $$PWD/../testUtils
DEPENDPATH += $$PWD/../testUtils

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../testUtils/release/libtestUtils.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../testUtils/debug/libtestUtils.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../testUtils/release/testUtils.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../testUtils/debug/testUtils.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../testUtils/libtestUtils.a
