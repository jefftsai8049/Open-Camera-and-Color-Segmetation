#ifndef CAMERA_H
#define CAMERA_H

#include <QObject>
#include <QWidget>
#include <QThread>
#include <opencv.hpp>

class camera : public QThread
{
public:
    camera();
    void receiveStopCam(const bool &status);
protected:
    void run();
private:
    bool status;


};

#endif // CAMERA_H
