QT += core
TEMPLATE = lib
CONFIG += staticlib c++17
TARGET = Storage

HEADERS += \
    controller/StorageController.h \
    model/StorageModel.h

SOURCES += \
    controller/StorageController.cpp \
    model/StorageModel.cpp
    
# Expose include dirs to other modules
INCLUDEPATH += model controller
