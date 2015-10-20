#include "parameterdlg2.h"

parameterDLG2::parameterDLG2()
{
    width_lab = new QLabel("Width:");
    height_lab = new QLabel("Height:");
    x_pos = new QLabel("Width Position:");
    y_pos = new QLabel("Height Position:");


    width_tx = new QLineEdit;
    height_tx = new QLineEdit;
    xpos_tx = new QLineEdit;
    ypos_tx = new QLineEdit;
    ok_func = new QPushButton("Calc");

    QHBoxLayout *hly_wid = new QHBoxLayout;
    hly_wid->addWidget(width_lab);
    hly_wid->addWidget(width_tx);
    QHBoxLayout *hly_heig = new QHBoxLayout;
    hly_heig->addWidget(height_lab);
    hly_heig->addWidget(height_tx);
    QHBoxLayout *hly_xpos = new QHBoxLayout;
    hly_xpos->addWidget(x_pos);
    hly_xpos->addWidget(xpos_tx);
    QHBoxLayout *hly_ypos = new QHBoxLayout;
    hly_ypos->addWidget(y_pos);
    hly_ypos->addWidget(ypos_tx);


    QVBoxLayout *vly = new QVBoxLayout;
    vly->addLayout(hly_wid);
    vly->addLayout(hly_heig);
    vly->addLayout(hly_xpos);
    vly->addLayout(hly_ypos);
    vly->addWidget(ok_func);
    this->setLayout(vly);
}

QImage parameterDLG2::crop_func(QImage xImg, QLineEdit *w, QLineEdit *h, QLineEdit *xpos, QLineEdit *ypos)
{

      QImage newImg(w->text().toInt(), h->text().toInt(), QImage::Format_RGB32);
      QColor oldColor;
      for(int y = ypos->text().toInt(); y<h->text().toInt()+ypos->text().toInt(); y++)
      {        for(int x = xpos->text().toInt(); x<w->text().toInt()+xpos->text().toInt(); x++)
          {
              oldColor = QColor(xImg.pixel(x,y));
              newImg.setPixel(x-xpos->text().toInt(),y-ypos->text().toInt(),qRgb(oldColor.red(),oldColor.green(),oldColor.blue()));
          }
      }
      return newImg;
}
