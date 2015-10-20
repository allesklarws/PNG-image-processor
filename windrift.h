#ifndef WINDRIFT_H
#define WINDRIFT_H

#include <QtWidgets>

class WinDrift:public QWidget
{
    Q_OBJECT
public:
    WinDrift();

public:
    QPushButton *drift_Button;
    QPushButton *drift_Stop;
    QLabel *drift_step_lb;
    QLabel *drift_ms_lb;
    QLineEdit *drift_step;
    QLineEdit *drift_ms;

};

#endif // WINDRIFT_H
