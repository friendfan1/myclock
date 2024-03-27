#include "widget.h"

#include <QApplication>
#include <QScreen>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    QScreen *screen = QGuiApplication::primaryScreen ();
    QRect screenRect =  screen->availableVirtualGeometry();
    int dWidth = screenRect.width();
    //int dHeight = screenRect.height();//桌面大小
    w.move(dWidth- w.width(),0);
    w.show();
    return a.exec();
}


