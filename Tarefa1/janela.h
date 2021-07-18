#ifndef JANELA_H
#define JANELA_H

#include <QWidget>
#include <QMetaType>
#include <QPointer>
#include <QHBoxLayout>
#include <QScrollArea>
#include <QFormLayout>
#include <QLabel>
#include <QSpinBox>
#include <QDebug>
#include <QMetaProperty>
#include "gadget.h"
#include "myspinbox.h"
#include "mydoublespinbox.h"
#include "mycheckbox.h"
#include "mycombobox.h"
#include "myframe.h"

using namespace std;

class janela : public QWidget
{
    Q_OBJECT
    ///Armazena a QMetaProperty sendo examinada
    QMetaProperty mp;
    ///Armazena um ponteiro para um gadget
    void *obj;
    ///Armazena um ponteiro para o QMetaObject sendo examinado
    const QMetaObject *M;
public:
    ///Gera o formulário baseado no ponteiro do objeto e no nome do tipo
    janela(void *ptr, const char *nomeTipo);
    ///Gera um objeto dado o seu tipo
    static QWidget *objectByType(int tipo, QWidget *parent, QMetaProperty *p = nullptr, void *OBJ = nullptr);

signals:
};

#endif // JANELA_H
