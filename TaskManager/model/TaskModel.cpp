#include "TaskModel.h"
#include <QFileInfo>
#include <QDir>
#include <QDebug>
#include <QCoreApplication>

TaskModel::TaskModel(QObject *parent)
    : QObject(parent)
{
    QString baseDir = QCoreApplication::applicationDirPath();
    m_filePath = QDir(baseDir).filePath("../../../data/tasks.ini");

}

bool TaskModel::save_tasks(const QVector<TaskInfo> &tasks) const
{
    QSettings settings(m_filePath, QSettings::IniFormat);
    settings.clear(); // Clear previous structure

    int index = 1;
    for (const auto &task : tasks) {
        QString groupName = QString("Tasks_%1").arg(index++);
        settings.beginGroup(groupName);

        settings.setValue("name", task.name);
        settings.setValue("due", task.due_date);
        settings.setValue("status", task.status);

        settings.endGroup();
    }

    // Check for errors
    if (settings.status() != QSettings::NoError) {
        qWarning() << "Failed to save tasks to" << m_filePath
                   << "Error code:" << settings.status();
        return false;
    }

    qDebug() << "Changes Saved";
    return true;
}

QVector<TaskInfo> TaskModel::load_tasks() const
{
    QVector<TaskInfo> loaded_tasks;
    if (!QFileInfo::exists(m_filePath))
        return loaded_tasks;

    QSettings settings(m_filePath, QSettings::IniFormat);

    const QStringList groups = settings.childGroups();
    for (const QString &group : groups) {
        if (!group.startsWith("Tasks_"))
            continue;

        settings.beginGroup(group);

        TaskInfo task;
        task.name = settings.value("name").toString();
        task.due_date = settings.value("due").toDate();
        task.status = settings.value("status").toBool();

        settings.endGroup();
        loaded_tasks.append(task);
    }


    qDebug() << "Loaded" << loaded_tasks.size() << "tasks from" << m_filePath;
    return loaded_tasks;
}
