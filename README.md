Setup
=====
To run the interface you will need the following packages in the same catkin workspace:  
&nbsp;&nbsp;&nbsp;&nbsp;- myo_raw - https://github.com/ylmeng/myo_raw  
&nbsp;&nbsp;&nbsp;&nbsp;- (optional) myo_nao - https://github.com/idkm23/myo_nao  

If you are completely new to ros, install rosindigo. Then, go to a directory you would like the project in and do:
```
mkdir myo
cd myo
mkdir src
cd src
catkin_init_workspace
git clone https://github.com/ylmeng/myo_raw.git
git clone https://github.com/idkm23/myo_nao.git
git clone https://github.com/idkm23/exercise_interface.git
cd ..
catkin_make
source devel/setup.bash
```

Now your project is configured properly and you may launch the interface with:  
```roslaunch exercise_interface interface.launch```
