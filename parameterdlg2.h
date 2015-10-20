#ifndef PARAMETERDLG2_H
#define PARAMETERDLG2_H
#include <QDialog>
#include <QtWidgets>

class parameterDLG2: public QWidget
{

public:
    parameterDLG2();
    QImage crop_func(QImage xImg,QLineEdit *w,QLineEdit *h,QLineEdit *xpos, QLineEdit *ypos);
    QLabel *width_lab, *height_lab, *x_pos, *y_pos;
    QLineEdit *width_tx, *height_tx, *xpos_tx, *ypos_tx;
    QPushButton *ok_func;

};

#endif // PARAMETERDLG2_H
