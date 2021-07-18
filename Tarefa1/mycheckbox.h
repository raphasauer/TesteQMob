#ifndef MYCHECKBOX_H
#define MYCHECKBOX_H

#include <QObject>
#include <QMetaProperty>
#include <QCheckBox>
#include <QDebug>

class MyCheckBox : public QCheckBox
{
    Q_OBJECT
    QMetaProperty *mP;
    void *obj;
public:
    ///Gera uma checkbox com os parâmetros fornecidos
    MyCheckBox(QWidget *parent, QMetaProperty *m = nullptr, void *p = nullptr);
public slots:
    ///Recebe o valor definido pelo usuário e escreve no objeto
    void setValue(int x);
};

#endif // MYCHECKBOX_H
