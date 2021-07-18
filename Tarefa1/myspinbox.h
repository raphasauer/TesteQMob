#ifndef MYSPINBOX_H
#define MYSPINBOX_H

#include <QObject>
#include <QSpinBox>
#include <QDebug>
#include <QMetaProperty>

class MySpinBox : public QSpinBox
{
    Q_OBJECT
    QMetaProperty *mP;
    void *obj;
public:
    ///Gera uma SpinBox com os parâmetros fornecidos
    MySpinBox(QWidget *parent, QMetaProperty *m = nullptr, void *p = nullptr);
public slots:
    ///Recebe o valor definido pelo usuário e escreve no objeto
    void setValue(int x);
};

#endif // MYSPINBOX_H
