#ifndef FORM_H
#define FORM_H

#include <QWidget>
#include <QKeyEvent>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();


    //int *GetHMS();
private slots:
    void on_pushButton_clicked();
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::Form *ui;
    //int* HMS;
    int hours;
    int mins;
    int secs;

signals:
    void newSetTimeSig(int h,int m,int s);
};

#endif // FORM_H
