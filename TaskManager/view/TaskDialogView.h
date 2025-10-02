#include <QDialog>
#include <QDate>

namespace Ui {
class TaskDialog;
}

class TaskDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TaskDialog(QWidget *parent = nullptr);
    ~TaskDialog();

    QString taskName() const;
    QDate dueDate() const;

private:
    Ui::TaskDialog *ui;
};