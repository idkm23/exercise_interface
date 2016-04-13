#!/bin/bash
cd ../../../src/myo_raw/data/ros\ bags
rosbag record /myo/l/emg /myo/u/emg /myo/l/imu /myo/u/imu
