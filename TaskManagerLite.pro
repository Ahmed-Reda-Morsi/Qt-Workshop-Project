TEMPLATE = subdirs
CONFIG += ordered

SUBDIRS = Storage TaskManager App

TaskManager.depends = Storage
App.depends = TaskManager Storage
