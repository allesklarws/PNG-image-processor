#include "color_win.h"

color_win::color_win()
{
    label_color_func = new QLabel("Color calibration:");
    ok_color_func = new QPushButton("Calc");
    model = new QStandardItemModel(3,3,this);
    color_table = new QTableView();
    model->setHorizontalHeaderItem(0,new QStandardItem(QString("R-Col")));
    model->setHorizontalHeaderItem(1,new QStandardItem(QString("G-Col")));
    model->setHorizontalHeaderItem(2,new QStandardItem(QString("B-Col")));
    color_table->setModel(model);

    QHBoxLayout *color_hly = new QHBoxLayout;
    color_hly->addWidget(label_color_func);
    color_hly->addWidget(color_table);
    color_hly->addWidget(ok_color_func);
    this->setLayout(color_hly);
}


