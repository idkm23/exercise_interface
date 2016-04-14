#include "../include/master_interface.h"

MasterInterface::MasterInterface(QMainWindow* parent) : QMainWindow(parent), uiComponents(new UIComponents()) {
    eventTimer.start(100, this);

    uiComponents->setupUi(this);
    ros::start();

    trialBegin_pub = n.advertise<std_msgs::Int32>("/exercise/begin_trial", 100);
    myoLaunch_pub = n.advertise<std_msgs::Int32>("/myo/launch", 100);
    myoCalibrate_pub = n.advertise<std_msgs::Int32>("/myo/calibrate", 100);
    exerciseMode_pub = n.advertise<std_msgs::Int32>("/exercise/mode", 100);

    setFixedSize(size());
}

void MasterInterface::timerEvent(QTimerEvent* event) {
    ros::spinOnce();
    update();
}

void MasterInterface::on_trainingRecord_clicked() {
    if(uiComponents->trainingRecord->text() != "stop training") {
        uiComponents->trainingRecord->setText("stop training");  
        uiComponents->trainingRecord->setDown(true);

        if(script_utils::getPIDbyName(script_utils::ROSBAG_PROCESS_NAME) != 0) {
            script_utils::startBagRecording();
        } else {
            ROS_INFO("already recording");
        }

    }  else {
        uiComponents->trainingRecord->setText("train");    
        uiComponents->trainingRecord->setDown(false);
        script_utils::killBagProcess();
    }
}

void MasterInterface::on_trainingClear_clicked() {
    script_utils::removeBags();
}

void MasterInterface::on_trainingDelete_clicked() {
    script_utils::removeLastBag();
}

void MasterInterface::on_trialBegin_clicked() {
    std_msgs::Int32 msg;
    msg.data = 0;
    trialBegin_pub.publish(msg);

    exerciseMode_pub.publish(msg); 
}

void MasterInterface::on_trialPractice_clicked() {
    std_msgs::Int32 msg;
    msg.data = 1;

    exerciseMode_pub.publish(msg);
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
    std_msgs::Int32 msg;

    if(uiComponents->naoLaunch->text() != "stop Nao") {
        uiComponents->naoLaunch->setText("stop Nao");  
        uiComponents->naoLaunch->setDown(true);
        
        msg.data = 3;
        exerciseMode_pub.publish(msg);

    }  else {
        uiComponents->naoLaunch->setText("launch Nao");    
        uiComponents->naoLaunch->setDown(false);
        
        msg.data = 4;
        exerciseMode_pub.publish(msg);
        
    }
}

MasterInterface::~MasterInterface() {
    delete uiComponents;
}
