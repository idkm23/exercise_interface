#ifndef MASTER_INTERFACE_H
#define MASTER_INTERFACE_H

#include <ros/ros.h>
#include <rosbag/bag.h>
#include <std_msgs/Int32.h>

#include <QMainWindow>
#include <QWidget>
#include <QTimer>
#include "ui_components.h"

class MasterInterface : public QMainWindow
{
  Q_OBJECT
public:
  explicit MasterInterface(QMainWindow* parent = 0);
  ~MasterInterface();

protected:
  void timerEvent(QTimerEvent* event); //"master" gui needs this??? -James

private:
  ros::NodeHandle n;
  ros::Publisher myoLaunch_pub, myoCalibrate_pub, trialBegin_pub, exerciseMode_pub;

  UIComponents *uiComponents;
  QBasicTimer eventTimer;

private Q_SLOTS:  
  void on_trainingRecord_clicked();
  void on_trainingDelete_clicked();
  void on_trainingClear_clicked();

  void on_trialBegin_clicked();
  void on_trialPractice_clicked();

  void on_myoLaunch_clicked();
  void on_myoCalibrate_clicked();
  void on_naoLaunch_clicked();
};
#endif 
