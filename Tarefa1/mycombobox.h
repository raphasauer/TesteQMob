#ifndef MYCOMBOBOX_H
#define MYCOMBOBOX_H

#include <QObject>
#include <QMetaProperty>
#include <QComboBox>
#include <QMetaEnum>
#include <QDebug>

class MyComboBox : public QComboBox
{
    Q_OBJECT
    QMetaProperty *mP;
    void *obj;
    QMetaEnum numb;
public:
    ///Gera uma ComboBox com os valores especificados no enumarador
    MyComboBox(QWidget *parent, QMetaProperty *m = nullptr, void *p = nullptr);
public slots:
    ///Recebe o valor definido pelo usuário e escreve no objeto
    void setValue(int x);
};

#endif // MYCOMBOBOX_H
