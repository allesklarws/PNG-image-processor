#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets>
#include <QImage>
#include <QString>
#include <qmath.h>
#include "qcustomplot.h"
#include "parameterdlg.h"
#include "parameterdlg2.h"
#include "color_win.h"
#include "pattern_make.h"
#include "windrift.h"

class MainWindow : public QWidget
{
    Q_OBJECT
    
public:
    MainWindow(QWidget *parent = 0);
    void layout_Set();
    void parameter_Set();
    QVector<double> prof_hori_R,prof_hori_G,prof_hori_B,prof_verti_R,prof_verti_G,prof_verti_B;

public slots:
    void drifting();
    void one_drift();
    void colorcalib_func();
    void offset_func();
    void binning_func();
    void grey_func();
    void do_crop();
    void hsl();
    void resetHsl_func();
    void board();
    void zoom_in();
    void zoom_out();
    void plot_func();
    void imgOpen();
    void imgSave();
    void profilSave();
    void reloadImg_func();
    void info();

private:
    // variables
    int r,g,b;
    double bin_factor;
    int bin_w, bin_h;
    double zoom_fac;
    double zoom_help;
    int h_old, s_old, l_old, h_new, s_new, l_new;
    int drift_ms_var, step_val;	// for image drifting
    // Menu
    QMenuBar *mMenubar;
    QMenu *mFile,*mImage,*mPattern,*mView,*mAbout;
    QAction *mOpen,*mSave,*mSavePfl, *mQuit,*mDrift,*mColorCal,*mBin,*mOffset,*mGrey,*mCut,*mBoard,*mZoomin,*mZoomout,*mInfo;
    QPushButton *reloadImg,*resetHsl, *prof_do;
    QLabel *imgWin,*prof_coord;
    QLineEdit *prof_width, *prof_height;
    QLabel *hue_name, *satur_name, *light_name;
    QPlainTextEdit *logging;
    QSlider *hue_slid, *satur_slid, *brig_slid;
    QImage img_orig;
    QImage img_new, img_zoom, img_temp,xImg,newImg,img_plot;
    QRgb pixel, pixel_new;
    QString filePath;

    QGroupBox *GBleft;
    QSplitter *split;
    QScrollArea *scrollArea;

    QMessageBox msgBox;

    // parameter windows
    parameterDLG *offset_Win, *bin_Win;
    parameterDLG2 *crop_Win;
    color_win *colorcalib_Win;	
	WinDrift *windrift_Obj;

	//Timer
    QTimer *timer_drift;
	
    //Plotting
    QCustomPlot *customPlot_hori, *customPlot_verti;

    QColor Color;

    //pattern
    pattern_make *muster;

};

#endif // MAINWINDOW_H
