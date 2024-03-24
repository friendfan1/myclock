#include "form.h"

#include "ui_form.h"

Form::Form(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Form)
{
    ui->setupUi(this);
}

Form::~Form()
{
    delete ui;
}

void Form::on_pushButton_clicked()
{
    this->hours = ui->sh->text().toInt();
    this->mins = ui->sm->text().toInt();
    this->secs = ui->ss->text().toInt();
    this->hide();
    emit newSetTimeSig(hours,mins,secs);
}
