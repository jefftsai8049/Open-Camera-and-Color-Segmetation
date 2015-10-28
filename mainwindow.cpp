#include "mainwindow.h"
#include "ui_mainwindow.h"


cv::Mat pic;
cv::Mat img;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    qRegisterMetaType<cv::Mat>("cv::Mat");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void mouseClick(int event, int x, int y, int flag, void *param)
{
    qDebug() << event << x << y << flag;

    static int xStart,yStart,xEnd,yEnd;
    if(!pic.empty())
    {

        if(event == 1)
        {
            xStart = x;
            yStart = y;
        }

        if(event == 4 || flag == 1)
        {
            cv::Mat dst;
            dst = pic.clone();
            xEnd = x;
            yEnd = y;
            qDebug() <<xStart<<yStart<<xEnd-xStart<<yEnd-yStart;
            cv::rectangle(dst,cv::Rect(xStart,yStart,xEnd-xStart,yEnd-yStart),cv::Scalar(255,255,255),5);
            cv::imshow("src",dst);
            if(flag == 0)
        {
                cv::imwrite("cut.jpg",dst(cv::Rect(xStart,yStart,xEnd-xStart,yEnd-yStart)));
            }
        }





    }

}

void MainWindow::on_openCam_pushButton_clicked()
{
    //start the cam capture thread
    cam = new camera;
    connect(cam,SIGNAL(sentImage(cv::Mat)),this,SLOT(receiveImage(cv::Mat)));


    cv::namedWindow("src");
    cam->start();
    cv::setMouseCallback("src",mouseClick,0);

}

void MainWindow::on_closeCam_pushButton_clicked()
{
    //stop capture image from webcam
    disconnect(cam,SIGNAL(sentImage(cv::Mat)),this,SLOT(receiveImage(cv::Mat)));
    cam->receiveStopCam(false);
}

void MainWindow::on_actionOpen_image_file_triggered()
{
    QString fileName = QFileDialog::getOpenFileName();
    qDebug() << fileName;
    img = cv::imread(fileName.toStdString());

    cv::imshow("img",img);
}

void MainWindow::receiveImage(const cv::Mat &src)
{
    cv::imshow("src",src);
    pic = src.clone();
}
