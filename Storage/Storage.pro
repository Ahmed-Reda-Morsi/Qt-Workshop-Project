QT += core
TEMPLATE = lib
CONFIG += staticlib c++17
TARGET = Storage

HEADERS += \
    controller/TaskStorage.h
    model/storagemodel.h
    view/storageview.h

SOURCES += \
    controller/TaskStorage.cpp
    model/storagemodel.cpp
    view/storageview.cpp
    
# Expose include dirs to other modules
INCLUDEPATH += model controller
