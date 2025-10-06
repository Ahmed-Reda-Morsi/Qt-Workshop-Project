QT += widgets core
TEMPLATE = lib
CONFIG += staticlib c++17
TARGET = TaskManager

HEADERS += \
    controller/TaskController.h \
    controller/StorageController.h \
    view/TaskManagerView.h \ 
    view/TaskDialogView.h  \

SOURCES += \
    controller/TaskController.cpp \
    view/TaskManagerView.cpp \ 
    view/TaskDialogView.cpp

FORMS += \
    TaskManager.ui \ 
    TaskDialog.ui

# Expose include dirs to other modules
INCLUDEPATH += view controller ../Storage/controller ../Storage/model
