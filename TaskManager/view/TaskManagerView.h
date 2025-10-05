#include <QWidget>
#include "TaskController.h"
#include "TaskDialogView.h"

namespace Ui {
class TaskManager;
}

class TaskManagerView : public QWidget
{
    Q_OBJECT

public:
    explicit TaskManagerView(QWidget *parent = nullptr);
    ~TaskManagerView();

private slots:
    void add_task();
    void edit_task();
    void delete_task();
    void task_status_changed();
    void update_task_manager_table();
    void edit_task_row(int row, TaskInfo &task);
    void add_new_task_row(TaskInfo &task);
private:
    TaskController m_controller;
    Ui::TaskManager *ui;


};
