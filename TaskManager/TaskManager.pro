QT += widgets core
TEMPLATE = lib
CONFIG += staticlib c++17
TARGET = TaskManager

HEADERS += \
    controller/TaskController.h \
    model/TaskModel.h \
    view/TaskManagerView.h \ 
    view/TaskDialogView.h  \

SOURCES += \
    controller/TaskController.cpp \
    model/TaskModel.cpp \
    view/TaskManagerView.cpp \ 
    view/TaskDialogView.cpp

FORMS += \
    TaskManager.ui \ 
    TaskDialog.ui

# Expose include dirs to other modules
INCLUDEPATH += model view controller ../Storage/controller
