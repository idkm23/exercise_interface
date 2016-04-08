#include <ros/ros.h>
#include <QApplication>

#include "../include/master_interface.h"

int main(int argc, char **argv) {

    ros::init(argc, argv, "exercise_interface");    
    QApplication app(argc, argv);
    MasterInterface w;
    w.show();

    return app.exec();
}
