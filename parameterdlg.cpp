#include "parameterdlg.h"

parameterDLG::parameterDLG(int choose)
{
    if (choose == 0){
        label_func = new QLabel("Offset:");
    }
    else label_func = new QLabel("Binning:");

    text_func = new QLineEdit;
    ok_func = new QPushButton("Calc");

    QHBoxLayout *hly = new QHBoxLayout;
    hly->addWidget(label_func);
    hly->addWidget(text_func);
    hly->addWidget(ok_func);
    this->setLayout(hly);
}
