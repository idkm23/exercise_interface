// /opt/ros/indigo/lib/rosbag/record --buffsize 256 --chunksize 768 /myo/l/ort /myo/u/ort /myo/l/imu /myo/u/imu
int getPIDbyName(std::string p_name) {
    char buf[512];
    FILE *cmd_pipe = popen(std::string("pidof -s \'") + p_name + "\'", "r");

    fgets(buf, 512, cmd_pipe);
    pid_t pid = strtoul(buf, NULL, 10);

    pclose( cmd_pipe );  
}
