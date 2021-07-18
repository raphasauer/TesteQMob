#include "janela.h"


janela::janela(void *ptr, const char *nomeTipo) : QWidget(nullptr)
{
    //Define o ID do meta objeto e o acessa pelo nome
    int typeId = QMetaType::type(nomeTipo);
    const QMetaObject *mo = QMetaType::metaObjectForType(typeId);
    obj = ptr;
    M = mo;

    setWindowTitle(mo->className());

    QHBoxLayout *layout = new QHBoxLayout(this);
    QScrollArea *scrollArea = new QScrollArea(this);
    scrollArea->setWidgetResizable(true);
    QWidget *scrollAreaConteudo = new QWidget;

    QFormLayout *form = new QFormLayout(scrollAreaConteudo);

    int n = mo->propertyCount();

    for(int i = 0; i < n; i++)
    {
        mp = mo->property(i);
        QLabel *label = new QLabel(mp.name());

        QWidget *objeto = objectByType(mp.type(), scrollAreaConteudo, &mp, obj);

        //Caso o resultado de ObjectType seja null,
        // quer dizer que o tipo é um ponteiro, logo
        // cria um formulário interno
        if(objeto != nullptr)
            form->addRow(label, objeto);
        else
        {
            MyFrame *frame = new MyFrame(scrollAreaConteudo, mp.typeName(), mp.name());
            QWidget *x = form->itemAt(i-1, QFormLayout::FieldRole)->widget();
            connect(x, SIGNAL(valueChanged(int)), frame, SLOT(nChanged(int)));

            form->addRow(label, frame);
        }
    }

    scrollAreaConteudo->setLayout(form);
    scrollArea->setWidget(scrollAreaConteudo);
    layout->addWidget(scrollArea);
}

QWidget *janela::objectByType(int tipo, QWidget *parent, QMetaProperty *p, void *OBJ)
{
    QWidget *objeto = nullptr;

    if(tipo == 36 or tipo == 37)
        objeto = new MySpinBox(parent, p, OBJ);
    else if(tipo == 38)
        objeto = new MyDoubleSpinBox(parent, p, OBJ);
    else if(tipo == 1)
        objeto = new MyCheckBox(parent, p, OBJ);
    else if(tipo == 2)
        objeto = new MyComboBox(parent, p, OBJ);

    return objeto;
}
