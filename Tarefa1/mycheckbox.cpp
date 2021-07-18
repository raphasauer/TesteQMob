#include "mycheckbox.h"

MyCheckBox::MyCheckBox(QWidget *parent, QMetaProperty *m, void *p)
{
    connect(this, SIGNAL(stateChanged(int)), this, SLOT(setValue(int)));
    mP = m;
    obj = p;
}

void MyCheckBox::setValue(int x)
{
    if(mP)
        x ? mP->writeOnGadget(obj, true) : mP->writeOnGadget(obj, false);
}


