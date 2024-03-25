#include "widget.h"
#include "form.h"
#include "./ui_widget.h"
#include <QTimer>
#include <QElapsedTimer>
#include <QTime>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    flag = 0;//初始化时钟为暂停

    setFocusPolicy( Qt::StrongFocus ); // 窗口将通过鼠标点击、按tab键等方式获取焦点

    this->setWindowFlags(Qt::FramelessWindowHint);//需要去掉标题栏
    this->setAttribute(Qt::WA_TranslucentBackground);
    this->setStyleSheet("#centralWidget{background:rgba(0,255,255,0.4);}"
                        "#label{background:rgba(255,255,0,1);}"
                        "#widget{background:rgba(0,255,255,1);}");
//    this->setStyleSheet("background-color: transparent;");
    this->setWindowFlags(this->windowFlags() | Qt::WindowStaysOnTopHint);

    time = new QTime();
    time->setHMS(0,0,30);

    w2 = new Form;
    w2->hide();

    ui->setupUi(this);
    m_timer_counter = new QTimer(this);
    m_timer_counter->stop();
    m_timer_counter->setTimerType(Qt::VeryCoarseTimer);
    m_timer = new QTimer(this);
    m_timer->stop();
    m_timer->setTimerType(Qt::VeryCoarseTimer);
    connect(m_timer,&QTimer::timeout,this,&Widget::do_timer_timeout);
    connect(m_timer_counter,&QTimer::timeout,this,&Widget::do_timer_counter_timeout);
    connect(w2,SIGNAL(newSetTimeSig(int,int,int)),this,SLOT(SetTime(int,int,int)));
}

Widget::~Widget()
{
    delete ui;
}


void Widget::do_timer_timeout()
{
    *time = time->addMSecs(-1000);
    if(time->hour() == 0 && time->minute() == 0 && time->second() == 0){
        m_timer_counter->stop();
        m_timer->stop();
        flag = 0;
    }
    if(time->hour() == 0){
        ui->lcdh->setHidden(1);
        if(time->minute() == 0){
            ui->lcdm->setHidden(1);
        }
    }
    ui->lcdh->display(time->hour());
    ui->lcdm->display(time->minute());
    ui->lcds->display(time->second());
}

void Widget::on_pushButton_clicked()
{
    //m_timer->start(1);
}


void Widget::on_start_clicked()
{
    if(flag == 0){
        m_timer->start(1000);
        m_timer_counter->start((time->hour()*3600+time->minute()*60+time->second())*1000);
        flag = 1;
        return;
    }
    else{
        m_timer->stop();
        m_timer_counter->stop();
        flag = 0;
        return;
    }
}

void Widget::do_timer_counter_timeout(){
    QApplication::beep();
}

void Widget::on_pushButton_2_clicked()
{
    w2->show();

}

void Widget::SetTime(int h,int m,int s){
    time->setHMS(h,m,s);
    ui->lcdh->setHidden(0);
    ui->lcdm->setHidden(0);
    ui->lcds->setHidden(0);
    ui->lcdh->display(time->hour());
    ui->lcdm->display(time->minute());
    ui->lcds->display(time->second());
}

void Widget::keyPressEvent(QKeyEvent* event){
    if (event->modifiers() == Qt::ControlModifier && event->key() == Qt::Key_S) {
        w2->show();
    } else if(event->modifiers() == Qt::ControlModifier && event->key() == Qt::Key_A){
        if(flag == 0){
            m_timer->start(1000);
            m_timer_counter->start((time->hour()*3600+time->minute()*60+time->second())*1000);
            flag = 1;
            return;
        }
        else{
            m_timer->stop();
            m_timer_counter->stop();
            flag = 0;
            return;
        }
    }
    else if(event->modifiers() == Qt::ControlModifier && event->key() == Qt::Key_Z){
        this->close();
    }
    else{
        QWidget::keyPressEvent(event); // 调用基类的keyPressEvent以处理其他按键事件
    }
}

