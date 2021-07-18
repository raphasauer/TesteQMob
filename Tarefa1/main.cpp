#include "gadget.h"
#include "janela.h"

#include <QApplication>
#include <QDebug>
#include <QMetaObject>
#include <QMetaProperty>
#include <QVariant>
#include <QWidget>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qRegisterMetaType<Player>();
    qRegisterMetaType<P2D>();

    Player p;
    janela j(&p, "Player");
    j.show();

    return a.exec();
}
