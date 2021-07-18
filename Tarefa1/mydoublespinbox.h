#ifndef MYDOUBLESPINBOX_H
#define MYDOUBLESPINBOX_H

#include <QObject>
#include <QDoubleSpinBox>
#include <QDebug>
#include <QMetaProperty>

class MyDoubleSpinBox : public QDoubleSpinBox
{
    Q_OBJECT
    QMetaProperty *mP;
    void *obj;
public:
    ///Gera uma DoubleSpinBox para a metapropriedade especificada
    MyDoubleSpinBox(QWidget *parent, QMetaProperty *m = nullptr, void *p = nullptr);
public slots:
    ///Recebe o valor definido pelo usuário e escreve no objeto
    void setValue(double x);
};

#endif // MYDOUBLESPINBOX_H
