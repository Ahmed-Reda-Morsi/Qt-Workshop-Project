#include <QWidget>
#include "TaskController.h"

namespace Ui {
class TaskManager;
}

class TaskManagerView : public QWidget
{
    Q_OBJECT

public:
    explicit TaskManagerView(QWidget *parent = nullptr);
    ~TaskManagerView();

    void add_task();
    void edit_task();
    void delete_task();

private:
    Ui::TaskManager *ui;

};
