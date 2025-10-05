#include "TaskDialogView.h"
#include "ui_TaskDialog.h"
#include <QMessageBox>

TaskDialog::TaskDialog(QWidget *parent)
    : QDialog(parent),
    ui(new Ui::TaskDialog)
{
    ui->setupUi(this);
    ui->task_date_line->setDate(QDate::currentDate());
    ui->ok_button->setDisabled(true);



    connect(ui->task_name_line,&QLineEdit::textChanged,this,&TaskDialog::task_name_changed);
    connect(ui->ok_button, &QPushButton::clicked, this, &QDialog::accept);
    connect(ui->cancel_button, &QPushButton::clicked, this, &QDialog::reject);
}

bool TaskDialog::task_name_changed()
{
    QString text = ui->task_name_line->text().trimmed();

    // Regex: starts with a letter, then letters/numbers/underscores only
    static const QRegularExpression validPattern("^[A-Za-z][A-Za-z0-9_]*$");

    bool valid = validPattern.match(text).hasMatch() && text.size()>= MENMUM_TASK_NAME_SIZE;

    ui->ok_button->setEnabled(valid);
    return valid;
}



TaskDialog::~TaskDialog()
{
    delete ui;
}

QString TaskDialog::get_task_name() const
{
    return ui->task_name_line->text().trimmed();
}

QDate TaskDialog::get_task_due_date() const
{
    return ui->task_date_line->date();
}

void TaskDialog::set_task_name(QString& name)
{
    ui->task_name_line->setText(name);
}
void TaskDialog::set_task_due_date(QDate due_date)
{
     ui->task_date_line->setDate(due_date);
}
