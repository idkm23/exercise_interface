#include "../include/master_interface.h"

MasterInterface::MasterInterface(QMainWindow* parent) : QMainWindow(parent), uiComponents(new UIComponents()) {
    eventTimer.start(100, this);

    uiComponents->setupUi(this);
    ros::start();

    trialBegin_pub = n.advertise<std_msgs::Int32>("/exercise/begin_trial", 100);
    myoLaunch_pub = n.advertise<std_msgs::Int32>("/myo/launch", 100);
    myoCalibrate_pub = n.advertise<std_msgs::Int32>("/myo/calibrate", 100);
}

void MasterInterface::timerEvent(QTimerEvent* event) {
    ros::spinOnce();
    update();
}

void MasterInterface::on_trainingRecord_clicked() {
    if(uiComponents->trainingRecord->text() != "stop training") {
        uiComponents->trainingRecord->setText("stop training");  
        uiComponents->trainingRecord->setDown(true);
    }  else {
        uiComponents->trainingRecord->setText("train");    
        uiComponents->trainingRecord->setDown(false);
    }

    ROS_INFO("train");
}

void MasterInterface::on_clearTraining_clicked() {
    ROS_INFO("clear");
}

void MasterInterface::on_trialBegin_clicked() {
    std_msgs::Int32 msg;
    msg.data = 0;
    trialBegin_pub.publish(msg);
}

void MasterInterface::on_myoLaunch_clicked() {
    std_msgs::Int32 msg;
    msg.data = uiComponents->getMyoCount();
    myoLaunch_pub.publish(msg);
}

void MasterInterface::on_myoCalibrate_clicked() {
    std_msgs::Int32 msg;
    msg.data = uiComponents->getMyoCount();
    myoCalibrate_pub.publish(msg);
}

void MasterInterface::on_naoLaunch_clicked() {
}

MasterInterface::~MasterInterface() {
    delete uiComponents;
}
