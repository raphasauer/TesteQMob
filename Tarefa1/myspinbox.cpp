#include "myspinbox.h"

MySpinBox::MySpinBox(QWidget *parent, QMetaProperty *m, void *p) : QSpinBox(parent)
{
    connect(this, SIGNAL(valueChanged(int)), this, SLOT(setValue(int)));
    mP = m;
    obj = p;
}

void MySpinBox::setValue(int x)
{
    if(mP)
        mP->writeOnGadget(obj, x);
}
