#include "pattern_make.h"

pattern_make::pattern_make()
{
    color1_text = new QLabel("1.Color:");
    color2_text = new QLabel("2.Color:");
    prn_w_text = new QLabel("Image width: ");
    prn_h_text = new QLabel("Image height: ");
    prn_wpos_text = new QLabel("Disp.width: ");
    prn_hpos_text = new QLabel("Disp.height: ");
    block_size_w_text = new QLabel("Block size width: ");
    block_size_h_text = new QLabel("Block size height: ");
    invert_text = new QLabel("Invert color: ");

    c1_r=new QLineEdit;c1_g=new QLineEdit;c1_b=new QLineEdit;
    c2_r=new QLineEdit;c2_g=new QLineEdit;c2_b=new QLineEdit;
    prn_w= new QLineEdit;
    prn_h = new QLineEdit;
    prn_wpos = new QLineEdit;
    prn_hpos = new QLineEdit;
    invert = new QRadioButton;

    block_size_w = new QLineEdit;
    block_size_h = new QLineEdit;
    ok_func = new QPushButton("Calc");

    QHBoxLayout *hly_c1 = new QHBoxLayout;
    hly_c1->addWidget(color1_text);
    hly_c1->addWidget(c1_r);hly_c1->addWidget(c1_g);hly_c1->addWidget(c1_b);
    QHBoxLayout *hly_c2 = new QHBoxLayout;
    hly_c2->addWidget(color2_text);
    hly_c2->addWidget(c2_r);hly_c2->addWidget(c2_g);hly_c2->addWidget(c2_b);
    QHBoxLayout *hly_w = new QHBoxLayout;
    hly_w->addWidget(prn_w_text);
    hly_w->addWidget(prn_w);
    QHBoxLayout *hly_h = new QHBoxLayout;
    hly_h->addWidget(prn_h_text);
    hly_h->addWidget(prn_h);
    QHBoxLayout *hly_wpos = new QHBoxLayout;
    hly_wpos->addWidget(prn_wpos_text);
    hly_wpos->addWidget(prn_wpos);
    QHBoxLayout *hly_hpos = new QHBoxLayout;
    hly_hpos->addWidget(prn_hpos_text);
    hly_hpos->addWidget(prn_hpos);
    QHBoxLayout *hly_block_w = new QHBoxLayout;
    hly_block_w->addWidget(block_size_w_text);
    hly_block_w->addWidget(block_size_w);
    QHBoxLayout *hly_block_h = new QHBoxLayout;
    hly_block_h->addWidget(block_size_h_text);
    hly_block_h->addWidget(block_size_h);
    QHBoxLayout *hly_radioB = new QHBoxLayout;
    hly_radioB->addWidget(invert_text);
    hly_radioB->addWidget(invert);

    QVBoxLayout *vly = new QVBoxLayout;
    vly->addLayout(hly_c1);
    vly->addLayout(hly_c2);
    vly->addLayout(hly_w);
    vly->addLayout(hly_h);
    vly->addLayout(hly_wpos);
    vly->addLayout(hly_hpos);
    vly->addLayout(hly_block_w);
    vly->addLayout(hly_block_h);
    vly->addLayout(hly_radioB);
    vly->addWidget(ok_func);
    this->setLayout(vly);
    this->setFixedWidth(200);
}


