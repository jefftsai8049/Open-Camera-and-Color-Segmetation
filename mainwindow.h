#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <opencv.hpp>
#include <camera.h>

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

private:
    Ui::MainWindow *ui;
    camera *cam;


};

#endif // MAINWINDOW_H
