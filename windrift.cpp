#include "windrift.h"

WinDrift::WinDrift()
{
    drift_step_lb = new QLabel(tr("Pixel step: "));
    drift_ms_lb = new QLabel(tr("Speed in ms: "));
    drift_step = new QLineEdit;
    drift_ms = new QLineEdit;
    drift_Button = new QPushButton(tr("Start"));
    drift_Stop = new QPushButton(tr("Stop"));

    QHBoxLayout *hLy_1 = new QHBoxLayout;
    QHBoxLayout *hLy_2 = new QHBoxLayout;
    QHBoxLayout *hLy_3 = new QHBoxLayout;
    hLy_1->addWidget(drift_step_lb);
    hLy_1->addWidget(drift_step);
    hLy_2->addWidget(drift_ms_lb);
    hLy_2->addWidget(drift_ms);
    hLy_3->addWidget(drift_Button);
    hLy_3->addWidget(drift_Stop);

    QVBoxLayout *vLy_drift = new QVBoxLayout;
    vLy_drift->addLayout(hLy_1);
    vLy_drift->addLayout(hLy_2);
    vLy_drift->addLayout(hLy_3);
    this->setLayout(vLy_drift);

}


