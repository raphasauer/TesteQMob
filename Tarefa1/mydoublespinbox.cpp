#include "mydoublespinbox.h"

MyDoubleSpinBox::MyDoubleSpinBox(QWidget *parent, QMetaProperty *m, void *p) : QDoubleSpinBox(parent)
{
    connect(this, SIGNAL(valueChanged(double)), this, SLOT(setValue(double)));
    mP = m;
    obj = p;
}

void MyDoubleSpinBox::setValue(double x)
{
    float y = (float) x;

    if(mP)
        mP->writeOnGadget(obj, y);
}


