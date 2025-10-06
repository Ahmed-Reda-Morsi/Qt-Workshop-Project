#include "StorageController.h"
#include <QDir>
#include <QDebug>

StorageController::StorageController(QObject *parent)
    : QObject(parent)
{
    load_tasks();
}

void StorageController::load_tasks()
{
    m_tasks = m_model.load_tasks();
}

void StorageController::save_tasks() const
{
    m_model.save_tasks(m_tasks);
}

void StorageController::add_task(const TaskInfo &task)
{
    m_tasks.append(task);
    save_tasks();
}

void StorageController::edit_task(int index, const TaskInfo &task)
{
    if (index >= 0 && index < m_tasks.size()) {
        m_tasks.replace(index,task);
        
    }
    save_tasks();

}
void StorageController::delete_task(int index)
{
    if (index >= 0 && index < m_tasks.size()) {
        m_tasks.removeAt(index);
    }
    save_tasks();
}

void StorageController::task_status_changed(int index)
{
    if (index >= 0 && index < m_tasks.size()) {
        m_tasks[index].status = !m_tasks[index].status;
    }
    save_tasks();
}

const QVector<TaskInfo>& StorageController::tasks() const
{
    return m_tasks;
}
