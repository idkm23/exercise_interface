#include <ros/ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Empty.h>

#include <string>

const std::string KEYWORD("tag");
ros::Publisher detected_state_pub;

void isKeyword(std_msgs::String msg) {
    
    if(msg.data == KEYWORD) {
        std_msgs::Empty empty;
        detected_state_pub.publish(empty);
    }
}

int main(int argc, char **argv) {

    ros::init(argc, argv, "state_listener"); 
    ros::NodeHandle n;

    detected_state_pub = n.advertise<std_msgs::Empty>("/exercise/detected_state", 1000);
    ros::Subscriber sphinx_sub = n.subscribe("/recognizer/output", 1000, isKeyword);

    ros::spin();

    return 0;
}
