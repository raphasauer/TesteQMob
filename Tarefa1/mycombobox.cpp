#include "mycombobox.h"

MyComboBox::MyComboBox(QWidget *parent, QMetaProperty *m, void *p) : QComboBox(parent)
{
    connect(this, SIGNAL(currentIndexChanged(int)), this, SLOT(setValue(int)));
    mP = m;
    obj = p;

    if(mP)
    {
        numb = m->enumerator();
        int n = numb.keyCount();

        for(int i = 0; i < n; i++)
            insertItem(i, numb.key(i));
    }
}

void MyComboBox::setValue(int x)
{
    if(mP)
        mP->writeOnGadget(obj, x);
}
