#ifndef MYFRAME_H
#define MYFRAME_H

#include <QFrame>
#include <QObject>
#include <QDebug>
#include <QMetaProperty>
#include <QVector>
#include <QVBoxLayout>
#include "janela.h"

class MyFrame : public QFrame
{
    Q_OBJECT
    const QMetaObject *m;
    QVBoxLayout *layout;
    QString nome;
public:
    MyFrame(QWidget *parent, const char *tipo, const char *nome);
public slots:
    ///Recebido quando a variável anterior é alterada
    /// altera o número de objetos no frame
    void nChanged(int n);
    ///Gera o formulário interno
    QWidget *newBox(QString text);
};

#endif // MYFRAME_H
