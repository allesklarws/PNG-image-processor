´#ifndef COLOR_WIN_H
#define COLOR_WIN_H
#include <QDialog>
#include <QtWidgets>

class color_win:public QWidget
{
public:
    color_win();

    QLabel *label_color_func;
    QPushButton *ok_color_func;

    //color calibration
    QTableView *color_table;
    QStandardItemModel *model;

};

#endif // COLOR_WIN_H
