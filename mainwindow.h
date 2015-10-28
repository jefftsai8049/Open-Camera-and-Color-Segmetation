#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QFileDialog>
#include <QString>
#include <opencv.hpp>
#include <camera.h>
#include "math.h"


void mouseClick(int event,int x,int y, int flag,void* param);




namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();



private slots:
    void on_openCam_pushButton_clicked();

    void on_closeCam_pushButton_clicked();

    void on_actionOpen_image_file_triggered();

    void receiveImage(const cv::Mat &src);

private:
    Ui::MainWindow *ui;
    camera *cam;
};

#endif // MAINWINDOW_H
