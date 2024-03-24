#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "form.h"
#include <QKeyEvent>

//#include "ui_form.h"

class QTimer;
class QEslapsedTimer;

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT
private:
    QTimer *m_timer;
    QTimer *m_timer_counter;
    QEslapsedTimer *m_counter;
    QTime *time;
    bool flag;
public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    Form *w2;

public slots:
    void do_timer_timeout();
private slots:
    void on_pushButton_clicked();

    void on_start_clicked();

    void do_timer_counter_timeout();
    void on_pushButton_2_clicked();

    void SetTime(int h, int m, int s);
    void keyPressEvent(QKeyEvent *event);
private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
