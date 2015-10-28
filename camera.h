#ifndef CAMERA_H
#define CAMERA_H

#include <QObject>
#include <QWidget>
#include <QThread>
#include <opencv.hpp>

class camera : public QThread
{
    Q_OBJECT

public:
    explicit camera(QObject *parent = 0);
    void receiveStopCam(const bool &status);
protected:
    void run();
private:
    bool status;
signals:
    void sentImage(const cv::Mat &src);


};

#endif // CAMERA_H
