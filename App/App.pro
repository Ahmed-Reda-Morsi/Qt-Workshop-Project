QT += widgets
TEMPLATE = app
CONFIG += c++17
TARGET = TaskManagerLite

HEADERS += \
    mainwindow.h

SOURCES += \
    main.cpp \
    mainwindow.cpp

FORMS += \
    mainwindow.ui


# Add include paths for all modules
INCLUDEPATH += ../TaskManager/model \
               ../TaskManager/view \
               ../TaskManager/controller \
               ../Storage/controller \
               ../Storage/model \
               ../Storage/view

LIBS += -L$$OUT_PWD/../TaskManager -lTaskManager \
        -L$$OUT_PWD/../Storage -lStorage
