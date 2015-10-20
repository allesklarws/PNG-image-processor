#include "mainwindow.h"

// Drifting functions
void MainWindow::drifting()
{
    logging->appendPlainText("drifting");
    drift_ms_var = windrift_Obj->drift_ms->text().toInt();
    connect(timer_drift, SIGNAL(timeout()), SLOT(one_drift()));
    timer_drift->start(drift_ms_var);
    logging->appendPlainText(QString::number(drift_ms_var));
}

void MainWindow::one_drift()
{
    QTime myTimer;
    int img_w, img_h;
    img_w = img_new.width();
    img_h = img_new.height();
    myTimer.start();
    int i,j,k;
    step_val= windrift_Obj->drift_step->text().toInt();
    for (i=0;i<img_h;i++)
    {
        for (k=0;k<step_val;k++) // steps
        {
            QRgb rgb_temp = img_new.pixel(0,i);
            for (j=1;j<img_w;j++)  // drift 1 pixel
            {
                img_new.setPixel(j-1,i,img_new.pixel(j,i));
                img_new.setPixel(img_w-1,i,rgb_temp);
            }
        }
    }
    imgWin->setPixmap(QPixmap::fromImage(img_new));
    int ms = myTimer.elapsed();
    logging->appendPlainText("Step: " + QString::number(step_val) + "   Speed ms: "+windrift_Obj->drift_ms->text()+"   Processing time: " +QString::number(ms));
    if (ms >= drift_ms_var)
    {

        logging->appendPlainText("process limited! "+QString::number(ms)+ "ms too large!");
    }

}
/////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////
void MainWindow::offset_func()
{
    for (int j=0; j<img_new.size().height();j++)
    {
        for(int i=0; i<img_new.size().width();i++)
        {
        pixel = img_new.pixel(i,j);
        r=qRed(pixel)+offset_Win->text_func->text().toDouble();
        g=qGreen(pixel)+offset_Win->text_func->text().toDouble();
        b=qBlue(pixel)+offset_Win->text_func->text().toDouble();
        pixel_new = qRgb(r,g,b);
        img_new.setPixel(i,j,pixel_new);       
        }
    }
        imgWin->setPixmap(QPixmap::fromImage(img_new));
        imgWin->setFixedSize(img_new.size());
}

void MainWindow::binning_func()
{
    bin_factor = bin_Win->text_func->text().toInt();
    bin_w = img_new.width()/bin_factor;
    bin_h = img_new.height()/bin_factor;
    img_temp=img_new.scaled(bin_w,bin_h,Qt::IgnoreAspectRatio);
    r =0, g =0, b =0;

    for (int j=0; j<bin_h;j++)
    {
        for(int i=0; i<bin_w;i++)
        {
            for(int m=bin_factor*j; m<bin_factor*(j+1) ;m++)
            {
                for(int n=bin_factor*i; n<bin_factor*(i+1) ;n++)
                {
                    r=r+qRed(img_new.pixel(n,m));
                    g=g+qGreen(img_new.pixel(n,m));
                    b=b+qBlue(img_new.pixel(n,m));
                }
            }
            r=r/pow(bin_factor,2); g=g/pow(bin_factor,2); b=b/pow(bin_factor,2);
            pixel_new= qRgb(r,g,b);
            img_temp.setPixel(i,j,pixel_new);
        }
    }
    img_new=img_temp.copy();
    imgWin->setPixmap(QPixmap::fromImage(img_new));
    imgWin->setFixedSize(img_new.size());
    logging->appendPlainText("image size binned: " + QString::number(img_new.width())+"*"+ QString::number(img_new.height()));
}

void MainWindow::grey_func()
{
    for (int j=0; j<img_new.size().height();j++)
    {
        for(int i=0; i<img_new.size().width();i++)
        {
        pixel = img_new.pixel(i,j);
        r=(qRed(pixel)+qGreen(pixel)+qBlue(pixel))/3;
        g=r;
        b=r;
        pixel_new = qRgb(r,g,b);
        img_new.setPixel(i,j,pixel_new);
        }
    }
    imgWin->setPixmap(QPixmap::fromImage(img_new));
    imgWin->setFixedSize(img_new.size());
}

void MainWindow::do_crop()
{
    img_new = crop_Win->crop_func(img_new,crop_Win->width_tx,crop_Win->height_tx,crop_Win->xpos_tx,crop_Win->ypos_tx).copy();
    imgWin->setPixmap(QPixmap::fromImage(img_new));
    imgWin->setFixedSize(img_new.size());
}

void MainWindow::colorcalib_func()
{

    for (int j=0; j<img_new.height();j++)
    {
        for(int i=0; i<img_new.width();i++)
        {
          r=qRed(img_new.pixel(i,j))*colorcalib_Win->model->data(colorcalib_Win->model->index(0,0)).toDouble()
           +qGreen(img_new.pixel(i,j))*colorcalib_Win->model->data(colorcalib_Win->model->index(0,1)).toDouble()
           +qBlue(img_new.pixel(i,j))*colorcalib_Win->model->data(colorcalib_Win->model->index(0,2)).toDouble();

          g=qRed(img_new.pixel(i,j))*colorcalib_Win->model->data(colorcalib_Win->model->index(1,0)).toDouble()
           +qGreen(img_new.pixel(i,j))*colorcalib_Win->model->data(colorcalib_Win->model->index(1,1)).toDouble()
           +qBlue(img_new.pixel(i,j))*colorcalib_Win->model->data(colorcalib_Win->model->index(1,2)).toDouble();

          b=qRed(img_new.pixel(i,j))*colorcalib_Win->model->data(colorcalib_Win->model->index(2,0)).toDouble()
           +qGreen(img_new.pixel(i,j))*colorcalib_Win->model->data(colorcalib_Win->model->index(2,1)).toDouble()
           +qBlue(img_new.pixel(i,j))*colorcalib_Win->model->data(colorcalib_Win->model->index(2,2)).toDouble();

            pixel_new= qRgb(r,g,b);
            img_new.setPixel(i,j,pixel_new);
        }
    }
    imgWin->setPixmap(QPixmap::fromImage(img_new));
    imgWin->setFixedSize(img_new.size());
}

void MainWindow::hsl()
{
    int h,s,l;
    h_new = hue_slid->value(); s_new = satur_slid->value(); l_new=brig_slid->value();

    for (int j=0; j<img_new.size().height();j++)
    {
        for(int i=0; i<img_new.size().width();i++)
        {
        Color = QColor(img_new.pixel(i,j));
        h=qBound(0,Color.hue()+h_new-h_old,360);
        s=qBound(0,Color.saturation()+s_new-s_old,255);
        l=qBound(0,Color.lightness()+l_new-l_old,100);
        Color.setHsl(h,s,l);
        img_new.setPixel(i,j,qRgb(Color.red(),Color.green(),Color.blue()));
        }
    }
        imgWin->setPixmap(QPixmap::fromImage(img_new));
        imgWin->setFixedSize(img_new.size());
        h_old=h_new; s_old=s_new; l_old=l_new;
}

void MainWindow::resetHsl_func()
{
    hue_slid->setValue(0);
    satur_slid->setValue(0);
    brig_slid->setValue(0);
}

void MainWindow::board()
{
    double w = muster->prn_w->text().toDouble();
    double h = muster->prn_h->text().toDouble();
    double bs_w = muster->block_size_w->text().toDouble();
    double bs_h = muster->block_size_h->text().toDouble();
    double bn_w= floor(w/bs_w)+2;
    double bn_h =floor(h/bs_h)+2;
    QColor color1, color2, temp;
    color1 = qRgb(muster->c1_r->text().toInt(),muster->c1_g->text().toInt(),muster->c1_b->text().toInt());
    color2 = qRgb(muster->c2_r->text().toInt(),muster->c2_g->text().toInt(),muster->c2_b->text().toInt());
    if ((muster->invert->isChecked())==true){
        temp.setRed(color2.red());temp.setGreen(color2.green());temp.setBlue(color2.blue());
        color2.setRed(color1.red());color2.setGreen(color1.green());color2.setBlue(color1.blue());
        color1.setRed(temp.red());color1.setGreen(temp.green());color1.setBlue(temp.blue());
    }
    QImage img_whole, img_end;
    QPixmap map_whole(bn_w*bs_w,bn_h*bs_h);map_whole.fill(Qt::white);
    img_whole=map_whole.toImage();

    for (int i=0;i<bn_h;i++){
        for(int j=i%2;j<bn_w;j+=2){
            for(int m=i*bs_h;m<(i+1)*bs_h;m++){
                for(int n=j*bs_w;n<(j+1)*bs_w;n++){
                   img_whole.setPixel(n,m,qRgb(color1.red(),color1.green(),color1.blue()));
                }
            }
        }
    }
    for (int i=0;i<bn_h;i++){
        for(int j=i%2-1;j<bn_w;j+=2){
            for(int m=i*bs_h;m<(i+1)*bs_h;m++){
                for(int n=j*bs_w;n<(j+1)*bs_w;n++){
                    img_whole.setPixel(n,m,qRgb(color2.red(),color2.green(),color2.blue()));
                }
            }
        }
    }
    img_end=crop_Win->crop_func(img_whole,muster->prn_w,muster->prn_h,muster->prn_wpos,muster->prn_hpos).copy();
    img_end.save("Board.png");
}


void MainWindow::plot_func()
{
    QVector<double> x(img_new.size().width()),y_red(img_new.size().width()),y_green(img_new.size().width()),y_blue(img_new.size().width());
    for (int i=0;i<img_new.size().width();i++)
    {
        x[i]=i;
        y_red[i]=qRed(img_new.pixel(i,prof_height->text().toInt()));
        y_green[i]=qGreen(img_new.pixel(i,prof_height->text().toInt()));
        y_blue[i]=qBlue(img_new.pixel(i,prof_height->text().toInt()));
    }
    customPlot_hori->addGraph();
    customPlot_hori->graph(0)->setData(x,y_red);
    customPlot_hori->graph(0)->setPen(QPen(Qt::red));
    customPlot_hori->addGraph();
    customPlot_hori->graph(1)->setData(x,y_green);
    customPlot_hori->graph(1)->setPen(QPen(Qt::green));
    customPlot_hori->addGraph();
    customPlot_hori->graph(2)->setData(x,y_blue);
    customPlot_hori->graph(2)->setPen(QPen(Qt::blue));
    customPlot_hori->xAxis->setLabel("Pixel");
    customPlot_hori->yAxis->setLabel("Density /horizontal");
    customPlot_hori->xAxis->setRange(0,img_new.size().width());
    customPlot_hori->yAxis->setRange(0,255);
    customPlot_hori->replot();
    prof_hori_R=y_red; prof_hori_G=y_green; prof_hori_B=y_blue;

    QVector<double> m(img_new.size().height()),n_red(img_new.size().height()),n_green(img_new.size().height()),n_blue(img_new.size().height());
    for (int i=0;i<img_new.size().height();i++)
    {
        m[i]=i;
        n_red[i]=qRed(img_new.pixel(prof_width->text().toInt(),i));
        n_green[i]=qGreen(img_new.pixel(prof_width->text().toInt(),i));
        n_blue[i]=qBlue(img_new.pixel(prof_width->text().toInt(),i));
    }
    customPlot_verti->addGraph();
    customPlot_verti->graph(0)->setData(m,n_red);
    customPlot_verti->graph(0)->setPen(QPen(Qt::red));
    customPlot_verti->addGraph();
    customPlot_verti->graph(1)->setData(m,n_green);
    customPlot_verti->graph(1)->setPen(QPen(Qt::green));
    customPlot_verti->addGraph();
    customPlot_verti->graph(2)->setData(m,n_blue);
    customPlot_verti->graph(2)->setPen(QPen(Qt::blue));
    customPlot_verti->xAxis->setLabel("Pixel");
    customPlot_verti->yAxis->setLabel("Density /vertical");
    customPlot_verti->xAxis->setRange(0,img_new.size().height());
    customPlot_verti->yAxis->setRange(0,255);
    customPlot_verti->replot();
    prof_verti_R=n_red; prof_verti_G=n_green; prof_verti_B=n_blue;

    //draw
    img_plot=img_new.copy();
    QPainter p(&img_plot);
    p.setPen(Qt::red);
    p.drawLine(0,prof_height->text().toInt(),img_new.width(),prof_height->text().toInt());
    p.drawLine(prof_width->text().toInt(),0,prof_width->text().toInt(),img_new.height());
    p.end();
    imgWin->setPixmap(QPixmap::fromImage(img_plot));
    imgWin->setFixedSize(img_plot.size());
}

void MainWindow::zoom_out()
{
    if(zoom_fac>1){
    zoom_fac-=1;}
    else {
        zoom_help+=1;
        zoom_fac=1/zoom_help;
    }
    img_zoom=img_new.scaled(img_new.width()*zoom_fac,img_new.height()*zoom_fac,Qt::IgnoreAspectRatio);
    imgWin->setPixmap(QPixmap::fromImage(img_zoom));
    imgWin->setFixedSize(img_zoom.size());
    logging->appendPlainText("Zoom factor: " + QString::number(zoom_fac));

}

void MainWindow::zoom_in()
{
    if(zoom_fac<1){
    zoom_help-=1;
    zoom_fac=1/zoom_help;
    }
    else{
    zoom_fac+=1;
    }
    img_zoom=img_new.scaled(img_new.width()*zoom_fac,img_new.height()*zoom_fac,Qt::IgnoreAspectRatio);
    imgWin->setPixmap(QPixmap::fromImage(img_zoom));
    imgWin->setFixedSize(img_zoom.size());
    logging->appendPlainText("Zoom factor: " + QString::number(zoom_fac));
}


void MainWindow::profilSave()
{
    filePath= QFileDialog::getSaveFileName(this,tr("save file"),"",tr("Text files (*.txt)"));
    QFile file(filePath);
    file.open(QIODevice::WriteOnly| QIODevice::Text);
    QTextStream stream(&file);
     stream << "Hori R"<<"\t"<<"Hori G"<<"\t"<<"Hori B"<<"\t"<<"Verti R"<<"\t"<<"Verti G"<<"\t"<<"Verti B"<<endl;
    if(img_new.size().width()>=img_new.size().height()){
    for(int i=0;i<prof_hori_R.size();i++){
        stream <<prof_hori_R[i]<<"\t"<<prof_hori_G[i]<<"\t"<<prof_hori_B[i]<<"\t"
               <<((prof_verti_R.size()>i)?prof_verti_R[i]:-9999)<<"\t"<<((prof_verti_G.size()>i)?prof_verti_G[i]:-9999)<<"\t"<<((prof_verti_B.size()>i)?prof_verti_B[i]:-9999)
               <<endl;
        }
    }
    else{
        for(int i=0;i<prof_verti_R.size();i++){
            stream <<((prof_hori_R.size()>i)?prof_hori_R[i]:-9999)<<"\t"<<((prof_hori_G.size()>i)?prof_hori_G[i]:-9999)<<"\t"<<((prof_hori_B.size()>i)?prof_hori_B[i]:-9999)
                   <<"\t"<<prof_verti_R[i]<<"\t"<<prof_verti_G[i]<<"\t"<<prof_verti_B[i]<<"\t"
                   <<endl;
            }
    }
    file.close();
}
