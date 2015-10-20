#ifndef PARAMETERDLG_H
#define PARAMETERDLG_H
#include <QDialog>
#include <QtWidgets>

class parameterDLG: public QWidget
{

public:
    parameterDLG(int choose);

    // binning and offset
    QLabel *label_func;
    QLineEdit *text_func;
    QPushButton *ok_func;

};

#endif // PARAMETERDLG_H
