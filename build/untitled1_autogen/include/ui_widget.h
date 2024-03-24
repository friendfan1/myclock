/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QLCDNumber *lcdh;
    QLCDNumber *lcdm;
    QLCDNumber *lcds;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(149, 40);
        lcdh = new QLCDNumber(Widget);
        lcdh->setObjectName("lcdh");
        lcdh->setGeometry(QRect(0, 0, 51, 41));
        lcdh->setFrameShape(QFrame::NoFrame);
        lcdh->setFrameShadow(QFrame::Plain);
        lcdh->setDigitCount(2);
        lcdh->setSegmentStyle(QLCDNumber::Flat);
        lcdm = new QLCDNumber(Widget);
        lcdm->setObjectName("lcdm");
        lcdm->setGeometry(QRect(50, 0, 51, 41));
        lcdm->setFrameShape(QFrame::NoFrame);
        lcdm->setFrameShadow(QFrame::Plain);
        lcdm->setLineWidth(1);
        lcdm->setDigitCount(2);
        lcdm->setProperty("intValue", QVariant(0));
        lcds = new QLCDNumber(Widget);
        lcds->setObjectName("lcds");
        lcds->setGeometry(QRect(100, 0, 51, 41));
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lcds->sizePolicy().hasHeightForWidth());
        lcds->setSizePolicy(sizePolicy);
        lcds->setFrameShape(QFrame::NoFrame);
        lcds->setFrameShadow(QFrame::Plain);
        lcds->setDigitCount(2);

        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
