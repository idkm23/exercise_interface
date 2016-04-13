#ifndef SCRIPT_UTILS_H
#define SCRIPT_UTILS_H

#include <sys/types.h>
#include <signal.h>

namespace script_utils {

    const std::string ROSBAG_PROCESS_NAME = "/opt/ros/indigo/lib/rosbag/record --buffsize 256 --chunksize 768 /myo/l/emg /myo/u/emg /myo/l/imu /myo/u/imu";
    const std::string ROSBAG_RECORD_LOC = "../../../src/exercise_interface/scripts/grabBag.sh &";
    const std::string ROSBAG_CLEAR_LOC = "../../../src/exercise_interface/scripts/removeBags.sh &";
    const std::string ROSBAG_REMOVELAST_LOC = "../../../src/exercise_interface/scripts/removeLastBag.sh &";

    inline int startBagRecording() {
        system(ROSBAG_RECORD_LOC.c_str());
    }

    inline int getPIDbyName(const std::string p_name) {
        char buf[512];

        std::string s = "pgrep -f \'" + p_name + "\'";
        FILE *cmd_pipe = popen(s.c_str(), "r");
        ROS_INFO(s.c_str());


        fgets(buf, 512, cmd_pipe);
        pid_t pid = strtoul(buf, NULL, 10);

        pclose( cmd_pipe );

        return pid;
    }

    inline void killBagProcess() {
        pid_t rosbag_pid = getPIDbyName(ROSBAG_PROCESS_NAME);
        kill(rosbag_pid, SIGINT);
    }

    inline void removeBags() {
        system(ROSBAG_CLEAR_LOC.c_str());
    }

    inline void removeLastBag() {
        system(ROSBAG_REMOVELAST_LOC.c_str());
    }
}

#endif
