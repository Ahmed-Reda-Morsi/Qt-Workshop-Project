#include "TaskController.h"
#include "StorageController.h"
#include <QDir>
#include <QDebug>

TaskController::TaskController(QObject *parent)
    : QObject(parent)
{
    m_storageController.load_tasks();
}

void TaskController::load_tasks()
{
    m_storageController.load_tasks();
}

void TaskController::save_tasks() const
{
    m_storageController.save_tasks();
}

void TaskController::add_task(const TaskInfo &task)
{
   m_storageController.add_task(task);
}

void TaskController::edit_task(int index, const TaskInfo &task)
{
    m_storageController.edit_task(index,task);

}
void TaskController::delete_task(int index)
{
  m_storageController.delete_task(index);
}

void TaskController::task_status_changed(int index)
{
    m_storageController.task_status_changed(index);
}

const QVector<TaskInfo>& TaskController::tasks() const
{
    return m_storageController.tasks();
}
