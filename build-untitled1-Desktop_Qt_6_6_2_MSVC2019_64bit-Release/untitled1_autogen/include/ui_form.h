/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QPushButton *pushButton;
    QLineEdit *sh;
    QLineEdit *sm;
    QLineEdit *ss;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName("Form");
        Form->resize(216, 115);
        pushButton = new QPushButton(Form);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(60, 70, 93, 28));
        sh = new QLineEdit(Form);
        sh->setObjectName("sh");
        sh->setGeometry(QRect(20, 20, 31, 31));
        sm = new QLineEdit(Form);
        sm->setObjectName("sm");
        sm->setGeometry(QRect(90, 20, 31, 31));
        ss = new QLineEdit(Form);
        ss->setObjectName("ss");
        ss->setGeometry(QRect(160, 20, 31, 31));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QCoreApplication::translate("Form", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("Form", "Yes", nullptr));
        sh->setText(QCoreApplication::translate("Form", "0", nullptr));
        sm->setText(QCoreApplication::translate("Form", "0", nullptr));
        ss->setText(QCoreApplication::translate("Form", "0", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
