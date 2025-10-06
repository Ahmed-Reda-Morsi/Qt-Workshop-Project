#ifndef STORAGECONTROLLER_H
#define STORAGECONTROLLER_H

#include <QObject>
#include <QVector>
#include <QString>
#include "StorageModel.h"

class StorageController : public QObject
{
    Q_OBJECT

public:
    explicit StorageController(QObject *parent = nullptr);

    void load_tasks();
    void save_tasks() const;

    void add_task(const TaskInfo &task);
    void delete_task(int index);
    void edit_task(int index,const TaskInfo &task);
    void task_status_changed(int index);

    const QVector<TaskInfo>& tasks() const;

private:
    QVector<TaskInfo> m_tasks;
    StorageModel m_model;

};

#endif // STORAGECONTROLLER_H
