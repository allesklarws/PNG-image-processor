#ifndef PATTERN_MAKE_H
#define PATTERN_MAKE_H
#include <QtWidgets>

// For Chessboard and Lineboard
class pattern_make:public QWidget
{
public:
    pattern_make();

public:
    QPushButton *ok_func;
    QRadioButton *invert;
    QLabel *prn_w_text, *prn_h_text, *prn_wpos_text, *prn_hpos_text,*block_size_w_text,*block_size_h_text,*invert_text;
    QLabel *color1_text, *color2_text;
    QLineEdit *prn_w, *prn_h,*prn_wpos,*prn_hpos, *block_size_w,*block_size_h;
    QLineEdit *c1_r,*c1_g,*c1_b,*c2_r,*c2_g,*c2_b;

};

#endif // PATTERN_MAKE_H
