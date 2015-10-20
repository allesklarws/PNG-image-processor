#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{    
	windrift_Obj = new WinDrift;
    timer_drift = new QTimer;
    colorcalib_Win = new color_win;
    offset_Win = new parameterDLG(0);
    bin_Win = new parameterDLG(1);
    crop_Win = new parameterDLG2;
    muster = new pattern_make;


// settings
    layout_Set();
    parameter_Set();
// connections
    connect(mOpen,SIGNAL(triggered()),SLOT(imgOpen()));   
    connect(mSave,SIGNAL(triggered()),SLOT(imgSave()));
    connect(mSavePfl,SIGNAL(triggered()),SLOT(profilSave()));
    connect(mQuit,SIGNAL(triggered()),this,SLOT(close()));
    connect(reloadImg,SIGNAL(clicked()),SLOT(reloadImg_func()));
	// image drifting
	connect(mDrift,SIGNAL(triggered()),windrift_Obj,SLOT(show()));
	connect(windrift_Obj->drift_Button,SIGNAL(clicked()),SLOT(drifting()));
    connect(windrift_Obj->drift_Stop,SIGNAL(clicked()),timer_drift,SLOT(stop()));
	
    //color calibration
    connect(mColorCal,SIGNAL(triggered()),colorcalib_Win,SLOT(show()));
    connect(colorcalib_Win->ok_color_func,SIGNAL(clicked()),SLOT(colorcalib_func()));
    //offset
    connect(mOffset,SIGNAL(triggered()),offset_Win,SLOT(show()));
    connect(offset_Win->ok_func,SIGNAL(clicked()),SLOT(offset_func()));
    //binning
    connect(mBin,SIGNAL(triggered()),bin_Win,SLOT(show()));
    connect(bin_Win->ok_func,SIGNAL(clicked()),SLOT(binning_func()));
    // grey image
    connect(mGrey,SIGNAL(triggered()),SLOT(grey_func()));
    // crop
    connect(mCut,SIGNAL(triggered()),crop_Win,SLOT(show()));
    connect(crop_Win->ok_func,SIGNAL(clicked()),SLOT(do_crop()));
    // HSL
    connect(hue_slid,SIGNAL(valueChanged(int)),SLOT(hsl()));
    connect(satur_slid,SIGNAL(valueChanged(int)),SLOT(hsl()));
    connect(brig_slid,SIGNAL(valueChanged(int)),SLOT(hsl()));
    connect(resetHsl,SIGNAL(clicked()),SLOT(resetHsl_func()));
    // Pattern
    connect(mBoard,SIGNAL(triggered()),muster,SLOT(show()));
    connect(muster->ok_func,SIGNAL(clicked()),SLOT(board()));
    //Info
    connect(mInfo,SIGNAL(triggered()),SLOT(info()));
    //Zoom
    connect(mZoomin,SIGNAL(triggered()),SLOT(zoom_in()));
    connect(mZoomout,SIGNAL(triggered()),SLOT(zoom_out()));
    //plot test
    connect(prof_do,SIGNAL(clicked()),SLOT(plot_func()));
}

void MainWindow::imgOpen()
{
    filePath= QFileDialog::getOpenFileName();
    img_orig.load(filePath);
    img_new= img_orig.copy();
    imgWin->setPixmap(QPixmap::fromImage(img_new));
    imgWin->setFixedSize(img_new.size());
    logging->appendPlainText("image size: " + QString::number(img_orig.width())+"*"+ QString::number(img_orig.height()));
}

void MainWindow::imgSave()
{
    filePath= QFileDialog::getSaveFileName(this,tr("save file"),"",tr("Images (*.png);;Text files (*.txt)"));
    QFile tbd(filePath);
    img_new.save(&tbd);
}

void MainWindow::reloadImg_func()
{
    imgWin->setPixmap(QPixmap::fromImage(img_orig));
    img_new=img_orig.copy();
    zoom_fac=1;
    parameter_Set();
    imgWin->setFixedSize(img_new.size());
}

void MainWindow::info()
{
    msgBox.setWindowTitle("About this program");
    msgBox.setText("copy right 2014 by Shuai WANG\ncreated with QT");
    msgBox.setStandardButtons(QMessageBox::Yes);
    msgBox.setDefaultButton(QMessageBox::Yes);
    msgBox.exec();
}

