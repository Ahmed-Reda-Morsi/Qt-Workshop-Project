#include "TaskManagerView.h"
#include "qheaderview.h"
#include "ui_TaskManager.h"
#include "TaskController.h"
#include <QMessageBox>
#include <QTableWidgetItem>


#define TASK_NAME_INDEX          0
#define TASK_DUE_DATE_INDEX      1
#define TASK_DONE_STAUS_INDEX    2

TaskManagerView::TaskManagerView(QWidget *parent)
    : QWidget(parent),
    ui(new Ui::TaskManager)
{
    ui->setupUi(this);

    ui->TaskTable->setColumnCount(3);
    ui->TaskTable->setHorizontalHeaderLabels({"Task Name  ", "  Due Date   ", "  Done  "});

    // Stretch Task Name to take available space
    ui->TaskTable->horizontalHeader()->setSectionResizeMode(TASK_NAME_INDEX, QHeaderView::Stretch);
    ui->TaskTable->horizontalHeader()->setSectionResizeMode(TASK_DUE_DATE_INDEX, QHeaderView::ResizeToContents);
    ui->TaskTable->horizontalHeader()->setSectionResizeMode(TASK_DONE_STAUS_INDEX, QHeaderView::ResizeToContents);

    // Single row selection only
    ui->TaskTable->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->TaskTable->setSelectionMode(QAbstractItemView::SingleSelection);

    // No inline editing, must use dialog
    ui->TaskTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->edit_task->setDisabled(true);
    ui->delete_task->setDisabled(true);

    connect(ui->TaskTable, &QTableWidget::itemSelectionChanged, this, [this]() {
        bool has_election = ui->TaskTable->currentRow() >= 0;
        if(has_election){
            ui->edit_task->setEnabled(has_election);
            ui->delete_task->setEnabled(has_election);
            auto current_task_status= ui->TaskTable->item(ui->TaskTable->currentRow(),TASK_DONE_STAUS_INDEX);
            if (current_task_status)
            {    current_task_status->setFlags(current_task_status->flags() | Qt::ItemIsEnabled | Qt::ItemIsUserCheckable );
                ui->TaskTable->viewport()->update();
            }
        }
    });

    connect(ui->add_task, &QPushButton::clicked,
            this, &TaskManagerView::add_task);
    connect(ui->delete_task, &QPushButton::clicked,
            this, &TaskManagerView::delete_task);
    connect(ui->edit_task, &QPushButton::clicked,
            this, &TaskManagerView::edit_task);
    connect(ui->TaskTable, &QTableWidget::itemChanged,
            this, &TaskManagerView::task_status_changed);
    connect(ui->TaskTable, &QTableWidget::itemChanged,
            this, &TaskManagerView::task_status_changed);

    //load existed tasks
    update_task_manager_table();
}


void TaskManagerView::add_task()
{
    TaskDialog dialog(this);

    if (dialog.exec() == QDialog::Accepted) {

        TaskInfo task;
        task.name = dialog.get_task_name();
        task.due_date = dialog.get_task_due_date();
        task.status =false;

        add_new_task_row(task);
        m_controller.add_task(task);

    }

}



void TaskManagerView::edit_task()
{
    int row = ui->TaskTable->currentRow();
    if (row >= 0) {

        auto current_task = m_controller.tasks().at(row);
        TaskDialog dialog(this);

        dialog.set_task_name(current_task.name);
        dialog.set_task_due_date(current_task.due_date);

        if (dialog.exec() == QDialog::Accepted) {
            TaskInfo task;
            task.name = dialog.get_task_name();
            task.due_date = dialog.get_task_due_date();
            task.status =false;

            m_controller.edit_task(row,task);
        }

    }

}

void TaskManagerView::delete_task()
{
    int row = ui->TaskTable->currentRow();
    if (row >= 0) {
        ui->TaskTable->removeRow(row);
        m_controller.delete_task(row);

    }
}

TaskManagerView::~TaskManagerView()
{
    delete ui;

}

void TaskManagerView::update_task_manager_table()
{
    for(auto task:m_controller.tasks())
    {
        add_new_task_row(task);
    }
}


void TaskManagerView::add_new_task_row(TaskInfo &task){

    int row = ui->TaskTable->rowCount();
    ui->TaskTable->insertRow(row);
    // Task name
    QTableWidgetItem *name_item = new QTableWidgetItem(task.name);
    ui->TaskTable->setItem(row, TASK_NAME_INDEX, name_item);

    // Due date
    QTableWidgetItem *date_item = new QTableWidgetItem(task.due_date.toString());
    ui->TaskTable->setItem(row, TASK_DUE_DATE_INDEX, date_item);

    // Done status
    QTableWidgetItem *status_item = new QTableWidgetItem();
    if (task.status==true)
    {
        status_item->setCheckState(Qt::Checked);
    }
    else
    {
        status_item->setCheckState(Qt::Unchecked);
    }
    status_item->setFlags(status_item->flags() & ~Qt::ItemIsEnabled);
    ui->TaskTable->setItem(row, TASK_DONE_STAUS_INDEX, status_item);

}


void TaskManagerView::task_status_changed()
{
    int row = ui->TaskTable->currentRow();
    if (row >= 0) {
        auto current_task_status= ui->TaskTable->item(row,TASK_DONE_STAUS_INDEX);
        auto current_task = m_controller.tasks().at(row);
        Qt::CheckState saved_status;
        current_task.status==true? saved_status=Qt::Checked:saved_status=Qt::Unchecked ;

        if (current_task_status->checkState() !=saved_status)
        {
              m_controller.task_status_changed(row);
        }
      
    }

}
