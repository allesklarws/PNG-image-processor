#include "mainwindow.h"

void MainWindow::layout_Set()
{
// Layouts
    QVBoxLayout *vLy = new QVBoxLayout;
    QVBoxLayout *vLy_left = new QVBoxLayout;
    QHBoxLayout *hLy_hsl_h = new QHBoxLayout;
    QHBoxLayout *hLy_hsl_s = new QHBoxLayout;
    QHBoxLayout *hLy_hsl_l = new QHBoxLayout;
    QHBoxLayout *hLy_prof = new QHBoxLayout;
    GBleft = new QGroupBox;
    split = new QSplitter;
    // Menu
    mMenubar = new QMenuBar;
    mMenubar->setFixedHeight(24);
    mFile = new QMenu;
    mFile = mMenubar->addMenu(tr("&File"));
    mOpen = new QAction ("&Open",this);
    mOpen->setShortcut(tr("Ctrl+O"));
    mSave = new QAction ("&Save",this);
    mSave->setShortcut(tr("Ctrl+S"));
    mSavePfl = new QAction("&Save profile",this);
    mSavePfl->setShortcut(tr("Ctrl+P"));
    mQuit = new QAction ("&Exit",this);
    mQuit->setShortcut(tr("Ctrl+Q"));
    mFile->addAction(mOpen);
    mFile->addAction(mSave);
    mFile->addAction(mSavePfl);
    mFile->addAction(mQuit);

    mImage = new QMenu;
    mImage = mMenubar->addMenu(tr("&Image"));
	mDrift = new QAction ("&Image drifting",this);
    mColorCal = new QAction ("&Color calibration",this);
    mBin = new QAction ("&Binning",this);
    mOffset = new QAction ("&Offset",this);
    mGrey = new QAction("Grey",this);
    mCut = new QAction("Crop",this);
	mImage->addAction(mDrift);
    mImage->addAction(mColorCal);
    mImage->addAction(mBin);
    mImage->addAction(mOffset);
    mImage->addAction(mGrey);
    mImage->addAction(mCut);

    //Pattern
    mPattern = new QMenu;
    mPattern = mMenubar->addMenu(tr("&Pattern"));
    mBoard = new QAction ("&Board-Generator",this);
    mPattern->addAction(mBoard);

//
    mView = new QMenu;
    mView = mMenubar->addMenu(tr("&View"));
    mZoomin = new QAction ("&Zoom in",this);
    mZoomin->setShortcut(tr("Ctrl++"));
    mZoomout = new QAction ("&Zoom out",this);
    mZoomout->setShortcut(tr("Ctrl+-"));
    mView->addAction(mZoomin);
    mView->addAction(mZoomout);

    mAbout = new QMenu;
    mAbout = mMenubar->addMenu(tr("&About"));
    mInfo = new QAction ("&Info",this);
    mAbout->addAction(mInfo);

    vLy->addWidget(mMenubar);

    customPlot_hori = new QCustomPlot;
    customPlot_verti = new QCustomPlot;

    reloadImg = new QPushButton ("Reload Image");
    resetHsl = new QPushButton("Reset HSL");
    reloadImg->setFixedWidth(100);
    hue_name = new QLabel("Hue: "); satur_name=new QLabel("Saturation: "); light_name=new QLabel("Brightness: ");
    hue_slid = new QSlider(Qt::Horizontal); hue_slid->setRange(0,360);
    satur_slid = new QSlider(Qt::Horizontal); satur_slid->setRange(0,100);
    brig_slid = new QSlider(Qt::Horizontal); brig_slid->setRange(0,100);
    hLy_hsl_h->addWidget(hue_name); hLy_hsl_h->addWidget(hue_slid);
    hLy_hsl_s->addWidget(satur_name); hLy_hsl_s->addWidget(satur_slid);
    hLy_hsl_l->addWidget(light_name); hLy_hsl_l->addWidget(brig_slid);

    // profile GUI
    prof_coord = new QLabel("Profile(w,h):");
    prof_width = new QLineEdit;
    prof_height = new QLineEdit;
    prof_do = new QPushButton("plot");
    hLy_prof->addWidget(prof_coord);
    hLy_prof->addWidget(prof_width);
    hLy_prof->addWidget(prof_height);
    hLy_prof->addWidget(prof_do);

    vLy_left->addWidget(reloadImg);
    vLy_left->addLayout(hLy_hsl_h);
    vLy_left->addLayout(hLy_hsl_s);
    vLy_left->addLayout(hLy_hsl_l);
    vLy_left->addWidget(resetHsl);
    vLy_left->addLayout(hLy_prof);
    vLy_left->addWidget(customPlot_hori);
    vLy_left->addWidget(customPlot_verti);


    imgWin = new QLabel("Image box");
    imgWin->setBackgroundRole(QPalette::Base);
    imgWin->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Ignored);
    imgWin->setScaledContents(false);
    scrollArea = new QScrollArea;
    scrollArea->setBackgroundRole(QPalette::Dark);
    scrollArea->setWidget(imgWin);

    logging = new QPlainTextEdit;
    GBleft->setLayout(vLy_left);
    split->addWidget(GBleft);
    split->addWidget(scrollArea);
    split->addWidget(logging);
    vLy->addWidget(split);
    this->setLayout(vLy);
}
