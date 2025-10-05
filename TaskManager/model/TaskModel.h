#ifndef TASKMODEL_H
#define TASKMODEL_H

#include <QObject>
#include <QVector>
#include <QString>
#include <QDate>
#include <QSettings>

struct TaskInfo {
    QString name;
    QDate due_date;
    bool status;
};

class TaskModel : public QObject
{
    Q_OBJECT

public:
    explicit TaskModel(QObject *parent = nullptr);

    bool save_tasks(const QVector<TaskInfo> &tasks) const;
    QVector<TaskInfo> load_tasks() const;

private:
    QString m_filePath;
};

#endif // TASKMODEL_H
