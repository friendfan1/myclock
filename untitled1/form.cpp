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

void Form::keyPressEvent(QKeyEvent* event){
    if(event->key() == Qt::Key_Return){
        //qDebug() << "yes";
        this->hours = ui->sh->text().toInt();
        this->mins = ui->sm->text().toInt();
        this->secs = ui->ss->text().toInt();
        this->hide();
        emit newSetTimeSig(hours,mins,secs);
    }
    else{
        QWidget::keyPressEvent(event); // 调用基类的keyPressEvent以处理其他按键事件
    }
}
