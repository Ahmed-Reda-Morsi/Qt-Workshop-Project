#include <QDialog>

namespace Ui {
class TaskDialog;
}

#define MENMUM_TASK_NAME_SIZE 5;

class TaskDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TaskDialog(QWidget *parent = nullptr);
    ~TaskDialog();

    QString get_task_name() const;
    QDate   get_task_due_date() const;

    void    set_task_name(QString& name) ;
    void    set_task_due_date( QDate due_date);

    bool    task_name_changed();

private:

    Ui::TaskDialog *ui;

};
