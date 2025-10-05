#ifndef TASKCONTROLLER_H
#define TASKCONTROLLER_H

#include <QObject>
#include <QVector>
#include <QString>
#include "TaskModel.h"

class TaskController : public QObject
{
    Q_OBJECT

public:
    explicit TaskController(QObject *parent = nullptr);
    ~TaskController();

    void load_tasks();
    void save_tasks() const;

    void add_task(const TaskInfo &task);
    void delete_task(int index);
    void edit_task(int index,const TaskInfo &task);
    void task_status_changed(int index);

    const QVector<TaskInfo>& tasks() const;

private:
    QVector<TaskInfo> m_tasks;
    TaskModel m_model;

};

#endif // TASKCONTROLLER_H
