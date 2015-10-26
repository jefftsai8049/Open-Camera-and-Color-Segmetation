#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_openCam_pushButton_clicked()
{
    //start the cam capture thread
    cam = new camera;
    cam->start();
}

void MainWindow::on_closeCam_pushButton_clicked()
{
    //stop capture image from webcam
    cam->receiveStopCam(false);
}
