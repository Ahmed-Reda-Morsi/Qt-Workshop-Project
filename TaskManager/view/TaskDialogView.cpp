#include "TaskDialogView.h"
#include "ui_TaskDialog.h"
#include <QMessageBox>

TaskDialog::TaskDialog(QWidget *parent)
    : QDialog(parent),
      ui(new Ui::TaskDialog)
{
    ui->setupUi(this);

    ui->task_date_line->setDate(QDate::currentDate());

    // Validate before accept
    // connect(ui->ok_button, &QDialogButtonBox::accepted, this, [this]() {
    //     if (ui->task_name_line->text().trimmed().isEmpty()) {
    //         QMessageBox::warning(this, "Invalid Input", "Task name cannot be empty.");
    //         return;
    //     }
    //     accept();
    // });

    // connect(ui->cancel_button, &QDialogButtonBox::rejected, this, &TaskDialog::reject);
}

TaskDialog::~TaskDialog()
{
    delete ui;
}

QString TaskDialog::taskName() const
{
    return ui->task_name_line->text().trimmed();
}

QDate TaskDialog::dueDate() const
{
    return ui->task_date_line->date();
}
