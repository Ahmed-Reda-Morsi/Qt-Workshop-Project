#include "TaskManagerView.h"
#include "qheaderview.h"
#include "ui_TaskManager.h"
#include "TaskDialogView.h"
#include <QMessageBox>
#include <QTableWidgetItem>

TaskManagerView::TaskManagerView(QWidget *parent)
    : QWidget(parent),
    ui(new Ui::TaskManager)
{
    ui->setupUi(this);

    ui->TaskTable->setColumnCount(3);
    ui->TaskTable->setHorizontalHeaderLabels({"Task Name  ", "  Due Date   ", "  Done  "});

    // Stretch Task Name to take available space
    ui->TaskTable->horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);
    ui->TaskTable->horizontalHeader()->setSectionResizeMode(1, QHeaderView::ResizeToContents);
    ui->TaskTable->horizontalHeader()->setSectionResizeMode(2, QHeaderView::ResizeToContents);

    // Single row selection only
    ui->TaskTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->TaskTable->setSelectionMode(QAbstractItemView::SingleSelection);

    // No inline editing, must use dialog
    ui->TaskTable->setEditTriggers(QAbstractItemView::NoEditTriggers);



    ui->edit_task->setDisabled(true);
    ui->delete_task->setDisabled(true);

    connect(ui->TaskTable, &QTableWidget::itemSelectionChanged, this, [this]() {
        bool hasSelection = ui->TaskTable->currentRow() >= 0;
        ui->edit_task->setEnabled(hasSelection);
        ui->delete_task->setEnabled(hasSelection);
    });


    connect(ui->add_task, &QPushButton::clicked, this, &TaskManagerView::add_task);
    connect(ui->delete_task, &QPushButton::clicked, this, &TaskManagerView::delete_task);

}


void TaskManagerView::add_task()
{
    qDebug() << "Add task button clicked!";  // add this line

    TaskDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted) {

    }

    int row = ui->TaskTable->rowCount();
    ui->TaskTable->insertRow(row);

    // Task name
    QTableWidgetItem *nameItem = new QTableWidgetItem("name");
    ui->TaskTable->setItem(row, 0, nameItem);

    // Due date
    QTableWidgetItem *dateItem = new QTableWidgetItem("due");
    ui->TaskTable->setItem(row, 1, dateItem);

    // Done (checkbox)
    QTableWidgetItem *doneItem = new QTableWidgetItem();
    doneItem->setCheckState(Qt::Unchecked);
    doneItem->setFlags(doneItem->flags() | Qt::ItemIsUserCheckable);
    ui->TaskTable->setItem(row, 2, doneItem);

}



void TaskManagerView::edit_task()
{

}

void TaskManagerView::delete_task()
{
    int row = ui->TaskTable->currentRow();
    if (row >= 0) {
        ui->TaskTable->removeRow(row);
    }
}

TaskManagerView::~TaskManagerView()
{
    delete ui;
}
