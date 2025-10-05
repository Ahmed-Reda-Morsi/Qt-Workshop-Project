#include "TaskController.h"
#include <QDir>
#include <QDebug>

TaskController::TaskController(QObject *parent)
    : QObject(parent)
{
    load_tasks();
}
TaskController::~TaskController()
{
    save_tasks();
}

void TaskController::load_tasks()
{
    m_tasks = m_model.load_tasks();
}

void TaskController::save_tasks() const
{
    m_model.save_tasks(m_tasks);
}

void TaskController::add_task(const TaskInfo &task)
{
    m_tasks.append(task);
    save_tasks();
}

void TaskController::edit_task(int index, const TaskInfo &task)
{
    if (index >= 0 && index < m_tasks.size()) {
        m_tasks.replace(index,task);
    }
}
void TaskController::delete_task(int index)
{
    if (index >= 0 && index < m_tasks.size()) {
        m_tasks.removeAt(index);
    }
}

void TaskController::task_status_changed(int index)
{
    if (index >= 0 && index < m_tasks.size()) {
        m_tasks[index].status = !m_tasks[index].status;
    }
}

const QVector<TaskInfo>& TaskController::tasks() const
{
    return m_tasks;
}
