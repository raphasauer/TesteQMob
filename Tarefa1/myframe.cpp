#include "myframe.h"

MyFrame::MyFrame(QWidget *parent, const char *tipo, const char *nome) : QFrame(parent)
{
    QString s = tipo;
    s.remove(s.size()-1, 1);
    this->nome = nome;

    layout = new QVBoxLayout;

    int id = QMetaType::type(s.toLatin1());
    m = QMetaType::metaObjectForType(id);

    this->setLayout(layout);
}

void MyFrame::nChanged(int n)
{
    if(n > layout->count())
    {
        int k = n - layout->count();

        while(k--)
            layout->addWidget(newBox(nome + " " + QString::number(layout->count())));
    }
    else
    {
        for(int i = layout->count()-1; i >= n; i--)
        {
            QWidget *w = layout->itemAt(i)->widget();
            layout->removeWidget(w);
            delete w;
        }
    }
}

QWidget *MyFrame::newBox(QString text)
{
    QMetaProperty p;
    int n = m->propertyCount();

    QWidget *w = new QWidget(this);
    QHBoxLayout *hLayout = new QHBoxLayout(w);

    QWidget *conteudo = new QWidget(w);
    QVBoxLayout *l = new QVBoxLayout(conteudo);

    for(int i = 0; i < n; i++)
    {
        p = m->property(i);
        QWidget *objeto = janela::objectByType(p.type(), conteudo);

        if(objeto)
            l->addWidget(objeto);
    }

    conteudo->setLayout(l);

    QLabel *label = new QLabel(w);
    label->setText(text);

    hLayout->addWidget(label);
    hLayout->addWidget(conteudo);

    return w;
}
