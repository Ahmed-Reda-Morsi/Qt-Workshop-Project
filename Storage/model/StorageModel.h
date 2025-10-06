#ifndef STORAGEMODEL_H
#define STORAGEMODEL_H

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

class StorageModel : public QObject
{
    Q_OBJECT

public:
    explicit StorageModel(QObject *parent = nullptr);

    bool save_tasks(const QVector<TaskInfo> &tasks) const;
    QVector<TaskInfo> load_tasks() const;

private:
    QString m_filePath;
};

#endif // STORAGEMODEL_H
